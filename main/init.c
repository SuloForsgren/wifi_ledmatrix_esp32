#include "../include/init.h"
#include "../include/sntp.h"
#include "nvs_flash.h"
#include "esp_wifi.h"
#include "esp_netif.h"
#include "esp_event.h"
#include "esp_sntp.h"

// Initialize flash memory
void init_nvs()
{
    esp_err_t nvs_init_result = nvs_flash_init();
    if (nvs_init_result == ESP_ERR_NVS_NO_FREE_PAGES || nvs_init_result == ESP_ERR_NVS_NEW_VERSION_FOUND) 
    {
        nvs_flash_erase();
        nvs_flash_init();
    }
}

// Initialize Wi-Fi module
void wifi_init() 
{
    const wifi_init_config_t wifi_conf = WIFI_INIT_CONFIG_DEFAULT();
    esp_err_t result = esp_wifi_init(&wifi_conf);

    if (result != ESP_OK) 
    {
        printf("Wi-Fi initialization failed...\n");
        return;
    }

    esp_wifi_set_mode(WIFI_MODE_STA);
}

// Initialize SNTP service with configuration
void init_sntp() 
{
    esp_sntp_config_t cfg = {
        .smooth_sync = false,
        .server_from_dhcp = false,
        .wait_for_sync = true,
        .start = true,
        .sync_cb = time_sync_callback,
        .renew_servers_after_new_IP = false,
        .ip_event_to_renew = IP_EVENT_STA_GOT_IP,
        .index_of_first_server = 0,
        .num_of_servers = 1,
        .servers = {"pool.ntp.org"}
    };
    esp_netif_sntp_init(&cfg);
}
