LOCAL_PATH := $(call my-dir)

ifeq ($(shell echo $(BOARD_WLAN_DEVICE) | tr '[A-Z]' '[a-z]'),mediatek)
    include $(call all-makefiles-under,$(LOCAL_PATH))
endif
