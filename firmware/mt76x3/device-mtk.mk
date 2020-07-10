CUR_PATH := vendor/amazon/wlan/mediatek/firmware/mt76x3

ifeq ($(TARGET_DEVICE),)
TARGET_DEVICE := $(TARGET_PRODUCT)
endif

ifeq ($(WIFI_DRIVER_MODULE_PATH),)
WIFI_DRIVER_MODULE_PATH_IN_DRV := $(WIFI_DRIVER_MODULE_PATH_FOR_DRV)
else
WIFI_DRIVER_MODULE_PATH_IN_DRV := $(WIFI_DRIVER_MODULE_PATH)
endif

ifeq ($(WIFI_DRIVER_MODULE_NAME),)
WIFI_DRIVER_MODULE_NAME_IN_DRV := $(WIFI_DRIVER_MODULE_NAME_FOR_DRV)
else
WIFI_DRIVER_MODULE_NAME_IN_DRV := $(WIFI_DRIVER_MODULE_NAME)
endif

COPY_PATH := $(TARGET_COPY_OUT_VENDOR)/firmware

FW_HIF := $(filter sdio usb, $(subst _, ,$(WIFI_DRIVER_MODULE_NAME_IN_DRV)))
FW_HIF := $(shell echo $(FW_HIF) | tr '[a-z]' '[A-Z]')

# firmware
PRODUCT_COPY_FILES += \
    $(CUR_PATH)/$(TARGET_DEVICE)/EEPROM_MT7663.bin:$(COPY_PATH)/EEPROM_MT7663.bin \
    $(CUR_PATH)/$(TARGET_DEVICE)/WIFI_RAM_CODE_MT7663.bin:$(COPY_PATH)/WIFI_RAM_CODE_MT7663.bin \
    $(CUR_PATH)/$(TARGET_DEVICE)/mt7663_patch_e2_hdr.bin:$(COPY_PATH)/mt7663_patch_e2_hdr.bin

# config file
PRODUCT_COPY_FILES += \
    $(CUR_PATH)/$(TARGET_DEVICE)/wifi.cfg:$(COPY_PATH)/wifi.cfg \
    $(CUR_PATH)/$(TARGET_DEVICE)/bt.cfg:$(COPY_PATH)/bt.cfg

# WoBLE enabling (need to be set before including this file)
ifeq ($(BT_DRIVER_WOBLE_SETTING), true)
PRODUCT_COPY_FILES += \
    $(CUR_PATH)/$(TARGET_DEVICE)/woble_setting_7663.bin:$(COPY_PATH)/woble_setting_7663.bin
endif

PRODUCT_COPY_FILES += $(CUR_PATH)/$(TARGET_DEVICE)/TxPwrLimit_MT76x3.dat:$(COPY_PATH)/TxPwrLimit_MT76x3.dat
