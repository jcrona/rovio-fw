#include "../Inc/CommonDef.h"


static PRD_TASK_T g_prdtskCheckBattery;

/* Check battery level */
static void prdTask_CheckBattery(void *pArg)
{
	static int first_call = 10;
        static int count = 0;		// Ping retry time (success retrys)
	static int fail_cnt = 0;	// Ping retry time upon failure
	static int fail_ping = 0;	// # of Ping failures
        static int led_red = 0;
	char *ping_ipaddr;
	BOOL bOnCharge;
#if defined IPCAM_CONFIG_IP_CAM_VER_1 || defined IPCAM_CONFIG_IP_CAM_VER_2 || defined IPCAM_CONFIG_IP_CAM_VER_3
	if(mcuGetBattery(FALSE, &bOnCharge) <= (unsigned char)0x71 && !bOnCharge )
		ledSetLowBattery(TRUE);
	else
		ledSetLowBattery(FALSE);

#elif defined IPCAM_CONFIG_IP_CAM_VER_0 || defined IPCAM_CONFIG_MP4_EVB_VER_0 || defined IPCAM_CONFIG_MP4_EVB_VER_1
#else
#	error "No hardware config defined!"
#endif

        /* SIMON */
	// Init framerate & AGC (Need to wait for system to bootup completely before applying settings)
	if (first_call) {
		first_call--;
		if (first_call == 0) {
			// Set framerate
			i2cWriteI2C((UINT32) 0x3b, (UINT32) 0xa2);
			// Set AGC (Automatic Gain Control
			i2cWriteI2C((UINT32) 0x14, (UINT32) 0x28);
		}
		return;
	}
	// Don't do anything if no ping IP Address set
	ping_ipaddr = g_ConfigParam.acWatchdogIP;
	if (*ping_ipaddr == '\0')
		return;

	if (fail_ping > 0) {
		fail_cnt++;
		// Flash LED in RED & GREEN up failure
		if (led_red) {
			led_red = 0;
			ledSetNetwork(LED_NETWORK_READY);
		} else {
			led_red = 1;
			ledSetNetwork(LED_NETWORK_STREAMING);
		}
		if (fail_cnt == 2) {	// Ping timer changed to every 4 seconds
			fail_cnt = 0;	// Failed ping retry timer
			if (ping_test(ping_ipaddr)) {
				fail_ping = 0;
				led_red = 0;
				ledSetNetwork(LED_NETWORK_READY);
			} else {
				fail_ping++;
				if (fail_ping == 13) {	// Failed ping threshold 52 seconds
					// # of failed ping threshold reached, perform reboot
					WebCameraSIGTERM(0);
					W99802Reboot();
					fail_ping = 0;
				}
			}
		}
	} else {
		count++;
        	if (count == 8) {	// Ping timer (once every 16 seconds)
			count = 0;
			if (ping_test(ping_ipaddr)) {
				// Ping succeeded
				fail_ping = 0;
				fail_cnt = 0;
			} else {
				// Ping failed
				fail_ping = 1;
				fail_cnt = 0;;
				led_red = 1;
				ledSetNetwork(LED_NETWORK_STREAMING);
			}
		}
	}

}



void prdAddTask_CheckBattery()
{
	prdAddTask(&g_prdtskCheckBattery, &prdTask_CheckBattery, 200, NULL);
}


void prdDelTask_CheckBattery()
{
	prdDelTask(&g_prdtskCheckBattery);
}

