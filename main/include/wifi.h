#ifndef WIFI_H
#define WIFI_H

#define HOTSPOT_WIFI_SSID "Galaxy S22 C284"
#define HOTSPOT_WIFI_PASS "cocknballs"
#define RUT_WIFI_SSID "RUT200_B046"
#define RUT_WIFI_PASS "q7Q9Djn0"
#define DNA_WIFI_SSID "DNA-Mokkula-Eteinen"
#define DNA_WIFI_PASS "17399557522"

#include <stdio.h>
#include <string.h>
#include "esp_wifi.h"
#include "esp_system.h"

esp_err_t wifi_start();
void wifi_scan();
void wifi_connect(const char *ssid);
void wifi_get_scanned_ap();


#endif