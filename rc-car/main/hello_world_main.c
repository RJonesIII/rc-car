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

#define LIGHTS 15 // Sitting on D15
#define L_BLINKER 2 // Sitting on D2
#define R_BLINKER 4 // Sitting on D4
// #define MOTOR 

void app_main(void)
{
    printf("Hello World");
    // Configure Lights
    // Configure Commands
    configure_leds(LIGHTS);
    configure_blinkers(L_BLINKER, R_BLINKER);

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
            toggle_lights(LIGHTS);
            c = 0;
        }
        

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
