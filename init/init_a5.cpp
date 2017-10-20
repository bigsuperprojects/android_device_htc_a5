/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fstream>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void cdma_properties(char const default_cdma_sub[], char const default_network[])
{
    property_set("ro.telephony.default_cdma_sub", default_cdma_sub);
    property_set("ro.telephony.default_network", default_network);
    property_set("telephony.lteOnCdmaDevice", "1");
    property_set("ro.ril.enable.sdr", "0");
    property_set("ro.ril.enable.gea3", "1");
    property_set("ro.ril.enable.r8fd", "1");
    property_set("ro.ril.enable.a52", "0");
    property_set("ro.ril.enable.a53", "1");
    property_set("ro.ril.disable.fd.plmn.prefix", "23402,23410,23411,23420");
    property_set("ro.ril.fast.dormancy.cdma.rule", "0");
    property_set("ro.ril.pdpnumber.policy.roaming", "3");
    property_set("ro.ril.air.enabled", "0");
    property_set("ro.ril.gsm.to.lte.blind.redir", "0");
    property_set("persist.radio.snapshot_enabled", "1");
    property_set("persist.radio.snapshot_timer", "22");
}

void gsm_properties(char const default_network[])
{
    property_set("ro.telephony.default_network", default_network);
    property_set("ro.ril.hsupa.category", "6");
    property_set("ro.ril.hsxpa", "4");
    property_set("ro.ril.disable.cpc", "1");
    property_set("ro.ril.enable.pre_r8fd", "1");
    property_set("ro.ril.enable.sdr", "1");
    property_set("ro.ril.enable.r8fd", "1");
    property_set("ro.ril.disable.fd.plmn.prefix", "23402,23410,23411,23420,23594,27202,27205");
    property_set("ro.telephony.ril_class", "A5RIL");
    property_set("persist.radio.dont_use_dsd", "true");
    property_set("ro.multisim.set_audio_params", "true");
    property_set("ro.telephony.ril.config", "simactivation,sim2gsmonly");

}

void vendor_load_properties()
{
    std::string platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    std::string bootmid = property_get("ro.boot.mid");
    std::string carrier = property_get("ro.boot.carrier");
    if (bootmid == "0P9C10000") {
        /* a5tl */
        gsm_properties("9");
        property_set("ro.build.fingerprint", "htc/htccn_chs_cmcc/htc_a5tl:4.4.2/KOT49H/391137.3:user/release-keys");
        property_set("ro.build.description", "2.07.1403.3 CL391137 release-keys");
        property_set("ro.product.model", "D816t");
        property_set("ro.product.device", "htc_a5tl");
        property_set("ro.build.product", "htc_a5tl");
        property_set("ro.ril.hsdpa.category", "10");
        property_set("ro.ril.hsxpa", "2");
        property_set("ro.ril.enable.sdr", "0");
        property_set("ro.ril.enable.a53", "1");
        property_set("ro.ril.disable.fd.plmn.prefix", "23402,23410,23411,23420,27202");
        property_set("ro.ril.oem.ecclist", "112,000,08,110,118,119,911,999,120,122");
        property_set("ro.ril.set.mtusize", "1420");
    } else if (bootmid == "0P9C30000") {
        /* a5chl */
        cdma_properties("1","8");
        property_set("ro.build.fingerprint", "htc/sprint_wwe_vm/htc_a5chl:5.0.2/LRX22G/510432.2:user/release-keys");
        property_set("ro.build.description", "2.33.652.2 CL510432 release-keys");
        property_set("ro.product.model", "710C");
        property_set("ro.product.device", "htc_a5chl");
        property_set("ro.build.product", "htc_a5chl");
        property_set("gsm.sim.operator.numeric", "000000");
        property_set("gsm.operator.numeric", "000000");
        property_set("gsm.sim.operator.alpha", "Chameleon");
        property_set("gsm.operator.alpha", "Chameleon");
        property_set("ro.cdma.home.operator.numeric", "310120");
        property_set("ro.cdma.home.operator.alpha", "Virgin Mobile"); 
        property_set("ro.home.operator.carrierid", "Sprint"); 
        property_set("ro.ril.oem.ecclist", "911");
        property_set("ro.ril.set.mtusize", "1422");
        property_set("gsm.sim.operator.iso-country", "us");
        property_set("gsm.operator.iso-country", "us");
        property_set("ro.telephony.ril_class", "A5SprRIL");
    } else if (bootmid == "0P9C50000") {
        /* a5dwg (chinese) */
        property_set("ro.build.fingerprint", "htc/htccn_chs_ct/htc_a5dwg:4.4.2/KOT49H/377271.2:user/release-keys");
        property_set("ro.build.description", "2.06.1401.2 CL377271 release-keys");
        property_set("ro.product.model", "D816d");
        property_set("ro.product.device", "htc_a5dwg");
        property_set("ro.build.product", "htc_a5dwg");
        property_set("ro.telephony.default_network", "7");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.ril.enable.pre_r8fd", "1");
        property_set("ro.ril.enable.sdr", "0");
        property_set("ro.ril.enable.r8fd", "1");
        property_set("ro.ril.disable.fd.plmn.prefix", "23402,23410,23411,23420,27202");
        property_set("ro.ril.oem.ecclist", "110,112,119,120,911,999");
        property_set("ro.ril.set.mtusize", "1420");
    } else if (bootmid == "0P9C51000") {
        /* a5dwg (international) */
        gsm_properties("7");
        property_set("ro.build.fingerprint", "htc/htc_asia_india/htc_a5dwg:4.4.2/KOT49H/334435.1:user/release-keys");
        property_set("ro.build.description", "1.24.720.1 CL334435 release-keys");
        property_set("ro.product.model", "Desire 816 dual sim");
        property_set("ro.product.device", "htc_a5dwg");
        property_set("ro.build.product", "htc_a5dwg");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.ril.hsdpa.category", "10");
        property_set("ro.ril.air.enabled", "1");
    } else if (bootmid == "0P9C70000") {
        /* a5dug */
        gsm_properties("0");
        property_set("ro.product.device", "htc_a5dug");
        property_set("ro.build.product", "htc_a5dug");
        property_set("persist.radio.multisim.config", "dsda");
        property_set("ro.ril.hsdpa.category", "24");
        property_set("ro.ril.disable.cpc", "1");
        property_set("ro.ril.enable.sdr", "0");
        if (carrier == "HTC-Russia") {
            /* russian */
            property_set("ro.build.fingerprint", "htc/htc_europe/htc_a5dug:4.4.2/KOT49H/372006.1:user/release-keys");
            property_set("ro.build.description", "2.06.1402.2 CL377269 release-keys");
            property_set("ro.product.model", "Desire 816 dual sim");
            property_set("ro.ril.enable.a53", "1");
        } else {
            /* chinese */
            property_set("ro.build.fingerprint", "htc/htccn_chs_cu/htc_a5dug:5.0.2/LRX22G/510432.1:user/release-keys");
            property_set("ro.build.description", "2.34.1402.1 CL510432 release-keyss");
            property_set("ro.product.model", "D816w");
        }
    } else {
        /* a5ul */
        gsm_properties("9");
        property_set("ro.build.fingerprint", "htc/htc_asia_wwe/htc_a5ul:4.4.2/KOT49H/358649.1:user/release-keys");
        property_set("ro.build.description", "1.49.707.1 CL358649 release-keys");
        property_set("ro.product.model", "Desire 816");
        property_set("ro.product.device", "htc_a5ul");
        property_set("ro.build.product", "htc_a5ul");
        property_set("ro.ril.hsdpa.category", "14");
        property_set("ro.ril.air.enabled", "1");
        property_set("ro.ril.enable.a53", "1");
        property_set("persist.radio.jbims", "1");
        property_set("ro.ril.enable.gea3", "1");
        property_set("ro.ril.gsm.to.lte.blind.redir", "1");
    }
      std::string device = property_get("ro.product.device"); 
      ERROR("Found bootmid %s setting build properties for %s device\n", bootmid.c_str(), device.c_str());
}
