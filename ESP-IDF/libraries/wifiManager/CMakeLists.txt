idf_component_register(
    SRCS "wifiManager.cpp"
    INCLUDE_DIRS "."
    REQUIRES esp_wifi nvs_flash esp_netif esp_event Counter
)
