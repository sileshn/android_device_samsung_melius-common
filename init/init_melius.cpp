#include <stdlib.h>

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/properties.h>
#include <android-base/strings.h>

#include "vendor_init.h"

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

using android::base::GetProperty;
using android::base::ReadFileToString;
using android::base::Trim;

#define MODEL_NAME_LEN 5
#define SERIAL_NUMBER_FILE "/efs/FactoryApp/serial_no"

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
    const std::string bootloader = GetProperty("ro.bootloader", "");
    const std::string platform = GetProperty("ro.board.platform", "");
    const std::string model = bootloader.substr(0, MODEL_NAME_LEN);

    char const *serial_number_file = SERIAL_NUMBER_FILE;
    std::string serial_number;

    if (platform != ANDROID_TARGET)
        return;

    if (ReadFileToString(serial_number_file, &serial_number)) {
        serial_number = Trim(serial_number);
        property_override("ro.serialno", serial_number.c_str());
    }

    if (model == "I9200") {
        /* melius3gxx */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/melius3gxx/melius3g:4.4.2/KOT49H/I9200XXUDNE4:user/release-keys");
        property_override("ro.build.description", "melius3gxx-user 4.4.2 KOT49H I9200XXUDNE4 release-keys");
        property_override_dual("ro.product.model", "ro.product.vendor.model", "GT-I9200");
        property_override_dual("ro.product.device", "ro.product.vendor.device", "melius3g");
        property_override("ro.build.product", "melius3g");
    } else if (model == "I9208") {
        /* melius3gzm */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/melius3gzm/melius3g:4.2.2/JDQ39/I9208ZMUCNB2:user/release-keys");
        property_override("ro.build.description", "melius3gzm-user 4.2.2 JDQ39 I9208ZMUCNB2 release-keys");
        property_override_dual("ro.product.model", "ro.product.vendor.model", "GT-I9208");
        property_override_dual("ro.product.device", "ro.product.vendor.device", "melius3gzm");
        property_override("ro.build.product", "melius3gzm");
    } else if (model == "I9205") {
        /* meliusltexx */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/meliusltexx/meliuslte:4.4.2/KOT49H/I9205XXUDNE4:user/release-keys");
        property_override("ro.build.description", "meliusltexx-user 4.4.2 KOT49H I9205XXUDNE4 release-keys");
        property_override_dual("ro.product.model", "ro.product.vendor.model", "GT-I9205");
        property_override_dual("ro.product.device", "ro.product.vendor.device", "meliuslte");
        property_override("ro.build.product", "meliuslte");
    } else if (model == "L600") {
        /* meliusltespr */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/meliusltespr/meliusltespr:4.4.2/KOT49H/L600VPUBOH1:user/release-keys");
        property_override("ro.build.description", "meliusltespr-user 4.4.2 KOT49H L600VPUBOH1 release-keys");
        property_override_dual("ro.product.model", "ro.product.vendor.model", "SPH-L600");
        property_override_dual("ro.product.device", "ro.product.vendor.device", "meliusltespr");
        property_override("ro.build.product", "meliusltespr");
    } else if (model == "I527M") {
        /* meliusltecan */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/meliusltevl/meliusltecan:4.2.2/JDQ39/I527MVLUBNA3:user/release-keys");
        property_override("ro.build.description", "meliusltevl-user 4.2.2 JDQ39 I527MVLUBNA3 release-keys");
        property_override_dual("ro.product.model", "ro.product.vendor.model", "SGH-I527M");
        property_override_dual("ro.product.device", "ro.product.vendor.device", "meliusltecan");
        property_override("ro.build.product", "meliusltecan");
    } else if ((model == "M819N") || (model == "M819NUVUBNI5")) {
        /* meliuslteMetroPCS */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/meliuslteMetroPCS/meliuslteMetroPCS:4.2.2/JDQ39/M819NUVUAMK7:user/release-keys");
        property_override("ro.build.description", "meliuslteMetroPCS-user 4.2.2 JDQ39 M819NUVUAMK7 release-keys");
        property_override_dual("ro.product.model", "ro.product.vendor.model", "SGH-M819N");
        property_override_dual("ro.product.device", "ro.product.vendor.device", "meliuslteMetroPCS");
        property_override("ro.build.product", "meliuslteMetroPCS");
    }

    const std::string device = GetProperty("ro.product.device", "");
    LOG(INFO) << "Found bootloader " << bootloader << ". " << "Setting build properties for " << device << ".\n";
}
