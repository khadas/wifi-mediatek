/******************************************************************************
 *
 * This file is provided under a dual license.  When you use or
 * distribute this software, you may choose to be licensed under
 * version 2 of the GNU General Public License ("GPLv2 License")
 * or BSD License.
 *
 * GPLv2 License
 *
 * Copyright(C) 2016 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 *
 * BSD LICENSE
 *
 * Copyright(C) 2016 MediaTek Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************/
/*
** Id: //Department/DaVinci/BRANCHES/MT6620_WIFI_DRIVER_V2_3/include/mgmt/ais_fsm.h#2
*/

/*! \file   ais_fsm.h
 *  \brief  Declaration of functions and finite state machine for AIS Module.
 *
 *  Declaration of functions and finite state machine for AIS Module.
*/


#ifndef _AIS_FSM_H
#define _AIS_FSM_H

/*******************************************************************************
*                         C O M P I L E R   F L A G S
********************************************************************************
*/

/*******************************************************************************
*                    E X T E R N A L   R E F E R E N C E S
********************************************************************************
*/

/*******************************************************************************
*                              C O N S T A N T S
********************************************************************************
*/
#define AIS_BG_SCAN_INTERVAL_MIN_SEC        2	/* 30 // exponential to 960 */
#define AIS_BG_SCAN_INTERVAL_MAX_SEC        2	/* 960 // 16min */
#if CFG_SUPPORT_ROAMING
#define AIS_DELAY_TIME_OF_DISCONNECT_SEC    0	/* 100 Milli-seconds - Immediate indication to reduce inter-SSID roam time */
#else
#define AIS_DELAY_TIME_OF_DISCONNECT_SEC    5	/* 10 */
#endif				/* CFG_SUPPORT_ROAMING */
#define AIS_IBSS_ALONE_TIMEOUT_SEC          20	/* seconds */

#define AIS_BEACON_TIMEOUT_COUNT_ADHOC      30
#define AIS_BEACON_TIMEOUT_COUNT_INFRA      10
#define AIS_BEACON_TIMEOUT_GUARD_TIME_SEC   1	/* Second */

#define AIS_BEACON_MAX_TIMEOUT_TU           100
#define AIS_BEACON_MIN_TIMEOUT_TU           5
#define AIS_BEACON_MAX_TIMEOUT_VALID        TRUE
#define AIS_BEACON_MIN_TIMEOUT_VALID        TRUE

#define AIS_BMC_MAX_TIMEOUT_TU              100
#define AIS_BMC_MIN_TIMEOUT_TU              5
#define AIS_BMC_MAX_TIMEOUT_VALID           TRUE
#define AIS_BMC_MIN_TIMEOUT_VALID           TRUE

#define AIS_JOIN_CH_GRANT_THRESHOLD         10
#if CFG_SUPPORT_CFG80211_AUTH
/* expand 4000 to 6000 to improve SAE connection success probability */
#define AIS_JOIN_CH_REQUEST_INTERVAL        6000
#else
#define AIS_JOIN_CH_REQUEST_INTERVAL        4000
#endif
#ifdef CFG_SUPPORT_ADJUST_JOIN_CH_REQ_INTERVAL
#define AIS_JOIN_CH_REQUEST_MAX_INTERVAL    4000
#endif

#define AIS_SCN_DONE_TIMEOUT_SEC            15 /* 15 for 2.4G + 5G */	/* 5 */

/*******************************************************************************
*                             D A T A   T Y P E S
********************************************************************************
*/
typedef enum _ENUM_AIS_STATE_T {
	AIS_STATE_IDLE = 0,
	AIS_STATE_SEARCH,
	AIS_STATE_SCAN,
	AIS_STATE_ONLINE_SCAN,
	AIS_STATE_LOOKING_FOR,
	AIS_STATE_WAIT_FOR_NEXT_SCAN,
	AIS_STATE_REQ_CHANNEL_JOIN,
	AIS_STATE_JOIN,
	AIS_STATE_JOIN_FAILURE,
	AIS_STATE_IBSS_ALONE,
	AIS_STATE_IBSS_MERGE,
	AIS_STATE_NORMAL_TR,
	AIS_STATE_DISCONNECTING,
	AIS_STATE_REQ_REMAIN_ON_CHANNEL,
	AIS_STATE_REMAIN_ON_CHANNEL,
	AIS_STATE_NUM
} ENUM_AIS_STATE_T;

typedef struct _MSG_AIS_ABORT_T {
	MSG_HDR_T rMsgHdr;	/* Must be the first member */
	UINT_8 ucReasonOfDisconnect;
	BOOLEAN fgDelayIndication;
} MSG_AIS_ABORT_T, *P_MSG_AIS_ABORT_T;

typedef struct _MSG_AIS_IBSS_PEER_FOUND_T {
	MSG_HDR_T rMsgHdr;	/* Must be the first member */
	UINT_8 ucBssIndex;
	BOOLEAN fgIsMergeIn;	/* TRUE: Merge In, FALSE: Merge Out */
	P_STA_RECORD_T prStaRec;
} MSG_AIS_IBSS_PEER_FOUND_T, *P_MSG_AIS_IBSS_PEER_FOUND_T;

typedef enum _ENUM_AIS_REQUEST_TYPE_T {
	AIS_REQUEST_SCAN,
	AIS_REQUEST_RECONNECT,
	AIS_REQUEST_ROAMING_SEARCH,
	AIS_REQUEST_ROAMING_CONNECT,
	AIS_REQUEST_REMAIN_ON_CHANNEL,
	AIS_REQUEST_NUM
} ENUM_AIS_REQUEST_TYPE_T;

typedef struct _AIS_REQ_HDR_T {
	LINK_ENTRY_T rLinkEntry;
	ENUM_AIS_REQUEST_TYPE_T eReqType;
} AIS_REQ_HDR_T, *P_AIS_REQ_HDR_T;

typedef struct _AIS_REQ_CHNL_INFO {
	ENUM_BAND_T eBand;
	ENUM_CHNL_EXT_T eSco;
	UINT_8 ucChannelNum;
	UINT_32 u4DurationMs;
	UINT_64 u8Cookie;
} AIS_REQ_CHNL_INFO, *P_AIS_REQ_CHNL_INFO;

typedef struct _AIS_MGMT_TX_REQ_INFO_T {
	BOOLEAN fgIsMgmtTxRequested;
	P_MSDU_INFO_T prMgmtTxMsdu;
	UINT_64 u8Cookie;
} AIS_MGMT_TX_REQ_INFO_T, *P_AIS_MGMT_TX_REQ_INFO_T;

typedef struct _AIS_FSM_INFO_T {
	ENUM_AIS_STATE_T ePreviousState;
	ENUM_AIS_STATE_T eCurrentState;

	BOOLEAN fgTryScan;

	BOOLEAN fgIsInfraChannelFinished;
	BOOLEAN fgIsChannelRequested;
	BOOLEAN fgIsChannelGranted;

#if CFG_SUPPORT_ROAMING
	BOOLEAN fgIsRoamingScanPending;
#endif				/* CFG_SUPPORT_ROAMING */

	UINT_8 ucAvailableAuthTypes;	/* Used for AUTH_MODE_AUTO_SWITCH */

	P_BSS_DESC_T prTargetBssDesc;	/* For destination */

	P_STA_RECORD_T prTargetStaRec;	/* For JOIN Abort */

	UINT_32 u4SleepInterval;

	TIMER_T rBGScanTimer;

	TIMER_T rIbssAloneTimer;

	TIMER_T rIndicationOfDisconnectTimer;

	TIMER_T rJoinTimeoutTimer;

	TIMER_T rChannelTimeoutTimer;

	TIMER_T rScanDoneTimer;

	TIMER_T rDeauthDoneTimer;

	UINT_8 ucSeqNumOfReqMsg;
	UINT_8 ucSeqNumOfChReq;
	UINT_8 ucSeqNumOfScanReq;

	UINT_32 u4ChGrantedInterval;

	UINT_8 ucConnTrialCount;

	UINT_8 ucScanSSIDNum;
	PARAM_SSID_T arScanSSID[SCN_SSID_MAX_NUM];

	UINT_32 u4ScanIELength;
	UINT_8 aucScanIEBuf[MAX_IE_LENGTH];

#if CFG_SCAN_CHANNEL_SPECIFIED
	UINT_8 ucScanChannelListNum;
	RF_CHANNEL_INFO_T arScanChnlInfoList[MAXIMUM_OPERATION_CHANNEL_LIST];
#endif
	UINT_8 fgIsScanOidAborted;

	/* Pending Request List */
	LINK_T rPendingReqList;

	/* Join Request Timestamp */
	OS_SYSTIME rJoinReqTime;

	/* for cfg80211 REMAIN_ON_CHANNEL support */
	AIS_REQ_CHNL_INFO rChReqInfo;

	/* Mgmt tx related. */
	AIS_MGMT_TX_REQ_INFO_T rMgmtTxInfo;

	/* Packet filter for AIS module. */
	UINT_32 u4AisPacketFilter;

	/* for roaming target */
	PARAM_SSID_T rRoamingSSID;
} AIS_FSM_INFO_T, *P_AIS_FSM_INFO_T;

/*******************************************************************************
*                            P U B L I C   D A T A
********************************************************************************
*/

/*******************************************************************************
*                           P R I V A T E   D A T A
********************************************************************************
*/

/*******************************************************************************
*                                 M A C R O S
********************************************************************************
*/
#define aisChangeMediaState(_prAdapter, _eNewMediaState) \
	(_prAdapter->prAisBssInfo->eConnectionState = (_eNewMediaState))

/*******************************************************************************
*                  F U N C T I O N   D E C L A R A T I O N S
********************************************************************************
*/
VOID aisInitializeConnectionSettings(IN P_ADAPTER_T prAdapter, IN P_REG_INFO_T prRegInfo);

VOID aisFsmInit(IN P_ADAPTER_T prAdapter);

VOID aisFsmUninit(IN P_ADAPTER_T prAdapter);

VOID aisFsmStateInit_JOIN(IN P_ADAPTER_T prAdapter, P_BSS_DESC_T prBssDesc);

BOOLEAN aisFsmStateInit_RetryJOIN(IN P_ADAPTER_T prAdapter, IN P_STA_RECORD_T prStaRec);

VOID aisFsmStateInit_IBSS_ALONE(IN P_ADAPTER_T prAdapter);

VOID aisFsmStateInit_IBSS_MERGE(IN P_ADAPTER_T prAdapter, P_BSS_DESC_T prBssDesc);

VOID aisFsmStateAbort(IN P_ADAPTER_T prAdapter, UINT_8 ucReasonOfDisconnect, BOOLEAN fgDelayIndication);

VOID aisFsmStateAbort_JOIN(IN P_ADAPTER_T prAdapter);

VOID aisFsmStateAbort_SCAN(IN P_ADAPTER_T prAdapter);

VOID aisFsmStateAbort_NORMAL_TR(IN P_ADAPTER_T prAdapter);

VOID aisFsmStateAbort_IBSS(IN P_ADAPTER_T prAdapter);

VOID aisFsmSteps(IN P_ADAPTER_T prAdapter, ENUM_AIS_STATE_T eNextState);

/*----------------------------------------------------------------------------*/
/* Mailbox Message Handling                                                   */
/*----------------------------------------------------------------------------*/
VOID aisFsmRunEventScanDone(IN P_ADAPTER_T prAdapter, IN P_MSG_HDR_T prMsgHdr);

VOID aisFsmRunEventAbort(IN P_ADAPTER_T prAdapter, IN P_MSG_HDR_T prMsgHdr);

VOID aisFsmRunEventJoinComplete(IN P_ADAPTER_T prAdapter, IN P_MSG_HDR_T prMsgHdr);

enum _ENUM_AIS_STATE_T aisFsmJoinCompleteAction(IN struct _ADAPTER_T *prAdapter, IN struct _MSG_HDR_T *prMsgHdr);

VOID aisFsmRunEventFoundIBSSPeer(IN P_ADAPTER_T prAdapter, IN P_MSG_HDR_T prMsgHdr);

VOID aisFsmRunEventRemainOnChannel(IN P_ADAPTER_T prAdapter, IN P_MSG_HDR_T prMsgHdr);

VOID aisFsmRunEventCancelRemainOnChannel(IN P_ADAPTER_T prAdapter, IN P_MSG_HDR_T prMsgHdr);

/*----------------------------------------------------------------------------*/
/* Handling for Ad-Hoc Network                                                */
/*----------------------------------------------------------------------------*/
VOID aisFsmCreateIBSS(IN P_ADAPTER_T prAdapter);

VOID aisFsmMergeIBSS(IN P_ADAPTER_T prAdapter, IN P_STA_RECORD_T prStaRec);

/*----------------------------------------------------------------------------*/
/* Handling of Incoming Mailbox Message from CNM                              */
/*----------------------------------------------------------------------------*/
VOID aisFsmRunEventChGrant(IN P_ADAPTER_T prAdapter, IN P_MSG_HDR_T prMsgHdr);

/*----------------------------------------------------------------------------*/
/* Generating Outgoing Mailbox Message to CNM                                 */
/*----------------------------------------------------------------------------*/
VOID aisFsmReleaseCh(IN P_ADAPTER_T prAdapter);

/*----------------------------------------------------------------------------*/
/* Event Indication                                                           */
/*----------------------------------------------------------------------------*/
VOID
aisIndicationOfMediaStateToHost(IN P_ADAPTER_T prAdapter,
				ENUM_PARAM_MEDIA_STATE_T eConnectionState, BOOLEAN fgDelayIndication);

VOID aisPostponedEventOfDisconnTimeout(IN P_ADAPTER_T prAdapter, ULONG ulParamPtr);

VOID aisUpdateBssInfoForJOIN(IN P_ADAPTER_T prAdapter, P_STA_RECORD_T prStaRec, P_SW_RFB_T prAssocRspSwRfb);

VOID aisUpdateBssInfoForCreateIBSS(IN P_ADAPTER_T prAdapter);

VOID aisUpdateBssInfoForMergeIBSS(IN P_ADAPTER_T prAdapter, IN P_STA_RECORD_T prStaRec);

BOOLEAN aisValidateProbeReq(IN P_ADAPTER_T prAdapter, IN P_SW_RFB_T prSwRfb, OUT PUINT_32 pu4ControlFlags);

WLAN_STATUS
aisFsmRunEventMgmtFrameTxDone(IN P_ADAPTER_T prAdapter,
			      IN P_MSDU_INFO_T prMsduInfo, IN ENUM_TX_RESULT_CODE_T rTxDoneStatus);

/*----------------------------------------------------------------------------*/
/* Disconnection Handling                                                     */
/*----------------------------------------------------------------------------*/
VOID aisFsmDisconnect(IN P_ADAPTER_T prAdapter, IN BOOLEAN fgDelayIndication);

/*----------------------------------------------------------------------------*/
/* Event Handling                                                             */
/*----------------------------------------------------------------------------*/
VOID aisBssBeaconTimeout(IN P_ADAPTER_T prAdapter, IN UINT_8 ucReasonCode);

VOID aisBssLinkDown(IN P_ADAPTER_T prAdapter);

#if CFG_SUPPORT_DBDC_TC6
BOOLEAN aisBssChangeNSS(IN P_ADAPTER_T prAdapter, IN UINT_8 fgDbdcEn);
#endif

WLAN_STATUS
aisDeauthXmitComplete(IN P_ADAPTER_T prAdapter, IN P_MSDU_INFO_T prMsduInfo, IN ENUM_TX_RESULT_CODE_T rTxDoneStatus);

#if CFG_SUPPORT_ROAMING
VOID aisFsmRunEventRoamingDiscovery(IN P_ADAPTER_T prAdapter, UINT_32 u4ReqScan);

ENUM_AIS_STATE_T aisFsmRoamingScanResultsUpdate(IN P_ADAPTER_T prAdapter);

VOID aisFsmRoamingDisconnectPrevAP(IN P_ADAPTER_T prAdapter, IN P_STA_RECORD_T prTargetStaRec);
#endif /*CFG_SUPPORT_ROAMING */

#if CFG_SUPPORT_ROAMING || CFG_SUPPORT_SAME_BSS_REASSOC
VOID aisUpdateBssInfoForRoamingAP(IN P_ADAPTER_T prAdapter, IN P_STA_RECORD_T prStaRec, IN P_SW_RFB_T prAssocRspSwRfb);
#endif /*CFG_SUPPORT_ROAMING || CFG_SUPPORT_SAME_BSS_REASSOC*/

/*----------------------------------------------------------------------------*/
/* Timeout Handling                                                           */
/*----------------------------------------------------------------------------*/
VOID aisFsmRunEventBGSleepTimeOut(IN P_ADAPTER_T prAdapter, ULONG ulParamPtr);

VOID aisFsmRunEventIbssAloneTimeOut(IN P_ADAPTER_T prAdapter, ULONG ulParamPtr);

VOID aisFsmRunEventJoinTimeout(IN P_ADAPTER_T prAdapter, ULONG ulParamPtr);

VOID aisFsmRunEventChannelTimeout(IN P_ADAPTER_T prAdapter, ULONG ulParamPtr);

VOID aisFsmRunEventDeauthTimeout(IN P_ADAPTER_T prAdapter, ULONG ulParamPtr);

#if CFG_SUPPORT_LAST_SEC_MCS_INFO
VOID aisRxMcsCollectionTimeout(IN P_ADAPTER_T prAdapter, ULONG ulParamPtr);
#endif

/*----------------------------------------------------------------------------*/
/* OID/IOCTL Handling                                                         */
/*----------------------------------------------------------------------------*/
VOID aisFsmScanRequest(IN P_ADAPTER_T prAdapter, IN P_PARAM_SSID_T prSsid, IN PUINT_8 pucIe, IN UINT_32 u4IeLength);

VOID
aisFsmScanRequestAdv(IN P_ADAPTER_T prAdapter,
	IN UINT_8 ucSsidNum, IN P_PARAM_SSID_T prSsid,
	IN UINT_8 ucChannelListNum, IN P_RF_CHANNEL_INFO_T prChnlInfoList,
	IN PUINT_8 pucIe, IN UINT_32 u4IeLength);

/*----------------------------------------------------------------------------*/
/* Internal State Checking                                                    */
/*----------------------------------------------------------------------------*/
BOOLEAN aisFsmIsRequestPending(IN P_ADAPTER_T prAdapter, IN ENUM_AIS_REQUEST_TYPE_T eReqType, IN BOOLEAN bRemove);

P_AIS_REQ_HDR_T aisFsmGetNextRequest(IN P_ADAPTER_T prAdapter);

BOOLEAN aisFsmInsertRequest(IN P_ADAPTER_T prAdapter, IN ENUM_AIS_REQUEST_TYPE_T eReqType);

VOID aisFsmFlushRequest(IN P_ADAPTER_T prAdapter);

WLAN_STATUS
aisFuncTxMgmtFrame(IN P_ADAPTER_T prAdapter,
		   IN P_AIS_MGMT_TX_REQ_INFO_T prMgmtTxReqInfo, IN P_MSDU_INFO_T prMgmtTxMsdu, IN UINT_64 u8Cookie);

VOID aisFsmRunEventMgmtFrameTx(IN P_ADAPTER_T prAdapter, IN P_MSG_HDR_T prMsgHdr);

VOID aisFuncValidateRxActionFrame(IN P_ADAPTER_T prAdapter, IN P_SW_RFB_T prSwRfb);

enum _ENUM_AIS_STATE_T aisFsmStateSearchAction(IN struct _ADAPTER_T *prAdapter, UINT_8 ucPhase);
#if defined(CFG_TEST_MGMT_FSM) && (CFG_TEST_MGMT_FSM != 0)
VOID aisTest(VOID);
#endif /* CFG_TEST_MGMT_FSM */
/*******************************************************************************
*                              F U N C T I O N S
********************************************************************************
*/

#endif /* _AIS_FSM_H */
