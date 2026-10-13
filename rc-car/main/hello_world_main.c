/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "lights.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"


// #define MOTOR 

void app_main(void)
{
    printf("Hello World");
    // Configure Lights
    // Configure Commands
    configure_leds();
    configure_blinkers();

    // First Step - Keyboard Commands
    // 'L' -> Turns Lights on (Front and Back)
    // 'C' -> Turns on left blinker
    // 'Z' -> Turns on right blinker
    // 'X' -> Turns on hazards (both left and right)
    // 'W' -> Drives Motor forward
    // 'D' -> Drives Motor backward
    volatile int c;

    while(1) {
        
        if((c = getchar()) == 'L') {
            toggle_lights();
            c = 0;
        }
        

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
