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
** Id: //Department/DaVinci/BRANCHES/MT6620_WIFI_DRIVER_V2_3/include/debug.h#1
*/

/*! \file   debug.h
*    \brief  Definition of SW debugging level.
*
*    In this file, it describes the definition of various SW debugging levels and
*    assert functions.
*/

#ifndef _DEBUG_H
#define _DEBUG_H

/*******************************************************************************
*                         C O M P I L E R   F L A G S
********************************************************************************
*/
#ifndef BUILD_QA_DBG
#define BUILD_QA_DBG 0
#endif

#define DBG_DISABLE_ALL_LOG             0

/*******************************************************************************
*                    E X T E R N A L   R E F E R E N C E S
********************************************************************************
*/
#include "gl_typedef.h"

extern UINT_8 aucDebugModule[];

/*******************************************************************************
*                              C O N S T A N T S
********************************************************************************
*/
/* Define debug category (class):
 * (1) ERROR (2) WARN (3) STATE (4) EVENT (5) TRACE (6) INFO (7) LOUD (8) TEMP
 */
#define DBG_CLASS_ERROR         BIT(0)
#define DBG_CLASS_WARN          BIT(1)
#define DBG_CLASS_STATE         BIT(2)
#define DBG_CLASS_EVENT         BIT(3)
#define DBG_CLASS_TRACE         BIT(4)
#define DBG_CLASS_INFO          BIT(5)
#define DBG_CLASS_LOUD          BIT(6)
#define DBG_CLASS_TEMP          BIT(7)
#define DBG_CLASS_MASK          BITS(0, 7)

#if defined(LINUX)
#define DBG_PRINTF_64BIT_DEC    "lld"
#else /* Windows */
#define DBG_PRINTF_64BIT_DEC    "I64d"
#endif
#define DBG_ALL_MODULE_IDX      0xFFFFFFFF
/*******************************************************************************
*                             D A T A   T Y P E S
********************************************************************************
*/
/* Define debug module index */
typedef enum _ENUM_DBG_MODULE_T {
	DBG_INIT_IDX = 0,	/* 0x00 *//* For driver initial */
	DBG_HAL_IDX,		/* 0x01 *//* For HAL(HW) Layer */
	DBG_INTR_IDX,		/* 0x02 *//* For Interrupt */
	DBG_REQ_IDX,		/* 0x03 */
	DBG_TX_IDX,		/* 0x04 */
	DBG_RX_IDX,		/* 0x05 */
	DBG_RFTEST_IDX,		/* 0x06 *//* For RF test mode */
	DBG_EMU_IDX,		/* 0x07 *//* Developer specific */
	DBG_SW1_IDX,		/* 0x08 *//* Developer specific */
	DBG_SW2_IDX,		/* 0x09 *//* Developer specific */
	DBG_SW3_IDX,		/* 0x0A *//* Developer specific */
	DBG_SW4_IDX,		/* 0x0B *//* Developer specific */
	DBG_HEM_IDX,		/* 0x0C *//* HEM */
	DBG_AIS_IDX,		/* 0x0D *//* AIS */
	DBG_RLM_IDX,		/* 0x0E *//* RLM */
	DBG_MEM_IDX,		/* 0x0F *//* RLM */
	DBG_CNM_IDX,		/* 0x10 *//* CNM */
	DBG_RSN_IDX,		/* 0x11 *//* RSN */
	DBG_BSS_IDX,		/* 0x12 *//* BSS */
	DBG_SCN_IDX,		/* 0x13 *//* SCN */
	DBG_SAA_IDX,		/* 0x14 *//* SAA */
	DBG_AAA_IDX,		/* 0x15 *//* AAA */
	DBG_P2P_IDX,		/* 0x16 *//* P2P */
	DBG_QM_IDX,		/* 0x17 *//* QUE_MGT */
	DBG_SEC_IDX,		/* 0x18 *//* SEC */
	DBG_BOW_IDX,		/* 0x19 *//* BOW */
	DBG_WAPI_IDX,		/* 0x1A *//* WAPI */
	DBG_ROAMING_IDX,	/* 0x1B *//* ROAMING */
	DBG_TDLS_IDX,		/* 0x1C *//* TDLS *//* CFG_SUPPORT_TDLS */
	DBG_PF_IDX,		/* 0x1D *//* PF */
	DBG_OID_IDX,
	DBG_NIC_IDX,
#if (HIF_TX_RSRC_WMM_ENHANCE == 1)
	DBG_HIF_WMM_ENHANCE_IDX,
#endif
	DBG_MODULE_NUM		/* Notice the XLOG check */
} ENUM_DBG_MODULE_T;
typedef enum _ENUM_DBG_ASSERT_CTRL_LEVEL_T {
	DBG_ASSERT_CTRL_LEVEL_ERROR,
	DBG_ASSERT_CTRL_LEVEL_WARN,
	DBG_ASSERT_CTRL_LEVEL_LITE
} ENUM_DBG_ASSERT_LEVEL_CTRL_T, *P_ENUM_DBG_ASSERT_LEVEL_CTRL_T;
typedef enum _ENUM_DBG_ASSERT_PATH_T {
	DBG_ASSERT_PATH_WIFI,
	DBG_ASSERT_PATH_WMT
} ENUM_DBG_ASSERT_PATH_T, *P_ENUM_DBG_ASSERT_PATH_T;
#if MTK_WCN_HIF_SDIO
#define DBG_ASSERT_PATH_DEFAULT DBG_ASSERT_PATH_WMT
#else
#define DBG_ASSERT_PATH_DEFAULT DBG_ASSERT_PATH_WIFI
#endif
#define DBG_ASSERT_CTRL_LEVEL_DEFAULT DBG_ASSERT_CTRL_LEVEL_ERROR
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
/* Debug print format string for the OS system time */
#define OS_SYSTIME_DBG_FORMAT               "0x%08x"
/* Debug print argument for the OS system time */
#define OS_SYSTIME_DBG_ARGUMENT(systime)    (systime)
/* Debug print format string for the MAC Address */
#define MACSTR		"%pM"
/* Debug print argument for the MAC Address */
#define MAC2STR(a)	a
/* Debug print format string for the IPv4 Address */
#define IPV4STR		"%pI4"
/* Debug print argument for the IPv4 Address */
#define IPV4TOSTR(a)	a
/* Debug print format string for the MAC Address */
#define IPV6STR		"%pI6"
/* Debug print argument for the MAC Address */
#define IPV6TOSTR(a)	a
/* The pre-defined format to dump the value of a varaible with its name shown. */
#define DUMPVAR(variable, format)           (#variable " = " format "\n", variable)
/* The pre-defined format to dump the MAC type value with its name shown. */
#define DUMPMACADDR(addr)                   (#addr " = " MACSTR "\n", MAC2STR(addr))
/* Debug print format string for the floating point */
#define FPSTR		"%u.%u"
/* Debug print argument for the floating point */
#define DIV2INT(_dividend, _divisor) ((_divisor) ? (_dividend) / (_divisor) : 0)
#define DIV2DEC(_dividend, _divisor) ((_divisor) ? (((_dividend) * 100) / (_divisor)) % 100 : 0)
/* Basiclly, we just do renaming of KAL functions although they should
 * be defined as "Nothing to do" if DBG=0. But in some compiler, the macro
 * syntax does not support  #define LOG_FUNC(x,...)
 *
 * A caller shall not invoke these three macros when DBG=0.
 */
#define LOG_FUNC                kalPrint
/* If __FUNCTION__ is already defined by compiler, we just use it. */
#define DEBUGFUNC(_Func)
/* Disabled due to AOSP
*#if defined(__FUNCTION__)
*#define DEBUGFUNC(_Func)
*#else
*    #define DEBUGFUNC(_Func) static const char __FUNCTION__[] = _Func;
*#endif
*/
#if DBG_DISABLE_ALL_LOG
#define DBGLOG(_Module, _Class, _Fmt)
#define DBGLOG_MEM8(_Module, _Class, _StartAddr, _Length)
#define DBGLOG_MEM32(_Module, _Class, _StartAddr, _Length)
#else
#define DBGLOG(_Module, _Class, _Fmt, ...) \
	do { \
		if ((aucDebugModule[DBG_##_Module##_IDX] & DBG_CLASS_##_Class) == 0) \
			break; \
		LOG_FUNC("[%u]%s:(" #_Module " " #_Class ") " _Fmt, KAL_GET_CURRENT_THREAD_ID(), \
			 __func__, ##__VA_ARGS__); \
	} while (0)
#define TOOL_PRINTLOG(_Module, _Class, _Fmt, ...) \
	do { \
		if ((aucDebugModule[DBG_##_Module##_IDX] & DBG_CLASS_##_Class) == 0) \
			break; \
		LOG_FUNC(_Fmt, ##__VA_ARGS__); \
	} while (0)
#define DBGLOG_MEM8(_Module, _Class, _StartAddr, _Length) \
	{ \
		if (aucDebugModule[DBG_##_Module##_IDX] & DBG_CLASS_##_Class) { \
			LOG_FUNC("%s:(" #_Module " " #_Class ")\n", __func__); \
			dumpMemory8((PUINT_8)(_StartAddr), (UINT_32)(_Length)); \
		} \
	}
#define DBGLOG_MEM32(_Module, _Class, _StartAddr, _Length) \
	{ \
		if (aucDebugModule[DBG_##_Module##_IDX] & DBG_CLASS_##_Class) { \
			LOG_FUNC("%s:(" #_Module " " #_Class ")\n", __func__); \
			dumpMemory32((PUINT_32)(_StartAddr), (UINT_32)(_Length)); \
		} \
	}
#endif
#define DISP_STRING(_str)       _str
#undef ASSERT
#undef ASSERT_REPORT
#if (BUILD_QA_DBG || DBG)
#ifdef _lint
#define ASSERT(_exp) \
	{ \
		if (!(_exp)) { \
			do {} while (1); \
		} \
	}
#define ASSERT_REPORT(_exp, _fmt) \
	{ \
		LOG_FUNC("Assertion failed: %s:%d (%s)\n", __FILE__, __LINE__, #_exp); \
		LOG_FUNC _fmt; \
		if (!(_exp)) { \
			do {} while (1); \
		} \
	}
#elif defined(WINDOWS_CE)
#define UNICODE_TEXT(_msg)  TEXT(_msg)
#define ASSERT(_exp) \
	{ \
		if (!(_exp) && !fgIsBusAccessFailed) { \
			TCHAR rUbuf[256]; \
			kalBreakPoint(); \
			_stprintf(rUbuf, TEXT("Assertion failed: %s:%d %s\n"), \
				  UNICODE_TEXT(__FILE__), __LINE__, UNICODE_TEXT(#_exp)); \
			MessageBox(NULL, rUbuf, TEXT("ASSERT!"), MB_OK); \
		} \
	}
#define ASSERT_REPORT(_exp, _fmt) \
	{ \
		if (!(_exp) && !fgIsBusAccessFailed) { \
			TCHAR rUbuf[256]; \
			kalBreakPoint(); \
			_stprintf(rUbuf, TEXT("Assertion failed: %s:%d %s\n"), \
				  UNICODE_TEXT(__FILE__), __LINE__, UNICODE_TEXT(#_exp)); \
			MessageBox(NULL, rUbuf, TEXT("ASSERT!"), MB_OK); \
		} \
	}
#else
#define ASSERT(_exp) \
	{ \
		if (!(_exp) && !fgIsBusAccessFailed) { \
			LOG_FUNC("Assertion failed: %s:%d (%s)\n", __FILE__, __LINE__, #_exp); \
			kalBreakPoint(); \
		} \
	}
#define ASSERT_REPORT(_exp, _fmt) \
	{ \
		if (!(_exp) && !fgIsBusAccessFailed) { \
			LOG_FUNC("Assertion failed: %s:%d (%s)\n", __FILE__, __LINE__, #_exp); \
			LOG_FUNC _fmt; \
			kalBreakPoint(); \
		} \
	}
#endif /* WINDOWS_CE */
#else
#define ASSERT(_exp)
#define ASSERT_REPORT(_exp, _fmt)
#endif /* BUILD_QA_DBG */
/* LOG function for print to buffer */
/* If buffer pointer is NULL, redirect to normal DBGLOG */
#define LOGBUF(_pucBuf, _maxLen, _curLen, _Fmt, ...) \
	do { \
		if (_pucBuf) \
			(_curLen) += kalScnprintf((_pucBuf) + (_curLen), (_maxLen) - (_curLen), _Fmt, ##__VA_ARGS__); \
		else \
			DBGLOG(SW4, INFO, _Fmt, ##__VA_ARGS__); \
	} while (0)
/* The following macro is used for debugging packed structures. */
#ifndef DATA_STRUCT_INSPECTING_ASSERT
#define DATA_STRUCT_INSPECTING_ASSERT(expr) \
{ \
	switch (0) {case 0: case (expr): default:; } \
}
#endif
/*******************************************************************************
*                  F U N C T I O N   D E C L A R A T I O N S
********************************************************************************
*/
VOID dumpMemory8(IN PUINT_8 pucStartAddr, IN UINT_32 u4Length);
VOID dumpMemory32(IN PUINT_32 pu4StartAddr, IN UINT_32 u4Length);
/*******************************************************************************
*                              F U N C T I O N S
********************************************************************************
*/
#endif /* _DEBUG_H */


