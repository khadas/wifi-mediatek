LOCAL_PATH := $(call my-dir)
ifeq ($(BOARD_WLAN_DEVICE),mediatek)
     include $(LOCAL_PATH)/$(BOARD_MTK_WLAN_CHIP)/Android.mk
endif
