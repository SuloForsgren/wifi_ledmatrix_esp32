#include "../include/sntp.h"
#include "esp_sntp.h"

esp_err_t sntp_start() 
{
    return esp_netif_sntp_start();
}

void time_sync_callback(struct timeval *tv) 
{
    printf("Time synchronized: %lld.%06ld\n", (long long)tv->tv_sec, tv->tv_usec);
}

void print_current_time() 
{
    time_t now;
    struct tm timeinfo;

    time(&now);
    localtime_r(&now, &timeinfo);

    printf("Current time: %s", asctime(&timeinfo));
}
