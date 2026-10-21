idf_component_register(SRCS "main.c" "lights.c"
                       PRIV_REQUIRES spi_flash esp_driver_gpio esp_driver_gptimer
                       INCLUDE_DIRS "")
