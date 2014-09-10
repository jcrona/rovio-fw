#include "../Inc/CommonDef.h"
int Http_GetAudio(HTTPCONNECTION hConnection,
								int *piPostState,
								char **ppcPostBuf,
								int *piPostBufLen,
								int *piPostDataLen,
								char *pcFillData,
								int iFillDataLen,
								int iIsMoreData/*bool*/,
								void *pParam/*other parameter for extend use*/)
{
	IO_THREAD_READ_T pArg;
	char *senbuf = pcFillData;
	pArg.mediatype = MEDIA_TYPE_AUDIO;
	pArg.txbuf = (unsigned char*)pcFillData;
	pArg.txlen = iFillDataLen;
	//diag_printf("receive audio length: %d\n", iFillDataLen);
	iothread_Write(&pArg);
	/*
	while((senbuf + 320) <=(pcFillData+iFillDataLen)) 
	{
		pArg.txbuf = (unsigned char *)senbuf;
		pArg.txlen = 320;	
		iothread_Write(&pArg);
		senbuf += 320;
	}
	if(senbuf < (pcFillData+iFillDataLen))
	{
		pArg.txbuf = (unsigned char *)senbuf;
		pArg.txlen = pcFillData+iFillDataLen-senbuf;	
		iothread_Write(&pArg);
		
	}
	*/
	return 1;
}


// SIMON
int Http_GetRCAudio(HTTPCONNECTION hConnection,
								int *piPostState,
								char **ppcPostBuf,
								int *piPostBufLen,
								int *piPostDataLen,
								char *pcFillData,
								int iFillDataLen,
								int iIsMoreData/*bool*/,
								void *pParam/*other parameter for extend use*/)
{
	IO_THREAD_READ_T pArg;
	int hAudio, recvSize, recv_rc;
	int dataAva;
	char *senbuf = pcFillData;
#define DUMB_BUFSIZE	256
#define MAX_AUDIO_DATASIZE	4096
#define MIN_AUDIO_DATASIZE	260
	char dumbBuf[DUMB_BUFSIZE];
	pArg.mediatype = MEDIA_TYPE_AUDIO;
	pArg.txbuf = (unsigned char*)pcFillData;
	pArg.txlen = iFillDataLen;
	//diag_printf("receive audio length: %d\n", iFillDataLen);

	hAudio = *((int *) hConnection);
	dataAva = 0;
	ioctl(hAudio, FIONREAD, &dataAva);
	if (dataAva) {
		if (dataAva > MAX_AUDIO_DATASIZE) {
			while (dataAva > MIN_AUDIO_DATASIZE) {
				if (dataAva > DUMB_BUFSIZE)
					recvSize = DUMB_BUFSIZE;
				else
					recvSize = dataAva;
				if (recvSize % 2)
					recvSize--;
				recv_rc = recv(hAudio, dumbBuf, recvSize, 0);
				if (recv_rc < 0)
					break;
				dataAva = 0;
				ioctl(hAudio, FIONREAD, &dataAva);
			}
		}

	}

	iothread_Write(&pArg);
	/*
	while((senbuf + 320) <=(pcFillData+iFillDataLen)) 
	{
		pArg.txbuf = (unsigned char *)senbuf;
		pArg.txlen = 320;	
		iothread_Write(&pArg);
		senbuf += 320;
	}
	if(senbuf < (pcFillData+iFillDataLen))
	{
		pArg.txbuf = (unsigned char *)senbuf;
		pArg.txlen = pcFillData+iFillDataLen-senbuf;	
		iothread_Write(&pArg);
		
	}
	*/
	return 1;
}