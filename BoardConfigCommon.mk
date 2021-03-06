# Copyright (C) 2013 The CyanogenMod Project
# Copyright (C) 2017-2019 The LineageOS Project
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
# This file sets variables that control the way modules are built
# thorughout the system. It should not be used to conditionally
# disable makefiles (the proper mechanism to control what gets
# included in a build is to use PRODUCT_PACKAGES in a product
# definition file).
#

COMMON_PATH := device/samsung/melius-common

# Inherit from common msm8930
-include device/samsung/msm8930-common/BoardConfigCommon.mk

# Includes
TARGET_SPECIFIC_HEADER_PATH += $(COMMON_PATH)/include

# Manifests
DEVICE_MANIFEST_FILE += $(COMMON_PATH)/manifest.xml

# Kernel
BOARD_KERNEL_CMDLINE         := androidboot.hardware=qcom user_debug=22 msm_rtb.filter=0x3F ehci-hcd.park=3 androidboot.bootdevice=msm_sdcc.1
BOARD_KERNEL_CMDLINE         += androidboot.selinux=permissive
BOARD_KERNEL_BASE            := 0x80200000
BOARD_KERNEL_IMAGE_NAME      := zImage
BOARD_MKBOOTIMG_ARGS         := --ramdisk_offset 0x02000000
BOARD_KERNEL_PAGESIZE        := 2048
BOARD_RAMDISK_USE_XZ 		 := true
TARGET_KERNEL_SOURCE         := kernel/samsung/msm8930-common
TARGET_KERNEL_CONFIG         := samsung_melius_defconfig

# Bootloader
TARGET_BOOTLOADER_BOARD_NAME := MSM8960

# Recovery
TARGET_RECOVERY_FSTAB := $(COMMON_PATH)/rootdir/fstab.qcom

# Filesystem
TARGET_FS_CONFIG_GEN := $(COMMON_PATH)/config.fs
TARGET_USERIMAGES_USE_EXT4 := true
BOARD_BOOTIMAGE_PARTITION_SIZE := 10485760
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 11430000
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 1572864000
BOARD_SYSTEMIMAGE_JOURNAL_SIZE := 0
BOARD_USERDATAIMAGE_PARTITION_SIZE := 5649710080
BOARD_CACHEIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_CACHEIMAGE_PARTITION_SIZE := 209715200
BOARD_FLASH_BLOCK_SIZE := 131072
BOARD_ROOT_EXTRA_FOLDERS := efs firmware persist
BOARD_ROOT_EXTRA_SYMLINKS := /data/tombstones:/tombstones

# Bluetooth
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(COMMON_PATH)/bluetooth

# GPS
BOARD_VENDOR_QCOM_GPS_LOC_API_HARDWARE := $(TARGET_BOARD_PLATFORM)
BOARD_VENDOR_QCOM_LOC_PDK_FEATURE_SET := true
TARGET_NO_RPC := true

# Camera
TARGET_NEED_CAMERA_ZSL := true
TARGET_NEED_FFC_PICTURE_FIXUP := true
TARGET_NEED_FFC_VIDEO_FIXUP := true
TARGET_NEED_DISABLE_FACE_DETECTION := true
TARGET_NEED_DISABLE_FACE_DETECTION_BOTH_CAMERAS := true

# Lights
TARGET_PROVIDES_LIBLIGHT := true

# Shims
TARGET_LD_SHIM_LIBS := \
    /system/vendor/lib/libperipheral_client.so|libshim_binder.so

# TWRP
ifeq ($(WITH_TWRP),true)
-include $(COMMON_PATH)/twrp.mk
endif

# Vendor init
TARGET_INIT_VENDOR_LIB := //$(COMMON_PATH):libinit_melius
TARGET_RECOVERY_DEVICE_MODULES := libinit_melius
