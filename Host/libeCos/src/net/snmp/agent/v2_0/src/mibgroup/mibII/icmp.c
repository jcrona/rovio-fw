//==========================================================================
//
//      snmp/snmpagent/current/src/mibgroup/mibII/icmp.c
//
//
//==========================================================================
//####ECOSGPLCOPYRIGHTBEGIN####
// -------------------------------------------
// This file is part of eCos, the Embedded Configurable Operating System.
// Copyright (C) 1998, 1999, 2000, 2001, 2002 Red Hat, Inc.
//
// eCos is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 or (at your option) any later version.
//
// eCos is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public License along
// with eCos; if not, write to the Free Software Foundation, Inc.,
// 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
//
// As a special exception, if other files instantiate templates or use macros
// or inline functions from this file, or you compile this file and link it
// with other works to produce a work based on this file, this file does not
// by itself cause the resulting work to be covered by the GNU General Public
// License. However the source code for this file must still be made available
// in accordance with section (3) of the GNU General Public License.
//
// This exception does not invalidate any other reasons why a work based on
// this file might be covered by the GNU General Public License.
//
// Alternative licenses for eCos may be arranged by contacting Red Hat, Inc.
// at http://sources.redhat.com/ecos/ecos-license/
// -------------------------------------------
//####ECOSGPLCOPYRIGHTEND####
//####UCDSNMPCOPYRIGHTBEGIN####
//
// -------------------------------------------
//
// Portions of this software may have been derived from the UCD-SNMP
// project,  <http://ucd-snmp.ucdavis.edu/>  from the University of
// California at Davis, which was originally based on the Carnegie Mellon
// University SNMP implementation.  Portions of this software are therefore
// covered by the appropriate copyright disclaimers included herein.
//
// The release used was version 4.1.2 of May 2000.  "ucd-snmp-4.1.2"
// -------------------------------------------
//
//####UCDSNMPCOPYRIGHTEND####
//==========================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):    hmt
// Contributors: hmt
// Date:         2000-05-30
// Purpose:      Port of UCD-SNMP distribution to eCos.
// Description:  
//              
//
//####DESCRIPTIONEND####
//
//==========================================================================
/********************************************************************
       Copyright 1989, 1991, 1992 by Carnegie Mellon University
 
                          Derivative Work -
Copyright 1996, 1998, 1999, 2000 The Regents of the University of California
 
                         All Rights Reserved
 
Permission to use, copy, modify and distribute this software and its
documentation for any purpose and without fee is hereby granted,
provided that the above copyright notice appears in all copies and
that both that copyright notice and this permission notice appear in
supporting documentation, and that the name of CMU and The Regents of
the University of California not be used in advertising or publicity
pertaining to distribution of the software without specific written
permission.
 
CMU AND THE REGENTS OF THE UNIVERSITY OF CALIFORNIA DISCLAIM ALL
WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL CMU OR
THE REGENTS OF THE UNIVERSITY OF CALIFORNIA BE LIABLE FOR ANY SPECIAL,
INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING
FROM THE LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF
CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*********************************************************************/
/* This file was generated by mib2c and is intended for use as a mib module
   for the ucd-snmp snmpd agent. */


/* This should always be included first before anything else */
#include <config.h>


/* minimal include directives */
#include "mibincl.h"
#include "mibgroup/util_funcs.h"
#include "mibgroup/mibII/icmp.h"


#define _KERNEL
#include <netinet/ip_icmp.h>
#include <netinet/icmp_var.h>

/* 
 * icmp_variables_oid:
 *   this is the top level oid that we want to register under.  This
 *   is essentially a prefix, with the suffix appearing in the
 *   variable below.
 */


oid icmp_variables_oid[] = { 1,3,6,1,2,1,5 };


/* 
 * variable2 icmp_variables:
 *   this variable defines function callbacks and type return information 
 *   for the icmp mib section 
 */


struct variable2 icmp_variables[] = {
/*  magic number        , variable type , ro/rw , callback fn  , L, oidsuffix */
#define   ICMPINMSGS            1
  { ICMPINMSGS          , ASN_COUNTER   , RONLY , var_icmp, 1, { 1 } },
#define   ICMPINERRORS          2
  { ICMPINERRORS        , ASN_COUNTER   , RONLY , var_icmp, 1, { 2 } },
#define   ICMPINDESTUNREACHS    3
  { ICMPINDESTUNREACHS  , ASN_COUNTER   , RONLY , var_icmp, 1, { 3 } },
#define   ICMPINTIMEEXCDS       4
  { ICMPINTIMEEXCDS     , ASN_COUNTER   , RONLY , var_icmp, 1, { 4 } },
#define   ICMPINPARMPROBS       5
  { ICMPINPARMPROBS     , ASN_COUNTER   , RONLY , var_icmp, 1, { 5 } },
#define   ICMPINSRCQUENCHS      6
  { ICMPINSRCQUENCHS    , ASN_COUNTER   , RONLY , var_icmp, 1, { 6 } },
#define   ICMPINREDIRECTS       7
  { ICMPINREDIRECTS     , ASN_COUNTER   , RONLY , var_icmp, 1, { 7 } },
#define   ICMPINECHOS           8
  { ICMPINECHOS         , ASN_COUNTER   , RONLY , var_icmp, 1, { 8 } },
#define   ICMPINECHOREPS        9
  { ICMPINECHOREPS      , ASN_COUNTER   , RONLY , var_icmp, 1, { 9 } },
#define   ICMPINTIMESTAMPS      10
  { ICMPINTIMESTAMPS    , ASN_COUNTER   , RONLY , var_icmp, 1, { 10 } },
#define   ICMPINTIMESTAMPREPS   11
  { ICMPINTIMESTAMPREPS , ASN_COUNTER   , RONLY , var_icmp, 1, { 11 } },
#define   ICMPINADDRMASKS       12
  { ICMPINADDRMASKS     , ASN_COUNTER   , RONLY , var_icmp, 1, { 12 } },
#define   ICMPINADDRMASKREPS    13
  { ICMPINADDRMASKREPS  , ASN_COUNTER   , RONLY , var_icmp, 1, { 13 } },
#define   ICMPOUTMSGS           14
  { ICMPOUTMSGS         , ASN_COUNTER   , RONLY , var_icmp, 1, { 14 } },
#define   ICMPOUTERRORS         15
  { ICMPOUTERRORS       , ASN_COUNTER   , RONLY , var_icmp, 1, { 15 } },
#define   ICMPOUTDESTUNREACHS   16
  { ICMPOUTDESTUNREACHS , ASN_COUNTER   , RONLY , var_icmp, 1, { 16 } },
#define   ICMPOUTTIMEEXCDS      17
  { ICMPOUTTIMEEXCDS    , ASN_COUNTER   , RONLY , var_icmp, 1, { 17 } },
#define   ICMPOUTPARMPROBS      18
  { ICMPOUTPARMPROBS    , ASN_COUNTER   , RONLY , var_icmp, 1, { 18 } },
#define   ICMPOUTSRCQUENCHS     19
  { ICMPOUTSRCQUENCHS   , ASN_COUNTER   , RONLY , var_icmp, 1, { 19 } },
#define   ICMPOUTREDIRECTS      20
  { ICMPOUTREDIRECTS    , ASN_COUNTER   , RONLY , var_icmp, 1, { 20 } },
#define   ICMPOUTECHOS          21
  { ICMPOUTECHOS        , ASN_COUNTER   , RONLY , var_icmp, 1, { 21 } },
#define   ICMPOUTECHOREPS       22
  { ICMPOUTECHOREPS     , ASN_COUNTER   , RONLY , var_icmp, 1, { 22 } },
#define   ICMPOUTTIMESTAMPS     23
  { ICMPOUTTIMESTAMPS   , ASN_COUNTER   , RONLY , var_icmp, 1, { 23 } },
#define   ICMPOUTTIMESTAMPREPS  24
  { ICMPOUTTIMESTAMPREPS, ASN_COUNTER   , RONLY , var_icmp, 1, { 24 } },
#define   ICMPOUTADDRMASKS      25
  { ICMPOUTADDRMASKS    , ASN_COUNTER   , RONLY , var_icmp, 1, { 25 } },
#define   ICMPOUTADDRMASKREPS   26
  { ICMPOUTADDRMASKREPS , ASN_COUNTER   , RONLY , var_icmp, 1, { 26 } },

};
/*    (L = length of the oidsuffix) */


/*
 * init_icmp():
 *   Initialization routine.  This is called when the agent starts up.
 *   At a minimum, registration of your variables should take place here.
 */
void init_icmp(void) {


  /* register ourselves with the agent to handle our mib tree */
  REGISTER_MIB("icmp", icmp_variables, variable2,
               icmp_variables_oid);


  /* place any other initialization junk you need here */
}


/*
 * var_icmp():
 *   This function is called every time the agent gets a request for
 *   a scalar variable that might be found within your mib section
 *   registered above.  It is up to you to do the right thing and
 *   return the correct value.
 *     You should also correct the value of "var_len" if necessary.
 *
 *   Please see the documentation for more information about writing
 *   module extensions, and check out the examples in the examples
 *   and mibII directories.
 */
unsigned char *
var_icmp(struct variable *vp, 
                oid     *name, 
                size_t  *length, 
                int     exact, 
                size_t  *var_len, 
                WriteMethod **write_method)
{
    /* variables we may use later */
    static long long_ret;
    int i;

    if (header_generic(vp,name,length,exact,var_len,write_method)
        == MATCH_FAILED )
        return NULL;

    switch (vp->magic){
    case ICMPINMSGS:
        long_ret = icmpstat.icps_badcode + icmpstat.icps_tooshort +
            icmpstat.icps_checksum + icmpstat.icps_badlen;
        for (i=0; i <= ICMP_MAXTYPE; i++)
            long_ret += icmpstat.icps_inhist[i];
        return (u_char *)&long_ret;
    case ICMPINERRORS:
        long_ret = icmpstat.icps_badcode + icmpstat.icps_tooshort +
            icmpstat.icps_checksum + icmpstat.icps_badlen;
        return (u_char *)&long_ret;
    case ICMPINDESTUNREACHS:
        long_ret = icmpstat.icps_inhist[ICMP_UNREACH];
        return (u_char *) &long_ret;
    case ICMPINTIMEEXCDS:
        long_ret = icmpstat.icps_inhist[ICMP_TIMXCEED];
        return (u_char *) &long_ret;
    case ICMPINPARMPROBS:
        long_ret = icmpstat.icps_inhist[ICMP_PARAMPROB];
        return (u_char *) &long_ret;
    case ICMPINSRCQUENCHS:
        long_ret = icmpstat.icps_inhist[ICMP_SOURCEQUENCH];
        return (u_char *) &long_ret;
    case ICMPINREDIRECTS:
        long_ret = icmpstat.icps_inhist[ICMP_REDIRECT];
        return (u_char *) &long_ret;
    case ICMPINECHOS:
        long_ret = icmpstat.icps_inhist[ICMP_ECHO];
        return (u_char *) &long_ret;
    case ICMPINECHOREPS:
        long_ret = icmpstat.icps_inhist[ICMP_ECHOREPLY];
        return (u_char *) &long_ret;
    case ICMPINTIMESTAMPS:
        long_ret = icmpstat.icps_inhist[ICMP_TSTAMP];
        return (u_char *) &long_ret;
    case ICMPINTIMESTAMPREPS:
        long_ret = icmpstat.icps_inhist[ICMP_TSTAMPREPLY];
        return (u_char *) &long_ret;
    case ICMPINADDRMASKS:
        long_ret = icmpstat.icps_inhist[ICMP_MASKREQ];
        return (u_char *) &long_ret;
    case ICMPINADDRMASKREPS:
        long_ret = icmpstat.icps_inhist[ICMP_MASKREPLY];
        return (u_char *) &long_ret;
    case ICMPOUTMSGS:
        long_ret = icmpstat.icps_oldshort + icmpstat.icps_oldicmp;
        for (i=0; i <= ICMP_MAXTYPE; i++)
            long_ret += icmpstat.icps_outhist[i];
        return (u_char *)&long_ret;
    case ICMPOUTERRORS:
        long_ret = icmpstat.icps_oldshort + icmpstat.icps_oldicmp;
        return (u_char *)&long_ret;
    case ICMPOUTDESTUNREACHS:
        long_ret = icmpstat.icps_outhist[ICMP_UNREACH];
        return (u_char *) &long_ret;
    case ICMPOUTTIMEEXCDS:
        long_ret = icmpstat.icps_outhist[ICMP_TIMXCEED];
        return (u_char *) &long_ret;
    case ICMPOUTPARMPROBS:
        long_ret = icmpstat.icps_outhist[ICMP_PARAMPROB];
        return (u_char *) &long_ret;
    case ICMPOUTSRCQUENCHS:
        long_ret = icmpstat.icps_outhist[ICMP_SOURCEQUENCH];
        return (u_char *) &long_ret;
    case ICMPOUTREDIRECTS:
        long_ret = icmpstat.icps_outhist[ICMP_REDIRECT];
        return (u_char *) &long_ret;
    case ICMPOUTECHOS:
        long_ret = icmpstat.icps_outhist[ICMP_ECHO];
        return (u_char *) &long_ret;
    case ICMPOUTECHOREPS:
        long_ret = icmpstat.icps_outhist[ICMP_ECHOREPLY];
        return (u_char *) &long_ret;
    case ICMPOUTTIMESTAMPS:
        long_ret = icmpstat.icps_outhist[ICMP_TSTAMP];
        return (u_char *) &long_ret;
    case ICMPOUTTIMESTAMPREPS:
        long_ret = icmpstat.icps_outhist[ICMP_TSTAMPREPLY];
        return (u_char *) &long_ret;
    case ICMPOUTADDRMASKS:
        long_ret = icmpstat.icps_outhist[ICMP_MASKREQ];
        return (u_char *) &long_ret;
    case ICMPOUTADDRMASKREPS:
        long_ret = icmpstat.icps_outhist[ICMP_MASKREPLY];
        return (u_char *) &long_ret;
    default:
        DEBUGMSGTL(("snmpd", "unknown sub-id %d in var_icmp\n", vp->magic));
    }
    
    return NULL;
}

// EOF icmp.c
