#include "../include/wifi.h"
#include "esp_wifi.h"
#include <string.h>
#include <stdio.h>

// Start Wi-Fi
esp_err_t wifi_start() 
{
    return esp_wifi_start();
}

// Scan for Wi-Fi access points
void wifi_scan() 
{
    esp_wifi_scan_start(NULL, true);
}

// Connect to an access point
void wifi_connect(const char *ssid) 
{
    wifi_config_t wifi_config = {};
    strcpy((char*)wifi_config.sta.ssid, ssid);
    strcpy((char*)wifi_config.sta.password, DNA_WIFI_PASS);  // Replace with actual password if needed

    esp_err_t ret = esp_wifi_set_config(WIFI_IF_STA, &wifi_config);
    if (ret == ESP_OK) {
        printf("Connecting to %s...\n", ssid);
        esp_err_t connection_status = esp_wifi_connect();
        
        if (connection_status != ESP_OK) 
        {
            printf("Error while connecting to %s\n", ssid);
        } 
        else 
        {
            printf("Connected to %s\n", ssid);
        }
    } 
    else 
    {
        printf("Failed to set Wi-Fi configuration: %s\n", esp_err_to_name(ret));
    }
}

// Retrieve and connect to a scanned access point
void wifi_get_scanned_ap() 
{
    printf("Getting scanned AP records\n");
    uint16_t ap_count = 0;

    esp_err_t ret = esp_wifi_scan_get_ap_num(&ap_count);
    wifi_ap_record_t ap_records[ap_count];

    ret = esp_wifi_scan_get_ap_records(&ap_count, ap_records);
    if (ret != ESP_OK) 
    {
        printf("Error retrieving AP records...\n");
        return;
    }

    for (int i = 0; i < ap_count; i++) 
    {
        printf("SSID: %s, RSSI: %d, Channel: %d\n", ap_records[i].ssid, ap_records[i].rssi, ap_records[i].primary);

        // Connect to mobile hotspot Galaxy S22 C284 or router RUT200_B046
        if (strcmp((const char *)ap_records[i].ssid, "Galaxy S22 C284") == 0 ||
            strcmp((const char *)ap_records[i].ssid, "DNA-Mokkula-Eteinen") == 0)
            //strcmp((const char *)ap_records[i].ssid, "RUT200_B046") == 0) 
        {
            printf("Target Wi-Fi found: %s\n", ap_records[i].ssid);
            wifi_connect((const char *)ap_records[i].ssid);
            break;
        }
    }

    esp_wifi_clear_ap_list();
}
