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
** Id: //Department/DaVinci/BRANCHES/MT6620_WIFI_DRIVER_V2_3/include/nic/mac.h#1
*/

/*! \file   "mac.h"
*    \brief  Brief description.
*
*    Detail description.
*/


#ifndef _MAC_H
#define _MAC_H

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
#if CFG_SUPPORT_CFG80211_AUTH
#define AUTH_DATA_MAX_LEN 1024 /* temp defined */
#endif
/* 3 --------------- Constants for Ethernet/802.11 MAC --------------- */
/* MAC Address */
#define MAC_ADDR_LEN                            6

#define MAC_ADDR_LOCAL_ADMIN                    BIT(1)

#define ETH_P_IPV4                              0x0800
#define ETH_P_ARP                               0x0806
#define ETH_P_IPX                               0x8137	/* Novell IPX */
#define ETH_P_AARP                              0x80F3	/* AppleTalk Address Resolution Protocol (AARP) */
#define ETH_P_IPV6                              0x86DD
#define ETH_P_VLAN                              0x8100

#define ETH_P_1X                                0x888E
#define ETH_P_PRE_1X                            0x88C7
#if CFG_SUPPORT_WAPI
#define ETH_WPI_1X                              0x88B4
#endif
#define ETH_EAPOL_KEY                           3

/* 802.3 Frame If Ether Type/Len <= 1500 */
#define ETH_802_3_MAX_LEN                       1500

/* IP Header definition */
#define IP_VERSION_MASK                         BITS(4, 7)
#define IP_VERSION_OFFSET                       4
#define IP_VERSION_4                            4
#define IP_VERSION_6                            6

#define IP_PROTOCOL_TCP                         6
#define IP_PROTOCOL_UDP                         17

/* IPv4 Header definition */
#define IPV4_HDR_TOS_OFFSET                     1
#define IPV4_HDR_TOS_PREC_MASK                  BITS(5, 7)
#define IPV4_HDR_TOS_PREC_OFFSET                5
#define IPV4_HDR_IP_IDENTIFICATION_OFFSET       4
#define IPV4_HDR_IP_PROTOCOL_OFFSET             9
#define IPV4_HDR_IP_CSUM_OFFSET                 10
#define IPV4_HDR_IP_SRC_ADDR_OFFSET             12
#define IPV4_HDR_IP_DST_ADDR_OFFSET             16

#define IPV4_HDR_LEN                            20
#define IPV4_ADDR_LEN                           4

#define IPV6_HDR_IP_PROTOCOL_OFFSET             6
#define IPV6_HDR_IP_SRC_ADDR_OFFSET             8
#define IPV6_HDR_IP_DST_ADDR_OFFSET             24
#define IPV6_HDR_IP_DST_ADDR_MAC_HIGH_OFFSET    32
#define IPV6_HDR_IP_DST_ADDR_MAC_LOW_OFFSET     37
#define IPV6_PROTOCOL_ICMPV6                    0x3A

#define IPV6_HDR_TC_PREC_OFFSET                 1
#define IPV6_HDR_TC_PREC_MASK                   BITS(1, 3)
#define IPV6_HDR_PROTOCOL_OFFSET                6
#define IPV6_HDR_LEN                            40

#define IPV6_ADDR_LEN                           16

#define ICMPV6_TYPE_OFFSET                      0
#define ICMPV6_FLAG_OFFSET                      4
#define ICMPV6_TARGET_ADDR_OFFSET				8
#define ICMPV6_TARGET_LL_ADDR_TYPE_OFFSET		24
#define ICMPV6_TARGET_LL_ADDR_LEN_OFFSET		25
#define ICMPV6_TARGET_LL_ADDR_TA_OFFSET			26

#define ICMPV6_FLAG_ROUTER_BIT                  BIT(7)
#define ICMPV6_FLAG_SOLICITED_BIT               BIT(6)
#define ICMPV6_FLAG_OVERWRITE_BIT               BIT(5)
#define ICMPV6_TYPE_NEIGHBOR_SOLICITATION       0x87
#define ICMPV6_TYPE_NEIGHBOR_ADVERTISEMENT      0x88

#define TCP_HDR_TCP_CSUM_OFFSET                 16

#define UDP_HDR_LEN                             8

#define UDP_HDR_SRC_PORT_OFFSET                 0
#define UDP_HDR_DST_PORT_OFFSET                 2
#define UDP_HDR_UDP_CSUM_OFFSET                 6

#define IP_PORT_BOOTP_SERVER                    67
#define IP_PORT_BOOTP_CLIENT                    68

#define DHCP_MAGIC_NUMBER                       0x63825363

#define ARP_OPERATION_OFFSET                    6
#define ARP_SNEDER_MAC_OFFSET                   8
#define ARP_SENDER_IP_OFFSET                    14
#define ARP_TARGET_MAC_OFFSET                   18
#define ARP_TARGET_IP_OFFSET                    24
#define ARP_OPERATION_REQUEST                   0x0001
#define ARP_OPERATION_RESPONSE                  0x0002

#define LLC_LEN                                 8	/* LLC(3) + SNAP(3) + EtherType(2) */

#define NULL_MAC_ADDR                           {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
#define BC_MAC_ADDR                             {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}

#if 1

#define ETH_HLEN                                14
#define ETH_TYPE_LEN_OFFSET                     12

#define IPVERSION                               4
#define IP_HEADER_LEN                           20

#define IPVH_VERSION_OFFSET                     4	/* For Little-Endian */
#define IPVH_VERSION_MASK                       0xF0
#define IPTOS_PREC_OFFSET                       5
#define IPTOS_PREC_MASK                         0xE0

#define SOURCE_PORT_LEN                         2

#define LOOK_AHEAD_LEN                          (ETH_HLEN + IP_HEADER_LEN + SOURCE_PORT_LEN)

#endif

/* Ethernet Frame Field Size, in byte */
#define ETHER_HEADER_LEN                        14
#define ETHER_TYPE_LEN                          2
#define ETHER_MIN_PKT_SZ                        60
#define ETHER_MAX_PKT_SZ                        1514

#define ETHER_TYPE_LEN_OFFSET                   12

/* 802.1Q (VLAN) */
#define ETH_802_1Q_HEADER_LEN                   4

/* 802.2 LLC/SNAP */
#define ETH_LLC_OFFSET                          (ETHER_HEADER_LEN)
#define ETH_LLC_LEN                             3
#define ETH_LLC_DSAP_SNAP                       0xAA
#define ETH_LLC_SSAP_SNAP                       0xAA
#define ETH_LLC_CONTROL_UNNUMBERED_INFORMATION  0x03
#define ETH_LLC                                 \
	{ETH_LLC_DSAP_SNAP, ETH_LLC_SSAP_SNAP, ETH_LLC_CONTROL_UNNUMBERED_INFORMATION}

/* Bluetooth SNAP */
#define ETH_SNAP_OFFSET                         (ETHER_HEADER_LEN + ETH_LLC_LEN)
#define ETH_SNAP_LEN                            5
#define ETH_SNAP_OUI_LEN                        3
#define ETH_SNAP_BT_SIG_OUI_0                   0x00
#define ETH_SNAP_BT_SIG_OUI_1                   0x19
#define ETH_SNAP_BT_SIG_OUI_2                   0x58
#define ETH_SNAP_BT_SIG_OUI                     {ETH_SNAP_BT_SIG_OUI_0, ETH_SNAP_BT_SIG_OUI_1, ETH_SNAP_BT_SIG_OUI_2}

#define BOW_PROTOCOL_ID_SECURITY_FRAME          0x0003

/* IEEE 802.11 WLAN Frame Field Size, in byte */
#define WLAN_MAC_HEADER_LEN                     24	/* Address 4 excluded */
#define WLAN_MAC_HEADER_A4_LEN                  30	/* Address 4 included */
#define WLAN_MAC_HEADER_QOS_LEN                 26	/* QoS Control included */
#define WLAN_MAC_HEADER_QOS_HTC_LEN             30	/* QoS Control and HTC included */
#define WLAN_MAC_HEADER_A4_QOS_LEN              32	/* Address 4 and QoS Control included */
#define WLAN_MAC_HEADER_A4_QOS_HTC_LEN          36	/* Address 4, QoS Control and HTC included */
#define WLAN_MAC_MGMT_HEADER_LEN                24	/* Address 4 excluded */
#define WLAN_MAC_MGMT_HEADER_HTC_LEN            28	/* HTC included */

#define QOS_CTRL_LEN                            2
#define HT_CTRL_LEN                             4

#define WLAN_MAC_CTS_ACK_LEN			(WLAN_MAC_CTS_ACK_FRAME_HEADER_LEN + FCS_LEN)

/* 6.2.1.1.2 Semantics of the service primitive */
#define MSDU_MAX_LENGTH                         2304

/* 7.1.3.3.3 Broadcast BSSID */
#define BC_BSSID                                BC_MAC_ADDR

/* 7.1.3.7 FCS field */
#define FCS_LEN                                 4

/* 7.3.1.6 Listen Interval field */
#define DEFAULT_LISTEN_INTERVAL_BY_DTIM_PERIOD  2	/* In unit of AP's DTIM interval, */
#define DEFAULT_LISTEN_INTERVAL                 10

/* 7.3.2.1 Broadcast(Wildcard) SSID */
#define BC_SSID                                 ""
#define BC_SSID_LEN                             0

/* 7.3.2.2 Data Rate Value */
#define RATE_1M                                 2	/* 1M in unit of 500kb/s */
#define RATE_2M                                 4	/* 2M */
#define RATE_5_5M                               11	/* 5.5M */
#define RATE_11M                                22	/* 11M */
#define RATE_22M                                44	/* 22M */
#define RATE_33M                                66	/* 33M */
#define RATE_6M                                 12	/* 6M */
#define RATE_9M                                 18	/* 9M */
#define RATE_12M                                24	/* 12M */
#define RATE_18M                                36	/* 18M */
#define RATE_24M                                48	/* 24M */
#define RATE_36M                                72	/* 36M */
#define RATE_48M                                96	/* 48M */
#define RATE_54M                                108	/* 54M */
/* 7.3.2.14 BSS membership selector */

#define RATE_VHT_PHY                            126	/* BSS Selector - Clause 22. HT PHY */
#define RATE_HT_PHY                             127	/* BSS Selector - Clause 20. HT PHY */
#define RATE_MASK                               BITS(0, 6)	/* mask bits for the rate */
#define RATE_BASIC_BIT                          BIT(7)	/* mask bit for the rate belonging to the BSSBasicRateSet */

/* 8.3.2.2 TKIP MPDU formats */
#define TKIP_MIC_LEN                            8

/* 9.2.10 DIFS */
#define DIFS                                    2	/* 2 x aSlotTime */

/* 11.3 STA Authentication and Association */
#define STA_STATE_1                             0	/* Accept Class 1 frames */
#define STA_STATE_2                             1	/* Accept Class 1 & 2 frames */
#define STA_STATE_3                             2	/* Accept Class 1,2 & 3 frames */

/* 15.4.8.5 802.11k RCPI-dBm mapping*/
#define NDBM_LOW_BOUND_FOR_RCPI                 110
#define RCPI_LOW_BOUND                          0
#define RCPI_HIGH_BOUND                         220
#define RCPI_MEASUREMENT_NOT_AVAILABLE          255

/* PHY characteristics */
/* 17.4.4/18.3.3/19.8.4 Slot Time (aSlotTime) */
#define SLOT_TIME_LONG                          20	/* Long Slot Time */
#define SLOT_TIME_SHORT                         9	/* Short Slot Time */

#define SLOT_TIME_HR_DSSS                       SLOT_TIME_LONG	/* 802.11b aSlotTime */
#define SLOT_TIME_OFDM                          SLOT_TIME_SHORT	/* 802.11a aSlotTime(20M Spacing) */
#define SLOT_TIME_OFDM_10M_SPACING              13	/* 802.11a aSlotTime(10M Spacing) */
#define SLOT_TIME_ERP_LONG                      SLOT_TIME_LONG	/* 802.11g aSlotTime(Long) */
#define SLOT_TIME_ERP_SHORT                     SLOT_TIME_SHORT	/* 802.11g aSlotTime(Short) */

/* 17.4.4/18.3.3/19.8.4 Contention Window (aCWmin & aCWmax) */
#define CWMIN_OFDM                              15	/* 802.11a aCWmin */
#define CWMAX_OFDM                              1023	/* 802.11a aCWmax */

#define CWMIN_HR_DSSS                           31	/* 802.11b aCWmin */
#define CWMAX_HR_DSSS                           1023	/* 802.11b aCWmax */

#define CWMIN_ERP_0                             31	/* 802.11g aCWmin(0) - for only have 1/2/5/11Mbps Rates */
#define CWMIN_ERP_1                             15	/* 802.11g aCWmin(1) */
#define CWMAX_ERP                               1023	/* 802.11g aCWmax */

/* Short Inter-Frame Space (aSIFSTime) */
/* 15.3.3 802.11b aSIFSTime */
#define SIFS_TIME_HR_DSSS                       10
/* 17.4.4 802.11a aSIFSTime */
#define SIFS_TIME_OFDM                          16
/* 19.8.4 802.11g aSIFSTime */
#define SIFS_TIME_ERP                           10

/* 15.4.6.2 Number of operating channels */
#define CH_1                                    0x1
#define CH_2                                    0x2
#define CH_3                                    0x3
#define CH_4                                    0x4
#define CH_5                                    0x5
#define CH_6                                    0x6
#define CH_7                                    0x7
#define CH_8                                    0x8
#define CH_9                                    0x9
#define CH_10                                   0xa
#define CH_11                                   0xb
#define CH_12                                   0xc
#define CH_13                                   0xd
#define CH_14                                   0xe

#define MAXIMUM_OPERATION_CHANNEL_LIST          32

/* 3 --------------- IEEE 802.11 PICS --------------- */
/* Annex D - dot11OperationEntry 2 */
#define DOT11_RTS_THRESHOLD_MIN                 0
#define DOT11_RTS_THRESHOLD_MAX                 2347	/* from Windows DDK */
/* #define DOT11_RTS_THRESHOLD_MAX                 3000 // from Annex D */

#define DOT11_RTS_THRESHOLD_DEFAULT             \
	    DOT11_RTS_THRESHOLD_MAX

/* Annex D - dot11OperationEntry 5 */
#define DOT11_FRAGMENTATION_THRESHOLD_MIN       256
#define DOT11_FRAGMENTATION_THRESHOLD_MAX       2346	/* from Windows DDK */
/* #define DOT11_FRAGMENTATION_THRESHOLD_MAX       3000 // from Annex D */

#define DOT11_FRAGMENTATION_THRESHOLD_DEFAULT   \
	    DOT11_FRAGMENTATION_THRESHOLD_MAX

/* Annex D - dot11OperationEntry 6 */
#define DOT11_TRANSMIT_MSDU_LIFETIME_TU_MIN     1
#define DOT11_TRANSMIT_MSDU_LIFETIME_TU_MAX     0xFFFFffff
#define DOT11_TRANSMIT_MSDU_LIFETIME_TU_DEFAULT 4095	/* 802.11 define 512 */
						     /* MT5921 only aceept N <= 4095 */

/* Annex D - dot11OperationEntry 7 */
#define DOT11_RECEIVE_LIFETIME_TU_MIN           1
#define DOT11_RECEIVE_LIFETIME_TU_MAX           0xFFFFffff
#define DOT11_RECEIVE_LIFETIME_TU_DEFAULT       4096	/* 802.11 define 512 */

/* Annex D - dot11StationConfigEntry 12 */
#define DOT11_BEACON_PERIOD_MIN                 1	/* TU. */
#define DOT11_BEACON_PERIOD_MAX                 0xffff	/* TU. */
#define DOT11_BEACON_PERIOD_DEFAULT             100	/* TU. */

/* Annex D - dot11StationConfigEntry 13 */
#define DOT11_DTIM_PERIOD_MIN                   1	/* TU. */
#define DOT11_DTIM_PERIOD_MAX                   255	/* TU. */
#define DOT11_DTIM_PERIOD_DEFAULT               1	/* TU. */

/* Annex D - dot11RegDomainsSupportValue */
#define REGULATION_DOMAIN_FCC                   0x10	/* FCC (US) */
#define REGULATION_DOMAIN_IC                    0x20	/* IC or DOC (Canada) */
#define REGULATION_DOMAIN_ETSI                  0x30	/* ETSI (Europe) */
#define REGULATION_DOMAIN_SPAIN                 0x31	/* Spain */
#define REGULATION_DOMAIN_FRANCE                0x32	/* France */
#define REGULATION_DOMAIN_JAPAN                 0x40	/* MKK (Japan) */
#define REGULATION_DOMAIN_CHINA                 0x50	/* China */
#define REGULATION_DOMAIN_OTHER                 0x00	/* Other */

/* 3 --------------- IEEE 802.11 MAC header fields --------------- */
/* 7.1.3.1 Masks for the subfields in the Frame Control field */
#define MASK_FC_PROTOCOL_VER                    BITS(0, 1)
#define MASK_FC_TYPE                            BITS(2, 3)
#define MASK_FC_SUBTYPE                         BITS(4, 7)
#define MASK_FC_SUBTYPE_QOS_DATA                BIT(7)
#define MASK_FC_TO_DS                           BIT(8)
#define MASK_FC_FROM_DS                         BIT(9)
#define MASK_FC_MORE_FRAG                       BIT(10)
#define MASK_FC_RETRY                           BIT(11)
#define MASK_FC_PWR_MGT                         BIT(12)
#define MASK_FC_MORE_DATA                       BIT(13)
#define MASK_FC_PROTECTED_FRAME                 BIT(14)
#define MASK_FC_ORDER                           BIT(15)

#define MASK_FRAME_TYPE                         (MASK_FC_TYPE | MASK_FC_SUBTYPE)
#define MASK_TO_DS_FROM_DS                      (MASK_FC_TO_DS | MASK_FC_FROM_DS)

#define MAX_NUM_OF_FC_SUBTYPES                  16
#define OFFSET_OF_FC_SUBTYPE                    4

/* 7.1.3.1.2 MAC frame types and subtypes */
#define MAC_FRAME_TYPE_MGT                      0
#define MAC_FRAME_TYPE_CTRL                     BIT(2)
#define MAC_FRAME_TYPE_DATA                     BIT(3)
#define MAC_FRAME_TYPE_QOS_DATA                 (MAC_FRAME_TYPE_DATA | MASK_FC_SUBTYPE_QOS_DATA)

#define MAC_FRAME_ASSOC_REQ                     (MAC_FRAME_TYPE_MGT | 0x0000)
#define MAC_FRAME_ASSOC_RSP                     (MAC_FRAME_TYPE_MGT | 0x0010)
#define MAC_FRAME_REASSOC_REQ                   (MAC_FRAME_TYPE_MGT | 0x0020)
#define MAC_FRAME_REASSOC_RSP                   (MAC_FRAME_TYPE_MGT | 0x0030)
#define MAC_FRAME_PROBE_REQ                     (MAC_FRAME_TYPE_MGT | 0x0040)
#define MAC_FRAME_PROBE_RSP                     (MAC_FRAME_TYPE_MGT | 0x0050)
#define MAC_FRAME_BEACON                        (MAC_FRAME_TYPE_MGT | 0x0080)
#define MAC_FRAME_ATIM                          (MAC_FRAME_TYPE_MGT | 0x0090)
#define MAC_FRAME_DISASSOC                      (MAC_FRAME_TYPE_MGT | 0x00A0)
#define MAC_FRAME_AUTH                          (MAC_FRAME_TYPE_MGT | 0x00B0)
#define MAC_FRAME_DEAUTH                        (MAC_FRAME_TYPE_MGT | 0x00C0)
#define MAC_FRAME_ACTION                        (MAC_FRAME_TYPE_MGT | 0x00D0)
#define MAC_FRAME_ACTION_NO_ACK                 (MAC_FRAME_TYPE_MGT | 0x00E0)

#define MAC_FRAME_CONTRL_WRAPPER                (MAC_FRAME_TYPE_CTRL | 0x0070)
#define MAC_FRAME_BLOCK_ACK_REQ                 (MAC_FRAME_TYPE_CTRL | 0x0080)
#define MAC_FRAME_BLOCK_ACK                     (MAC_FRAME_TYPE_CTRL | 0x0090)
#define MAC_FRAME_PS_POLL                       (MAC_FRAME_TYPE_CTRL | 0x00A0)
#define MAC_FRAME_RTS                           (MAC_FRAME_TYPE_CTRL | 0x00B0)
#define MAC_FRAME_CTS                           (MAC_FRAME_TYPE_CTRL | 0x00C0)
#define MAC_FRAME_ACK                           (MAC_FRAME_TYPE_CTRL | 0x00D0)
#define MAC_FRAME_CF_END                        (MAC_FRAME_TYPE_CTRL | 0x00E0)
#define MAC_FRAME_CF_END_CF_ACK                 (MAC_FRAME_TYPE_CTRL | 0x00F0)

#define MAC_FRAME_DATA                          (MAC_FRAME_TYPE_DATA | 0x0000)
#define MAC_FRAME_DATA_CF_ACK                   (MAC_FRAME_TYPE_DATA | 0x0010)
#define MAC_FRAME_DATA_CF_POLL                  (MAC_FRAME_TYPE_DATA | 0x0020)
#define MAC_FRAME_DATA_CF_ACK_CF_POLL           (MAC_FRAME_TYPE_DATA | 0x0030)
#define MAC_FRAME_NULL                          (MAC_FRAME_TYPE_DATA | 0x0040)
#define MAC_FRAME_CF_ACK                        (MAC_FRAME_TYPE_DATA | 0x0050)
#define MAC_FRAME_CF_POLL                       (MAC_FRAME_TYPE_DATA | 0x0060)
#define MAC_FRAME_CF_ACK_CF_POLL                (MAC_FRAME_TYPE_DATA | 0x0070)
#define MAC_FRAME_QOS_DATA                      (MAC_FRAME_TYPE_DATA | 0x0080)
#define MAC_FRAME_QOS_DATA_CF_ACK               (MAC_FRAME_TYPE_DATA | 0x0090)
#define MAC_FRAME_QOS_DATA_CF_POLL              (MAC_FRAME_TYPE_DATA | 0x00A0)
#define MAC_FRAME_QOS_DATA_CF_ACK_CF_POLL       (MAC_FRAME_TYPE_DATA | 0x00B0)
#define MAC_FRAME_QOS_NULL                      (MAC_FRAME_TYPE_DATA | 0x00C0)
#define MAC_FRAME_QOS_CF_POLL                   (MAC_FRAME_TYPE_DATA | 0x00E0)
#define MAC_FRAME_QOS_CF_ACK_CF_POLL            (MAC_FRAME_TYPE_DATA | 0x00F0)

/* 7.1.3.2 Mask for the AID value in the Duration/ID field */
#define MASK_DI_DURATION                        BITS(0, 14)
#define MASK_DI_AID                             BITS(0, 13)
#define MASK_DI_AID_MSB                         BITS(14, 15)
#define MASK_DI_CFP_FIXED_VALUE                 BIT(15)

/* 7.1.3.4 Masks for the subfields in the Sequence Control field */
#define MASK_SC_SEQ_NUM                         BITS(4, 15)
#define MASK_SC_SEQ_NUM_OFFSET                  4
#define MASK_SC_FRAG_NUM                        BITS(0, 3)
#define INVALID_SEQ_CTRL_NUM                    0x000F	/* According to 6.2.1.1.2
							 * FRAG_NUM won't equal to 15
							 */

/* 7.1.3.5 QoS Control field */
#define TID_NUM                                 16
#define TID_MASK                                BITS(0, 3)
#define EOSP                                    BIT(4)
#define ACK_POLICY                              BITS(5, 6)
#define A_MSDU_PRESENT                          BIT(7)

#define MASK_QC_TID                  BITS(0, 3)
#define MASK_QC_EOSP                 BIT(4)
#define MASK_QC_EOSP_OFFSET          4
#define MASK_QC_ACK_POLICY           BITS(5, 6)
#define MASK_QC_ACK_POLICY_OFFSET    5
#define MASK_QC_A_MSDU_PRESENT       BIT(7)

/* 7.1.3.5a HT Control field */
#define HT_CTRL_LINK_ADAPTATION_CTRL            BITS(0, 15)
#define HT_CTRL_CALIBRATION_POSITION            BITS(16, 17)
#define HT_CTRL_CALIBRATION_SEQUENCE            BITS(18, 19)
#define HT_CTRL_CSI_STEERING                    BITS(22, 23)
#define HT_CTRL_NDP_ANNOUNCEMENT                BIT(24)
#define HT_CTRL_AC_CONSTRAINT                   BIT(30)
#define HT_CTRL_RDG_MORE_PPDU                   BIT(31)

#define LINK_ADAPTATION_CTRL_TRQ                BIT(1)
#define LINK_ADAPTATION_CTRL_MAI_MRQ            BIT(2)
#define LINK_ADAPTATION_CTRL_MAI_MSI            BITS(3, 5)
#define LINK_ADAPTATION_CTRL_MFSI               BITS(6, 8)
#define LINK_ADAPTATION_CTRL_MFB_ASELC_CMD      BITS(9, 11)
#define LINK_ADAPTATION_CTRL_MFB_ASELC_DATA     BITS(12, 15)

/* 7.1.3.5.3 Ack Policy subfield*/
#define ACK_POLICY_NORMAL_ACK_IMPLICIT_BA_REQ 0
#define ACK_POLICY_NO_ACK 1
#define ACK_POLICY_NO_EXPLICIT_ACK_PSMP_ACK 2
#define ACK_POLICY_BA 3

/* 7.1.3.7 FCS field */
#define FCS_LEN                                 4

/* 7.2.1.4 WLAN Control Frame - PS-POLL Frame */
#define PSPOLL_FRAME_LEN                        16	/* w/o FCS */

/* 7.2.7.1 BAR */
#define OFFSET_BAR_SSC_SN                       4

/* 8.3.2.2 TKIP MPDU formats */
#define TKIP_MIC_LEN                            8

#define BA_POLICY_IMMEDIATE                     BIT(1)

/* Block Ack Starting Sequence Control field */
#define BA_START_SEQ_CTL_FRAG_NUM               BITS(0, 3)
#define BA_START_SEQ_CTL_SSN                    BITS(4, 15)

/* BAR Control field */
#define BAR_CONTROL_NO_ACK_POLICY               BIT(0)
#define BAR_CONTROL_MULTI_TID                   BIT(1)
#define BAR_CONTROL_COMPRESSED_BA               BIT(2)
#define BAR_CONTROL_TID_INFO                    BITS(12, 15)
#define BAR_CONTROL_TID_INFO_OFFSET             12

/* TID Value */
#define BAR_INFO_TID_VALUE                      BITS(12, 15)

#define BAR_COMPRESSED_VARIANT_FRAME_LEN        (16 + 4)

/* 3 --------------- IEEE 802.11 frame body fields --------------- */
/* 3 Management frame body components (I): Fixed Fields. */
/* 7.3.1.1 Authentication Algorithm Number field */
#define AUTH_ALGORITHM_NUM_FIELD_LEN                2

#define AUTH_ALGORITHM_NUM_OPEN_SYSTEM              0	/* Open System */
#define AUTH_ALGORITHM_NUM_SHARED_KEY               1	/* Shared Key */
#define AUTH_ALGORITHM_NUM_FAST_BSS_TRANSITION      2	/* Fast BSS Transition */
#if CFG_SUPPORT_CFG80211_AUTH
#define AUTH_ALGORITHM_NUM_SAE                      3	/* SAE */
#endif

/* 7.3.1.2 Authentication Transaction Sequence Number field */
#define AUTH_TRANSACTION_SEQENCE_NUM_FIELD_LEN      2
#define AUTH_TRANSACTION_SEQ_1                      1
#define AUTH_TRANSACTION_SEQ_2                      2
#define AUTH_TRANSACTION_SEQ_3                      3
#define AUTH_TRANSACTION_SEQ_4                      4

/* 7.3.1.3 Beacon Interval field */
#define BEACON_INTERVAL_FIELD_LEN                   2

/* 7.3.1.4 Capability Information field */
#define CAP_INFO_FIELD_LEN                          2
#define CAP_INFO_ESS                                BIT(0)
#define CAP_INFO_IBSS                               BIT(1)
#define CAP_INFO_BSS_TYPE                           (CAP_INFO_ESS | CAP_INFO_IBSS)
#define CAP_INFO_CF_POLLABLE                        BIT(2)
#define CAP_INFO_CF_POLL_REQ                        BIT(3)
#define CAP_INFO_CF                                 (CAP_INFO_CF_POLLABLE | CAP_INFO_CF_POLL_REQ)
#define CAP_INFO_PRIVACY                            BIT(4)
#define CAP_INFO_SHORT_PREAMBLE                     BIT(5)
#define CAP_INFO_PBCC                               BIT(6)
#define CAP_INFO_CH_AGILITY                         BIT(7)
#define CAP_INFO_SPEC_MGT                           BIT(8)
#define CAP_INFO_QOS                                BIT(9)
#define CAP_INFO_SHORT_SLOT_TIME                    BIT(10)
#define CAP_INFO_APSD                               BIT(11)
#define CAP_INFO_RESERVED                           BIT(12)
#define CAP_INFO_DSSS_OFDM                          BIT(13)
#define CAP_INFO_DELAYED_BLOCK_ACK                  BIT(14)
#define CAP_INFO_IMM_BLOCK_ACK                      BIT(15)
/* STA usage of CF-Pollable and CF-Poll Request subfields */
/* STA: not CF-Pollable */
#define CAP_CF_STA_NOT_POLLABLE                     0x0000
/* STA: CF-Pollable, not requesting on the CF-Polling list */
#define CAP_CF_STA_NOT_ON_LIST                      CAP_INFO_CF_POLL_REQ
/* STA: CF-Pollable, requesting on the CF-Polling list */
#define CAP_CF_STA_ON_LIST                          CAP_INFO_CF_POLLABLE
/* STA: CF-Pollable, requesting never to be polled */
#define CAP_CF_STA_NEVER_POLLED                     (CAP_INFO_CF_POLLABLE | CAP_INFO_CF_POLL_REQ)

/* AP usage of CF-Pollable and CF-Poll Request subfields */
/* AP: No point coordinator (PC) */
#define CAP_CF_AP_NO_PC                             0x0000
/* AP: PC at AP for delivery only (no polling) */
#define CAP_CF_AP_DELIVERY_ONLY                     CAP_INFO_CF_POLL_REQ
/* AP: PC at AP for delivery and polling */
#define CAP_CF_AP_DELIVERY_POLLING                  CAP_INFO_CF_POLLABLE

/* 7.3.1.5 Current AP Address field */
#define CURR_AP_ADDR_FIELD_LEN                      MAC_ADDR_LEN

/* 7.3.1.6 Listen Interval field */
#define LISTEN_INTERVAL_FIELD_LEN                   2

/* 7.3.1.7 Reason Code field */
#define REASON_CODE_FIELD_LEN                       2

#define REASON_CODE_RESERVED                        0	/* Reseved */
#define REASON_CODE_UNSPECIFIED                     1	/* Unspecified reason */
#define REASON_CODE_PREV_AUTH_INVALID               2	/* Previous auth no longer valid */
#define REASON_CODE_DEAUTH_LEAVING_BSS              3	/* Deauth because sending STA is leaving BSS */
#define REASON_CODE_DISASSOC_INACTIVITY             4	/* Disassoc due to inactivity */
#define REASON_CODE_DISASSOC_AP_OVERLOAD            5	/* Disassoc because AP is unable to handle all assoc STAs */
#define REASON_CODE_CLASS_2_ERR                     6	/* Class 2 frame rx from nonauth STA */
#define REASON_CODE_CLASS_3_ERR                     7	/* Class 3 frame rx from nonassoc STA */
#define REASON_CODE_DISASSOC_LEAVING_BSS            8	/* Disassoc because sending STA is leaving BSS */
#define REASON_CODE_ASSOC_BEFORE_AUTH               9	/* STA requesting (re)assoc is not auth with responding STA */
/* Disassoc because the info in Power Capability is unacceptable */
#define REASON_CODE_DISASSOC_PWR_CAP_UNACCEPTABLE   10
/* Disassoc because the info in Supported Channels is unacceptable */
#define REASON_CODE_DISASSOC_SUP_CHS_UNACCEPTABLE   11
#define REASON_CODE_INVALID_INFO_ELEM               13	/* Invalid information element */
#define REASON_CODE_MIC_FAILURE                     14	/* MIC failure */
#define REASON_CODE_4_WAY_HANDSHAKE_TIMEOUT         15	/* 4-way handshake timeout */
#define REASON_CODE_GROUP_KEY_UPDATE_TIMEOUT        16	/* Group key update timeout */
/* Info element in 4-way handshake different from */
/* (Re-)associate request/Probe response/Beacon */
#define REASON_CODE_DIFFERENT_INFO_ELEM             17
#define REASON_CODE_MULTICAST_CIPHER_NOT_VALID      18	/* Multicast Cipher is not valid */
#define REASON_CODE_UNICAST_CIPHER_NOT_VALID        19	/* Unicast Cipher is not valid */
#define REASON_CODE_AKMP_NOT_VALID                  20	/* AKMP is not valid */
#define REASON_CODE_UNSUPPORTED_RSNE_VERSION        21	/* Unsupported RSNE version */
#define REASON_CODE_INVALID_RSNE_CAPABILITIES       22	/* Invalid RSNE Capabilities */
#define REASON_CODE_IEEE_802_1X_AUTH_FAILED         23	/* IEEE 802.1X Authentication failed */
#define REASON_CODE_CIPHER_REJECT_SEC_POLICY        24	/* Cipher suite rejected because of the security policy */
#define REASON_CODE_DISASSOC_UNSPECIFIED_QOS        32	/* Disassoc for unspecified, QoS-related reason */
/* Disassoc because QAP lacks sufficient bandwidth for this QSTA */
#define REASON_CODE_DISASSOC_LACK_OF_BANDWIDTH      33
/* Disassoc because of too many ACKs lost for AP transmissions */
/* and/or poor channel conditions */
#define REASON_CODE_DISASSOC_ACK_LOST_POOR_CHANNEL  34
/* Disassoc because QSTA is transmitting outside the limits of its TXOPs */
#define REASON_CODE_DISASSOC_TX_OUTSIDE_TXOP_LIMIT  35
#define REASON_CODE_PEER_WHILE_LEAVING              36	/* QSTA is leaving the QBSS or resetting */
#define REASON_CODE_PEER_REFUSE_DLP                 37	/* Peer does not want to use this mechanism */
#define REASON_CODE_PEER_SETUP_REQUIRED             38	/* Frames received but a setup is reqired */
#define REASON_CODE_PEER_TIME_OUT                   39	/* Time out */
#define REASON_CODE_PEER_CIPHER_UNSUPPORTED         45	/* Peer does not support the requested cipher suite */
#define REASON_CODE_BEACON_TIMEOUT		    100	/* for beacon timeout, defined by mediatek */
/* 7.3.1.8 AID field */
#define AID_FIELD_LEN                               2
#define AID_MASK                                    BITS(0, 13)
#define AID_MSB                                     BITS(14, 15)
#define AID_MIN_VALUE                               1
#define AID_MAX_VALUE                               2007

/* 7.3.1.9 Status Code field */
#define STATUS_CODE_FIELD_LEN                       2

#define STATUS_CODE_RESERVED                        0	/* Reserved - Used by TX Auth */
#define STATUS_CODE_SUCCESSFUL                      0	/* Successful */
#define STATUS_CODE_UNSPECIFIED_FAILURE             1	/* Unspecified failure */
#define STATUS_CODE_CAP_NOT_SUPPORTED               10	/* Cannot support all requested cap in the Cap Info field */
/* Reassoc denied due to inability to confirm that assoc exists */
#define STATUS_CODE_REASSOC_DENIED_WITHOUT_ASSOC    11
#define STATUS_CODE_ASSOC_DENIED_OUTSIDE_STANDARD   12	/* Assoc denied due to reason outside the scope of this std. */
/* Responding STA does not support the specified auth algorithm */
#define STATUS_CODE_AUTH_ALGORITHM_NOT_SUPPORTED    13
/* Rx an auth frame with auth transaction seq num out of expected seq */
#define STATUS_CODE_AUTH_OUT_OF_SEQ                 14
#define STATUS_CODE_AUTH_REJECTED_CHAL_FAIL         15	/* Auth rejected because of challenge failure */
/* Auth rejected due to timeout waiting for next frame in sequence */
#define STATUS_CODE_AUTH_REJECTED_TIMEOUT           16
/* Assoc denied because AP is unable to handle additional assoc STAs */
#define STATUS_CODE_ASSOC_DENIED_AP_OVERLOAD        17
/* Assoc denied due to requesting STA not supporting all of basic rates */
#define STATUS_CODE_ASSOC_DENIED_RATE_NOT_SUPPORTED 18
/* Assoc denied due to requesting STA not supporting short preamble */
#define STATUS_CODE_ASSOC_DENIED_NO_SHORT_PREAMBLE  19
#define STATUS_CODE_ASSOC_DENIED_NO_PBCC            20	/* Assoc denied due to requesting STA not supporting PBCC */
/* Assoc denied due to requesting STA not supporting channel agility */
#define STATUS_CODE_ASSOC_DENIED_NO_CH_AGILITY      21
#define STATUS_CODE_ASSOC_REJECTED_NO_SPEC_MGT      22	/* Assoc rejected because Spectrum Mgt capability is required */
/* Assoc rejected because the info in Power Capability is unacceptable */
#define STATUS_CODE_ASSOC_REJECTED_PWR_CAP          23
/* Assoc rejected because the info in Supported Channels is unacceptable */
#define STATUS_CODE_ASSOC_REJECTED_SUP_CHS          24
/* Assoc denied due to requesting STA not supporting short slot time */
#define STATUS_CODE_ASSOC_DENIED_NO_SHORT_SLOT_TIME 25
/* Assoc denied due to requesting STA not supporting DSSS-OFDM */
#define STATUS_CODE_ASSOC_DENIED_NO_DSSS_OFDM       26
#if CFG_SUPPORT_802_11W
#define STATUS_CODE_ASSOC_REJECTED_TEMPORARILY      30	/*  IEEE 802.11w, Assoc denied due to the SA query */
/* IEEE 802.11w, Assoc denied due to the MFP select policy */
#define STATUS_CODE_ROBUST_MGMT_FRAME_POLICY_VIOLATION 31
#endif
#define STATUS_CODE_UNSPECIFIED_QOS_FAILURE         32	/* Unspecified, QoS-related failure */
/* Assoc denied due to insufficient bandwidth to handle another QSTA */
#define STATUS_CODE_ASSOC_DENIED_BANDWIDTH          33
/* Assoc denied due to excessive frame loss rates and/or poor channel conditions */
#define STATUS_CODE_ASSOC_DENIED_POOR_CHANNEL       34
/* Assoc denied due to requesting STA not supporting QoS facility */
#define STATUS_CODE_ASSOC_DENIED_NO_QOS_FACILITY    35
#define STATUS_CODE_REQ_DECLINED                    37	/* Request has been declined */
/* Request has not been successful as one or more parameters have invalid values */
#define STATUS_CODE_REQ_INVALID_PARAMETER_VALUE     38
/* TS not created because request cannot be honored. */
/* Suggested TSPEC provided. */
#define STATUS_CODE_REQ_NOT_HONORED_TSPEC           39
#define STATUS_CODE_INVALID_INFO_ELEMENT            40	/* Invalid information element */
#define STATUS_CODE_INVALID_GROUP_CIPHER            41	/* Invalid group cipher */
#define STATUS_CODE_INVALID_PAIRWISE_CIPHER         42	/* Invalid pairwise cipher */
#define STATUS_CODE_INVALID_AKMP                    43	/* Invalid AKMP */
#define STATUS_CODE_UNSUPPORTED_RSN_IE_VERSION      44	/* Unsupported RSN information element version */
#define STATUS_CODE_INVALID_RSN_IE_CAP              45	/* Invalid RSN information element capabilities */
#define STATUS_CODE_CIPHER_SUITE_REJECTED           46	/* Cipher suite rejected because of security policy */
/* TS not created because request cannot be honored. */
/* Attempt to create a TS later. */
#define STATUS_CODE_REQ_NOT_HONORED_TS_DELAY        47
#define STATUS_CODE_DIRECT_LINK_NOT_ALLOWED         48	/* Direct Link is not allowed in the BSS by policy */
#define STATUS_CODE_DESTINATION_STA_NOT_PRESENT     49	/* Destination STA is not present within this QBSS */
#define STATUS_CODE_DESTINATION_STA_NOT_QSTA        50	/* Destination STA is not a QSTA */
#define STATUS_CODE_ASSOC_DENIED_LARGE_LIS_INTERVAL 51	/* Association denied because the ListenInterval is too large */

/* proprietary definition of reserved field of Status Code */
#define STATUS_CODE_JOIN_FAILURE                    0xFFF0	/* Join failure */
#define STATUS_CODE_JOIN_TIMEOUT                    0xFFF1	/* Join timeout */
#define STATUS_CODE_AUTH_TIMEOUT                    0xFFF2	/* Authentication timeout */
#define STATUS_CODE_ASSOC_TIMEOUT                   0xFFF3	/* (Re)Association timeout */
#define STATUS_CODE_CCX_CCKM_REASSOC_FAILURE        0xFFF4	/* CCX CCKM reassociation failure */

/* 7.3.1.10 Timestamp field */
#define TIMESTAMP_FIELD_LEN                         8

/* 7.3.1.11 Category of Action field */
#define CATEGORY_SPEC_MGT                           0
#define CATEGORY_QOS_ACTION                         1	/* QoS action */
#define CATEGORY_DLS_ACTION                         2	/* Direct Link Protocol (DLP) action */
#define CATEGORY_BLOCK_ACK_ACTION                   3	/* Block ack action */
#define CATEGORY_PUBLIC_ACTION                      4	/* Public action */
#define CATEGORY_RM_ACTION                          5	/* Radio measurement action */
#define CATEGORY_HT_ACTION                          7
#if CFG_SUPPORT_802_11W
#define CATEGORY_SA_QUERY_ACTION                    8
#define CATEGORY_PROTECTED_DUAL_OF_PUBLIC_ACTION    9
#endif
#define CATEGORY_WNM_ACTION                         10	/* 802.11v Wireless Network Management */
#define CATEGORY_UNPROTECTED_WNM_ACTION             11	/* 802.11v Wireless Network Management */
#define CATEGORY_WME_MGT_NOTIFICATION               17	/* WME management notification */

#define CATEGORY_VHT_ACTION                         21	/* VHT action */

#if CFG_SUPPORT_802_11W
#define CATEGORY_VENDOR_SPECIFIC_ACTION_PROTECTED   126
#endif
#define CATEGORY_VENDOR_SPECIFIC_ACTION             127

/* 7.3.1.14 Block Ack Parameter Set field */
#define BA_PARAM_SET_ACK_POLICY_MASK                BIT(1)
#define BA_PARAM_SET_ACK_POLICY_MASK_OFFSET         1
#define BA_PARAM_SET_TID_MASK                       BITS(2, 5)
#define BA_PARAM_SET_TID_MASK_OFFSET                2
#define BA_PARAM_SET_BUFFER_SIZE_MASK               BITS(6, 15)
#define BA_PARAM_SET_BUFFER_SIZE_MASK_OFFSET        6

#define BA_PARAM_SET_ACK_POLICY_IMMEDIATE_BA        1
#define BA_PARAM_SET_ACK_POLICY_DELAYED_BA          0

/* 3 Management frame body components (II): Information Elements. */
/* 7.3.2 Element IDs of information elements */
#define ELEM_HDR_LEN                                2

#define ELEM_ID_SSID                                0	/* SSID */
#define ELEM_ID_SUP_RATES                           1	/* Supported rates */
#define ELEM_ID_FH_PARAM_SET                        2	/* FH parameter set */
#define ELEM_ID_DS_PARAM_SET                        3	/* DS parameter set */
#define ELEM_ID_CF_PARAM_SET                        4	/* CF parameter set */
#define ELEM_ID_TIM                                 5	/* TIM */
#define ELEM_ID_IBSS_PARAM_SET                      6	/* IBSS parameter set */
#define ELEM_ID_COUNTRY_INFO                        7	/* Country information */
#define ELEM_ID_HOPPING_PATTERN_PARAM               8	/* Hopping pattern parameters */
#define ELEM_ID_HOPPING_PATTERN_TABLE               9	/* Hopping pattern table */
#define ELEM_ID_REQUEST                             10	/* Request */
#define ELEM_ID_BSS_LOAD                            11	/* BSS load */
#define ELEM_ID_EDCA_PARAM_SET                      12	/* EDCA parameter set */
#define ELEM_ID_TSPEC                               13	/* Traffic specification (TSPEC) */
#define ELEM_ID_TCLAS                               14	/* Traffic classification (TCLAS) */
#define ELEM_ID_SCHEDULE                            15	/* Schedule */
#define ELEM_ID_CHALLENGE_TEXT                      16	/* Challenge text */

#define ELEM_ID_PWR_CONSTRAINT                      32	/* Power constraint */
#define ELEM_ID_PWR_CAP                             33	/* Power capability */
#define ELEM_ID_TPC_REQ                             34	/* TPC request */
#define ELEM_ID_TPC_REPORT                          35	/* TPC report */
#define ELEM_ID_SUP_CHS                             36	/* Supported channels */
#define ELEM_ID_CH_SW_ANNOUNCEMENT                  37	/* Channel switch announcement */
#define ELEM_ID_MEASUREMENT_REQ                     38	/* Measurement request */
#define ELEM_ID_MEASUREMENT_REPORT                  39	/* Measurement report */
#define ELEM_ID_QUIET                               40	/* Quiet */
#define ELEM_ID_IBSS_DFS                            41	/* IBSS DFS */
#define ELEM_ID_ERP_INFO                            42	/* ERP information */
#define ELEM_ID_TS_DELAY                            43	/* TS delay */
#define ELEM_ID_TCLAS_PROCESSING                    44	/* TCLAS processing */
#define ELEM_ID_HT_CAP                              45	/* HT Capabilities subelement */
#define ELEM_ID_QOS_CAP                             46	/* QoS capability */
#define ELEM_ID_RSN                                 48	/* RSN IE */
#define ELEM_ID_EXTENDED_SUP_RATES                  50	/* Extended supported rates */
#if CFG_SUPPORT_802_11W
#define ELEM_ID_TIMEOUT_INTERVAL                    56	/* 802.11w SA Timeout interval */
#endif
#define ELEM_ID_SUP_OPERATING_CLASS					59	/* Supported Operating Classes */

#define ELEM_ID_HT_OP                               61	/* HT Operation */
#define ELEM_ID_SCO                                 62	/* Secondary Channel Offset */
#define ELEM_ID_RRM_ENABLED_CAP                     70	/* Radio Resource Management Enabled Capabilities */
#define ELEM_ID_20_40_BSS_COEXISTENCE               72	/* 20/40 BSS Coexistence */
#define ELEM_ID_20_40_INTOLERANT_CHNL_REPORT        73	/* 20/40 BSS Intolerant Channel Report */
#define ELEM_ID_OBSS_SCAN_PARAMS                    74	/* Overlapping BSS Scan Parameters */
#define ELEM_ID_EXTENDED_CAP                        127	/* Extended capabilities */

#define ELEM_ID_INTERWORKING                        107	/* Interworking with External Network */
#define ELEM_ID_ADVERTISEMENT_PROTOCOL              108	/* Advertisement Protocol */
#define ELEM_ID_ROAMING_CONSORTIUM                  111	/* Roaming Consortium */
#define ELEM_ID_EXTENDED_CAP                        127	/* Extended capabilities */

#define ELEM_ID_VENDOR                              221	/* Vendor specific IE */
#define ELEM_ID_WPA                                 ELEM_ID_VENDOR	/* WPA IE */
#define ELEM_ID_WMM                                 ELEM_ID_VENDOR	/* WMM IE */
#define ELEM_ID_P2P                                 ELEM_ID_VENDOR	/* WiFi Direct */
#define ELEM_ID_WSC                                 ELEM_ID_VENDOR	/* WSC IE */

#define ELEM_ID_VHT_CAP                             191	/* VHT Capabilities subelement */
#define ELEM_ID_VHT_OP                              192	/* VHT Operation information */
#define ELEM_ID_WIDE_BAND_CHANNEL_SWITCH            194	/*Wide Bandwidth Channel Switch */
#define ELEM_ID_OP_MODE                             199	/* Operation Mode Notification */
#define ELEM_ID_RESERVED                            255	/* Reserved */

/* 7.3.2.1 SSID element */
#define ELEM_MAX_LEN_SSID                           32

/* 7.3.2.2 Supported Rates */
#define ELEM_MAX_LEN_SUP_RATES                      8

/* 7.3.2.4 DS Parameter Set */
#define ELEM_MAX_LEN_DS_PARAMETER_SET               1

/* 7.3.2.5 CF Parameter Set */
#define ELEM_CF_PARM_LEN                            8

/* 7.3.2.6 TIM */
#define ELEM_MIX_LEN_TIM                            4
#define ELEM_MAX_LEN_TIM                            254

/* 7.3.2.7 IBSS Parameter Set element */
#define ELEM_MAX_LEN_IBSS_PARAMETER_SET             2

/* 7.3.2.8 Challenge Text element */
#define ELEM_MIN_LEN_CHALLENGE_TEXT                 1
#define ELEM_MAX_LEN_CHALLENGE_TEXT                 253

/* 7.3.2.9 Country Information element */
/* Country IE should contain at least 3-bytes country code string and one subband triplet. */
#define ELEM_MIN_LEN_COUNTRY_INFO                   6

#define ELEM_ID_COUNTRY_INFO_TRIPLET_LEN_FIXED              3
#define ELEM_ID_COUNTRY_INFO_SUBBAND_TRIPLET_LEN_FIXED      3
#define ELEM_ID_COUNTRY_INFO_REGULATORY_TRIPLET_LEN_FIXED   3

/* 7.3.2.13 ERP Information element */
#define ELEM_MAX_LEN_ERP                            1
/* -- bits in the ERP Information element */
#define ERP_INFO_NON_ERP_PRESENT                    BIT(0)	/* NonERP_Present bit */
#define ERP_INFO_USE_PROTECTION                     BIT(1)	/* Use_Protection bit */
#define ERP_INFO_BARKER_PREAMBLE_MODE               BIT(2)	/* Barker_Preamble_Mode bit */

#define ELEM_MAX_LEN_SUPPORTED_CHANNELS            (MAX_CHN_NUM * 2)

/* 7.3.2.14 Extended Supported Rates */
#define ELEM_MAX_LEN_EXTENDED_SUP_RATES             255

/* 7.3.2.16 Power Capability element */
#define ELEM_MAX_LEN_POWER_CAP                      2


/* 7.3.2.21 Measurement Request element */
#define ELEM_RM_TYPE_BASIC_REQ                      0
#define ELEM_RM_TYPE_CCA_REQ                        1
#define ELEM_RM_TYPE_RPI_HISTOGRAM_REQ              2
#define ELEM_RM_TYPE_CHNL_LOAD_REQ                  3
#define ELEM_RM_TYPE_NOISE_HISTOGRAM_REQ            4
#define ELEM_RM_TYPE_BEACON_REQ                     5
#define ELEM_RM_TYPE_FRAME_REQ                      6
#define ELEM_RM_TYPE_STA_STATISTICS_REQ             7
#define ELEM_RM_TYPE_LCI_REQ                        8
#define ELEM_RM_TYPE_TS_REQ                         9
#define ELEM_RM_TYPE_MEASURE_PAUSE_REQ              255

/* 7.3.2.22 Measurement Report element */
#define ELEM_RM_TYPE_BASIC_REPORT                   0
#define ELEM_RM_TYPE_CCA_REPORT                     1
#define ELEM_RM_TYPE_RPI_HISTOGRAM_REPORT           2
#define ELEM_RM_TYPE_CHNL_LOAD_REPORT               3
#define ELEM_RM_TYPE_NOISE_HISTOGRAM_REPORT         4
#define ELEM_RM_TYPE_BEACON_REPORT                  5
#define ELEM_RM_TYPE_FRAME_REPORT                   6
#define ELEM_RM_TYPE_STA_STATISTICS_REPORT          7
#define ELEM_RM_TYPE_LCI_REPORT                     8
#define ELEM_RM_TYPE_TS_REPORT                      9

/* 7.3.2.25 RSN information element */
#define ELEM_MAX_LEN_WPA                            34	/* one pairwise, one AKM suite, one PMKID */
#define ELEM_MAX_LEN_RSN                            38	/* one pairwise, one AKM suite, one PMKID */
#define ELEM_MAX_LEN_WAPI                           38	/* one pairwise, one AKM suite, one BKID */
#define ELEM_MAX_LEN_WSC                            200	/* one pairwise, one AKM suite, one BKID */

/* 802.11i */
/* length of one PMKID */
#define RSN_PMKID_LEN                               16

#if CFG_SUPPORT_802_11W
#define ELEM_WPA_CAP_MFPR                           BIT(6)
#define ELEM_WPA_CAP_MFPC                           BIT(7)
#endif

/* 7.3.2.27 Extended Capabilities information element */
#define ELEM_EXT_CAP_20_40_COEXIST_SUPPORT          BIT(0)
#define ELEM_EXT_CAP_PSMP_CAP                       BIT(4)
#define ELEM_EXT_CAP_SERVICE_INTERVAL_GRANULARITY   BIT(5)
#define ELEM_EXT_CAP_SCHEDULE_PSMP                  BIT(6)

#define ELEM_EXT_CAP_BSS_TRANSITION_BIT             19
#define ELEM_EXT_CAP_UTC_TSF_OFFSET_BIT             27
#define ELEM_EXT_CAP_INTERWORKING_BIT               31
#define ELEM_EXT_CAP_WNM_NOTIFICATION_BIT           46
#define ELEM_EXT_CAP_OP_MODE_NOTIFICATION_BIT       62

#define ELEM_MAX_LEN_EXT_CAP                        (8)

/* 7.3.2.30 TSPEC element */
#define TS_INFO_TRAFFIC_TYPE_MASK                   BIT(0)	/* WMM: 0 (Asynchronous TS of low-duty cycles) */
#define TS_INFO_TID_OFFSET                          1
#define TS_INFO_TID_MASK                            BITS(1, 4)
#define TS_INFO_DIRECTION_OFFSET                    5
#define TS_INFO_DIRECTION_MASK                      BITS(5, 6)
#define TS_INFO_ACCESS_POLICY_OFFSET                7
#define TS_INFO_ACCESS_POLICY_MASK                  BITS(7, 8)
#define TS_INFO_AGGREGATION_MASK                    BIT(9)	/* WMM: 0 */
#define TS_INFO_APSD_MASK                           BIT(10)
#define TS_INFO_UP_OFFSET                           11
#define TS_INFO_UP_MASK                             BITS(11, 13)
#define TS_INFO_ACK_POLICY_OFFSET                   14
#define TS_INFO_ACK_POLICY_MASK                     BITS(14, 15)
#define TS_INFO_SCHEDULE_MASK                       16

/* 7.3.2.56 HT capabilities element */
#define ELEM_MAX_LEN_HT_CAP                         (28 - ELEM_HDR_LEN)	/* sizeof(IE_HT_CAP_T)-2 */

/* 7.3.2.56.2 HT capabilities Info field */
#define HT_CAP_INFO_LDPC_CAP                        BIT(0)
#define HT_CAP_INFO_SUP_CHNL_WIDTH                  BIT(1)
#define HT_CAP_INFO_SM_POWER_SAVE                   BITS(2, 3)
#define HT_CAP_INFO_SM_POWER_SAVE_OFFSET            2
#define HT_CAP_INFO_HT_GF                           BIT(4)
#define HT_CAP_INFO_SHORT_GI_20M                    BIT(5)
#define HT_CAP_INFO_SHORT_GI_40M                    BIT(6)
#define HT_CAP_INFO_TX_STBC                         BIT(7)
#define HT_CAP_INFO_RX_STBC                         BITS(8, 9)
#define HT_CAP_INFO_HT_DELAYED_BA                   BIT(10)
#define HT_CAP_INFO_MAX_AMSDU_LEN                   BIT(11)
#define HT_CAP_INFO_DSSS_CCK_IN_40M                 BIT(12)
#define HT_CAP_INFO_40M_INTOLERANT                  BIT(14)
#define HT_CAP_INFO_LSIG_TXOP_SUPPORT               BIT(15)

#define HT_CAP_INFO_RX_STBC_NO_SUPPORTED            0
#define HT_CAP_INFO_RX_STBC_1_SS                    BIT(8)
#define HT_CAP_INFO_RX_STBC_2_SS                    BIT(9)
#define HT_CAP_INFO_RX_STBC_3_SS                    HT_CAP_INFO_RX_STBC

#define ELEM_MAX_LEN_VHT_CAP                         (14 - ELEM_HDR_LEN)	/* sizeof(IE_VHT_CAP_T)-2 */
/* 8.4.2.161 VHT Operation element */
#define ELEM_MAX_LEN_VHT_OP                          (7 - ELEM_HDR_LEN)	/* sizeof(IE_VHT_OP_T)-2 */

#define ELEM_MAX_LEN_VHT_OP_MODE_NOTIFICATION        (3 - ELEM_HDR_LEN)	/* sizeof(IE_VHT_OP_MODE_T)-2 */

/*8.4.2.160.3 VHT Supported MCS Set field*/

/*8.4.2.160.2 VHT Capabilities Info field*/
#define VHT_CAP_INFO_MAX_MPDU_LEN_3K							0
#define VHT_CAP_INFO_MAX_MPDU_LEN_8K							BIT(0)
#define VHT_CAP_INFO_MAX_MPDU_LEN_11K						    BIT(1)
#define VHT_CAP_INFO_MAX_MPDU_LEN_MASK							BITS(0, 1)

#define VHT_CAP_INFO_MAX_SUP_CHANNEL_WIDTH_SET_NONE				0
#define VHT_CAP_INFO_MAX_SUP_CHANNEL_WIDTH_SET_160				BIT(2)
#define VHT_CAP_INFO_MAX_SUP_CHANNEL_WIDTH_SET_160_80P80		BIT(3)
#define VHT_CAP_INFO_MAX_SUP_CHANNEL_WIDTH_MASK					BITS(2, 3)

#define VHT_CAP_INFO_RX_LDPC									BIT(4)
#define VHT_CAP_INFO_SHORT_GI_80								BIT(5)
#define VHT_CAP_INFO_SHORT_GI_160_80P80							BIT(6)
#define VHT_CAP_INFO_TX_STBC									BIT(7)

#define VHT_CAP_INFO_RX_STBC_NONE								0
#define VHT_CAP_INFO_RX_STBC_MASK								BITS(8, 10)
#define VHT_CAP_INFO_RX_STBC_OFFSET								8
#define VHT_CAP_INFO_RX_STBC_ONE_STREAM							BIT(8)
#define VHT_CAP_INFO_RX_STBC_TWO_STREAM							BIT(9)
#define VHT_CAP_INFO_RX_STBC_THREE_STREAM						BITS(8, 9)
#define VHT_CAP_INFO_RX_STBC_FOUR_STREAM						BIT(10)

#define VHT_CAP_INFO_SU_BEAMFORMER_CAPABLE						BIT(11)
#define VHT_CAP_INFO_SU_BEAMFORMEE_CAPABLE						BIT(12)
#define VHT_CAP_INFO_SU_BEAMFORMEE_CAPABLE_OFFSET			12

#define VHT_CAP_INFO_COMP_STEERING_NUM_OF_BFER_ANT_SUP_OFFSET 13
#define VHT_CAP_INFO_COMP_STEERING_NUM_OF_BFER_ANT_SUP BITS(13, 15)
#define VHT_CAP_INFO_COMPRESSED_STEERING_NUMBER_OF_BEAMFORMER_ANTENNAS_2_SUPPOERTED BIT(13)
#define VHT_CAP_INFO_COMPRESSED_STEERING_NUMBER_OF_BEAMFORMER_ANTENNAS_3_SUPPOERTED BIT(14)
#define VHT_CAP_INFO_COMPRESSED_STEERING_NUMBER_OF_BEAMFORMER_ANTENNAS_4_SUPPOERTED BITS(13, 14)

#define VHT_CAP_INFO_NUMBER_OF_SOUNDING_DIMENSIONS_OFFSET		16
#define VHT_CAP_INFO_NUMBER_OF_SOUNDING_DIMENSIONS				BITS(16, 18)
#define VHT_CAP_INFO_NUMBER_OF_SOUNDING_DIMENSIONS_2_SUPPORTED	BIT(16)
#define VHT_CAP_INFO_NUMBER_OF_SOUNDING_DIMENSIONS_3_SUPPORTED	BIT(17)
#define VHT_CAP_INFO_NUMBER_OF_SOUNDING_DIMENSIONS_4_SUPPORTED	BITS(16, 17)

#define	VHT_CAP_INFO_MU_BEAMFOMER_CAPABLE						BIT(19)
#define VHT_CAP_INFO_MU_BEAMFOMEE_CAPABLE						BIT(20)
#define VHT_CAP_INFO_VHT_TXOP_PS								BIT(21)
#define VHT_CAP_INFO_HTC_VHT_CAPABLE							BIT(22)

#define VHT_CAP_INFO_MAX_AMPDU_LENGTH_OFFSET                    23

#define VHT_CAP_INFO_VHT_LINK_ADAPTATION_CAPABLE_NOFEEDBACK				0
#define VHT_CAP_INFO_VHT_LINK_ADAPTATION_CAPABLE_UNSOLICITED				BITS(27)
#define VHT_CAP_INFO_VHT_LINK_ADAPTATION_CAPABLE_BOTH						BITS(26, 27)

#define VHT_CAP_INFO_RX_ANTENNA_PATTERN_CONSISTENCY			BIT(28)
#define VHT_CAP_INFO_TX_ANTENNA_PATTERN_CONSISTENCY			BIT(29)

#define VHT_CAP_INFO_MCS_MAP_MCS7								0
#define VHT_CAP_INFO_MCS_MAP_MCS8								BIT(0)
#define VHT_CAP_INFO_MCS_MAP_MCS9								BIT(1)
#define VHT_CAP_INFO_MCS_NOT_SUPPORTED							BITS(0, 1)

#define VHT_CAP_INFO_MCS_1SS_OFFSET						0
#define VHT_CAP_INFO_MCS_2SS_OFFSET						2
#define VHT_CAP_INFO_MCS_3SS_OFFSET						4
#define VHT_CAP_INFO_MCS_4SS_OFFSET						6
#define VHT_CAP_INFO_MCS_5SS_OFFSET						8
#define VHT_CAP_INFO_MCS_6SS_OFFSET						10
#define VHT_CAP_INFO_MCS_7SS_OFFSET						12
#define VHT_CAP_INFO_MCS_8SS_OFFSET						14

#define VHT_CAP_INFO_MCS_1SS_MASK						BITS(0, 1)
#define VHT_CAP_INFO_MCS_2SS_MASK						BITS(2, 3)
#define VHT_CAP_INFO_MCS_3SS_MASK						BITS(4, 5)
#define VHT_CAP_INFO_MCS_4SS_MASK						BITS(6, 7)
#define VHT_CAP_INFO_MCS_5SS_MASK						BITS(8, 9)
#define VHT_CAP_INFO_MCS_6SS_MASK						BITS(10, 11)
#define VHT_CAP_INFO_MCS_7SS_MASK						BITS(12, 13)
#define VHT_CAP_INFO_MCS_8SS_MASK						BITS(14, 15)

#define VHT_OP_CHANNEL_WIDTH_20_40						0
#define VHT_OP_CHANNEL_WIDTH_80							1
#define VHT_OP_CHANNEL_WIDTH_160						2
#define VHT_OP_CHANNEL_WIDTH_80P80						3

/*8.4.1.50 Operating Mode Field*/
#define VHT_OP_MODE_CHANNEL_WIDTH                   BITS(0, 1)
#define VHT_OP_MODE_RX_NSS                          BITS(4, 6)
#define VHT_OP_MODE_RX_NSS_TYPE                     BIT(7)

#define VHT_OP_MODE_CHANNEL_WIDTH_OFFSET                   0
#define VHT_OP_MODE_RX_NSS_OFFSET                   4
#define VHT_OP_MODE_RX_NSS_TYPE_OFFSET              7

#define VHT_OP_MODE_CHANNEL_WIDTH_20                0
#define VHT_OP_MODE_CHANNEL_WIDTH_40                1
#define VHT_OP_MODE_CHANNEL_WIDTH_80                2
#define VHT_OP_MODE_CHANNEL_WIDTH_160_80P80         3

/* 8.4.1.22 SM Power Control field*/
#define HT_SM_POWER_SAVE_CONTROL_ENABLED            BIT(0)
#define HT_SM_POWER_SAVE_CONTROL_SM_MODE            BIT(1) /* 0:static, 1:dynamic */
#define HT_SM_POWER_SAVE_CONTROL_SM_MODE_OFFSET     1

/* 8.4.1.21 Channel Width field */
#define HT_NOTIFY_CHANNEL_WIDTH_20				0
#define HT_NOTIFY_CHANNEL_WIDTH_ANY_SUPPORT_CAHNNAEL_WIDTH	1

/* 7.3.2.56.3 A-MPDU Parameters field */
#define AMPDU_PARAM_MAX_AMPDU_LEN_EXP               BITS(0, 1)
#define AMPDU_PARAM_MIN_START_SPACING               BITS(2, 4)

#define AMPDU_PARAM_MAX_AMPDU_LEN_8K                0
#define AMPDU_PARAM_MAX_AMPDU_LEN_16K               BIT(0)
#define AMPDU_PARAM_MAX_AMPDU_LEN_32K               BIT(1)
#define AMPDU_PARAM_MAX_AMPDU_LEN_64K               BITS(0, 1)
#define AMPDU_PARAM_MAX_AMPDU_LEN_128K              BIT(2)
#define AMPDU_PARAM_MAX_AMPDU_LEN_256K              (BIT(2) | BIT(0))
#define AMPDU_PARAM_MAX_AMPDU_LEN_512K              BITS(1, 2)
#define AMPDU_PARAM_MAX_AMPDU_LEN_1024K             BITS(0, 2)

#define AMPDU_PARAM_MSS_NO_RESTRICIT                0
#define AMPDU_PARAM_MSS_1_4_US                      BIT(2)
#define AMPDU_PARAM_MSS_1_2_US                      BIT(3)
#define AMPDU_PARAM_MSS_1_US                        BITS(2, 3)
#define AMPDU_PARAM_MSS_2_US                        BIT(4)
#define AMPDU_PARAM_MSS_4_US                        (BIT(4) | BIT(2))
#define AMPDU_PARAM_MSS_8_US                        (BIT(4) | BIT(3))
#define AMPDU_PARAM_MSS_16_US                       BITS(2, 4)

/* 7.3.2.56.4 Supported MCS Set field (TX rate: octects 12~15) */
#define SUP_MCS_TX_SET_DEFINED                      BIT(0)
#define SUP_MCS_TX_RX_SET_NOT_EQUAL                 BIT(1)
#define SUP_MCS_TX_MAX_NUM_SS                       BITS(2, 3)
#define SUP_MCS_TX_UNEQUAL_MODULATION               BIT(4)

#define SUP_MCS_TX_MAX_NUM_1_SS                     0
#define SUP_MCS_TX_MAX_NUM_2_SS                     BIT(2)
#define SUP_MCS_TX_MAX_NUM_3_SS                     BIT(3)
#define SUP_MCS_TX_MAX_NUM_4_SS                     BITS(2, 3)

#define SUP_MCS_RX_BITMASK_OCTET_NUM                10
#define SUP_MCS_RX_DEFAULT_HIGHEST_RATE             0	/* Not specify */

/* 7.3.2.56.5 HT Extended Capabilities field */
#define HT_EXT_CAP_PCO                              BIT(0)
#define HT_EXT_CAP_PCO_TRANSITION_TIME              BITS(1, 2)
#define HT_EXT_CAP_MCS_FEEDBACK                     BITS(8, 9)
#define HT_EXT_CAP_HTC_SUPPORT                      BIT(10)
#define HT_EXT_CAP_RD_RESPONDER                     BIT(11)

#define HT_EXT_CAP_PCO_TRANS_TIME_NONE              0
#define HT_EXT_CAP_PCO_TRANS_TIME_400US             BIT(1)
#define HT_EXT_CAP_PCO_TRANS_TIME_1_5MS             BIT(2)
#define HT_EXT_CAP_PCO_TRANS_TIME_5MS               BITS(1, 2)

#define HT_EXT_CAP_MCS_FEEDBACK_NO_FB               0
#define HT_EXT_CAP_MCS_FEEDBACK_UNSOLICITED         BIT(9)
#define HT_EXT_CAP_MCS_FEEDBACK_BOTH                BITS(8, 9)

/* 7.3.2.56.6 Transmit Beamforming Capabilities field */
#define TXBF_IMPLICIT_RX_CAPABLE                    BIT(0)
#define TXBF_RX_STAGGERED_SOUNDING_CAPABLE          BIT(1)
#define TXBF_TX_STAGGERED_SOUNDING_CAPABLE          BIT(2)
#define TXBF_RX_NDP_CAPABLE_OFFSET                  3
#define TXBF_RX_NDP_CAPABLE                         BIT(3)
#define TXBF_TX_NDP_CAPABLE                         BIT(4)
#define TXBF_IMPLICIT_TX_CAPABLE                    BIT(5)
#define TXBF_CALIBRATION_CAPABLE                    BITS(6, 7)
#define TXBF_EXPLICIT_CSI_TX_CAPABLE                BIT(8)
#define TXBF_EXPLICIT_NONCOMPRESSED_TX_CAPABLE      BIT(9)
#define TXBF_EXPLICIT_COMPRESSED_TX_CAPAB           BIT(10)
#define TXBF_EXPLICIT_CSI_FEEDBACK_CAPABLE          BITS(11, 12)
#define TXBF_EXPLICIT_NONCOMPRESSED_FEEDBACK_CAPABLE BITS(13, 14)

#define TXBF_EXPLICIT_COMPRESSED_FEEDBACK_CAPABLE_OFFSET 15
#define TXBF_EXPLICIT_COMPRESSED_FEEDBACK_CAPABLE   BITS(15, 16)
#define TXBF_EXPLICIT_COMPRESSED_FEEDBACK_IMMEDIATE_CAPABLE BIT(16)

#define TXBF_MINIMAL_GROUPING_CAPABLE               BITS(17, 18)
#define TXBF_MINIMAL_GROUPING_1_2_3_CAPABLE         BITS(17, 18)

#define TXBF_CSI_BFER_ANTENNANUM_SUPPORTED          BITS(19, 20)
#define TXBF_NONCOMPRESSED_TX_ANTENNANUM_SUPPORTED  BITS(21, 22)

#define TXBF_COMPRESSED_TX_ANTENNANUM_SUPPORTED_OFFSET  23
#define TXBF_COMPRESSED_TX_ANTENNANUM_SUPPORTED     BITS(23, 24)
#define TXBF_COMPRESSED_TX_ANTENNANUM_4_SUPPORTED   BITS(23, 24)

#define TXBF_CSI_MAX_ROWS_BFER_SUPPORTED            BITS(25, 26)

#define TXBF_CHANNEL_ESTIMATION_CAPABILITY          BITS(27, 28)
#define TXBF_CHANNEL_ESTIMATION_4STS_CAPABILITY     BITS(27, 28)

/* 7.3.2.56.7 Antenna Selection Capability field */
#define ASEL_CAP_CAPABLE                            BIT(0)
#define ASEL_CAP_CSI_FB_BY_TX_ASEL_CAPABLE          BIT(1)
#define ASEL_CAP_ANT_INDICES_FB_BY_TX_ASEL_CAPABLE  BIT(2)
#define ASEL_CAP_EXPLICIT_CSI_FB_CAPABLE            BIT(3)
#define ASEL_CAP_ANT_INDICES_CAPABLE                BIT(4)
#define ASEL_CAP_RX_ASEL_CAPABLE                    BIT(5)
#define ASEL_CAP_TX_SOUNDING_CAPABLE                BIT(6)

/* 7.3.2.57 HT Operation element */
#define ELEM_MAX_LEN_HT_OP                          (24 - ELEM_HDR_LEN)	/* sizeof(IE_HT_OP_T)-2 */

#define HT_OP_INFO1_SCO                             BITS(0, 1)
#define HT_OP_INFO1_STA_CHNL_WIDTH                  BIT(2)
#define HT_OP_INFO1_RIFS_MODE                       BIT(3)

#define HT_OP_INFO2_HT_PROTECTION                   BITS(0, 1)
#define HT_OP_INFO2_NON_GF_HT_STA_PRESENT           BIT(2)
#define HT_OP_INFO2_OBSS_NON_HT_STA_PRESENT         BIT(4)

#define HT_OP_INFO3_DUAL_BEACON                     BIT(6)
#define HT_OP_INFO3_DUAL_CTS_PROTECTION             BIT(7)
#define HT_OP_INFO3_STBC_BEACON                     BIT(8)
#define HT_OP_INFO3_LSIG_TXOP_FULL_SUPPORT          BIT(9)
#define HT_OP_INFO3_PCO_ACTIVE                      BIT(10)
#define HT_OP_INFO3_PCO_PHASE                       BIT(11)

/* 7.3.2.59 OBSS Scan Parameter element */
#define ELEM_MAX_LEN_OBSS_SCAN                      (16 - ELEM_HDR_LEN)

/* 7.3.2.60 20/40 BSS Coexistence element */
#define ELEM_MAX_LEN_20_40_BSS_COEXIST              (3 - ELEM_HDR_LEN)

#define BSS_COEXIST_INFO_REQ                        BIT(0)
#define BSS_COEXIST_40M_INTOLERANT                  BIT(1)
#define BSS_COEXIST_20M_REQ                         BIT(2)
#define BSS_COEXIST_OBSS_SCAN_EXEMPTION_REQ         BIT(3)
#define BSS_COEXIST_OBSS_SCAN_EXEMPTION_GRANT       BIT(4)

/* 802.11u 7.3.2.92 Interworking IE */
#define ELEM_MAX_LEN_INTERWORKING                   (11 - ELEM_HDR_LEN)

/* 802.11u 7.3.2.93 Advertisement Protocol IE */
#define ELEM_MAX_LEN_ADV_PROTOCOL                   (4 - ELEM_HDR_LEN)

/* 802.11u 7.3.2.96 Roaming Consortium IE */
#define ELEM_MAX_LEN_ROAMING_CONSORTIUM             (19 - ELEM_HDR_LEN)

#define IW_IE_LENGTH_ANO                            1
#define IW_IE_LENGTH_ANO_VENUE                      3
#define IW_IE_LENGTH_ANO_HESSID                     7
#define IW_IE_LENGTH_ANO_VENUE_HESSID               9

#if CFG_SUPPORT_PASSPOINT
/* HOTSPOT 2.0 Indication IE*/
#define ELEM_MAX_LEN_HS20_INDICATION                5
#define ELEM_MIN_LEN_HS20_INDICATION                4

/* Hotspot Configuration*/
#define ELEM_HS_CONFIG_DGAF_DISABLED_MASK           BIT(0)	/* Downstream Group-Addressed Forwarding */
#endif /* CFG_SUPPORT_PASSPOINT */

/* MTK Vendor Specific OUI */
#define ELEM_MIN_LEN_MTK_OUI                        7
#define VENDOR_OUI_MTK                              { 0x00, 0x0C, 0xE7 }
#define MTK_SYNERGY_CAP_SUPPORT_24G_MCS89           BIT(3)
#define MTK_SYNERGY_CAP0                            (MTK_SYNERGY_CAP_SUPPORT_24G_MCS89)
#define MTK_SYNERGY_CAP1                            0x0
#define MTK_SYNERGY_CAP2                            0x0
#define MTK_SYNERGY_CAP3                            0x0

/* 802.11h CSA element */
#define ELEM_MIN_LEN_CSA                            3

/* 3 Management frame body components (III): 7.4 Action frame format details. */
/* 7.4.1 Spectrum Measurement Action frame details */
#define ACTION_MEASUREMENT_REQ                      0	/* Spectrum measurement request */
#define ACTION_MEASUREMENT_REPORT                   1	/* Spectrum measurement report */
#define ACTION_TPC_REQ                              2	/* TPC request */
#define ACTION_TPC_REPORT                           3	/* TPC report */
#define ACTION_CHNL_SWITCH                          4	/* Channel Switch Announcement */

#define ACTION_SM_TPC_REQ_LEN                       5
#define ACTION_SM_TPC_REPORT_LEN                    7
#define ACTION_SM_MEASURE_REQ_LEN                   19
#define ACTION_SM_MEASURE_REPORT_LEN                8
#define ACTION_SM_BASIC_REPORT_LEN                  12
#define ACTION_SM_CCA_REPORT_LEN                    12
#define ACTION_SM_PRI_REPORT_LEN                    19
#define MIN_RCV_PWR                                 100 /* Negative value ((dBm) */

/* 7.4.2 QoS Action frame details */
#define ACTION_ADDTS_REQ                            0	/* ADDTS request */
#define ACTION_ADDTS_RSP                            1	/* ADDTS response */
#define ACTION_DELTS                                2	/* DELTS */
#define ACTION_SCHEDULE                             3	/* Schedule */

#define ACTION_ADDTS_REQ_FRAME_LEN                  (24+3+63)	/* WMM TSPEC IE: 63 */
#define ACTION_ADDTS_RSP_FRAME_LEN                  (24+4+63)	/* WMM Status Code: 1; WMM TSPEC IE: 63 */

/* 7.4.3 DLS Action frame details */
#define ACTION_DLS_REQ                              0	/* DLS request */
#define ACTION_DLS_RSP                              1	/* DLS response */
#define ACTION_DLS_TEARDOWN                         2	/* DLS teardown */

/* 7.4.4 Block ack  Action frame details */
#define ACTION_ADDBA_REQ                            0	/* ADDBA request */
#define ACTION_ADDBA_RSP                            1	/* ADDBA response */
#define ACTION_DELBA                                2	/* DELBA */

#define ACTION_ADDBA_REQ_FRAME_LEN                  (24+9)
#define ACTION_ADDBA_RSP_FRAME_LEN                  (24+9)

#define ACTION_DELBA_INITIATOR_MASK                 BIT(11)
#define ACTION_DELBA_TID_MASK                       BITS(12, 15)
#define ACTION_DELBA_TID_OFFSET                     12
#define ACTION_DELBA_FRAME_LEN                      (24+6)

/* 7.4.6 Radio Measurement Action frame details */
#define ACTION_RM_REQ                               0	/* Radio measurement request */
#define ACTION_RM_REPORT                            1	/* Radio measurement report */
#define ACTION_LM_REQ                               2	/* Link measurement request */
#define ACTION_LM_REPORT                            3	/* Link measurement report */
#define ACTION_NEIGHBOR_REPORT_REQ                  4	/* Neighbor report request */
#define ACTION_NEIGHBOR_REPORT_RSP                  5	/* Neighbor report response */

/* 7.4.7 Public Action frame details */
#define ACTION_PUBLIC_20_40_COEXIST                 0	/* 20/40 BSS coexistence */

#if CFG_SUPPORT_802_11W
/* SA Query Action frame (IEEE 802.11w/D8.0, 7.4.9) */
#define ACTION_SA_QUERY_REQUEST                     0
#define ACTION_SA_QUERY_RESPONSE                    1

#define ACTION_SA_QUERY_TR_ID_LEN                   2

/* Timeout Interval Type */
#define ACTION_SA_TIMEOUT_REASSOC_DEADLINE          1
#define ACTION_SA_TIMEOUT_KEY_LIFETIME              2
#define ACTION_SA_TIMEOUT_ASSOC_COMEBACK            3
#endif

/* 7.4.10.1 HT action frame details */
#define ACTION_HT_NOTIFY_CHANNEL_WIDTH              0	/* Notify Channel Width */
#define ACTION_HT_SM_POWER_SAVE                     1	/* SM Power Save */
#define ACTION_HT_PSMP                              2	/* PSMP */
#define ACTION_HT_SET_PCO_PHASE                     3	/* Set PCO Phase */
#define ACTION_HT_CSI                               4	/* CSI */
#define ACTION_HT_NON_COMPRESSED_BEAMFORM           5	/* Non-compressed Beamforming */
#define ACTION_HT_COMPRESSED_BEAMFORM               6	/* Compressed Beamforming */
#define ACTION_HT_ANT_SEL_INDICES_FB                7	/* Antenna Selection Indices Feedback */

/* 802.11v Wireless Network Management */
#define ACTION_WNM_TIMING_MEASUREMENT_REQUEST       27

#define ACTION_UNPROTECTED_WNM_TIM                  0
#define ACTION_UNPROTECTED_WNM_TIMING_MEASUREMENT   1

#define ACTION_UNPROTECTED_WNM_TIMING_MEAS_LEN      12

/* 8.5.23.1 VHT Action */
#define ACTION_VHT_COMPRESSED_BFEAMFORMING          0
#define ACTION_GROUP_ID_MANAGEMENT                  1
#define ACTION_OPERATING_MODE_NOTIFICATION          2

/* 3  --------------- WFA  frame body fields --------------- */
#define VENDOR_OUI_WFA                              { 0x00, 0x50, 0xF2 }
#define VENDOR_OUI_WFA_SPECIFIC                     { 0x50, 0x6F, 0x9A }
#define VENDOR_OUI_TYPE_WPA                         1
#define VENDOR_OUI_TYPE_WMM                         2
#define VENDOR_OUI_TYPE_WPS                         4
#define VENDOR_OUI_TYPE_P2P                         9
#define VENDOR_OUI_TYPE_WFD                         10

#if CFG_SUPPORT_PASSPOINT
#define VENDOR_OUI_TYPE_HS20                        16
#endif /* CFG_SUPPORT_PASSPOINT */

#define VENDOR_OUI_TYPE_LEN                         4	/* Length of OUI and Type */

/* VERSION(2 octets for WPA) / SUBTYPE(1 octet)-VERSION(1 octet) fields for WMM in WFA IE */
#define VERSION_WPA                                 0x0001	/* Little Endian Format */
#define VENDOR_OUI_SUBTYPE_VERSION_WMM_INFO         0x0100
#define VENDOR_OUI_SUBTYPE_VERSION_WMM_PARAM        0x0101

/* SUBTYPE(1 octet) for WMM */
#define VENDOR_OUI_SUBTYPE_WMM_INFO                 0x00	/* WMM Spec version 1.1 */
#define VENDOR_OUI_SUBTYPE_WMM_PARAM                0x01
#define VENDOR_OUI_SUBTYPE_WMM_TSPEC                0x02

/* VERSION(1 octet) for WMM */
#define VERSION_WMM                                 0x01	/* WMM Spec version 1.1 */

/* WMM-2.1.6 QoS Control Field */
#define WMM_QC_UP_MASK                              BITS(0, 2)
#define WMM_QC_EOSP                                 BIT(4)
#define WMM_QC_ACK_POLICY_MASK                      BITS(5, 6)
#define WMM_QC_ACK_POLICY_OFFSET                    5
#define WMM_QC_ACK_POLICY_ACKNOWLEDGE               0
#define WMM_QC_ACK_POLICY_NOT_ACKNOWLEDGE           (1 << WMM_QC_ACK_POLICY_OFFSET)

/* WMM-2.2.1 WMM Information Element */
#define ELEM_MIN_LEN_WFA_OUI_TYPE_SUBTYPE           6

/* 3 Control frame body */
/* 7.2.1.7 BlockAckReq */
#define CTRL_BAR_BAR_CONTROL_OFFSET                 16
#define CTRL_BAR_BAR_CONTROL_TID_OFFSET             12
#define CTRL_BAR_BAR_INFORMATION_OFFSET             18
#define CTRL_BAR_BAR_INFORMATION_SSN_OFFSET         4

/*******************************************************************************
*                             D A T A   T Y P E S
********************************************************************************
*/
#if defined(WINDOWS_DDK) || defined(WINDOWS_CE)
#pragma pack(1)
#endif

typedef struct _LLC_SNAP_HEADER_T {
	UINT_8 ucDSAP;
	UINT_8 ucSSAP;
	UINT_8 ucControl;
	UINT_8 aucCode[3];
	UINT_16 u2Type;
} __KAL_ATTRIB_PACKED__ LLC_SNAP_HEADER_T, *P_LLC_SNAP_HEADER_T;

/* 3 MAC Header. */
/* Ethernet Frame Header */
typedef struct _ETH_FRAME_HEADER_T {
	UINT_8 aucDestAddr[MAC_ADDR_LEN];
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];
	UINT_16 u2TypeLen;
} __KAL_ATTRIB_PACKED__ ETH_FRAME_HEADER_T, *P_ETH_FRAME_HEADER_T;

/* Ethernet Frame Structure */
typedef struct _ETH_FRAME_T {
	UINT_8 aucDestAddr[MAC_ADDR_LEN];
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];
	UINT_16 u2TypeLen;
	UINT_8 aucData[1];
} __KAL_ATTRIB_PACKED__ ETH_FRAME_T, *P_ETH_FRAME_T;

typedef struct _BOOTP_PROTOCOL_T {
	UINT_8 ucOperation;
	UINT_8 ucHdrType;
	UINT_8 ucHdrLen;
	UINT_8 ucHops;
	UINT_32 u4TransId;
	UINT_16 u2Seconds;
	UINT_16 u2Flags;
	UINT_32 u4CIAddr;
	UINT_32 u4YIAddr;
	UINT_32 u4SIAddr;
	UINT_32 u4GIAddr;
	UINT_8 aucCHAddr[16];
	UINT_8 aucServerName[64];
	UINT_8 aucFileName[128];
	UINT_8 aucOptions[0];
} __KAL_ATTRIB_PACKED__ BOOTP_PROTOCOL_T, *P_BOOTP_PROTOCOL_T;

/* IEEE 802.11 WLAN Frame Structure */
/* WLAN MAC Header (without Address 4 and QoS Control fields) */
typedef struct _WLAN_MAC_HEADER_T {
	UINT_16 u2FrameCtrl;
	UINT_16 u2DurationID;
	UINT_8 aucAddr1[MAC_ADDR_LEN];
	UINT_8 aucAddr2[MAC_ADDR_LEN];
	UINT_8 aucAddr3[MAC_ADDR_LEN];
	UINT_16 u2SeqCtrl;
} __KAL_ATTRIB_PACKED__ WLAN_MAC_HEADER_T, *P_WLAN_MAC_HEADER_T;

/* WLAN MAC Header (QoS Control fields included) */
typedef struct _WLAN_MAC_HEADER_QOS_T {
	UINT_16 u2FrameCtrl;
	UINT_16 u2DurationID;
	UINT_8 aucAddr1[MAC_ADDR_LEN];
	UINT_8 aucAddr2[MAC_ADDR_LEN];
	UINT_8 aucAddr3[MAC_ADDR_LEN];
	UINT_16 u2SeqCtrl;
	UINT_16 u2QosCtrl;
} __KAL_ATTRIB_PACKED__ WLAN_MAC_HEADER_QOS_T, *P_WLAN_MAC_HEADER_QOS_T;

/* WLAN MAC Header (HT Control fields included) */
typedef struct _WLAN_MAC_HEADER_HT_T {
	UINT_16 u2FrameCtrl;
	UINT_16 u2DurationID;
	UINT_8 aucAddr1[MAC_ADDR_LEN];
	UINT_8 aucAddr2[MAC_ADDR_LEN];
	UINT_8 aucAddr3[MAC_ADDR_LEN];
	UINT_16 u2SeqCtrl;
	UINT_16 u2QosCtrl;
	UINT_32 u4HtCtrl;
} __KAL_ATTRIB_PACKED__ WLAN_MAC_HEADER_HT_T, *P_WLAN_MAC_HEADER_HT_T;

/* WLAN MAC Header (Address 4 included) */
typedef struct _WLAN_MAC_HEADER_A4_T {
	UINT_16 u2FrameCtrl;
	UINT_16 u2DurationID;
	UINT_8 aucAddr1[MAC_ADDR_LEN];
	UINT_8 aucAddr2[MAC_ADDR_LEN];
	UINT_8 aucAddr3[MAC_ADDR_LEN];
	UINT_16 u2SeqCtrl;
	UINT_8 aucAddr4[MAC_ADDR_LEN];
} __KAL_ATTRIB_PACKED__ WLAN_MAC_HEADER_A4_T, *P_WLAN_MAC_HEADER_A4_T;

/* WLAN MAC Header (Address 4 and QoS Control fields included) */
typedef struct _WLAN_MAC_HEADER_A4_QOS_T {
	UINT_16 u2FrameCtrl;
	UINT_16 u2DurationID;
	UINT_8 aucAddr1[MAC_ADDR_LEN];
	UINT_8 aucAddr2[MAC_ADDR_LEN];
	UINT_8 aucAddr3[MAC_ADDR_LEN];
	UINT_16 u2SeqCtrl;
	UINT_8 aucAddr4[MAC_ADDR_LEN];
	UINT_16 u2QosCtrl;
} __KAL_ATTRIB_PACKED__ WLAN_MAC_HEADER_A4_QOS_T, *P_WLAN_MAC_HEADER_A4_QOS_T;

typedef struct _WLAN_MAC_HEADER_A4_HT_T {
	UINT_16 u2FrameCtrl;
	UINT_16 u2DurationID;
	UINT_8 aucAddr1[MAC_ADDR_LEN];
	UINT_8 aucAddr2[MAC_ADDR_LEN];
	UINT_8 aucAddr3[MAC_ADDR_LEN];
	UINT_16 u2SeqCtrl;
	UINT_8 aucAddr4[MAC_ADDR_LEN];
	UINT_16 u2QosCtrl;
	UINT_32 u4HtCtrl;
} __KAL_ATTRIB_PACKED__ WLAN_MAC_HEADER_A4_HT_T, *P_WLAN_MAC_HEADER_A4_HT_T;

/* 7.2.3 WLAN MAC Header for Management Frame - MMPDU */
typedef struct _WLAN_MAC_MGMT_HEADER_T {
	UINT_16 u2FrameCtrl;
	UINT_16 u2Duration;
	UINT_8 aucDestAddr[MAC_ADDR_LEN];
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];
	UINT_8 aucBSSID[MAC_ADDR_LEN];
	UINT_16 u2SeqCtrl;
} __KAL_ATTRIB_PACKED__ WLAN_MAC_MGMT_HEADER_T, *P_WLAN_MAC_MGMT_HEADER_T;

/* WLAN MAC Header for Management Frame (HT Control fields included) */
typedef struct _WLAN_MAC_MGMT_HEADER_HT_T {
	UINT_16 u2FrameCtrl;
	UINT_16 u2DurationID;
	UINT_8 aucAddr1[MAC_ADDR_LEN];
	UINT_8 aucAddr2[MAC_ADDR_LEN];
	UINT_8 aucAddr3[MAC_ADDR_LEN];
	UINT_16 u2SeqCtrl;
	UINT_32 u4HtCtrl;
} __KAL_ATTRIB_PACKED__ WLAN_MAC_MGMT_HEADER_HT_T, *P_WLAN_MAC_MGMT_HEADER_HT_T;

/* 3 WLAN CONTROL Frame */
/* 7.2.1.4 WLAN Control Frame - PS-POLL Frame */
typedef struct _CTRL_PSPOLL_FRAME_T {
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2AID;		/* AID */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_8 aucTA[MAC_ADDR_LEN];	/* TA */
} __KAL_ATTRIB_PACKED__ CTRL_PSPOLL_FRAME_T, *P_CTRL_PSPOLL_FRAME_T;

/* BAR */
typedef struct _CTRL_BAR_FRAME_T {
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2DurationID;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* RA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* TA */
	UINT_16 u2BarControl;
	UINT_8 aucBarInfo[2];	/* Variable size */
} __KAL_ATTRIB_PACKED__ CTRL_BAR_FRAME_T, *P_CTRL_BAR_FRAME_T;

/* 3 WLAN Management Frame. */
/* 7.2.3.1 WLAN Management Frame - Beacon Frame */
typedef struct _WLAN_BEACON_FRAME_T {
	/* Beacon header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2DurationID;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* Beacon frame body */
	UINT_32 au4Timestamp[2];	/* Timestamp */
	UINT_16 u2BeaconInterval;	/* Beacon Interval */
	UINT_16 u2CapInfo;	/* Capability */
	UINT_8 aucInfoElem[1];	/* Various IEs, start from SSID */
} __KAL_ATTRIB_PACKED__ WLAN_BEACON_FRAME_T, *P_WLAN_BEACON_FRAME_T;

typedef struct _WLAN_BEACON_FRAME_BODY_T {
	/* Beacon frame body */
	UINT_32 au4Timestamp[2];	/* Timestamp */
	UINT_16 u2BeaconInterval;	/* Beacon Interval */
	UINT_16 u2CapInfo;	/* Capability */
	UINT_8 aucInfoElem[1];	/* Various IEs, start from SSID */
} __KAL_ATTRIB_PACKED__ WLAN_BEACON_FRAME_BODY_T, *P_WLAN_BEACON_FRAME_BODY_T;

/* 7.2.3.3 WLAN Management Frame - Disassociation Frame */
typedef struct _WLAN_DISASSOC_FRAME_T {
	/* Authentication MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2DurationID;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* Disassociation frame body */
	UINT_16 u2ReasonCode;	/* Reason code */
	UINT_8 aucInfoElem[1];	/* Various IEs, possible no. */
} __KAL_ATTRIB_PACKED__ WLAN_DISASSOC_FRAME_T, *P_WLAN_DISASSOC_FRAME_T;

/* 7.2.3.4 WLAN Management Frame - Association Request frame */
typedef struct _WLAN_ASSOC_REQ_FRAME_T {
	/* Association Request MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2DurationID;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* Association Request frame body */
	UINT_16 u2CapInfo;	/* Capability information */
	UINT_16 u2ListenInterval;	/* Listen interval */
	UINT_8 aucInfoElem[1];	/* Information elements, include WPA IE */
} __KAL_ATTRIB_PACKED__ WLAN_ASSOC_REQ_FRAME_T, *P_WLAN_ASSOC_REQ_FRAME_T;

/* 7.2.3.5 WLAN Management Frame - Association Response frame */
typedef struct _WLAN_ASSOC_RSP_FRAME_T {
	/* Association Response MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2DurationID;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* Association Response frame body */
	UINT_16 u2CapInfo;	/* Capability information */
	UINT_16 u2StatusCode;	/* Status code */
	UINT_16 u2AssocId;	/* Association ID */
	UINT_8 aucInfoElem[1];	/* Information elements, such as */
				/* supported rates, and etc. */
} __KAL_ATTRIB_PACKED__ WLAN_ASSOC_RSP_FRAME_T, *P_WLAN_ASSOC_RSP_FRAME_T;

/* 7.2.3.6 WLAN Management Frame - Reassociation Request frame */
typedef struct _WLAN_REASSOC_REQ_FRAME_T {
	/* Reassociation Request MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2DurationID;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* Reassociation Request frame body */
	UINT_16 u2CapInfo;	/* Capability information */
	UINT_16 u2ListenInterval;	/* Listen interval */
	UINT_8 aucCurrentAPAddr[MAC_ADDR_LEN];	/* Current AP address */
	UINT_8 aucInfoElem[1];	/* Information elements, include WPA IE */
} __KAL_ATTRIB_PACKED__ WLAN_REASSOC_REQ_FRAME_T, *P_WLAN_REASSOC_REQ_FRAME_T;

/* 7.2.3.7 WLAN Management Frame - Reassociation Response frame */
/*   (the same as Association Response frame) */
typedef WLAN_ASSOC_RSP_FRAME_T WLAN_REASSOC_RSP_FRAME_T, *P_WLAN_REASSOC_RSP_FRAME_T;

/* 7.2.3.9 WLAN Management Frame - Probe Response Frame */
typedef WLAN_BEACON_FRAME_T WLAN_PROBE_RSP_FRAME_T, *P_WLAN_PROBE_RSP_FRAME_T;

/* 7.2.3.10 WLAN Management Frame - Authentication Frame */
typedef struct _WLAN_AUTH_FRAME_T {
	/* Authentication MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2DurationID;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* Authentication frame body */
	UINT_16 u2AuthAlgNum;	/* Authentication algorithm number */
#if CFG_SUPPORT_CFG80211_AUTH
	BOOLEAN aucAuthData[AUTH_DATA_MAX_LEN];
#else
	UINT_16 u2AuthTransSeqNo;	/* Authentication transaction sequence number */
	UINT_16 u2StatusCode;	/* Status code */
#endif
	UINT_8 aucInfoElem[1];	/* Various IEs for Fast BSS Transition */
} __KAL_ATTRIB_PACKED__ WLAN_AUTH_FRAME_T, *P_WLAN_AUTH_FRAME_T;

/* 7.2.3.11 WLAN Management Frame - Deauthentication Frame */
typedef struct _WLAN_DEAUTH_FRAME_T {
	/* Authentication MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2DurationID;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* Deauthentication frame body */
	UINT_16 u2ReasonCode;	/* Reason code */
	UINT_8 aucInfoElem[1];	/* Various IEs, possible no. */
} __KAL_ATTRIB_PACKED__ WLAN_DEAUTH_FRAME_T, *P_WLAN_DEAUTH_FRAME_T;

/* 3 Information Elements. */
/* 7.3.2 Generic element format */
typedef struct _IE_HDR_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 aucInfo[1];
} __KAL_ATTRIB_PACKED__ IE_HDR_T, *P_IE_HDR_T;

/* 7.3.2.1 SSID element */
typedef struct _IE_SSID_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 aucSSID[ELEM_MAX_LEN_SSID];
} __KAL_ATTRIB_PACKED__ IE_SSID_T, *P_IE_SSID_T;

/* 7.3.2.2 Supported Rates element */
typedef struct _IE_SUPPORTED_RATE_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 aucSupportedRates[ELEM_MAX_LEN_SUP_RATES];
} __KAL_ATTRIB_PACKED__ IE_SUPPORTED_RATE_T, *P_IE_SUPPORTED_RATE_T;

/* 7.3.2.4 DS Parameter Set element */
typedef struct _IE_DS_PARAM_SET_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucCurrChnl;
} __KAL_ATTRIB_PACKED__ IE_DS_PARAM_SET_T, *P_IE_DS_PARAM_SET_T;

/* 7.3.2.5 CF Parameter Set element */
typedef struct _IE_CF_PARAM_SET_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucCFPCount;
	UINT_8 ucCFPPeriod;
	UINT_16 u2CFPMaxDur;
	UINT_16 u2DurRemaining;
} __KAL_ATTRIB_PACKED__ IE_CF_PARAM_SET_T, *P_IE_CF_PARAM_SET_T;

/* 7.3.2.6 TIM */
typedef struct _IE_TIM_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucDTIMCount;
	UINT_8 ucDTIMPeriod;
	UINT_8 ucBitmapControl;
	UINT_8 aucPartialVirtualMap[1];
} __KAL_ATTRIB_PACKED__ IE_TIM_T, *P_IE_TIM_T;

/* 7.3.2.7 IBSS Parameter Set element */
typedef struct _IE_IBSS_PARAM_SET_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_16 u2ATIMWindow;
} __KAL_ATTRIB_PACKED__ IE_IBSS_PARAM_SET_T, *P_IE_IBSS_PARAM_SET_T;

/* 7.3.2.8 Challenge Text element */
typedef struct _IE_CHALLENGE_TEXT_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 aucChallengeText[ELEM_MAX_LEN_CHALLENGE_TEXT];
} __KAL_ATTRIB_PACKED__ IE_CHALLENGE_TEXT_T, *P_IE_CHALLENGE_TEXT_T;

/* 7.3.2.9 Country information element */
#if CFG_SUPPORT_802_11D
/*! \brief COUNTRY_INFO_TRIPLET is defined for the COUNTRY_INFO_ELEM structure. */
typedef struct _COUNTRY_INFO_TRIPLET_T {
	UINT_8 ucParam1;	/*!< If param1 >= 201, this triplet is referred to as */
				/* Regulatory Triplet in 802_11J. */
	UINT_8 ucParam2;
	UINT_8 ucParam3;
} __KAL_ATTRIB_PACKED__ COUNTRY_INFO_TRIPLET_T, *P_COUNTRY_INFO_TRIPLET_T;

typedef struct _COUNTRY_INFO_SUBBAND_TRIPLET_T {
	UINT_8 ucFirstChnlNum;	/*!< First Channel Number */
	UINT_8 ucNumOfChnl;	/*!< Number of Channels */
	INT_8 cMaxTxPwrLv;	/*!< Maximum Transmit Power Level */
} __KAL_ATTRIB_PACKED__ COUNTRY_INFO_SUBBAND_TRIPLET_T, *P_COUNTRY_INFO_SUBBAND_TRIPLET_T;

typedef struct _COUNTRY_INFO_REGULATORY_TRIPLET_T {
	UINT_8 ucRegExtId;	/*!< Regulatory Extension Identifier, should */
				/* be greater than or equal to 201 */
	UINT_8 ucRegClass;	/*!< Regulatory Class */
	UINT_8 ucCoverageClass;	/*!< Coverage Class, unsigned 1-octet value 0~31 */
				/* , 32~255 reserved */
} __KAL_ATTRIB_PACKED__ COUNTRY_INFO_REGULATORY_TRIPLET_T, *P_COUNTRY_INFO_REGULATORY_TRIPLET_T;

typedef struct _IE_COUNTRY_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 aucCountryStr[3];
	COUNTRY_INFO_SUBBAND_TRIPLET_T arCountryStr[1];
} __KAL_ATTRIB_PACKED__ IE_COUNTRY_T, *P_IE_COUNTRY_T;
#endif /* CFG_SUPPORT_802_11D */

/* 7.3.2.13 ERP element */
typedef struct _IE_ERP_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucERP;
} __KAL_ATTRIB_PACKED__ IE_ERP_T, *P_IE_ERP_T;

/* 7.3.2.14 Extended Supported Rates element */
typedef struct _IE_EXT_SUPPORTED_RATE_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 aucExtSupportedRates[ELEM_MAX_LEN_EXTENDED_SUP_RATES];
} __KAL_ATTRIB_PACKED__ IE_EXT_SUPPORTED_RATE_T, *P_IE_EXT_SUPPORTED_RATE_T;

/* 7.3.2.15 Power Constraint element */
typedef struct _IE_POWER_CONSTRAINT_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucLocalPowerConstraint;	/* Unit: dBm */
} __KAL_ATTRIB_PACKED__ IE_POWER_CONSTRAINT_T, *P_IE_POWER_CONSTRAINT_T;

/* 7.3.2.16 Power Capability element */
typedef struct _IE_POWER_CAP_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	INT_8 cMinTxPowerCap;	/* Unit: dBm */
	INT_8 cMaxTxPowerCap;	/* Unit: dBm */
} __KAL_ATTRIB_PACKED__ IE_POWER_CAP_T, *P_IE_POWER_CAP_T;

/* 7.3.2.17 TPC request element */
typedef struct _IE_TPC_REQ_T {
	UINT_8 ucId;
	UINT_8 ucLength;
} __KAL_ATTRIB_PACKED__ IE_TPC_REQ_T, *P_IE_TPC_REQ_T;

/* 7.3.2.18 TPC report element */
typedef struct _IE_TPC_REPORT_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	INT_8 cTxPower;		/* Unit: dBm */
	INT_8 cLinkMargin;	/* Unit: dB */
} __KAL_ATTRIB_PACKED__ IE_TPC_REPORT_T, *P_IE_TPC_REPORT_T;

/* 7.3.2.19 Supported Channels element*/
typedef struct _IE_SUPPORTED_CHANNELS_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucChannelNum[0];
} __KAL_ATTRIB_PACKED__ IE_SUPPORTED_CHANNELS_T, *P_IE_SUPPORTED_CHANNELS_T;

/* 7.3.2.20 Channel Switch Announcement element*/
typedef struct _IE_CHANNEL_SWITCH_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucChannelSwitchMode;
	UINT_8 ucNewChannelNum;
	UINT_8 ucChannelSwitchCount;
} __KAL_ATTRIB_PACKED__ IE_CHANNEL_SWITCH_T, *P_IE_CHANNEL_SWITCH_T;

typedef struct _IE_TIMEOUT_INTERVAL_T {
	UINT_8 ucId;
	UINT_8 ucLength;
#define IE_TIMEOUT_INTERVAL_TYPE_RESERVED			0
#define IE_TIMEOUT_INTERVAL_TYPE_REASSOC			1
#define IE_TIMEOUT_INTERVAL_TYPE_KEY_LIFETIME		43200
#define IE_TIMEOUT_INTERVAL_TYPE_ASSOC_COMEBACK		3
	UINT_8 ucType;
	UINT_32 u4Value;
} __KAL_ATTRIB_PACKED__ IE_TIMEOUT_INTERVAL_T;

/* 7.3.2.20 Channel Switch Announcement element */
typedef struct _IE_CHNL_SWITCH_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucSwitchMode;
	UINT_8 ucNewChannel;
	UINT_8 ucSwitchCount;
} __KAL_ATTRIB_PACKED__ IE_CHNL_SWITCH_T, *P_IE_CHNL_SWITCH_T;

/* 7.3.2.21 Measurement Request element */
typedef struct _IE_MEASUREMENT_REQ_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucToken;
	UINT_8 ucRequestMode;
	UINT_8 ucMeasurementType;
	UINT_8 aucRequestFields[1];
} __KAL_ATTRIB_PACKED__ IE_MEASUREMENT_REQ_T, *P_IE_MEASUREMENT_REQ_T;

/* 7.3.2.60 20/40 BSS Coexistence element */
typedef struct _IE_SUP_OPERATING_CLASS_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucCur;
	UINT_8 ucSup[255];
} __KAL_ATTRIB_PACKED__ IE_SUP_OPERATING_CLASS_T, *P_IE_SUP_OPERATING_CLASS_T;

typedef struct _SM_BASIC_REQ_T {
	UINT_8 ucChannel;
	UINT_32 au4StartTime[2];
	UINT_16 u2Duration;
} __KAL_ATTRIB_PACKED__ SM_BASIC_REQ_T, *P_SM_BASIC_REQ_T;

/* SM_COMMON_REQ_T is not specified in Spec. Use it as common structure of SM */
typedef SM_BASIC_REQ_T SM_REQ_COMMON_T, *P_SM_REQ_COMMON_T;
typedef SM_BASIC_REQ_T SM_CCA_REQ_T, *P_SM_CCA_REQ_T;
typedef SM_BASIC_REQ_T SM_RPI_HISTOGRAM_REQ_T, *P_SM_RPI_HISTOGRAM_REQ_T;

typedef struct _RM_CHNL_LOAD_REQ_T {
	UINT_8 ucRegulatoryClass;
	UINT_8 ucChannel;
	UINT_16 u2RandomInterval;
	UINT_16 u2Duration;
	UINT_8 aucSubElements[1];
} __KAL_ATTRIB_PACKED__ RM_CHNL_LOAD_REQ_T, *P_RM_CHNL_LOAD_REQ_T;

typedef RM_CHNL_LOAD_REQ_T RM_NOISE_HISTOGRAM_REQ_T, *P_RM_NOISE_HISTOGRAM_REQ_T;

typedef struct _RM_BCN_REQ_T {
	UINT_8 ucRegulatoryClass;
	UINT_8 ucChannel;
	UINT_16 u2RandomInterval;
	UINT_16 u2Duration;
	UINT_8 ucMeasurementMode;
	UINT_8 aucBssid[6];
	UINT_8 aucSubElements[1];
} __KAL_ATTRIB_PACKED__ RM_BCN_REQ_T, *P_RM_BCN_REQ_T;

typedef struct _RM_FRAME_REQ_T {
	UINT_8 ucRegulatoryClass;
	UINT_8 ucChannel;
	UINT_16 u2RandomInterval;
	UINT_16 u2Duration;
	UINT_8 ucFrameReqType;
	UINT_8 aucMacAddr[6];
	UINT_8 aucSubElements[1];
} __KAL_ATTRIB_PACKED__ RM_FRAME_REQ_T, *P_RM_FRAME_REQ_T;

typedef struct _RM_STA_STATS_REQ_T {
	UINT_8 aucPeerMacAddr[6];
	UINT_16 u2RandomInterval;
	UINT_16 u2Duration;
	UINT_8 ucGroupID;
	UINT_8 aucSubElements[1];
} __KAL_ATTRIB_PACKED__ RM_STA_STATS_REQ_T, *P_RM_STA_STATS_REQ_T;

typedef struct _RM_LCI_REQ_T {
	UINT_8 ucLocationSubject;
	UINT_8 ucLatitudeResolution;
	UINT_8 ucLongitudeResolution;
	UINT_8 ucAltitudeResolution;
	UINT_8 aucSubElements[1];
} __KAL_ATTRIB_PACKED__ RM_LCI_REQ_T, *P_RM_LCI_REQ_T;

typedef struct _RM_TS_MEASURE_REQ_T {
	UINT_16 u2RandomInterval;
	UINT_16 u2Duration;
	UINT_8 aucPeerStaAddr[6];
	UINT_8 ucTrafficID;
	UINT_8 ucBin0Range;
	UINT_8 aucSubElements[1];
} __KAL_ATTRIB_PACKED__ RM_TS_MEASURE_REQ_T, *P_RM_TS_MEASURE_REQ_T;

typedef struct _RM_MEASURE_PAUSE_REQ_T {
	UINT_16 u2PauseTime;
	UINT_8 aucSubElements[1];
} __KAL_ATTRIB_PACKED__ RM_MEASURE_PAUSE_REQ_T, *P_RM_MEASURE_PAUSE_REQ_T;

/* 7.3.2.22 Measurement Report element */
typedef struct _IE_MEASUREMENT_REPORT_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucToken;
	UINT_8 ucReportMode;
	UINT_8 ucMeasurementType;
	UINT_8 aucReportFields[1];
} __KAL_ATTRIB_PACKED__ IE_MEASUREMENT_REPORT_T, *P_IE_MEASUREMENT_REPORT_T;

typedef struct _SM_BASIC_REPORT_T {
	UINT_8 ucChannel;
	UINT_32 u4StartTime[2];
	UINT_16 u2Duration;
	UINT_8 ucMap;
} __KAL_ATTRIB_PACKED__ SM_BASIC_REPORT_T, *P_SM_BASIC_REPORT_T;

typedef struct _SM_CCA_REPORT_T {
	UINT_8 ucChannel;
	UINT_32 u4StartTime[2];
	UINT_16 u2Duration;
	UINT_8 ucCcaBusyFraction;
} __KAL_ATTRIB_PACKED__ SM_CCA_REPORT_T, *P_SM_CCA_REPORT_T;

typedef struct _SM_RPI_REPORT_T {
	UINT_8 ucChannel;
	UINT_32 u4StartTime[2];
	UINT_16 u2Duration;
	UINT_8 aucRPI[8];
} __KAL_ATTRIB_PACKED__ SM_RPI_REPORT_T, *P_SM_RPI_REPORT_T;

typedef struct _RM_CHNL_LOAD_REPORT_T {
	UINT_8 ucRegulatoryClass;
	UINT_8 ucChannel;
	UINT_32 u4StartTime[2];
	UINT_16 u2Duration;
	UINT_8 ucChnlLoad;
} __KAL_ATTRIB_PACKED__ RM_CHNL_LOAD_REPORT_T, *P_RM_CHNL_LOAD_REPORT_T;

typedef struct _RM_IPI_REPORT_T {
	UINT_8 ucRegulatoryClass;
	UINT_8 ucChannel;
	UINT_32 u4StartTime[2];
	UINT_16 u2Duration;
	UINT_8 ucAntennaId;
	INT_8 cANPI;
	UINT_8 aucIPI[11];
} __KAL_ATTRIB_PACKED__ RM_IPI_REPORT_T, *P_RM_IPI_REPORT_T;

/* 7.3.2.23 Quiet element */
typedef struct _IE_QUIET_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucCount;
	UINT_8 ucPeriod;
	UINT_16 u2Duration;
	UINT_16 u2Offset;
} __KAL_ATTRIB_PACKED__ IE_QUIET_T, *P_IE_QUIET_T;

/* 7.3.2.27 Extended Capabilities element */
typedef struct _IE_EXT_CAP_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 aucCapabilities[1];
} __KAL_ATTRIB_PACKED__ IE_EXT_CAP_T, *P_EXT_CAP_T;

/* 7.3.2.27 Extended Capabilities element */
typedef struct _IE_RRM_ENABLED_CAP_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 aucCap[5];
} __KAL_ATTRIB_PACKED__ IE_RRM_ENABLED_CAP_T, *P_IE_RRM_ENABLED_CAP_T;

/* 7.3.2.56 HT Capabilities element */
typedef struct _SUP_MCS_SET_FIELD {
	UINT_8 aucRxMcsBitmask[SUP_MCS_RX_BITMASK_OCTET_NUM];
	UINT_16 u2RxHighestSupportedRate;
	UINT_32 u4TxRateInfo;
} __KAL_ATTRIB_PACKED__ SUP_MCS_SET_FIELD, *P_SUP_MCS_SET_FIELD;

typedef struct _IE_HT_CAP_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_16 u2HtCapInfo;
	UINT_8 ucAmpduParam;
	SUP_MCS_SET_FIELD rSupMcsSet;
	UINT_16 u2HtExtendedCap;
	UINT_32 u4TxBeamformingCap;
	UINT_8 ucAselCap;
} __KAL_ATTRIB_PACKED__ IE_HT_CAP_T, *P_IE_HT_CAP_T;

/* 7.3.2.57 HT Operation element */
typedef struct _IE_HT_OP_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucPrimaryChannel;
	UINT_8 ucInfo1;
	UINT_16 u2Info2;
	UINT_16 u2Info3;
	UINT_8 aucBasicMcsSet[16];
} __KAL_ATTRIB_PACKED__ IE_HT_OP_T, *P_IE_HT_OP_T;

/*8.4.2.160.3 VHT Supported MCS Set field*/
typedef struct _VHT_SUPPORTED_MCS_FIELD {
	UINT_16 u2RxMcsMap;
	UINT_16 u2RxHighestSupportedDataRate;
	UINT_16 u2TxMcsMap;
	UINT_16 u2TxHighestSupportedDataRate;
} __KAL_ATTRIB_PACKED__ VHT_SUPPORTED_MCS_FIELD, *P_VHT_SUPPORTED_MCS_FIELD;

typedef struct _IE_VHT_CAP_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_32 u4VhtCapInfo;
	VHT_SUPPORTED_MCS_FIELD rVhtSupportedMcsSet;
} __KAL_ATTRIB_PACKED__ IE_VHT_CAP_T, *P_IE_VHT_CAP_T;

/*8.4.2.161 VHT Operation element*/
typedef struct _IE_VHT_OP_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucVhtOperation[3];
	UINT_16 u2VhtBasicMcsSet;
} __KAL_ATTRIB_PACKED__ IE_VHT_OP_T, *P_IE_VHT_OP_T;

/*8.4.1.50 Operating Mode field*/
typedef struct _IE_VHT_OP_MODE_NOTIFICATION_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucOperatingMode;
} __KAL_ATTRIB_PACKED__ IE_VHT_OP_MODE_NOTIFICATION_T, *P_IE_VHT_OP_MODE_NOTIFICATION_T;


/*8.4.2.22 Secondary Channel Offset element*/
typedef struct _IE_SECONDARY_OFFSET_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucSecondaryOffset;
} __KAL_ATTRIB_PACKED__ IE_SECONDARY_OFFSET_T, *P_IE_SECONDARY_OFFSET_T;

/*8.4.2.105 Mesh Channel Switch Parameters element*/
typedef struct _IE_MESH_CHANNEL_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucTimetoLive;
	UINT_8 ucFlags;
	UINT_16 u2ReasonCodes;
	UINT_16 u2ProcedenceValue;
} __KAL_ATTRIB_PACKED__ IE_MESH_CHANNEL_T, *P_IE_MESH_CHANNEL_T;

/*8.4.2.163 Wide Bandwidth Channel Switch element*/
typedef struct _IE_WIDE_BAND_CHANNEL_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucNewChannelWidth;
	UINT_8 ucChannelS1;
	UINT_8 ucChannelS2;
} __KAL_ATTRIB_PACKED__ IE_WIDE_BAND_CHANNEL_T, *P_IE_WIDE_BAND_CHANNEL_T;

/*8.4.2.168 Operating Mode Notification element*/
typedef struct _IE_OP_MODE_NOTIFICATION_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucOpMode;
} __KAL_ATTRIB_PACKED__ IE_OP_MODE_NOTIFICATION_T, *P_IE_OP_MODE_NOTIFICATION_T;

/* 7.3.2.25 RSN Information element format */
typedef struct _RSN_INFO_ELEM_T {
	UCHAR ucElemId;
	UCHAR ucLength;
	UINT_16 u2Version;
	UINT_32 u4GroupKeyCipherSuite;
	UINT_16 u2PairwiseKeyCipherSuiteCount;
	UCHAR aucPairwiseKeyCipherSuite1[4];
} __KAL_ATTRIB_PACKED__ RSN_INFO_ELEM_T, *P_RSN_INFO_ELEM_T;

/* 7.3.2.26 WPA Information element format */
typedef struct _WPA_INFO_ELEM_T {
	UCHAR ucElemId;
	UCHAR ucLength;
	UCHAR aucOui[3];
	UCHAR ucOuiType;
	UINT_16 u2Version;
	UINT_32 u4GroupKeyCipherSuite;
	UINT_16 u2PairwiseKeyCipherSuiteCount;
	UCHAR aucPairwiseKeyCipherSuite1[4];
} __KAL_ATTRIB_PACKED__ WPA_INFO_ELEM_T, *P_WPA_INFO_ELEM_T;

/* 7.3.2.58 20/40 BSS Intolerant Channel Report element */
typedef struct _IE_INTOLERANT_CHNL_REPORT_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucRegulatoryClass;
	UINT_8 aucChannelList[1];
} __KAL_ATTRIB_PACKED__ IE_INTOLERANT_CHNL_REPORT_T, *P_IE_INTOLERANT_CHNL_REPORT_T;

/* 7.3.2.59 OBSS Scan Parameters element */
typedef struct _IE_OBSS_SCAN_PARAM_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_16 u2ScanPassiveDwell;
	UINT_16 u2ScanActiveDwell;
	UINT_16 u2TriggerScanInterval;
	UINT_16 u2ScanPassiveTotalPerChnl;
	UINT_16 u2ScanActiveTotalPerChnl;
	UINT_16 u2WidthTransDelayFactor;
	UINT_16 u2ScanActivityThres;
} __KAL_ATTRIB_PACKED__ IE_OBSS_SCAN_PARAM_T, *P_IE_OBSS_SCAN_PARAM_T;

/* 7.3.2.60 20/40 BSS Coexistence element */
typedef struct _IE_20_40_COEXIST_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 ucData;
} __KAL_ATTRIB_PACKED__ IE_20_40_COEXIST_T, *P_IE_20_40_COEXIST_T;

/* 3 7.4 Action Frame. */
/* 7.4 Action frame format */
typedef struct _WLAN_ACTION_FRAME {
	/* Action MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2DurationID;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* Action frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 ucActionDetails[1];	/* Action details */
} __KAL_ATTRIB_PACKED__ WLAN_ACTION_FRAME, *P_WLAN_ACTION_FRAME;

/* 7.4.1.1 Spectrum Measurement Request frame format */
typedef struct _ACTION_SM_REQ_FRAME {
	/* ADDTS Request MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2Duration;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* ADDTS Request frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 ucDialogToken;	/* Dialog Token */
	UINT_8 aucInfoElem[1];	/* Information elements  */
} __KAL_ATTRIB_PACKED__ ACTION_SM_REQ_FRAME, *P_ACTION_SM_REQ_FRAME;

/* 7.4.1.2 Spectrum Measurement Report frame format */
typedef ACTION_SM_REQ_FRAME ACTION_SM_REPORT_FRAME, *P_ACTION_SM_REPORT_FRAME;

/* 7.4.1.3 Spectrum TPC Request frame format */
typedef struct _ACTION_TPC_REQ_FRAME {
	/* ADDTS Request MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2Duration;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* ADDTS Request frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 ucDialogToken;	/* Dialog Token */
	UINT_8 ucElemId;	/* Element ID */
	UINT_8 ucLength;	/* Length */
} __KAL_ATTRIB_PACKED__ ACTION_TPC_REQ_FRAME, *P_ACTION_TPC_REQ_FRAME;

/* 7.4.1.4 Spectrum TPC Report frame format */
typedef struct _ACTION_TPC_REPORT_FRAME {
	/* ADDTS Request MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2Duration;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* ADDTS Request frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 ucDialogToken;	/* Dialog Token */
	UINT_8 ucElemId;	/* Element ID */
	UINT_8 ucLength;	/* Length */
	UINT_8 ucTransPwr;	/* Transmit Power */
	UINT_8 ucLinkMargin;	/* Link Margin */
} __KAL_ATTRIB_PACKED__ ACTION_TPC_REPORT_FRAME, *P_ACTION_TPC_REPORT_FRAME;

/* 7.4.1.5 Channel Switch Announcement frame format */
typedef struct _ACTION_CHANNEL_SWITCH_FRAME {
	/* ADDTS Request MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2Duration;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* ADDTS Request frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 aucInfoElem[5];	/* Information elements */
} __KAL_ATTRIB_PACKED__ ACTION_CHANNEL_SWITCH_FRAME, *P_ACTION_CHANNEL_SWITCH_FRAME;

/* 7.4.2.1 ADDTS Request frame format */
typedef struct _ACTION_ADDTS_REQ_FRAME {
	/* ADDTS Request MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2Duration;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* ADDTS Request frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 ucDialogToken;	/* Dialog Token */
	UINT_8 aucInfoElem[1];	/* Information elements, such as */
				/* TS Delay, and etc. */
} __KAL_ATTRIB_PACKED__ ACTION_ADDTS_REQ_FRAME, *P_ACTION_ADDTS_REQ_FRAME;

/* 7.4.2.2 ADDTS Response frame format */
typedef struct _ACTION_ADDTS_RSP_FRAME {
	/* ADDTS Response MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2Duration;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* ADDTS Response frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 ucDialogToken;	/* Dialog Token */
	UINT_8 ucStatusCode;	/* WMM Status Code is of one byte */
	UINT_8 aucInfoElem[1];	/* Information elements, such as */
				/* TS Delay, and etc. */
} __KAL_ATTRIB_PACKED__ ACTION_ADDTS_RSP_FRAME, *P_ACTION_ADDTS_RSP_FRAME;

/* 7.4.2.3 DELTS frame format */
typedef struct _ACTION_DELTS_FRAME {
	/* DELTS MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2DurationID;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* DELTS frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 aucTsInfo[3];	/* TS Info */
} __KAL_ATTRIB_PACKED__ ACTION_DELTS_FRAME, *P_ACTION_DELTS_FRAME;

/* 7.4.4.1 ADDBA Request frame format */
typedef struct _ACTION_ADDBA_REQ_FRAME_T {
	/* Action MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2DurationID;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* Action frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 ucDialogToken;	/* Dialog Token chosen by the sender */
	UINT_8 aucBAParameterSet[2];	/* BA policy, TID, buffer size */
	UINT_8 aucBATimeoutValue[2];
	UINT_8 aucBAStartSeqCtrl[2];	/* SSN */
} __KAL_ATTRIB_PACKED__ ACTION_ADDBA_REQ_FRAME_T, *P_ACTION_ADDBA_REQ_FRAME_T;

typedef struct _ACTION_ADDBA_REQ_BODY_T {
	UINT_16 u2BAParameterSet;	/* BA policy, TID, buffer size */
	UINT_16 u2BATimeoutValue;
	UINT_16 u2BAStartSeqCtrl;	/* SSN */
} __KAL_ATTRIB_PACKED__ ACTION_ADDBA_REQ_BODY_T, *P_ACTION_ADDBA_REQ_BODY_T;

/* 7.4.4.2 ADDBA Response frame format */
typedef struct _ACTION_ADDBA_RSP_FRAME_T {
	/* Action MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2DurationID;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* Action frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 ucDialogToken;	/* Dialog Token chosen by the sender */
	UINT_8 aucStatusCode[2];
	UINT_8 aucBAParameterSet[2];	/* BA policy, TID, buffer size */
	UINT_8 aucBATimeoutValue[2];
} __KAL_ATTRIB_PACKED__ ACTION_ADDBA_RSP_FRAME_T, *P_ACTION_ADDBA_RSP_FRAME_T;

typedef struct _ACTION_ADDBA_RSP_BODY_T {
	UINT_16 u2StatusCode;
	UINT_16 u2BAParameterSet;	/* BA policy, TID, buffer size */
	UINT_16 u2BATimeoutValue;
} __KAL_ATTRIB_PACKED__ ACTION_ADDBA_RSP_BODY_T, *P_ACTION_ADDBA_RSP_BODY_T;

/* 7.4.4.3 DELBA frame format */
typedef struct _ACTION_DELBA_FRAME_T {
	/* Action MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2DurationID;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* Action frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_16 u2DelBaParameterSet;	/* Bit 11 Initiator, Bits 12-15 TID */
	UINT_16 u2ReasonCode;	/* 7.3.1.7 */
} __KAL_ATTRIB_PACKED__ ACTION_DELBA_FRAME_T, *P_ACTION_DELBA_FRAME_T;

/* 7.4.6.1 Radio Measurement Request frame format */
typedef struct _ACTION_RM_REQ_FRAME {
	/* MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2Duration;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* Radio Measurement Request frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 ucDialogToken;	/* Dialog Token */
	UINT_16 u2Repetitions;	/* Number of repetitions */
	UINT_8 aucInfoElem[1];	/* Measurement Request elements, such as */
				/* channel load request, and etc. */
} __KAL_ATTRIB_PACKED__ ACTION_RM_REQ_FRAME, *P_ACTION_RM_REQ_FRAME;

/* 7.4.6.2 Radio Measurement Report frame format */
typedef struct _ACTION_RM_REPORT_FRAME {
	/* MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2Duration;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* Radio Measurement Report frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 ucDialogToken;	/* Dialog Token */
	UINT_8 aucInfoElem[1];	/* Measurement Report elements, such as */
				/* channel load report, and etc. */
} __KAL_ATTRIB_PACKED__ ACTION_RM_REPORT_FRAME, *P_ACTION_RM_REPORT_FRAME;

/* 7.4.7.1a 20/40 BSS Coexistence Management frame format */
typedef struct _ACTION_20_40_COEXIST_FRAME {
	/* MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2Duration;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* BSS Coexistence Management frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */

	IE_20_40_COEXIST_T rBssCoexist;	/* 20/40 BSS coexistence element */
	IE_INTOLERANT_CHNL_REPORT_T rChnlReport;	/* Intolerant channel report */

} __KAL_ATTRIB_PACKED__ ACTION_20_40_COEXIST_FRAME, *P_ACTION_20_40_COEXIST_FRAME;

#if CFG_SUPPORT_802_11W
/* 7.4.9 SA Query Management frame format */
typedef struct _ACTION_SA_QUERY_FRAME {
	/* MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2Duration;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* BSS Coexistence Management frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */

	UINT_8 ucTransId[ACTION_SA_QUERY_TR_ID_LEN];	/* Transaction id */

} __KAL_ATTRIB_PACKED__ ACTION_SA_QUERY_FRAME, *P_ACTION_SA_QUERY_FRAME;
#endif

/* 7.4.10 Notify Channel Width Management frame format */
typedef struct _ACTION_NOTIFY_CHNL_WIDTH_FRAME {
	/* MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2Duration;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* BSS Coexistence Management frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 ucChannelWidth;	/* Channel Width */
} __KAL_ATTRIB_PACKED__ ACTION_NOTIFY_CHNL_WIDTH_FRAME, *P_ACTION_NOTIFY_CHNL_WIDTH_FRAME;

/* 802.11v Wireless Network Management: Timing Measurement Request */
typedef struct _ACTION_WNM_TIMING_MEAS_REQ_FRAME {
	/* MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2Duration;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* Timing Measurement Request Management frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 ucTrigger;	/* Trigger */
} __KAL_ATTRIB_PACKED__ ACTION_WNM_TIMING_MEAS_REQ_FRAME, *P_ACTION_WNM_TIMING_MEAS_REQ_FRAME;

/* 802.11v Wireless Network Management: Timing Measurement */
typedef struct _ACTION_UNPROTECTED_WNM_TIMING_MEAS_FRAME {
	/* MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2Duration;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* Timing Measurement Management frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 ucDialogToken;	/* Dialog Token */
	UINT_8 ucFollowUpDialogToken;	/* Follow Up Dialog Token */
	UINT_32 u4ToD;		/* Timestamp of Departure [10ns] */
	UINT_32 u4ToA;		/* Timestamp of Arrival [10ns] */
	UINT_8 ucMaxToDErr;	/* Maximum of ToD Error [10ns] */
	UINT_8 ucMaxToAErr;	/* Maximum of ToA Error [10ns] */
} __KAL_ATTRIB_PACKED__ ACTION_UNPROTECTED_WNM_TIMING_MEAS_FRAME, *P_ACTION_UNPROTECTED_WNM_TIMING_MEAS_FRAME;

/* 8.5.23.4 Operating Mode Notification frame format */
typedef struct _ACTION_OP_MODE_NOTIFICATION_FRAME {
	/* MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2Duration;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* Operating Mode Notification frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 ucOperatingMode;	/* Operating Mode */
} __KAL_ATTRIB_PACKED__ ACTION_OP_MODE_NOTIFICATION_FRAME, *P_ACTION_OP_MODE_NOTIFICATION_FRAME;

/* 8.5.12.3 SM Power Save frame format */
typedef struct _ACTION_SM_POWER_SAVE_FRAME {
	/* MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2Duration;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* SM power save frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 ucSmPowerCtrl;	/* SM Power Control (see 8.4.1.22) */
} __KAL_ATTRIB_PACKED__ ACTION_SM_POWER_SAVE_FRAME, *P_ACTION_SM_POWER_SAVE_FRAME;

/* 8.5.12.2 Notify Channel Width frame format */
typedef struct _ACTION_NOTIFY_CHANNEL_WIDTH_FRAME {
	/* MAC header */
	UINT_16 u2FrameCtrl;	/* Frame Control */
	UINT_16 u2Duration;	/* Duration */
	UINT_8 aucDestAddr[MAC_ADDR_LEN];	/* DA */
	UINT_8 aucSrcAddr[MAC_ADDR_LEN];	/* SA */
	UINT_8 aucBSSID[MAC_ADDR_LEN];	/* BSSID */
	UINT_16 u2SeqCtrl;	/* Sequence Control */
	/* SM power save frame body */
	UINT_8 ucCategory;	/* Category */
	UINT_8 ucAction;	/* Action Value */
	UINT_8 ucChannelWidth;	/* Channel Width (see 8.4.1.21) */
} __KAL_ATTRIB_PACKED__ ACTION_NOTIFY_CHANNEL_WIDTH_FRAME, *P_ACTION_NOTIFY_CHANNEL_WIDTH_FRAME;


/* 3 Information Elements from WFA. */
typedef struct _IE_WFA_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 aucOui[3];
	UINT_8 ucOuiType;
	UINT_8 aucOuiSubTypeVersion[2];
	/*!< Please be noted. WPA defines a 16 bit field version */
	/* instead of one subtype field and one version field */
} __KAL_ATTRIB_PACKED__ IE_WFA_T, *P_IE_WFA_T;

#if CFG_SUPPORT_PASSPOINT
/* HS20 3.1 - HS 2.0 Indication Information Element */
typedef struct _IE_HS20_INDICATION_T {
	UINT_8 ucId;		/* Element ID */
	UINT_8 ucLength;	/* Length */
	UINT_8 aucOui[3];	/* OUI */
	UINT_8 ucType;		/* Type */
	UINT_8 ucHotspotConfig;	/* Hotspot Configuration */
} __KAL_ATTRIB_PACKED__ IE_HS20_INDICATION_T, *P_IE_HS20_INDICATION_T;
#endif /* CFG_SUPPORT_PASSPOINT */

/* WAPI Information element format */
typedef struct _WAPI_INFO_ELEM_T {
	UCHAR ucElemId;
	UCHAR ucLength;
	UINT_16 u2Version;
	UINT_16 u2AuthKeyMgtSuiteCount;
	UCHAR aucAuthKeyMgtSuite1[4];
} __KAL_ATTRIB_PACKED__ WAPI_INFO_ELEM_T, *P_WAPI_INFO_ELEM_T;

/* Information Elements from MTK Synergies.*/
typedef struct _IE_MTK_OUI_T {
	UINT_8 ucId;
	UINT_8 ucLength;
	UINT_8 aucOui[3];
	UINT_8 aucCapability[4];
	UINT_8 aucInfoElem[1];
} __KAL_ATTRIB_PACKED__ IE_MTK_OUI_T, *P_IE_MTK_OUI_T;

#if defined(WINDOWS_DDK) || defined(WINDOWS_CE)
#pragma pack()
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
/* Convert the ECWmin(max) to CWmin(max) */
#define ECW_TO_CW(_ECW)         ((1 << (_ECW)) - 1)

/* Convert the RCPI to dBm */
#define RCPI_TO_dBm(_rcpi)                          \
	((PARAM_RSSI)(((_rcpi) > RCPI_HIGH_BOUND ? RCPI_HIGH_BOUND : (_rcpi)) >> 1) - NDBM_LOW_BOUND_FOR_RCPI)

/* Convert the dBm to RCPI */
#define dBm_TO_RCPI(_dbm)                           \
	(RCPI)(((((PARAM_RSSI)(_dbm) + NDBM_LOW_BOUND_FOR_RCPI) << 1) > RCPI_HIGH_BOUND) ? RCPI_HIGH_BOUND : \
	((((PARAM_RSSI)(_dbm) + NDBM_LOW_BOUND_FOR_RCPI) << 1) < RCPI_LOW_BOUND ? RCPI_LOW_BOUND : \
	(((PARAM_RSSI)(_dbm) + NDBM_LOW_BOUND_FOR_RCPI) << 1)))

/* Convert an unsigned char pointer to an information element pointer */
#define IE_ID(fp)               (((P_IE_HDR_T) fp)->ucId)
#define IE_LEN(fp)              (((P_IE_HDR_T) fp)->ucLength)
#define IE_SIZE(fp)             (ELEM_HDR_LEN + IE_LEN(fp))

#define SSID_IE(fp)             ((P_IE_SSID_T) fp)

#define SUP_RATES_IE(fp)        ((P_IE_SUPPORTED_RATE_T) fp)

#define DS_PARAM_IE(fp)         ((P_IE_DS_PARAM_SET_T) fp)

#define TIM_IE(fp)              ((P_IE_TIM_T) fp)

#define IBSS_PARAM_IE(fp)       ((P_IE_IBSS_PARAM_SET_T) fp)

#define ERP_INFO_IE(fp)         ((P_IE_ERP_T) fp)

#define EXT_SUP_RATES_IE(fp)    ((P_IE_EXT_SUPPORTED_RATE_T) fp)

#define WFA_IE(fp)              ((P_IE_WFA_T) fp)

#if CFG_SUPPORT_802_11D
#define COUNTRY_IE(fp)          ((P_IE_COUNTRY_T) fp)
#endif

#define EXT_CAP_IE(fp)          ((P_EXT_CAP_T) fp)

#define POWER_CAP_IE(fp)          ((P_IE_POWER_CAP_T) fp)

#define SUP_CH_IE(fp)           ((P_IE_SUPPORTED_CHANNELS_T) fp)

#define HT_CAP_IE(fp)           ((P_IE_HT_CAP_T) fp)

#define HT_OP_IE(fp)            ((P_IE_HT_OP_T) fp)

#define VHT_CAP_IE(fp)           ((P_IE_VHT_CAP_T) fp)

#define VHT_OP_IE(fp)            ((P_IE_VHT_OP_T) fp)

#define OBSS_SCAN_PARAM_IE(fp)  ((P_IE_OBSS_SCAN_PARAM_T) fp)

#define BSS_20_40_COEXIST_IE(fp) ((P_IE_20_40_COEXIST_T) fp)

#define SUP_OPERATING_CLASS_IE(fp) ((P_IE_SUP_OPERATING_CLASS_T) fp)

#define QUIET_IE(fp)            ((P_IE_QUIET_T) fp)

#define MTK_OUI_IE(fp)          ((P_IE_MTK_OUI_T) fp)

#define CSA_IE(fp)              ((P_IE_CHANNEL_SWITCH_T) fp)

#define SUPPORTED_CHANNELS_IE(fp) ((P_IE_SUPPORTED_CHANNELS_T)fp)
#define TIMEOUT_INTERVAL_IE(fp)	((IE_TIMEOUT_INTERVAL_T *)fp)

#define SM_TPC_REQ_IE(fp) ((P_IE_TPC_REQ_T) fp)
#define SM_TPC_REP_IE(fp) ((P_IE_TPC_REPORT_T) fp)
#define SM_MEASUREMENT_REQ_IE(fp) ((P_IE_MEASUREMENT_REQ_T) fp)
#define SM_MEASUREMENT_REP_IE(fp) ((P_IE_MEASUREMENT_REPORT_T) fp)
#define SM_BASIC_REQ_IE(fp) ((P_SM_BASIC_REQ_T) fp)

/* The macro to check if the MAC address is B/MCAST Address */
#define IS_BMCAST_MAC_ADDR(_pucDestAddr)            \
	((BOOLEAN) (((PUINT_8)(_pucDestAddr))[0] & BIT(0)))

/* The macro to check if the MAC address is UCAST Address */
#define IS_UCAST_MAC_ADDR(_pucDestAddr)             \
	((BOOLEAN) !(((PUINT_8)(_pucDestAddr))[0] & BIT(0)))

/* The macro to copy the MAC address */
#define COPY_MAC_ADDR(_pucDestAddr, _pucSrcAddr)    \
	kalMemCopy(_pucDestAddr, _pucSrcAddr, MAC_ADDR_LEN)

/* The macro to check if two MAC addresses are equal */
#define EQUAL_MAC_ADDR(_pucDestAddr, _pucSrcAddr)   \
	(!kalMemCmp(_pucDestAddr, _pucSrcAddr, MAC_ADDR_LEN))

/* The macro to check if two MAC addresses are not equal */
#define UNEQUAL_MAC_ADDR(_pucDestAddr, _pucSrcAddr) \
	(kalMemCmp(_pucDestAddr, _pucSrcAddr, MAC_ADDR_LEN))

/* The macro to check whether two SSIDs are equal */
#define EQUAL_SSID(pucSsid1, ucSsidLen1, pucSsid2, ucSsidLen2) \
	((ucSsidLen1 <= ELEM_MAX_LEN_SSID) && \
	(ucSsidLen2 <= ELEM_MAX_LEN_SSID) && \
	((ucSsidLen1) == (ucSsidLen2)) && \
	!kalMemCmp(pucSsid1, pucSsid2, ucSsidLen1))

/* The macro to check whether two SSIDs are equal */
#define UNEQUAL_SSID(pucSsid1, ucSsidLen1, pucSsid2, ucSsidLen2) \
	((ucSsidLen1 > ELEM_MAX_LEN_SSID) || \
	(ucSsidLen2 > ELEM_MAX_LEN_SSID) || \
	((ucSsidLen1) != (ucSsidLen2)) || \
	kalMemCmp(pucSsid1, pucSsid2, ucSsidLen1))

/* The macro to copy the SSID, the length of pucDestSsid should have at least 32 bytes */
#define COPY_SSID(pucDestSsid, ucDestSsidLen, pucSrcSsid, ucSrcSsidLen) \
	do { \
		ucDestSsidLen = ucSrcSsidLen; \
		if (ucSrcSsidLen) { \
			ASSERT(ucSrcSsidLen <= ELEM_MAX_LEN_SSID); \
			kalMemCopy(pucDestSsid, pucSrcSsid,	\
			((ucSrcSsidLen > ELEM_MAX_LEN_SSID) ? ELEM_MAX_LEN_SSID : ucSrcSsidLen)); \
		} \
	} while (FALSE)

/* The macro to copy the IE */
#define COPY_IE(pucDestIE, pucSrcIE) \
	do { \
		kalMemCopy((PUINT_8)pucDestIE, \
		(PUINT_8)pucSrcIE,\
		IE_SIZE(pucSrcIE)); \
	} while (FALSE)

#define IE_FOR_EACH(_pucIEsBuf, _u2IEsBufLen, _u2Offset) \
	for ((_u2Offset) = 0;	\
		((((_u2Offset) + 2) <= (_u2IEsBufLen)) && (((_u2Offset) + IE_SIZE(_pucIEsBuf)) <= (_u2IEsBufLen))); \
		(_u2Offset) += IE_SIZE(_pucIEsBuf), (_pucIEsBuf) += IE_SIZE(_pucIEsBuf))

#define SET_EXT_CAP(_aucField, _ucFieldLength, _ucBit) \
			do { \
				if ((_ucBit) < ((_ucFieldLength) * 8)) { \
					PUINT_8 aucExtCap = (PUINT_8)(_aucField); \
					((aucExtCap)[(_ucBit) / 8]) |= BIT((_ucBit) % 8); \
				} \
			} while (FALSE)

/*******************************************************************************
*                   F U N C T I O N   D E C L A R A T I O N S
********************************************************************************
*/

/*******************************************************************************
*                              F U N C T I O N S
********************************************************************************
*/

#endif /* _MAC_H */
