/*
 * Copyright 2004 Henning Brauer <henning@openbsd.org>
 * Copyright (c) 1995, 1996, 1997, 1998, 1999
 * The Internet Software Consortium.    All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of The Internet Software Consortium nor the names
 *    of its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INTERNET SOFTWARE CONSORTIUM AND
 * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE INTERNET SOFTWARE CONSORTIUM OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This software has been written for the Internet Software Consortium
 * by Ted Lemon <mellon@fugue.com> in cooperation with Vixie
 * Enterprises.  To learn more about the Internet Software Consortium,
 * see ``http://www.vix.com/isc''.  To learn more about Vixie
 * Enterprises, see ``http://www.vix.com''.
 *
 * This client was substantially modified and enhanced by Elliot Poger
 * for use on Linux while he was working on the MosquitoNet project at
 * Stanford.
 *
 * The current version owes much to Elliot's Linux enhancements, but
 * was substantially reorganized and partially rewritten by Ted Lemon
 * so as to use the same networking framework that the Internet Software
 * Consortium DHCP server uses.   Much system-specific configuration code
 * was moved into a shell script so that as support for more operating
 * systems is added, it will not be necessary to port and maintain
 * system-specific configuration code to these operating systems - instead,
 * the shell script can invoke the native tools to accomplish the same
 * purpose.
 */
/*
 * WIDE Project DHCP Implementation
 * Copyright (c) 1995-1997 Akihiro Tominaga
 * Copyright (c) 1995-1997 WIDE Project
 * All rights reserved.
 *
 * Permission to use, copy, modify and distribute this software and its
 * documentation is hereby granted, provided the following conditions
 * are satisfied,
 *
 * 1. Both the copyright notice and this permission notice appear in
 *    all copies of the software, derivative works or modified versions,
 *    and any portions thereof, and that both notices appear in
 *    supporting documentation.
 * 2. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by WIDE Project and
 *      its contributors.
 * 3. Neither the name of WIDE Project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE DEVELOPER ``AS IS'' AND WIDE
 * PROJECT DISCLAIMS ANY LIABILITY OF ANY KIND FOR ANY DAMAGES
 * WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE. ALSO, THERE
 * IS NO WARRANTY IMPLIED OR OTHERWISE, NOR IS SUPPORT PROVIDED.
 *
 * Feedback of the results generated from any improvements or
 * extensions made to this software would be much appreciated.
 * Any such feedback should be sent to:
 * 
 *  Akihiro Tominaga
 *  WIDE Project
 *  Keio University, Endo 5322, Kanagawa, Japan
 *  (E-mail: dhcp-dist@wide.ad.jp)
 *
 * WIDE project has the rights to redistribute these changes.
 */
/*
 *  TINET (TCP/IP Protocol Stack)
 * 
 *  Copyright (C) 2011 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *
 *  ????????????????????????????????? (1)???(4) ???????????????Free Software Foundation 
 *  ????????????????????????????????? GNU General Public License ??? Version 2 ??????
 *  ???????????????????????????????????????????????????????????????????????????????????????????????????
 *  ???????????????????????????????????????????????????????????????????????????????????????????????????
 *  ?????????????????????????????????????????????????????????
 *  (1) ?????????????????????????????????????????????????????????????????????????????????????????????
 *      ????????????????????????????????????????????????????????????????????????????????????????????????
 *      ?????????????????????????????????????????????
 *  (2) ?????????????????????????????????????????????????????????????????????????????????????????????
 *      ?????????????????????????????????????????????????????????????????????????????????????????????
 *      ?????????????????????????????????????????????????????????????????????????????????????????????
 *      ??????????????????????????????????????????
 *  (3) ?????????????????????????????????????????????????????????????????????????????????????????????
 *      ?????????????????????????????????????????????????????????????????????????????????????????????
 *      ??????
 *    (a) ??????????????????????????????????????????????????????????????????????????????????????????
 *        ??????????????????????????????????????????????????????????????????????????????????????????
 *    (b) ????????????????????????????????????????????????????????????TOPPERS?????????????????????
 *        ?????????????????????
 *  (4) ?????????????????????????????????????????????????????????????????????????????????????????????
 *      ??????????????????????????????????????????TOPPERS??????????????????????????????????????????
 *
 *  ???????????????????????????????????????????????????????????????????????????????????????????????????
 *  ??????TOPPERS????????????????????????????????????????????????????????????????????????????????????
 *  ???????????????????????????????????????????????????????????????????????????????????????????????????
 *  ??????????????????????????????????????????????????????????????????????????????????????????????????????
 * 
 *  @(#) $Id: dhcp4_cli_var.h 1.7 2017/6/1 8:50:20 abe $
 */

#ifndef DHCP4_CLI_VAR_H
#define DHCP4_CLI_VAR_H

/*
 *  DHCP ?????????????????????????????????????????????
 */

/* TIMER ????????? */

#define DHCP4C_TIMER_SND_DISC	0
#define DHCP4C_TIMER_SND_REQ	1
#define DHCP4C_TIMER_SND_REL	2
#define DHCP4C_TIMER_RCV_OFFER	3
#define DHCP4C_TIMER_RCV_ACK	4
#define DHCP4C_TIMER_RENEW	5
#define DHCP4C_TIMER_REBIND	6
#define DHCP4C_TIMER_EXPIRE	7
#define NUM_DHCP4C_TIMERS	8

#define DHCP4C_TIMER_HZ		1

typedef struct dhcp4_cli_context {
	T_DHCP4_CLI_MSG	*rcv_lst;	/* ???????????????????????????????????????		*/
	T_DHCP4_CLI_MSG	*val_lst;	/* ???????????????????????????????????????		*/
	T_DHCP4_CLI_MSG	*prf_lst;	/* ???????????????????????????????????????		*/
	T_DHCP4_CLI_MSG	*snd_msg;	/* ??????????????????????????????			*/
	T_DHCP4_CLI_MSG	*off_msg;	/* ???????????????????????????????????????????????????	*/
	T_DHCP4_CLI_MSG	*act_msg;	/* ?????????????????????????????????????????????	*/
	T_IF_SOFTC	*sc;		/* IF ???????????????????????????		*/
	T_IPV4EP	dst;		/* ????????????IP????????????/???????????????	*/
	SYSTIM		snd_start;	/* ???????????????????????????			*/
	SYSTIM		bind_start;	/* BIND?????????????????????			*/
	SYSTIM		expire;		/* ???????????????????????????ms???		*/
	SYSTIM		renew;		/* RENEW???T1?????????????????????ms???	*/
	SYSTIM		rebind;		/* REBIND???T2?????????????????????ms???	*/
	SYSTIM		timers[NUM_DHCP4C_TIMERS];	
					/* ??????????????????			*/
	RELTIM		interval;	/* ????????????			*/
	ER_UINT		error;		/* ????????????????????????		*/
	ID		cepid;		/* CEP ID			*/
	uint32_t	xid;		/* ???????????????????????? ID		*/
	uint16_t	flags;		/* ???????????????			*/
	uint16_t	max_prefer;	/* ???????????????????????????????????????	*/
	uint16_t	secs;		/* seconds since boot began	*/
	uint8_t		fsm;		/* ???????????????			*/
	} T_DHCP4_CLI_CONTEXT;

/* fsm??????????????????????????? */

#define DHCP4_FSM_INIT		1
#define DHCP4_FSM_SELECT	2
#define DHCP4_FSM_REQUEST	3
#define DHCP4_FSM_BOUND		4
#define DHCP4_FSM_RENEW		5
#define DHCP4_FSM_REBIND	6
#define DHCP4_FSM_INIT_REBOOT	7
#define DHCP4_FSM_REBOOT	8
#define DHCP4_FSM_REL_INFO	11	/* DHCPv4 ??? RFC2131 ???????????????*/
#define DHCP4_FSM_SLEEP		12	/* DHCPv4 ??? RFC2131 ???????????????*/

/* flag ????????? */

#define DHCP4C_FLAG_TMOUT_SND_DISC	(DHCP4C_FLAG_TMOUT_TIMER|DHCP4C_TIMER_SND_DISC)
#define DHCP4C_FLAG_TMOUT_SND_REQ	(DHCP4C_FLAG_TMOUT_TIMER|DHCP4C_TIMER_SND_REQ)
#define DHCP4C_FLAG_TMOUT_SND_REL	(DHCP4C_FLAG_TMOUT_TIMER|DHCP4C_TIMER_SND_REL)
#define DHCP4C_FLAG_TMOUT_RCV_OFFER	(DHCP4C_FLAG_TMOUT_TIMER|DHCP4C_TIMER_RCV_OFFER)
#define DHCP4C_FLAG_TMOUT_RCV_ACK	(DHCP4C_FLAG_TMOUT_TIMER|DHCP4C_TIMER_RCV_ACK)
#define DHCP4C_FLAG_TMOUT_EXPIRE	(DHCP4C_FLAG_TMOUT_TIMER|DHCP4C_TIMER_EXPIRE)
#define DHCP4C_FLAG_TMOUT_RENEW		(DHCP4C_FLAG_TMOUT_TIMER|DHCP4C_TIMER_RENEW)
#define DHCP4C_FLAG_TMOUT_REBIND	(DHCP4C_FLAG_TMOUT_TIMER|DHCP4C_TIMER_REBIND)
#define DHCP4C_FLAG_TMOUT_TIMER		UINT_C(0x0010)
#define DHCP4C_FLAG_TMOUT_TIMER_MASK	UINT_C(0x000f)
#define DHCP4C_FLAG_TMOUT_MASK		UINT_C(0x001f)

#define DHCP4C_FLAG_RCV_MSG		UINT_C(0x0200)
#define DHCP4C_FLAG_RENEW		UINT_C(0x0400)

/*
 *  ???????????????????????????????????????
 */

/* ??????????????????????????? */

#define DHCP4C_TMOC(t)		(((t)-1000)+dhcp_rand()%2000)

/* ???????????? */

#define TIMEC_GT(a,b)		((int32_t)((a)-(b))>0)
#define TIMEC_GE(a,b)		((int32_t)((a)-(b))>=0)

/* ????????????????????? */

#define SYSTIM2TIMER(t)		(((t)<SYSTIM_HZ/DHCP4C_TIMER_HZ)?(DHCP4C_TIMER_HZ):((t)*DHCP4C_TIMER_HZ)/SYSTIM_HZ)
#define SYSTIM2SEC(t)		(((t)<SYSTIM_HZ)?1:((t)/SYSTIM_HZ))
#define SEC2TIMER(t)		((t)*DHCP4C_TIMER_HZ)
#define SEC2SYSTIM(t)		((t)*SYSTIM_HZ)

#endif	/* of #ifndef DHCP4_CLI_VAR_H */
