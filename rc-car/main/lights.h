

// Include int types
#include <stdio.h>
#include <stdint.h>
#include "driver/gpio.h"
#include "driver/gptimer.h"
#include "esp_attr.h"

#define LIGHTS_PIN 15 // Sitting on D15
#define LEFT_PIN 2 // Sitting on D2
#define RIGHT_PIN 4 // Sitting on D4

// Configure Idle Lamps

void configure_leds();

// Configure Blinkers
void configure_blinkers();

// Blinker Interrupt
// static bool IRAM_ATTR blinker_alarm(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_ctx);

// Blinker Toggle
void toggle_left_blinker();
void toggle_right_blinker();
void toggle_hazzard_flag();

// Lights toggle
void toggle_lights();
void toggle_left_led();
void toggle_right_led();
