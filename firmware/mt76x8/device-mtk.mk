CUR_PATH := vendor/amazon/wlan/mediatek/firmware/mt76x8
COPY_PATH := system/etc/firmware

ifeq ($(TARGET_DEVICE),)
TARGET_DEVICE := $(TARGET_PRODUCT)
endif

ifeq ($(TARGET_DEVICE), $(filter steffi foraker_eu, $(TARGET_DEVICE)))
TARGET_DEVICE := sophia
endif

ifeq ($(TARGET_DEVICE), $(filter duckie_mtk, $(TARGET_DEVICE)))
TARGET_DEVICE := duckie
endif

ifeq ($(TARGET_DEVICE), $(filter blanche keira leela, $(TARGET_DEVICE)))
COPY_PATH := system/etc/firmware
else
COPY_PATH := $(TARGET_COPY_OUT_VENDOR)/firmware
endif

FW_HIF := $(filter sdio usb, $(subst _, ,$(WIFI_DRIVER_MODULE_NAME)))
FW_HIF := $(shell echo $(FW_HIF) | tr '[a-z]' '[A-Z]')

# firmware
PRODUCT_COPY_FILES += \
    $(CUR_PATH)/$(TARGET_DEVICE)/EEPROM_MT7668.bin:$(COPY_PATH)/EEPROM_MT7668.bin \
    $(CUR_PATH)/$(TARGET_DEVICE)/WIFI_RAM_CODE2_$(FW_HIF)_MT7668.bin:$(COPY_PATH)/WIFI_RAM_CODE2_$(FW_HIF)_MT7668.bin \
    $(CUR_PATH)/$(TARGET_DEVICE)/WIFI_RAM_CODE_MT7668.bin:$(COPY_PATH)/WIFI_RAM_CODE_MT7668.bin \
    $(CUR_PATH)/$(TARGET_DEVICE)/mt7668_patch_e2_hdr.bin:$(COPY_PATH)/mt7668_patch_e2_hdr.bin

# config file
PRODUCT_COPY_FILES += \
    $(CUR_PATH)/$(TARGET_DEVICE)/wpa_supplicant.conf:/system/etc/wifi/wpa_supplicant.conf \
    $(CUR_PATH)/$(TARGET_DEVICE)/wifi.cfg:$(COPY_PATH)/wifi.cfg

# WoBLE enabling (need to be set before including this file)
ifeq ($(BT_DRIVER_WOBLE_SETTING), true)
PRODUCT_COPY_FILES += \
    $(CUR_PATH)/$(TARGET_DEVICE)/woble_setting.bin:$(COPY_PATH)/woble_setting.bin
endif

# currently only have a few devices have TxPwrLimt dat ready, only merge them into image
# Once all of them are ready, will remove device check
ifeq ($(TARGET_DEVICE), $(filter lidar pablo donut mantis lagunaf raven cupcake, $(TARGET_DEVICE)))
PRODUCT_COPY_FILES += $(CUR_PATH)/$(TARGET_DEVICE)/TxPwrLimit_MT76x8.dat:$(COPY_PATH)/TxPwrLimit_MT76x8.dat
endif
