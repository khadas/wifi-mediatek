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
** Id: //Department/DaVinci/BRANCHES/MT6620_WIFI_DRIVER_V2_3/include/nic/wlan_def.h#1
*/

/*! \file   "wlan_def.h"
 *  \brief  This file includes the basic definition of WLAN
 *
 */


#ifndef _WLAN_DEF_H
#define _WLAN_DEF_H

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
/* disconnect reason */
#define DISCONNECT_REASON_CODE_RESERVED         0
#define DISCONNECT_REASON_CODE_RADIO_LOST       1
#define DISCONNECT_REASON_CODE_DEAUTHENTICATED  2
#define DISCONNECT_REASON_CODE_DISASSOCIATED    3
#define DISCONNECT_REASON_CODE_NEW_CONNECTION   4
#define DISCONNECT_REASON_CODE_REASSOCIATION    5

/* Beacon Timeout Event Reason */
#define BEACON_TIMEOUT_EVENT_DUE_2_RX_DEAUTH_IN_STR 	11

/* The rate definitions */
#define TX_MODE_CCK             0x00
#define TX_MODE_OFDM            0x40
#define TX_MODE_HT_MM           0x80
#define TX_MODE_HT_GF           0xC0
#define TX_MODE_VHT             0x100

#define RATE_CCK_SHORT_PREAMBLE 0x4

#define PHY_RATE_1M             0x0
#define PHY_RATE_2M             0x1
#define PHY_RATE_5_5M           0x2
#define PHY_RATE_11M            0x3
#define PHY_RATE_6M             0xB
#define PHY_RATE_9M             0xF
#define PHY_RATE_12M            0xA
#define PHY_RATE_18M            0xE
#define PHY_RATE_24M            0x9
#define PHY_RATE_36M            0xD
#define PHY_RATE_48M            0x8
#define PHY_RATE_54M            0xC

#define PHY_RATE_MCS0           0x0
#define PHY_RATE_MCS1           0x1
#define PHY_RATE_MCS2           0x2
#define PHY_RATE_MCS3           0x3
#define PHY_RATE_MCS4           0x4
#define PHY_RATE_MCS5           0x5
#define PHY_RATE_MCS6           0x6
#define PHY_RATE_MCS7           0x7
#define PHY_RATE_MCS8           0x8
#define PHY_RATE_MCS9           0x9
#define PHY_RATE_MCS32          0x20

#define RATE_CCK_1M_LONG        (TX_MODE_CCK | PHY_RATE_1M)
#define RATE_CCK_2M_LONG        (TX_MODE_CCK | PHY_RATE_2M)
#define RATE_CCK_5_5M_LONG      (TX_MODE_CCK | PHY_RATE_5_5M)
#define RATE_CCK_11M_LONG       (TX_MODE_CCK | PHY_RATE_11M)
#define RATE_CCK_2M_SHORT       (TX_MODE_CCK | PHY_RATE_2M | RATE_CCK_SHORT_PREAMBLE)
#define RATE_CCK_5_5M_SHORT     (TX_MODE_CCK | PHY_RATE_5_5M | RATE_CCK_SHORT_PREAMBLE)
#define RATE_CCK_11M_SHORT      (TX_MODE_CCK | PHY_RATE_11M | RATE_CCK_SHORT_PREAMBLE)
#define RATE_OFDM_6M            (TX_MODE_OFDM | PHY_RATE_6M)
#define RATE_OFDM_9M            (TX_MODE_OFDM | PHY_RATE_9M)
#define RATE_OFDM_12M           (TX_MODE_OFDM | PHY_RATE_12M)
#define RATE_OFDM_18M           (TX_MODE_OFDM | PHY_RATE_18M)
#define RATE_OFDM_24M           (TX_MODE_OFDM | PHY_RATE_24M)
#define RATE_OFDM_36M           (TX_MODE_OFDM | PHY_RATE_36M)
#define RATE_OFDM_48M           (TX_MODE_OFDM | PHY_RATE_48M)
#define RATE_OFDM_54M           (TX_MODE_OFDM | PHY_RATE_54M)

#define RATE_MM_MCS_0           (TX_MODE_HT_MM | PHY_RATE_MCS0)
#define RATE_MM_MCS_1           (TX_MODE_HT_MM | PHY_RATE_MCS1)
#define RATE_MM_MCS_2           (TX_MODE_HT_MM | PHY_RATE_MCS2)
#define RATE_MM_MCS_3           (TX_MODE_HT_MM | PHY_RATE_MCS3)
#define RATE_MM_MCS_4           (TX_MODE_HT_MM | PHY_RATE_MCS4)
#define RATE_MM_MCS_5           (TX_MODE_HT_MM | PHY_RATE_MCS5)
#define RATE_MM_MCS_6           (TX_MODE_HT_MM | PHY_RATE_MCS6)
#define RATE_MM_MCS_7           (TX_MODE_HT_MM | PHY_RATE_MCS7)
#define RATE_MM_MCS_32          (TX_MODE_HT_MM | PHY_RATE_MCS32)

#define RATE_GF_MCS_0           (TX_MODE_HT_GF | PHY_RATE_MCS0)
#define RATE_GF_MCS_1           (TX_MODE_HT_GF | PHY_RATE_MCS1)
#define RATE_GF_MCS_2           (TX_MODE_HT_GF | PHY_RATE_MCS2)
#define RATE_GF_MCS_3           (TX_MODE_HT_GF | PHY_RATE_MCS3)
#define RATE_GF_MCS_4           (TX_MODE_HT_GF | PHY_RATE_MCS4)
#define RATE_GF_MCS_5           (TX_MODE_HT_GF | PHY_RATE_MCS5)
#define RATE_GF_MCS_6           (TX_MODE_HT_GF | PHY_RATE_MCS6)
#define RATE_GF_MCS_7           (TX_MODE_HT_GF | PHY_RATE_MCS7)
#define RATE_GF_MCS_32          (TX_MODE_HT_GF | PHY_RATE_MCS32)

#define RATE_VHT_MCS_0          (TX_MODE_VHT | PHY_RATE_MCS0)
#define RATE_VHT_MCS_1          (TX_MODE_VHT | PHY_RATE_MCS1)
#define RATE_VHT_MCS_2          (TX_MODE_VHT | PHY_RATE_MCS2)
#define RATE_VHT_MCS_3          (TX_MODE_VHT | PHY_RATE_MCS3)
#define RATE_VHT_MCS_4          (TX_MODE_VHT | PHY_RATE_MCS4)
#define RATE_VHT_MCS_5          (TX_MODE_VHT | PHY_RATE_MCS5)
#define RATE_VHT_MCS_6          (TX_MODE_VHT | PHY_RATE_MCS6)
#define RATE_VHT_MCS_7          (TX_MODE_VHT | PHY_RATE_MCS7)
#define RATE_VHT_MCS_8          (TX_MODE_VHT | PHY_RATE_MCS8)
#define RATE_VHT_MCS_9          (TX_MODE_VHT | PHY_RATE_MCS9)

#define RATE_NSTS_MASK								BITS(9, 10)
#define RATE_NSTS_OFFSET							9
#define RATE_TX_MODE_MASK                           BITS(6, 8)
#define RATE_TX_MODE_OFFSET                         6
#define RATE_CODE_GET_TX_MODE(_ucRateCode)          ((_ucRateCode & RATE_TX_MODE_MASK) >> RATE_TX_MODE_OFFSET)
#define RATE_PHY_RATE_MASK                          BITS(0, 5)
#define RATE_PHY_RATE_OFFSET                        0
#define RATE_CODE_GET_PHY_RATE(_ucRateCode)         ((_ucRateCode & RATE_PHY_RATE_MASK) >> RATE_PHY_RATE_OFFSET)
#define RATE_PHY_RATE_SHORT_PREAMBLE                BIT(2)
#define RATE_CODE_IS_SHORT_PREAMBLE(_ucRateCode)    ((_ucRateCode & RATE_PHY_RATE_SHORT_PREAMBLE) ? TRUE : FALSE)

#define CHNL_LIST_SZ_2G         14
#define CHNL_LIST_SZ_5G         14

/*! CNM(STA_RECORD_T) related definition */
#define CFG_STA_REC_NUM         27

/* PHY TYPE bit definitions */
#define PHY_TYPE_BIT_HR_DSSS    BIT(PHY_TYPE_HR_DSSS_INDEX)	/* HR/DSSS PHY (clause 18) */
#define PHY_TYPE_BIT_ERP        BIT(PHY_TYPE_ERP_INDEX)	/* ERP PHY (clause 19) */
#define PHY_TYPE_BIT_OFDM       BIT(PHY_TYPE_OFDM_INDEX)	/* OFDM 5 GHz PHY (clause 17) */
#define PHY_TYPE_BIT_HT         BIT(PHY_TYPE_HT_INDEX)	/* HT PHY (clause 20) */
#define PHY_TYPE_BIT_VHT        BIT(PHY_TYPE_VHT_INDEX)	/* HT PHY (clause 22) */

/* PHY TYPE set definitions */
#define PHY_TYPE_SET_802_11ABGN (PHY_TYPE_BIT_OFDM | \
				 PHY_TYPE_BIT_HR_DSSS | \
				 PHY_TYPE_BIT_ERP | \
				 PHY_TYPE_BIT_HT)

#define PHY_TYPE_SET_802_11BGN  (PHY_TYPE_BIT_HR_DSSS | \
				 PHY_TYPE_BIT_ERP | \
				 PHY_TYPE_BIT_HT)

#define PHY_TYPE_SET_802_11GN   (PHY_TYPE_BIT_ERP | \
				 PHY_TYPE_BIT_HT)

#define PHY_TYPE_SET_802_11AN   (PHY_TYPE_BIT_OFDM | \
				 PHY_TYPE_BIT_HT)

#define PHY_TYPE_SET_802_11ABG  (PHY_TYPE_BIT_OFDM | \
				 PHY_TYPE_BIT_HR_DSSS | \
				 PHY_TYPE_BIT_ERP)

#define PHY_TYPE_SET_802_11BG   (PHY_TYPE_BIT_HR_DSSS | \
				 PHY_TYPE_BIT_ERP)

#define PHY_TYPE_SET_802_11A    (PHY_TYPE_BIT_OFDM)

#define PHY_TYPE_SET_802_11G    (PHY_TYPE_BIT_ERP)

#define PHY_TYPE_SET_802_11B    (PHY_TYPE_BIT_HR_DSSS)

#define PHY_TYPE_SET_802_11N    (PHY_TYPE_BIT_HT)

#define PHY_TYPE_SET_802_11AC   (PHY_TYPE_BIT_VHT)

#define PHY_TYPE_SET_802_11ANAC (PHY_TYPE_BIT_OFDM | \
				 PHY_TYPE_BIT_HT | \
				 PHY_TYPE_BIT_VHT)

#define PHY_TYPE_SET_802_11ABGNAC (PHY_TYPE_BIT_OFDM | \
				   PHY_TYPE_BIT_HR_DSSS | \
				   PHY_TYPE_BIT_ERP | \
				   PHY_TYPE_BIT_HT | \
				   PHY_TYPE_BIT_VHT)

/* Rate set bit definitions */
#define RATE_SET_BIT_1M         BIT(RATE_1M_SW_INDEX)	/* Bit 0: 1M */
#define RATE_SET_BIT_2M         BIT(RATE_2M_SW_INDEX)	/* Bit 1: 2M */
#define RATE_SET_BIT_5_5M       BIT(RATE_5_5M_SW_INDEX)	/* Bit 2: 5.5M */
#define RATE_SET_BIT_11M        BIT(RATE_11M_SW_INDEX)	/* Bit 3: 11M */
#define RATE_SET_BIT_22M        BIT(RATE_22M_SW_INDEX)	/* Bit 4: 22M */
#define RATE_SET_BIT_33M        BIT(RATE_33M_SW_INDEX)	/* Bit 5: 33M */
#define RATE_SET_BIT_6M         BIT(RATE_6M_SW_INDEX)	/* Bit 6: 6M */
#define RATE_SET_BIT_9M         BIT(RATE_9M_SW_INDEX)	/* Bit 7: 9M */
#define RATE_SET_BIT_12M        BIT(RATE_12M_SW_INDEX)	/* Bit 8: 12M */
#define RATE_SET_BIT_18M        BIT(RATE_18M_SW_INDEX)	/* Bit 9: 18M */
#define RATE_SET_BIT_24M        BIT(RATE_24M_SW_INDEX)	/* Bit 10: 24M */
#define RATE_SET_BIT_36M        BIT(RATE_36M_SW_INDEX)	/* Bit 11: 36M */
#define RATE_SET_BIT_48M        BIT(RATE_48M_SW_INDEX)	/* Bit 12: 48M */
#define RATE_SET_BIT_54M        BIT(RATE_54M_SW_INDEX)	/* Bit 13: 54M */
#define RATE_SET_BIT_HT_PHY     BIT(RATE_HT_PHY_SW_INDEX)	/* Bit 14: BSS Selector */

/* Rate set definitions */
#define RATE_SET_HR_DSSS            (RATE_SET_BIT_1M | \
				     RATE_SET_BIT_2M | \
				     RATE_SET_BIT_5_5M | \
				     RATE_SET_BIT_11M)

#define RATE_SET_ERP                (RATE_SET_BIT_1M | \
				     RATE_SET_BIT_2M | \
				     RATE_SET_BIT_5_5M | \
				     RATE_SET_BIT_11M | \
				     RATE_SET_BIT_6M | \
				     RATE_SET_BIT_9M | \
				     RATE_SET_BIT_12M | \
				     RATE_SET_BIT_18M | \
				     RATE_SET_BIT_24M | \
				     RATE_SET_BIT_36M | \
				     RATE_SET_BIT_48M | \
				     RATE_SET_BIT_54M)

#define RATE_SET_ERP_P2P            (RATE_SET_BIT_6M | \
				     RATE_SET_BIT_9M | \
				     RATE_SET_BIT_12M | \
				     RATE_SET_BIT_18M | \
				     RATE_SET_BIT_24M | \
				     RATE_SET_BIT_36M | \
				     RATE_SET_BIT_48M | \
				     RATE_SET_BIT_54M)

#define RATE_SET_OFDM               (RATE_SET_BIT_6M | \
				     RATE_SET_BIT_9M | \
				     RATE_SET_BIT_12M | \
				     RATE_SET_BIT_18M | \
				     RATE_SET_BIT_24M | \
				     RATE_SET_BIT_36M | \
				     RATE_SET_BIT_48M | \
				     RATE_SET_BIT_54M)

#define RATE_SET_HT                 (RATE_SET_ERP)
/* #define RATE_SET_HT                 (RATE_SET_ERP | RATE_SET_BIT_HT_PHY) *//* NOTE(Kevin): TBD */

#define RATE_SET_ALL_ABG             RATE_SET_ERP

#define BASIC_RATE_SET_HR_DSSS      (RATE_SET_BIT_1M | \
				     RATE_SET_BIT_2M)

#define BASIC_RATE_SET_HR_DSSS_ERP  (RATE_SET_BIT_1M | \
				     RATE_SET_BIT_2M | \
				     RATE_SET_BIT_5_5M | \
				     RATE_SET_BIT_11M)

#define BASIC_RATE_SET_ERP          (RATE_SET_BIT_1M | \
				     RATE_SET_BIT_2M | \
				     RATE_SET_BIT_5_5M | \
				     RATE_SET_BIT_11M | \
				     RATE_SET_BIT_6M | \
				     RATE_SET_BIT_12M | \
				     RATE_SET_BIT_24M)

#define BASIC_RATE_SET_OFDM         (RATE_SET_BIT_6M | \
				     RATE_SET_BIT_12M | \
				     RATE_SET_BIT_24M)

#define BASIC_RATE_SET_ERP_P2P      (RATE_SET_BIT_6M | \
				     RATE_SET_BIT_12M | \
				     RATE_SET_BIT_24M)

#define INITIAL_RATE_SET_RCPI_100    RATE_SET_ALL_ABG

#define INITIAL_RATE_SET_RCPI_80    (RATE_SET_BIT_1M | \
				     RATE_SET_BIT_2M | \
				     RATE_SET_BIT_5_5M | \
				     RATE_SET_BIT_11M | \
				     RATE_SET_BIT_6M | \
				     RATE_SET_BIT_9M | \
				     RATE_SET_BIT_12M | \
				     RATE_SET_BIT_24M)

#define INITIAL_RATE_SET_RCPI_60    (RATE_SET_BIT_1M | \
				     RATE_SET_BIT_2M | \
				     RATE_SET_BIT_5_5M | \
				     RATE_SET_BIT_11M | \
				     RATE_SET_BIT_6M)

#define INITIAL_RATE_SET(_rcpi)     (INITIAL_RATE_SET_ ## _rcpi)

#define RCPI_100                    100	/* -60 dBm */
#define RCPI_80                     80	/* -70 dBm */
#define RCPI_60                     60	/* -80 dBm */

/* The number of RCPI records used to calculate their average value */
#define MAX_NUM_RCPI_RECORDS        10

/* The number of RCPI records used to calculate their average value */
#define NO_RCPI_RECORDS             -128
#define MAX_RCPI_DBM                0
#define MIN_RCPI_DBM                -100

#define MAX_ASSOC_ID                (CFG_STA_REC_NUM)	/* Available AID: 1 ~ 20(STA_REC_NUM) */

#define MAX_DEAUTH_INFO_COUNT       4	/* NOTE(Kevin): Used in auth.c */
#define MIN_DEAUTH_INTERVAL_MSEC    500	/* The minimum interval if continuously send Deauth Frame */

/* Authentication Type */
#define AUTH_TYPE_OPEN_SYSTEM                       BIT(AUTH_ALGORITHM_NUM_OPEN_SYSTEM)
#define AUTH_TYPE_SHARED_KEY                        BIT(AUTH_ALGORITHM_NUM_SHARED_KEY)
#define AUTH_TYPE_FAST_BSS_TRANSITION               BIT(AUTH_ALGORITHM_NUM_FAST_BSS_TRANSITION)
#if CFG_SUPPORT_CFG80211_AUTH
#define AUTH_TYPE_SAE                               BIT(AUTH_ALGORITHM_NUM_SAE)
#endif

/* Authentication Retry Limit */
#define TX_AUTH_ASSOCI_RETRY_LIMIT                  2
#define TX_AUTH_ASSOCI_RETRY_LIMIT_FOR_ROAMING      1

/* WMM-2.2.1 WMM Information Element */
#define ELEM_MAX_LEN_WMM_INFO       7

/* PF TCP/UDP max port number */
#define MAX_TCP_UDP_PORT            20

/*******************************************************************************
 *                             D A T A   T Y P E S
 ********************************************************************************
 */
typedef UINT_16 PHY_TYPE, *P_PHY_TYPE;
typedef UINT_8 RCPI, *P_RCPI;
typedef UINT_8 ALC_VAL, *P_ALC_VAL;

typedef enum _ENUM_HW_BSSID_T {
	BSSID_0 = 0,
	BSSID_1,
	BSSID_2,
	BSSID_3,
	BSSID_NUM
} ENUM_HW_BSSID_T;

typedef enum _ENUM_HW_MAC_ADDR_T {
	MAC_ADDR_0 = 0,
	MAC_ADDR_1,
	MAC_ADDR_NUM
} ENUM_HW_MAC_ADDR_T;

typedef enum _ENUM_HW_OP_MODE_T {
	HW_OP_MODE_STA = 0,
	HW_OP_MODE_AP,
	HW_OP_MODE_ADHOC,
	HW_OP_MODE_NUM
} ENUM_HW_OP_MODE_T;

typedef enum _ENUM_TSF_T {
	ENUM_LOCAL_TSF_0,
	ENUM_LOCAL_TSF_1,
	ENUM_LOCAL_TSF_NUM
} ENUM_LOCAL_TSF_T, *P_ENUM_LOCAL_TSF_T;

typedef enum _HAL_TS_HW_UPDATE_MODE {
	HAL_TSF_HW_UPDATE_BY_TICK_AND_RECEIVED_FRAME,
	HAL_TSF_HW_UPDATE_BY_TICK_ONLY,
	HAL_TSF_HW_UPDATE_BY_RECEIVED_FRAME_ONLY,
	HAL_TSF_HW_UPDATE_BY_TICK_AND_RECEIVED_FRAME_AD_HOC
} HAL_TSF_HW_UPDATE_MODE;

typedef enum _ENUM_AC_T {
	AC0 = 0,
	AC1,
	AC2,
	AC3,
	AC_NUM
} ENUM_AC_T, *P_ENUM_AC_T;

typedef enum _ENUM_NETWORK_TYPE_T {
	NETWORK_TYPE_AIS,
	NETWORK_TYPE_P2P,
	NETWORK_TYPE_BOW,
	NETWORK_TYPE_MBSS,
	NETWORK_TYPE_NUM
} ENUM_NETWORK_TYPE_T;

/* The Type of STA Type. */
typedef enum _ENUM_STA_TYPE_INDEX_T {
	STA_TYPE_LEGACY_INDEX = 0,
	STA_TYPE_P2P_INDEX,
	STA_TYPE_BOW_INDEX,
	STA_TYPE_INDEX_NUM
} ENUM_STA_TYPE_INDEX_T;

#define STA_ROLE_BASE_INDEX     4

typedef enum _ENUM_STA_ROLE_INDEX_T {
	STA_ROLE_ADHOC_INDEX = STA_ROLE_BASE_INDEX,	/* 4 */
	STA_ROLE_CLIENT_INDEX,
	STA_ROLE_AP_INDEX,
	STA_ROLE_DLS_INDEX,
	STA_ROLE_MAX_INDEX
} ENUM_STA_ROLE_INDEX_T;

#define STA_ROLE_INDEX_NUM      (STA_ROLE_MAX_INDEX - STA_ROLE_BASE_INDEX)

/* The Power State of a specific Network */
typedef enum _ENUM_PWR_STATE_T {
	PWR_STATE_IDLE = 0,
	PWR_STATE_ACTIVE,
	PWR_STATE_PS,
	PWR_STATE_NUM
} ENUM_PWR_STATE_T;

typedef enum _ENUM_PHY_TYPE_INDEX_T {
	/* PHY_TYPE_DSSS_INDEX, *//* DSSS PHY (clause 15) -- Not used anymore */
	PHY_TYPE_HR_DSSS_INDEX = 0,	/* HR/DSSS PHY (clause 18) */
	PHY_TYPE_ERP_INDEX,	/* ERP PHY (clause 19) */
	PHY_TYPE_ERP_P2P_INDEX,	/* ERP PHY (clause 19) w/o HR/DSSS */
	PHY_TYPE_OFDM_INDEX,	/* OFDM 5 GHz PHY (clause 17) */
	PHY_TYPE_HT_INDEX,	/* HT PHY (clause 20) */
	PHY_TYPE_VHT_INDEX,	/* HT PHY (clause 22) */
	PHY_TYPE_INDEX_NUM	/* 6 */
} ENUM_PHY_TYPE_INDEX_T, *P_ENUM_PHY_TYPE_INDEX_T;

typedef enum _ENUM_SW_RATE_INDEX_T {
	RATE_1M_SW_INDEX = 0,	/* 1M */
	RATE_2M_SW_INDEX,	/* 2M */
	RATE_5_5M_SW_INDEX,	/* 5.5M */
	RATE_11M_SW_INDEX,	/* 11M */
	RATE_22M_SW_INDEX,	/* 22M */
	RATE_33M_SW_INDEX,	/* 33M */
	RATE_6M_SW_INDEX,	/* 6M */
	RATE_9M_SW_INDEX,	/* 9M */
	RATE_12M_SW_INDEX,	/* 12M */
	RATE_18M_SW_INDEX,	/* 18M */
	RATE_24M_SW_INDEX,	/* 24M */
	RATE_36M_SW_INDEX,	/* 36M */
	RATE_48M_SW_INDEX,	/* 48M */
	RATE_54M_SW_INDEX,	/* 54M */
	RATE_HT_PHY_SW_INDEX,	/* BSS Selector - HT PHY */
	RATE_NUM_SW		/* 15 */
} ENUM_SW_RATE_INDEX_T, *P_ENUM_SW_RATE_INDEX_T;

typedef enum _ENUM_CCK_RATE_INDEX_T {
	RATE_1M_INDEX = 0,	/* 1M */
	RATE_2M_INDEX,		/* 2M */
	RATE_5_5M_INDEX,	/* 5.5M */
	RATE_11M_INDEX,		/* 11M */
	CCK_RATE_NUM		/* 4 */
} ENUM_CCK_RATE_INDEX_T, *P_ENUM_CCK_RATE_INDEX_T;

typedef enum _ENUM_OFDM_RATE_INDEX_T {
	RATE_6M_INDEX = 0,	/* 6M */
	RATE_9M_INDEX,		/* 9M */
	RATE_12M_INDEX,		/* 12M */
	RATE_18M_INDEX,		/* 18M */
	RATE_24M_INDEX,		/* 24M */
	RATE_36M_INDEX,		/* 36M */
	RATE_48M_INDEX,		/* 48M */
	RATE_54M_INDEX,		/* 54M */
	OFDM_RATE_NUM		/* 8 */
} ENUM_OFDM_RATE_INDEX_T, *P_ENUM_OFDM_RATE_INDEX_T;

typedef enum _ENUM_HT_RATE_INDEX_T {
	HT_RATE_MCS32_INDEX = 0,
	HT_RATE_MCS0_INDEX,
	HT_RATE_MCS1_INDEX,
	HT_RATE_MCS2_INDEX,
	HT_RATE_MCS3_INDEX,
	HT_RATE_MCS4_INDEX,
	HT_RATE_MCS5_INDEX,
	HT_RATE_MCS6_INDEX,
	HT_RATE_MCS7_INDEX,
	HT_RATE_MCS8_INDEX,
	HT_RATE_MCS9_INDEX,
	HT_RATE_MCS10_INDEX,
	HT_RATE_MCS11_INDEX,
	HT_RATE_MCS12_INDEX,
	HT_RATE_MCS13_INDEX,
	HT_RATE_MCS14_INDEX,
	HT_RATE_MCS15_INDEX,
	HT_RATE_NUM	/* 16 */
} ENUM_HT_RATE_INDEX_T, *P_ENUM_HT_RATE_INDEX_T;

typedef enum _ENUM_VHT_RATE_INDEX_T {
	VHT_RATE_MCS0_INDEX = 0,
	VHT_RATE_MCS1_INDEX,
	VHT_RATE_MCS2_INDEX,
	VHT_RATE_MCS3_INDEX,
	VHT_RATE_MCS4_INDEX,
	VHT_RATE_MCS5_INDEX,
	VHT_RATE_MCS6_INDEX,
	VHT_RATE_MCS7_INDEX,
	VHT_RATE_MCS8_INDEX,
	VHT_RATE_MCS9_INDEX,
	VHT_RATE_NUM		/* 10 */
} ENUM_VHT_RATE_INDEX_T, *P_ENUM_VHT_RATE_INDEX_T;

typedef enum _ENUM_PREMABLE_OPTION_T {
	PREAMBLE_DEFAULT_LONG_NONE = 0,	/* LONG for PHY_TYPE_HR_DSSS, NONE for PHY_TYPE_OFDM */
	PREAMBLE_OPTION_SHORT,	/* SHORT mandatory for PHY_TYPE_ERP, SHORT option for PHY_TYPE_HR_DSSS */
	PREAMBLE_OFDM_MODE,
	PREAMBLE_HT_MIXED_MODE,
	PREAMBLE_HT_GREEN_FIELD,
	PREAMBLE_VHT_FIELD,
	PREAMBLE_OPTION_NUM
} ENUM_PREMABLE_OPTION_T, *P_ENUM_PREMABLE_OPTION_T;

typedef enum _ENUM_MODULATION_SYSTEM_T {
	MODULATION_SYSTEM_CCK = 0,
	MODULATION_SYSTEM_OFDM,
	MODULATION_SYSTEM_HT20,
	MODULATION_SYSTEM_HT40,
	MODULATION_SYSTEM_NUM
} ENUM_MODULATION_SYSTEM_T, *P_ENUM_MODULATION_SYSTEM_T;

typedef enum _ENUM_MODULATION_TYPE_T {
	MODULATION_TYPE_CCK_BPSK = 0,
	MODULATION_TYPE_QPSK,
	MODULATION_TYPE_16QAM,
	MODULATION_TYPE_64QAM,
	MODULATION_TYPE_MCS6,
	MODULATION_TYPE_54M_MCS7,
	MODULATION_TYPE_MCS32,
	MODULATION_TYPE_NUM
} ENUM_MODULATION_TYPE_T, *P_ENUM_MODULATION_TYPE_T;

enum ENUM_VHT_SYSTEM {
	VHT_SYSTEM_VHT20 = 0,
	VHT_SYSTEM_VHT40,
	VHT_SYSTEM_VHT80,
	VHT_SYSTEM_VHT160C,
	VHT_SYSTEM_VHT160NC,
	VHT_SYSTEM_LG_VHT40,
	VHT_SYSTEM_LG_VHT80,
	VHT_SYSTEM_LG_VHT160,
	VHT_SYSTEM_NUM
};

enum ENUM_VHT_MODULATION_TYPE {
	MODULATION_TYPE_VHT_BPSK = 0,
	MODULATION_TYPE_VHT_QPSK,
	MODULATION_TYPE_VHT_16QAM,
	MODULATION_TYPE_VHT_64QAM_MSC5_6,
	MODULATION_TYPE_VHT_64QAM_MSC7,
	MODULATION_TYPE_VHT_64QAM_MSC8,
	MODULATION_TYPE_VHT_64QAM_MSC9,
	MODULATION_TYPE_VHT_NUM
};

enum PWR_DSSS_CAT {
	PWR_DSSS_CCK,
	PWR_DSSS_BPKS,
	PWR_DSSS_NUM
};

enum PWR_OFDM_CAT {
	PWR_OFDM_BPSK, /* 6M, 9M */
	PWR_OFDM_QPSK, /* 12M, 18M */
	PWR_OFDM_16QAM, /* 24M, 36M */
	PWR_OFDM_48Mbps, /* 48M */
	PWR_OFDM_54Mbps, /* 54M */
	PWR_OFDM_NUM
};

enum PWR_HT20_CAT {
	PWR_HT_BPSK, /* MCS0*/
	PWR_HT_QPSK, /* MCS1, MCS2 */
	PWR_HT_16QAM, /* MCS3, MCS4 */
	PWR_HT_MCS5, /* MCS5 */
	PWR_HT_MCS6, /* MCS6 */
	PWR_HT_MCS7, /* MCS7 */
	PWR_HT_MCS32, /* MCS32 */
	PWR_HT_NUM
};

enum PWR_VHT20_CAT {
	PWR_VHT20_BPSK,
	PWR_VHT20_QPSK,
	PWR_VHT20_16QAM,
	PWR_VHT20_64QAM,
	PWR_VHT20_MCS7,
	PWR_VHT20_MCS8,
	PWR_VHT20_MCS9,
	PWR_VHT20_NUM
};

enum PWR_VHT_OFST_CAT {
	PWR_Vht40_OFFSET = VHT_SYSTEM_VHT40, /*to sync to ENUM_VHT_SYSTEM_T*/
	PWR_Vht80_OFFSET,
	PWR_Vht160c_OFFSET,
	PWR_Vht160nc_OFFSET,
	PWR_LgVht40_OFFSET,
	PWR_LgVht80_OFFSET,
	PWR_VHT_OFST_NUM
};

#ifdef CFG_DUMP_TXPOWR_TABLE
struct POWER_LIMIT {
	UINT_8 ucCentralCh;
	UINT_8 tx_pwr_dsss[PWR_DSSS_NUM]; /*unit: 0.5 dbm*/
	UINT_8 tx_pwr_ofdm[PWR_OFDM_NUM]; /*unit: 0.5 dbm*/
	UINT_8 tx_pwr_ht20[PWR_HT_NUM]; /*unit: 0.5 dbm*/
	UINT_8 tx_pwr_ht40[PWR_HT_NUM]; /*unit: 0.5 dbm*/
	UINT_8 tx_pwr_vht20[PWR_VHT20_NUM]; /*unit: 0.5 dbm*/
	UINT_8 tx_pwr_vht_OFST[PWR_VHT_OFST_NUM]; /*unit: 0.5 dbm*/
};

enum ENUM_TXPWR_TBL_IDX {
	LIMIT_TBL,
	EEPROM_TBL,
	MAC_TBL,
	TXPWR_TBL_NUM
};
#endif

typedef enum _ENUM_ACPI_STATE_T {
	ACPI_STATE_D0 = 0,
	ACPI_STATE_D1,
	ACPI_STATE_D2,
	ACPI_STATE_D3
} ENUM_ACPI_STATE_T;

/* The operation mode of a specific Network */
typedef enum _ENUM_OP_MODE_T {
	OP_MODE_INFRASTRUCTURE = 0,	/* Infrastructure/GC */
	OP_MODE_IBSS,		/* AdHoc */
	OP_MODE_ACCESS_POINT,	/* For GO */
	OP_MODE_P2P_DEVICE,	/* P2P Device */
	OP_MODE_BOW,
	OP_MODE_NUM
} ENUM_OP_MODE_T, *P_ENUM_OP_MODE_T;

typedef enum _ENUM_CHNL_EXT_T {
	CHNL_EXT_SCN = 0,
	CHNL_EXT_SCA = 1,
	CHNL_EXT_RES = 2,
	CHNL_EXT_SCB = 3
} ENUM_CHNL_EXT_T, *P_ENUM_CHNL_EXT_T;

typedef enum _ENUM_CHANNEL_WIDTH_T {
	CW_20_40MHZ = 0,
	CW_80MHZ = 1,
	CW_160MHZ = 2,
	CW_80P80MHZ = 3
} ENUM_CHANNEL_WIDTH_T, *P_ENUM_CHANNEL_WIDTH_P;

/* This starting freq of the band is unit of kHz */
typedef enum _ENUM_BAND_T {
	BAND_NULL,
	BAND_2G4,
	BAND_5G,
	BAND_NUM
} ENUM_BAND_T, *P_ENUM_BAND_T;

typedef enum _ENUM_DBDC_BN_T {
	ENUM_BAND_0,
	ENUM_BAND_1,
	ENUM_BAND_NUM,
	ENUM_BAND_ALL,
	ENUM_BAND_AUTO	/*Auto select by A/G band, Driver only*/
} ENUM_DBDC_BN_T, *P_ENUM_DBDC_BN_T;

/* Provide supported channel list to other components in array format */
typedef struct _RF_CHANNEL_INFO_T {
	ENUM_BAND_T eBand;
	UINT_32 u4CenterFreq1; /* To record Channel Center Frequency Segment 0 (MHz) from CFG80211 */
	UINT_32 u4CenterFreq2; /* To record Channel Center Frequency Segment 1 (MHz) from CFG80211 */
	UINT_16 u2PriChnlFreq; /* To record primary channel frequency (MHz) from CFG80211 */
	UINT_8 ucChnlBw; /* To record channel bandwidth from CFG80211 */
	UINT_8 ucChannelNum;
#if (CFG_SUPPORT_DFS_MASTER == 1)
	UINT_32 u4ChnlDfsState; /* Channel DFS State */
#endif
} RF_CHANNEL_INFO_T, *P_RF_CHANNEL_INFO_T;

typedef enum _ENUM_PS_FORWARDING_TYPE_T {
	PS_FORWARDING_TYPE_NON_PS = 0,
	PS_FORWARDING_TYPE_DELIVERY_ENABLED,
	PS_FORWARDING_TYPE_NON_DELIVERY_ENABLED,
	PS_FORWARDING_MORE_DATA_ENABLED,
	PS_FORWARDING_TYPE_NUM
} ENUM_PS_FORWARDING_TYPE_T, *P_ENUM_PS_FORWARDING_TYPE_T;

typedef enum _ENUM_AR_SS_T {
	AR_SS_NULL = 0,
	AR_SS_1,
	AR_SS_2,
	AR_SS_3,
	AR_SS_4,
	AR_SS_NUM
} ENUM_AR_SS_T, P_ENUM_AR_SS_T;

typedef enum _ENUM_MAC_BANDWIDTH_T {
	MAC_BW_20 = 0,
	MAC_BW_40,
	MAC_BW_80,
	MAC_BW_160
} ENUM_MAC_BANDWIDTH_T, *P_ENUM_MAC_BANDWIDTH_T;

typedef struct _DEAUTH_INFO_T {
	UINT_8 aucRxAddr[MAC_ADDR_LEN];
	OS_SYSTIME rLastSendTime;
} DEAUTH_INFO_T, *P_DEAUTH_INFO_T;

/*----------------------------------------------------------------------------*/
/* Information Element (IE) handlers                                          */
/*----------------------------------------------------------------------------*/
typedef VOID(*PFN_APPEND_IE_FUNC) (P_ADAPTER_T, P_MSDU_INFO_T);
typedef VOID(*PFN_HANDLE_IE_FUNC) (P_ADAPTER_T, P_SW_RFB_T, P_IE_HDR_T);
typedef VOID(*PFN_VERIFY_IE_FUNC) (P_ADAPTER_T, P_SW_RFB_T, P_IE_HDR_T, PUINT_16);
typedef UINT_32(*PFN_CALCULATE_VAR_IE_LEN_FUNC) (P_ADAPTER_T, UINT_8, P_STA_RECORD_T);

typedef struct _APPEND_IE_ENTRY_T {
	UINT_16 u2EstimatedIELen;
	PFN_APPEND_IE_FUNC pfnAppendIE;
} APPEND_IE_ENTRY_T, *P_APPEND_IE_ENTRY_T;

typedef struct _APPEND_VAR_IE_ENTRY_T {
	UINT_16 u2EstimatedFixedIELen;	/* For Fixed Length */
	PFN_CALCULATE_VAR_IE_LEN_FUNC pfnCalculateVariableIELen;
	PFN_APPEND_IE_FUNC pfnAppendIE;
} APPEND_VAR_IE_ENTRY_T, *P_APPEND_VAR_IE_ENTRY_T;

typedef struct _HANDLE_IE_ENTRY_T {
	UINT_8 ucElemID;
	PFN_HANDLE_IE_FUNC pfnHandleIE;
} HANDLE_IE_ENTRY_T, *P_HANDLE_IE_ENTRY_T;

typedef struct _VERIFY_IE_ENTRY_T {
	UINT_8 ucElemID;
	PFN_VERIFY_IE_FUNC pfnVarifyIE;
} VERIFY_IE_ENTRY_T, *P_VERIFY_IE_ENTRY_T;

/*----------------------------------------------------------------------------*/
/* Parameters of User Configuration                                           */
/*----------------------------------------------------------------------------*/
typedef enum _ENUM_PARAM_CONNECTION_POLICY_T {
	CONNECT_BY_SSID_BEST_RSSI = 0,
	CONNECT_BY_SSID_GOOD_RSSI_MIN_CH_LOAD,
	CONNECT_BY_SSID_ANY,	/* NOTE(Kevin): Needed by WHQL */
	CONNECT_BY_BSSID,
	CONNECT_BY_CUSTOMIZED_RULE	/* NOTE(Kevin): TBD */
} ENUM_PARAM_CONNECTION_POLICY_T, *P_ENUM_PARAM_CONNECTION_POLICY_T;

typedef enum _ENUM_PARAM_PREAMBLE_TYPE_T {
	PREAMBLE_TYPE_LONG = 0,
	PREAMBLE_TYPE_SHORT,
	PREAMBLE_TYPE_AUTO	/*!< Try preamble short first, if fail tray preamble long. */
} ENUM_PARAM_PREAMBLE_TYPE_T, *P_ENUM_PARAM_PREAMBLE_TYPE_T;

/* This is enum defined for user to select a phy config listed in combo box */
typedef enum _ENUM_PARAM_PHY_CONFIG_T {
	PHY_CONFIG_802_11ABG = 0,	/*!< Can associated with 802.11abg AP but without n capability, Scan dual band.
					 **/
	PHY_CONFIG_802_11BG,	/*!< Can associated with 802_11bg AP, Scan single band and not report 5G BSSs.
				 **/
	PHY_CONFIG_802_11G,	/*!< Can associated with 802_11g only AP, Scan single band and not report 5G BSSs. */
	PHY_CONFIG_802_11A,	/*!< Can associated with 802_11a only AP, Scan single band and not report 2.4G BSSs. */
	PHY_CONFIG_802_11B,	/*!< Can associated with 802_11b only AP, Scan single band and not report 5G BSSs. */
	PHY_CONFIG_802_11ABGN,	/*!< Can associated with 802.11abgn AP, Scan dual band. */
	PHY_CONFIG_802_11BGN,	/*!< Can associated with 802_11bgn AP, Scan single band and not report 5G BSSs.
				 **/
	PHY_CONFIG_802_11AN,	/*!< Can associated with 802_11an AP, Scan single band and not report 2.4G BSSs.
				 **/
	PHY_CONFIG_802_11GN,	/*!< Can associated with 802_11gn AP, Scan single band and not report 5G BSSs.
				 **/
	PHY_CONFIG_802_11AC,
	PHY_CONFIG_802_11ANAC,
	PHY_CONFIG_802_11ABGNAC,
	PHY_CONFIG_NUM		/* 12 */
} ENUM_PARAM_PHY_CONFIG_T, *P_ENUM_PARAM_PHY_CONFIG_T;

/* This is enum defined for user to select an AP Mode */
typedef enum _ENUM_PARAM_AP_MODE_T {
	AP_MODE_11B = 0,	/*!< Create 11b BSS if we support 802.11abg/802.11bg. */
	AP_MODE_MIXED_11BG,	/*!< Create 11bg mixed BSS if we support 802.11abg/802.11bg/802.11g. */
	AP_MODE_11G,		/*!< Create 11g only BSS if we support 802.11abg/802.11bg/802.11g. */
	AP_MODE_11G_P2P,	/*!< Create 11g only BSS for P2P if we support 802.11abg/802.11bg/802.11g. */
	AP_MODE_11A,		/*!< Create 11a only BSS if we support 802.11abg. */
	AP_MODE_NUM		/* 4 */
} ENUM_PARAM_AP_MODE_T, *P_ENUM_PARAM_AP_MODE_T;

/* Masks for determining the Network Type or the Station Role, given the ENUM_STA_TYPE_T */
#define STA_TYPE_LEGACY_MASK                BIT(STA_TYPE_LEGACY_INDEX)
#define STA_TYPE_P2P_MASK                   BIT(STA_TYPE_P2P_INDEX)
#define STA_TYPE_BOW_MASK                   BIT(STA_TYPE_BOW_INDEX)
#define STA_TYPE_ADHOC_MASK                 BIT(STA_ROLE_ADHOC_INDEX)
#define STA_TYPE_CLIENT_MASK                BIT(STA_ROLE_CLIENT_INDEX)
#define STA_TYPE_AP_MASK                    BIT(STA_ROLE_AP_INDEX)
#define STA_TYPE_DLS_MASK                   BIT(STA_ROLE_DLS_INDEX)

/* Macros for obtaining the Network Type or the Station Role, given the ENUM_STA_TYPE_T */
#define IS_STA_IN_AIS(_prStaRec)        ((_prStaRec)->ucBssIndex == prAdapter->prAisBssInfo->ucBssIndex)
#define IS_STA_IN_P2P(_prStaRec)        (prAdapter->aprBssInfo[(_prStaRec)->ucBssIndex]->eNetworkType == \
					 NETWORK_TYPE_P2P)
#define IS_STA_LEGACY_TYPE(_prStaRec)   ((_prStaRec->eStaType) & STA_TYPE_LEGACY_MASK)
#define IS_STA_P2P_TYPE(_prStaRec)      ((_prStaRec->eStaType) & STA_TYPE_P2P_MASK)
#define IS_STA_BOW_TYPE(_prStaRec)      ((_prStaRec->eStaType) & STA_TYPE_BOW_MASK)
#define IS_ADHOC_STA(_prStaRec)         ((_prStaRec->eStaType) & STA_TYPE_ADHOC_MASK)
#define IS_CLIENT_STA(_prStaRec)        ((_prStaRec->eStaType) & STA_TYPE_CLIENT_MASK)
#define IS_AP_STA(_prStaRec)            ((_prStaRec->eStaType) & STA_TYPE_AP_MASK)
#define IS_DLS_STA(_prStaRec)           ((_prStaRec->eStaType) & STA_TYPE_DLS_MASK)

/* The ENUM_STA_TYPE_T accounts for ENUM_NETWORK_TYPE_T and ENUM_STA_ROLE_INDEX_T.
 *   It is a merged version of Network Type and STA Role.
 */
typedef enum _ENUM_STA_TYPE_T {
	STA_TYPE_LEGACY_AP = (STA_TYPE_LEGACY_MASK | STA_TYPE_AP_MASK),
	STA_TYPE_LEGACY_CLIENT = (STA_TYPE_LEGACY_MASK | STA_TYPE_CLIENT_MASK),
	STA_TYPE_ADHOC_PEER = (STA_TYPE_LEGACY_MASK | STA_TYPE_ADHOC_MASK),
#if CFG_ENABLE_WIFI_DIRECT
	STA_TYPE_P2P_GO = (STA_TYPE_P2P_MASK | STA_TYPE_AP_MASK),
	STA_TYPE_P2P_GC = (STA_TYPE_P2P_MASK | STA_TYPE_CLIENT_MASK),
#endif
#if CFG_ENABLE_BT_OVER_WIFI
	STA_TYPE_BOW_AP = (STA_TYPE_BOW_MASK | STA_TYPE_AP_MASK),
	STA_TYPE_BOW_CLIENT = (STA_TYPE_BOW_MASK | STA_TYPE_CLIENT_MASK),
#endif
	STA_TYPE_DLS_PEER = (STA_TYPE_LEGACY_MASK | STA_TYPE_DLS_MASK),
} ENUM_STA_TYPE_T, *P_ENUM_STA_TYPE_T;

/* The type of BSS we discovered */
typedef enum _ENUM_BSS_TYPE_T {
	BSS_TYPE_INFRASTRUCTURE = 1,
	BSS_TYPE_IBSS,
	BSS_TYPE_P2P_DEVICE,
	BSS_TYPE_BOW_DEVICE,
	BSS_TYPE_NUM
} ENUM_BSS_TYPE_T, *P_ENUM_BSS_TYPE_T;

typedef enum _ENUM_ANTENNA_NUM {
	ANTENNA_WF0 = 0,
	ANTENNA_WF1 = 1,
	MAX_ANTENNA_NUM
} ENUM_ANTENNA_NUM, *P_ENUM_ANTENNA_NUM;

/*----------------------------------------------------------------------------*/
/* RSN structures                                                             */
/*----------------------------------------------------------------------------*/
/* #if defined(WINDOWS_DDK) || defined(WINDOWS_CE) */
/* #pragma pack(1) */
/* #endif */

#if CFG_SUPPORT_CFG80211_AUTH
/* max number of supported cipher suites */
#define MAX_NUM_SUPPORTED_CIPHER_SUITES 10
#if CFG_SUPPORT_802_11W
/* max number of supported AKM suites */
#define MAX_NUM_SUPPORTED_AKM_SUITES    15
#else
/* max number of supported AKM suites */
#define MAX_NUM_SUPPORTED_AKM_SUITES    13
#endif
#else
#define MAX_NUM_SUPPORTED_CIPHER_SUITES 8
#if CFG_SUPPORT_802_11W
/* max number of supported AKM suites */
#define MAX_NUM_SUPPORTED_AKM_SUITES    8
#else
/* max number of supported AKM suites */
#define MAX_NUM_SUPPORTED_AKM_SUITES    6
#endif
#endif
/* max number of supported PMKID */
#define MAX_NUM_SUPPORTED_PMKID	        10

/* Structure of RSN Information */
typedef struct _RSN_INFO_T {
	UINT_8 ucElemId;
	UINT_8 ucRsneLen;
	UINT_16 u2Version;
	UINT_32 u4GroupKeyCipherSuite;
	UINT_32 u4PairwiseKeyCipherSuiteCount;
	UINT_32 au4PairwiseKeyCipherSuite[MAX_NUM_SUPPORTED_CIPHER_SUITES];
	UINT_32 u4AuthKeyMgtSuiteCount;
	UINT_32 au4AuthKeyMgtSuite[MAX_NUM_SUPPORTED_AKM_SUITES];
	UINT_16 u2RsnCap;
	BOOLEAN fgRsnCapPresent;
	UINT_16 u2PmkidCnt;
	BOOLEAN aucPmkidList[MAX_NUM_SUPPORTED_PMKID * RSN_PMKID_LEN];
	UINT_32 u4GroupMgmtKeyCipherSuite;
} /*__KAL_ATTRIB_PACKED__*/ RSN_INFO_T, *P_RSN_INFO_T;

#define MAX_NUM_SUPPORTED_WAPI_AKM_SUITES    1	/* max number of supported AKM suites */
#define MAX_NUM_SUPPORTED_WAPI_CIPHER_SUITES 1	/* max number of supported cipher suites */

/* Structure of WAPI Information */
typedef struct _WAPI_INFO_T {
	UINT_8 ucElemId;
	UCHAR ucLength;
	UINT_16 u2Version;
	UINT_32 u4AuthKeyMgtSuiteCount;
	UINT_32 au4AuthKeyMgtSuite[MAX_NUM_SUPPORTED_WAPI_AKM_SUITES];
	UINT_32 u4PairwiseKeyCipherSuiteCount;
	UINT_32 au4PairwiseKeyCipherSuite[MAX_NUM_SUPPORTED_WAPI_CIPHER_SUITES];
	UINT_32 u4GroupKeyCipherSuite;
	UINT_16 u2WapiCap;
	UINT_16 u2Bkid;
	UINT_8 aucBkid[1][16];
} /* __KAL_ATTRIB_PACKED__ */ WAPI_INFO_T, *P_WAPI_INFO_T;

/* #if defined(WINDOWS_DDK) || defined(WINDOWS_CE) */
/* #pragma pack() */
/* #endif */

#if CFG_ENABLE_WIFI_DIRECT

typedef struct _P2P_DEVICE_TYPE_T {
	UINT_16 u2CategoryID;
	UINT_16 u2SubCategoryID;
} P2P_DEVICE_TYPE_T, *P_P2P_DEVICE_TYPE_T;

typedef struct _P2P_DEVICE_DESC_T {
	LINK_ENTRY_T rLinkEntry;
	BOOLEAN fgDevInfoValid;
	UINT_8 aucDeviceAddr[MAC_ADDR_LEN];	/* Device Address. */
	UINT_8 aucInterfaceAddr[MAC_ADDR_LEN];	/* Interface Address. */
	UINT_8 ucDeviceCapabilityBitmap;
	UINT_8 ucGroupCapabilityBitmap;
	UINT_16 u2ConfigMethod;	/* Configure Method support. */
	P2P_DEVICE_TYPE_T rPriDevType;
	UINT_8 ucSecDevTypeNum;
	P2P_DEVICE_TYPE_T arSecDevType[8];	/* Reference to P2P_GC_MAX_CACHED_SEC_DEV_TYPE_COUNT */
	UINT_16 u2NameLength;
	UINT_8 aucName[32];	/* Reference to WPS_ATTRI_MAX_LEN_DEVICE_NAME */
	/* TODO: Service Information or PasswordID valid? */
} P2P_DEVICE_DESC_T, *P_P2P_DEVICE_DESC_T;

#endif

#if CFG_SUPPORT_OWE
/* Structure of OWE Information */
struct OWE_INFO_T {
	UINT_8 ucElemId;
	UINT_8 ucLength;
	UINT_8 ucElemIdExt;
	UINT_16 u2Group;
	UINT_8 aucPublicKey[100];
};
#endif

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
/* Macros to get and set the wireless LAN frame fields those are 16/32 bits in length. */
#define WLAN_GET_FIELD_16(_memAddr_p, _value_p) \
	{ \
		PUINT_8 __cp = (PUINT_8)(_memAddr_p); \
		*(PUINT_16)(_value_p) = ((UINT_16)__cp[0]) | ((UINT_16)__cp[1] << 8); \
	}

#define WLAN_GET_FIELD_BE16(_memAddr_p, _value_p) \
	{ \
		PUINT_8 __cp = (PUINT_8)(_memAddr_p); \
		*(PUINT_16)(_value_p) = ((UINT_16)__cp[0] << 8) | ((UINT_16)__cp[1]); \
	}

#define WLAN_GET_FIELD_32(_memAddr_p, _value_p) \
	{ \
		PUINT_8 __cp = (PUINT_8)(_memAddr_p); \
		*(PUINT_32)(_value_p) = ((UINT_32)__cp[0]) | ((UINT_32)__cp[1] << 8) | \
					((UINT_32)__cp[2] << 16) | ((UINT_32)__cp[3] << 24); \
	}

#define WLAN_GET_FIELD_BE32(_memAddr_p, _value_p) \
	{ \
		PUINT_8 __cp = (PUINT_8)(_memAddr_p); \
		*(PUINT_32)(_value_p) = ((UINT_32)__cp[0] << 24) | \
		    ((UINT_32)__cp[1] << 16) | ((UINT_32)__cp[2] << 8) | \
		    ((UINT_32)__cp[3]); \
	}

#define WLAN_GET_FIELD_64(_memAddr_p, _value_p) \
	{ \
		PUINT_8 __cp = (PUINT_8)(_memAddr_p); \
		*(PUINT_64)(_value_p) = \
			((UINT_64)__cp[0]) | ((UINT_64)__cp[1] << 8) | \
			((UINT_64)__cp[2] << 16) | ((UINT_64)__cp[3] << 24) | \
			((UINT_64)__cp[4] << 32) | ((UINT_64)__cp[5] << 40) | \
			((UINT_64)__cp[6] << 48) | ((UINT_64)__cp[7] << 56); \
	}

#define WLAN_SET_FIELD_16(_memAddr_p, _value) \
	{ \
		PUINT_8 __cp = (PUINT_8)(_memAddr_p); \
		__cp[0] = (UINT_8)(_value); \
		__cp[1] = (UINT_8)((_value) >> 8); \
	}

#define WLAN_SET_FIELD_BE16(_memAddr_p, _value) \
	{ \
		PUINT_8 __cp = (PUINT_8)(_memAddr_p); \
		__cp[0] = (UINT_8)((_value) >> 8); \
		__cp[1] = (UINT_8)(_value); \
	}

#define WLAN_SET_FIELD_32(_memAddr_p, _value) \
	{ \
		PUINT_8 __cp = (PUINT_8)(_memAddr_p); \
		__cp[0] = (UINT_8)(_value); \
		__cp[1] = (UINT_8)((_value) >> 8); \
		__cp[2] = (UINT_8)((_value) >> 16); \
		__cp[3] = (UINT_8)((_value) >> 24); \
	}

#define WLAN_SET_FIELD_BE24(_memAddr_p, _value) \
	{ \
		PUINT_8 __cp = (PUINT_8)(_memAddr_p); \
		__cp[0] = (UINT_8)((_value) >> 16); \
		__cp[1] = (UINT_8)((_value) >> 8); \
		__cp[2] = (UINT_8)(_value); \
	}

#define WLAN_SET_FIELD_BE32(_memAddr_p, _value) \
	{ \
		PUINT_8 __cp = (PUINT_8)(_memAddr_p); \
		__cp[0] = (UINT_8)((_value) >> 24); \
		__cp[1] = (UINT_8)((_value) >> 16); \
		__cp[2] = (UINT_8)((_value) >> 8); \
		__cp[3] = (UINT_8)(_value); \
	}

/*******************************************************************************
 *                   F U N C T I O N   D E C L A R A T I O N S
 ********************************************************************************
 */

/*******************************************************************************
 *                              F U N C T I O N S
 ********************************************************************************
 */

#endif /* _WLAN_DEF_H */
