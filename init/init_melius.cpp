#include <stdlib.h>
#include <unistd.h>

#include <android-base/logging.h>
#include <cutils/properties.h>
#include "vendor_init.h"

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void property_override_dual(char const system_prop[], char const vendor_prop[], char const value[])
{
    property_override(system_prop, value);
    property_override(vendor_prop, value);
}

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform, NULL);
    if (!rc || strncmp(platform, ANDROID_TARGET, PROP_VALUE_MAX))
        return;

    property_get("ro.bootloader", bootloader, NULL);

   if (strstr(bootloader, "I9200")) {
        /* melius3gxx */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/melius3gxx/melius3g:4.4.2/KOT49H/I9200XXUDNE4:user/release-keys");
        property_override("ro.build.description", "melius3gxx-user 4.4.2 KOT49H I9200XXUDNE4 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "GT-I9200");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "melius3gxx");
    } else if (strstr(bootloader, "I9208")) {
        /* melius3gzm */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/melius3gzm/melius3g:4.2.2/JDQ39/I9208ZMUCNB2:user/release-keys");
        property_override("ro.build.description", "melius3gzm-user 4.2.2 JDQ39 I9208ZMUCNB2 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "GT-I9208");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "melius3gzm");
    } else if (strstr(bootloader, "I9205")) {
        /* meliusltexx */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/meliusltexx/meliuslte:4.4.2/KOT49H/I9205XXUDNE4:user/release-keys");
        property_override("ro.build.description", "meliusltexx-user 4.4.2 KOT49H I9205XXUDNE4 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "GT-I9205");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "meliusltexx");
    } else if (strstr(bootloader, "L600")) {
        /* meliusltespr */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/meliusltespr/meliusltespr:4.4.2/KOT49H/L600VPUBOH1:user/release-keys");
        property_override("ro.build.description", "meliusltespr-user 4.4.2 KOT49H L600VPUBOH1 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SPH-L600");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "meliusltespr");
    } else if (strstr(bootloader, "I527M")) {
        /* meliusltecan */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/meliusltevl/meliusltecan:4.2.2/JDQ39/I527MVLUBNA3:user/release-keys");
        property_override("ro.build.description", "meliusltevl-user 4.2.2 JDQ39 I527MVLUBNA3 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SGH-I527M");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "meliusltecan");
    } else if ((strstr(bootloader, "M819N")) || (strstr(bootloader, "M819NUVUBNI5"))) {
        /* meliuslteMetroPCS */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/meliuslteMetroPCS/meliuslteMetroPCS:4.2.2/JDQ39/M819NUVUAMK7:user/release-keys");
        property_override("ro.build.description", "meliuslteMetroPCS-user 4.2.2 JDQ39 M819NUVUAMK7 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SGH-M819N");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "meliuslteMetroPCS");
    }

    property_get("ro.product.device", device, NULL);
    strlcpy(devicename, device, sizeof(devicename));
    LOG(ERROR) << "Found bootloader id " << bootloader << " setting build properties for " << devicename << " device\n";
}
