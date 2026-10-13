

// Include int types
#include <stdio.h>
#include <stdint.h>
#include "driver/gpio.h"


// Configure Idle Lamps

void configure_leds(int light);

// Configure Blinkers
void configure_blinkers(int left, int right);

// Blinker Interrupt
void blinker_interrupt();

// Blinker Toggle
void toggle_left_blinker();
void toggle_right_blinker();

// Lights toggle
void toggle_lights();