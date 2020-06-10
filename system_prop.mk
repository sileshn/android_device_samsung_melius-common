# RIL
PRODUCT_PROPERTY_OVERRIDES += \
    ro.com.android.mobiledata=false \
    persist.radio.add_power_save=1 \
    persist.radio.apm_sim_not_pwdn=1 \
    persist.radio.no_wait_for_card=1

# GPS
PRODUCT_PROPERTY_OVERRIDES += \
    persist.gps.qc_nlp_in_use=1 \
    ro.gps.agps_provider=1

# Media
PRODUCT_PROPERTY_OVERRIDES += \
    audio.offload.disable=1 \
    debug.stagefright.ccodec=0 \
    persist.vendor.audio.fluence.speaker=true \
    persist.vendor.audio.fluence.voicecall=true \
    ro.vendor.audio.sdk.fluencetype=fluence \
    ro.vendor.fm.use_audio_session=true \
    vendor.dedicated.device.for.voip=true \
    vendor.voice.path.for.pcm.voip=true

# Graphics
PRODUCT_PROPERTY_OVERRIDES += \
    debug.composition.type=c2d \
    debug.hwui.use_buffer_age=false \
    debug.sf.enable_gl_backpressure=1 \
    ro.sf.lcd_density=240 \
    ro.opengles.version=196608 \
    ro.qualcomm.cabl=0 \
    ro.hwui.text_large_cache_height=2048

# Camera
PRODUCT_PROPERTY_OVERRIDES += \
    camera2.portability.force_api=1 \
    debug.camcorder.disablemeta=true

# Bluetooth
PRODUCT_PROPERTY_OVERRIDES += \
    ro.bt.bdaddr_path=/efs/bluetooth/bt_addr \
    ro.qualcomm.bt.hci_transport=smd

# Misc
PRODUCT_PROPERTY_OVERRIDES += \
    ro.chipname=MSM8930AB \
    wifi.direct.interface=p2p0 \
    wifi.interface=wlan0

# QC Perf
PRODUCT_PROPERTY_OVERRIDES += \
    ro.vendor.extension_library=libqti-perfd-client.so

# Dalvik
PRODUCT_PROPERTY_OVERRIDES += \
    dalvik.vm.dex2oat-swap=false

# Enable traced by default
PRODUCT_PROPERTY_OVERRIDES += \
    persist.traced.enable=1

# Vendor security patch level
PRODUCT_PROPERTY_OVERRIDES += \
    ro.lineage.build.vendor_security_patch=2016-08-01

# Set default locale
PRODUCT_PROPERTY_OVERRIDES += \
    ro.product.locale=en-GB

# LMKD
PRODUCT_PROPERTY_OVERRIDES += \
    ro.lmk.critical_upgrade=true \
    ro.lmk.downgrade_pressure=60 \
    ro.lmk.kill_heaviest_task=false \
    ro.lmk.log_stats=true \
    ro.lmk.upgrade_pressure=40 \
    ro.lmk.use_psi=false
