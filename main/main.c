#include <stdio.h>
#include <string.h>
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "nvs_flash.h"

#include "../include/init.h"
#include "../include/wifi.h"
#include "../include/sntp.h"


//Main program
void app_main(void)
{
    init_nvs();
    init_sntp();

    esp_netif_init();
    esp_event_loop_create_default();

    wifi_mode_t mode;
    esp_err_t result = esp_wifi_get_mode(&mode);
    
    printf("Booting..\n");

    if (result == ESP_ERR_WIFI_NOT_INIT) 
    {
        wifi_init();
    }
    else if (result == ESP_ERR_INVALID_ARG)
    {
        esp_restart();
    }

    esp_err_t wifi_start_t = wifi_start();

    switch(wifi_start_t) 
    {
        case ESP_OK:
            printf("Wifi started succesfully!\n");
            break;
        case ESP_ERR_WIFI_NOT_INIT:
            printf("Wifi not initialized..\nInitializing.....\n");
            wifi_init();
            break;
        case ESP_ERR_INVALID_ARG:
            printf("Invalid arguments when starting wifi..\nRestarting esp32....\n");
            esp_restart();
            break;
        case ESP_ERR_NO_MEM:
            printf("No memory available..\nRestarting esp32.....\n");
            esp_restart();
            break;
        case ESP_ERR_WIFI_CONN:
            printf("Wifi internal error, station or soft-AP control block wrong...\nRestarting....\n");
            esp_restart();
            break;
        case ESP_FAIL:
            printf("Error with something else with wifi...\nRestarting......\n");
            esp_restart();
            break;
        default:
            printf("Ran into an unknown error..\nRestarting....\n");
            break;
    }

    wifi_scan();
    wifi_get_scanned_ap();
    
    esp_err_t res = sntp_start();
    printf("==\n==\n==\n%s\n==\n==\n==\n", esp_err_to_name(res));
    
    
    while (true) 
    {
        vTaskDelay(pdMS_TO_TICKS(2000));
        print_current_time();
    }
}

