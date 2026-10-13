

#include "lights.h"


// Configure Idle Lamps

void configure_leds(int light) {
    // Reset pin
    // Configure it for output
    gpio_reset_pin(light);
    gpio
}

// Configure Blinkers
void configure_blinkers(int left, int right) {
    // Reset pins
    // Configure for output
}

// Blinker Interrupt
void blinker_interrupt() {
    // This code may not be needed
    return
}

// Blinker Toggle
void toggle_left_blinker() {
    // sets blinker flag to on if off
    // else turns off
}

void toggle_right_blinker() {
    // set blinker flag to on if off
    // else turns off
}

// Lights toggle
void toggle_lights() {
    // set headlights on if off
    // off if on
}