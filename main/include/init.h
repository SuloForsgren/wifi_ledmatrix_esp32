#ifndef INIT_H
#define INIT_H

#include <stdio.h>
#include <string.h>
#include "esp_netif_sntp.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "nvs_flash.h"

void init_nvs();
void wifi_init();
void init_sntp();

#endif