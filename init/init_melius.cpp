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

// copied from build/tools/releasetools/ota_from_target_files.py
// but with "." at the end and empty entry
std::vector<std::string> ro_product_props_default_source_order = {
    "",
    "product.",
    "product_services.",
    "odm.",
    "vendor.",
    "system.",
	"system_ext.",
};

void property_override(char const prop[], char const value[], bool add = true)
{
    auto pi = (prop_info *) __system_property_find(prop);

    if (pi != nullptr) {
        __system_property_update(pi, value, strlen(value));
    } else if (add) {
        __system_property_add(prop, strlen(prop), value, strlen(value));
    }
}

void vendor_load_properties()
{
    const std::string bootloader = GetProperty("ro.bootloader", "");
    const std::string model = bootloader.substr(0, MODEL_NAME_LEN);

    char const *serial_number_file = SERIAL_NUMBER_FILE;
    std::string serial_number;

    if (ReadFileToString(serial_number_file, &serial_number)) {
        serial_number = Trim(serial_number);
        property_override("ro.serialno", serial_number.c_str());
    }

    const auto set_ro_product_prop = [](const std::string &source,
            const std::string &prop, const std::string &value) {
        auto prop_name = "ro.product." + source + prop;
        property_override(prop_name.c_str(), value.c_str(), false);
    };

    if (model == "I9200") {
        /* melius3gxx */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/melius3gxx/melius3g:4.4.2/KOT49H/I9200XXUDNE4:user/release-keys");
            set_ro_product_prop(source, "device", "melius3g");
            set_ro_product_prop(source, "model", "GT-I9200");
            set_ro_product_prop(source, "name", "melius3g");
        }
        property_override("ro.build.description", "melius3gxx-user 4.4.2 KOT49H I9200XXUDNE4 release-keys");
        property_override("ro.build.product", "melius3g");
    } else if (model == "I9208") {
        /* melius3gzm */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/melius3gzm/melius3g:4.2.2/JDQ39/I9208ZMUCNB2:user/release-keys");
            set_ro_product_prop(source, "device", "melius3gzm");
            set_ro_product_prop(source, "model", "GT-I9208");
            set_ro_product_prop(source, "name", "melius3gzm");
        }
        property_override("ro.build.description", "melius3gzm-user 4.2.2 JDQ39 I9208ZMUCNB2 release-keys");
        property_override("ro.build.product", "melius3gzm");
    } else if (model == "I9205") {
        /* meliusltexx */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/meliusltexx/meliuslte:4.4.2/KOT49H/I9205XXUDNE4:user/release-keys");
            set_ro_product_prop(source, "device", "meliuslte");
            set_ro_product_prop(source, "model", "GT-I9205");
            set_ro_product_prop(source, "name", "meliuslte");
        }
        property_override("ro.build.description", "meliusltexx-user 4.4.2 KOT49H I9205XXUDNE4 release-keys");
        property_override("ro.build.product", "meliuslte");
    } else if (model == "L600") {
        /* meliusltespr */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/meliusltespr/meliusltespr:4.4.2/KOT49H/L600VPUBOH1:user/release-keys");
            set_ro_product_prop(source, "device", "meliusltespr");
            set_ro_product_prop(source, "model", "SPH-L600");
            set_ro_product_prop(source, "name", "meliusltespr");
        }
        property_override("ro.build.description", "meliusltespr-user 4.4.2 KOT49H L600VPUBOH1 release-keys");
        property_override("ro.build.product", "meliusltespr");
    } else if (model == "I527M") {
        /* meliusltecan */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/meliusltevl/meliusltecan:4.2.2/JDQ39/I527MVLUBNA3:user/release-keys");
            set_ro_product_prop(source, "device", "meliusltecan");
            set_ro_product_prop(source, "model", "SGH-I257M");
            set_ro_product_prop(source, "name", "meliusltecan");
        }
        property_override("ro.build.description", "meliusltevl-user 4.2.2 JDQ39 I527MVLUBNA3 release-keys");
        property_override("ro.build.product", "meliusltecan");
    } else if ((model == "M819N") || (model == "M819NUVUBNI5")) {
        /* meliuslteMetroPCS */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/meliuslteMetroPCS/meliuslteMetroPCS:4.2.2/JDQ39/M819NUVUAMK7:user/release-keys");
            set_ro_product_prop(source, "device", "meliuslteMetroPCS");
            set_ro_product_prop(source, "model", "SGH-M819N");
            set_ro_product_prop(source, "name", "meliuslteMetroPCS");
        }
        property_override("ro.build.description", "meliuslteMetroPCS-user 4.2.2 JDQ39 M819NUVUAMK7 release-keys");
        property_override("ro.build.product", "meliuslteMetroPCS");
    }

    const std::string device = GetProperty("ro.product.device", "");
    LOG(INFO) << "Found bootloader " << bootloader << ". " << "Setting build properties for " << device << ".\n";
}
