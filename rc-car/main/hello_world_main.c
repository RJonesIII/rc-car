*
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

#define LIGHTS 15; // Sitting on D15
#define L_BLINKER 2; // Sitting on D2
#define R_BLINKER 4; // Sitting on D4
// #define MOTOR 

void app_main(void)
{
    printf("Hello World")
    // Configure Lights
    // Configure Commands

    // First Step - Keyboard Commands
    // 'L' -> Turns Lights on (Front and Back)
    // 'C' -> Turns on left blinker
    // 'Z' -> Turns on right blinker
    // 'X' -> Turns on hazards (both left and right)
    // 'W' -> Drives Motor forward
    // 'D' -> Drives Motor backward

    for (int i = 10; i >= 0; i--) {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}
