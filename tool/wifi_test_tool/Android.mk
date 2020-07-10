LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := libcutils

EEPROM_BIN := EEPROM_MT7668.bin
BIN_PATH := system/etc/firmware
TMP_PATH := /data/local/tmp
WRITE_PATH := /data

ifeq ($(strip $(MTK_COMBO_CHIP)), MT7668)
EEPROM_BIN := EEPROM_MT7668.bin
endif
ifeq ($(strip $(MTK_COMBO_CHIP)), MT7663)
EEPROM_BIN := EEPROM_MT7663.bin
endif


ifdef WIFI_DRIVER_FW_PATH_PARAM
BIN_PATH := $(WIFI_DRIVER_FW_PATH_PARAM)
else
ifneq ($(filter keira blanche, $(TARGET_DEVICE)),)
BIN_PATH := /system/etc/firmware
else
BIN_PATH := $(TARGET_COPY_OUT_VENDOR)/firmware
endif
endif

include $(CLEAR_VARS)
LOCAL_MODULE := wifitest
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk
LOCAL_MODULE_TAGS := optional
LOCAL_CFLAGS += -DEEPROM_FILE=\"$(BIN_PATH)/$(EEPROM_BIN)\"
LOCAL_CFLAGS += -DEEPROM_TMP_FILE=\"$(TMP_PATH)/$(EEPROM_BIN)\"
LOCAL_CFLAGS += -DEEPROM_WRITE_FILE=\"$(WRITE_PATH)/$(EEPROM_BIN)\"
LOCAL_CFLAGS += -Wall
LOCAL_SRC_FILES := main.c lib.c libwifitest.c

include $(BUILD_EXECUTABLE)
