// Copyright 2018 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "sdkconfig.h"
#include "esp_phy_init.h"

// constrain a value between 'low' and 'high', inclusive
#define LIMIT(val, low, high) ((val < low) ? low : (val > high) ? high : val)
#define PHY_INIT_MAGIC "PHYINIT"

static const char phy_init_magic_pre[] = PHY_INIT_MAGIC;

/**
 * @brief Structure containing default recommended PHY initialization parameters.
 *
 * NB: The WiFi transmit power values have been modified for my specific hardware.
 *     This no longer honours the configuration parameter CONFIG_ESP8266_PHY_MAX_WIFI_TX_POWER.
 *     If this code is to be used on other hardware then additional configuration parameters
 *     should be added rather than further modifying these magic numbers.
 */
static const esp_phy_init_data_t phy_init_data= { {
        0x05,
        0x08,
        0x04,
        0x02,
        0x05,
        0x05,
        0x05,
        0x02,
        0x05,
        0x00,
        0x04,
        0x05,
        0x05,
        0x04,
        0x05,
        0x05,
        0x04,
        0xfe,
        0xfd,
        0xff,
        0xf0,
        0xf0,
        0xf0,
        0xe0,
        0xe0,
        0xe0,
        0xe1,
        0x0a,
        0xff,
        0xff,
        0xf8,
        0x00,
        0xf8,
        0xf8,
        61,   // power index 0 = 15.25 dBm
        37,   // power index 1 =  9.25 dBm
        37,   // power index 2 =  9.25 dBm
        37,   // power index 3 =  9.25 dBm
        37,   // power index 4 =  9.25 dBm
        37,   // power index 5 =  9.25 dBm
        1,    // 802.11n MCS0 and 802.11g 6 Mb/s, 9 Mb/s use power index 1
        1,    // 802.11n MCS1 and 802.11g 12 Mb/s        use power index 1
        1,    // 802.11n MCS2 and 802.11g 18 Mb/s        use power index 1
        1,    // 802.11n MCS3 and 802.11g 24 Mb/s        use power index 1
        1,    // 802.11n MCS4 and 802.11g 36 Mb/s        use power index 1
        1,    // 802.11n MCS5 and 802.11g 48 Mb/s        use power index 1
        1,    // 802.11n MCS6 and 802.11g 54 Mb/s        use power index 1
        1,    // 802.11n MCS7                            use power index 1
        ESP8266_XTAL_FLAG,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x02,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0xe1,
        0x0a,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x01,
        0x93,
        0x43,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x01, // enable next two fields:
        0,    // 802.11b 1 Mb/s and 2 Mb/s   use power index 0
        0,    // 802.11b 5.5Mb/s and 11 Mb/s use power index 0
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
#ifdef CONFIG_ESP_PHY_INIT_DATA_VDD33_CONST
        CONFIG_ESP_PHY_INIT_DATA_VDD33_CONST,
#else
        0x00,
#endif
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x01,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
} };

static const char phy_init_magic_post[] = PHY_INIT_MAGIC;

