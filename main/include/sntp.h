#ifndef SNTP_H
#define SNTP_H

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_netif_sntp.h"
#include "esp_log.h"


esp_err_t sntp_start();
void time_sync_callback(struct timeval *tv);
void print_current_time();

#endif