/*
 *  TINET (TCP/IP Protocol Stack)
 * 
 *  Copyright (C) 2001-2017 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *
 *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation 
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次の条件を満たすこと．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 * 
 *  @(#) $Id: tcp_discard_cli.h 1.7 2017/6/1 8:50:23 abe $
 */

#ifndef _TCP_DISCARD_CLI_H_
#define _TCP_DISCARD_CLI_H_

/* スタックサイズ */

#define TCP_DISCARD_CLI_STACK_SIZE	1024		/* TCP DISCARD クライアントタスクのスタックサイズ */

/* 優先度 */

#define TCP_DISCARD_CLI_MAIN_PRIORITY	5	/* TCP DISCARD クライアントタスクの優先度 */

/*
 *  TCP 送受信ウインドバッファサイズ
 */

#if defined(USE_TCP_MSS_SEG) || defined(USE_IPV6_MMTU)

#if defined(SUPPORT_INET6)

#define TCP_DISCARD_CLI_SWBUF_SIZE	(1024)

#elif defined(SUPPORT_INET4)

#define TCP_DISCARD_CLI_SWBUF_SIZE	(512)

#endif	/* of #if defined(SUPPORT_INET6) */

#else	/* of #if defined(USE_TCP_MSS_SEG) || defined(USE_IPV6_MMTU) */

#define TCP_DISCARD_CLI_SWBUF_SIZE	(2048)

#endif	/* of #if defined(USE_TCP_MSS_SEG) || defined(USE_IPV6_MMTU) */

/*
 *  変数
 */

extern bool_t	tcp_discard_cli_valid;

/* TCP 送受信バッファ */

extern uint8_t tcp_discard_cli_swbuf[];
extern uint8_t tcp_discard_cli_rwbuf[];

/* タスク */

extern void tcp_discard_cli_task(intptr_t exinf);

/* 関数 */

extern ER callback_nblk_tcp_discard_cli (ID cepid, FN fncd, void *p_parblk);

#endif	/* of #ifndef _TCP_DISCARD_CLI_H_ */
