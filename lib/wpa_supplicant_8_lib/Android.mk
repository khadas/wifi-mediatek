#
# Copyright (C) 2008 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

#ifeq ($(WPA_SUPPLICANT_VERSION),VER_0_8_X)

ifneq ($(BOARD_WPA_SUPPLICANT_DRIVER),)
  CONFIG_DRIVER_$(BOARD_WPA_SUPPLICANT_DRIVER) := y
endif

CONFIG_DRIVER_NL80211 :=y

WPA_SUPPL_DIR = external/wpa_supplicant_8
WPA_SRC_FILE :=

include $(WPA_SUPPL_DIR)/wpa_supplicant/android.config

WPA_SUPPL_DIR_INCLUDE = $(WPA_SUPPL_DIR)/src \
	$(WPA_SUPPL_DIR)/src/common \
	$(WPA_SUPPL_DIR)/src/drivers \
	$(WPA_SUPPL_DIR)/src/l2_packet \
	$(WPA_SUPPL_DIR)/src/utils \
	$(WPA_SUPPL_DIR)/src/wps \
	$(WPA_SUPPL_DIR)/wpa_supplicant

WPA_SUPPL_DIR_INCLUDE += external/libnl/include

ifdef CONFIG_DRIVER_NL80211
WPA_SUPPL_DIR_INCLUDE += external/libnl-headers
WPA_SRC_FILE += driver_cmd_nl80211.c
endif

ifeq ($(TARGET_ARCH),arm)
# To force sizeof(enum) = 4
L_CFLAGS += -mabi=aapcs-linux
endif

ifdef CONFIG_ANDROID_LOG
L_CFLAGS += -DCONFIG_ANDROID_LOG
endif

ifeq ($(CONFIG_MANUAL_GO_PASSPHRASE_SUPPORT), y)
L_CFLAGS += -DCONFIG_MANUAL_GO_PASSPHRASE_SUPPORT
L_CFLAGS += -DCONFIG_DEBUG_MANUAL_GO_PASSPHRASE_SUPPORT
endif

ifdef CONFIG_P2P_DISCONNECT_SUPPORT
L_CFLAGS += -DCONFIG_P2P_DISCONNECT_SUPPORT
endif

ifeq ($(CONFIG_SYSTEM_TIMESTAMP), y)
L_CFLAGS += -DCONFIG_SYSTEM_TIMESTAMP
endif

ifeq ($(CONFIG_FIXED_P2P_LISTEN_CHANNEL), y)
L_CFLAGS += -DCONFIG_FIXED_P2P_LISTEN_CHANNEL=1
endif

ifeq ($(CONFIG_FIXED_P2P_OP_CHANNEL), y)
L_CFLAGS += -DCONFIG_FIXED_P2P_OP_CHANNEL=1
endif

ifeq ($(CONFIG_P2P_LISTEN_CH_FOLLOW_AP), y)
L_CFLAGS += -DCONFIG_P2P_LISTEN_CH_FOLLOW_AP
endif
ifeq ($(CONFIG_ACL_SUPPORT), y)
L_CFLAGS += -DCONFIG_ACL_SUPPORT
endif
ifeq ($(CONFIG_WOW_SUPPORT), y)
L_CFLAGS += -DCONFIG_WOW_SUPPORT
endif

ifeq ($(CONFIG_ACTIVE_CHANNEL_SCAN_SUPPORT), y)
L_CFLAGS += -DCONFIG_ACTIVE_CHANNEL_SCAN_SUPPORT
endif

ifeq ($(CONFIG_ACS_SUPPORT), y)
L_CFLAGS += -DCONFIG_ACS_SUPPORT
endif

ifeq ($(CONFIG_CONSISTENT_P2P_IF_NAME), y)
L_CFLAGS += -DCONFIG_CONSISTENT_P2P_IF_NAME
endif

ifeq ($(CONFIG_SUPPORT_GET_LISTEN_FREQ), y)
L_CFLAGS += -DCONFIG_SUPPORT_GET_LISTEN_FREQ
endif

ifeq ($(CONFIG_SUPPORT_GET_P2P_INFOR), y)
L_CFLAGS += -DCONFIG_SUPPORT_GET_P2P_INFOR
endif

ifeq ($(CONFIG_SUPPORT_SET_GO_INTENT), y)
L_CFLAGS += -DCONFIG_SUPPORT_SET_GO_INTENT
endif

ifeq ($(CONFIG_SET_5G_HIGHER_PRIORITY), y)
L_CFLAGS += -DCONFIG_SET_5G_HIGHER_PRIORITY
endif

ifeq ($(CONFIG_SUPPORT_GET_WFD_ASSOCBSSID_IN_CONN_MSG), y)
L_CFLAGS += -DCONFIG_SUPPORT_GET_WFD_ASSOCBSSID_IN_CONN_MSG
endif

ifeq ($(CONFIG_BLOCK_STA_SCAN_CMD_SUPPORT), y)
L_CFLAGS += -DCONFIG_BLOCK_STA_SCAN_CMD_SUPPORT
endif

ifeq ($(CONFIG_DYNAMIC_BSS_RESULT_BUFFER), y)
L_CFLAGS += -DDYNAMIC_BSS_RESULT_BUFFER
endif

ifeq ($(CONFIG_DISABLE_WPA2_AUTH_FLAG_IN_WPS), y)
L_CFLAGS += -DCONFIG_DISABLE_WPA2_AUTH_FLAG_IN_WPS
endif

ifeq ($(CONFIG_SUPPORT_SET_OP_FREQ), y)
L_CFLAGS += -DCONFIG_SUPPORT_SET_OP_FREQ
endif

ifeq ($(CONFIG_P2P_GET_ALL_KEYS_SUPPORT), y)
L_CFLAGS += -DCONFIG_P2P_GET_ALL_KEYS_SUPPORT
endif

ifeq ($(-DCONFIG_CUSTOMIZED_FEATURE_SUPPORT), y)
L_CFLAGS += -DCONFIG_CUSTOMIZED_FEATURE_SUPPORT
endif

ifeq ($(CONFIG_SHARED_P2P_MAC_ADDR), y)
L_CFLAGS += -DCONFIG_SHARED_P2P_MAC_ADDR
endif

########################

include $(CLEAR_VARS)
LOCAL_MODULE := lib_driver_cmd_mtk
LOCAL_SHARED_LIBRARIES := libc libcutils liblog
LOCAL_CFLAGS := $(L_CFLAGS)
LOCAL_SRC_FILES := $(WPA_SRC_FILE)
LOCAL_C_INCLUDES := $(WPA_SUPPL_DIR_INCLUDE)
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk
include $(BUILD_STATIC_LIBRARY)

########################

#endif
