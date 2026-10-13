

#include "lights.h"


// Configure Idle Lamps

void configure_leds(int LIGHT_PIN) {
    // Reset pin
    // Configure it for output
    gpio_reset_pin(LIGHT_PIN);
    gpio_set_direction(LIGHT_PIN, GPIO_MODE_INPUT_OUTPUT);

}

// Configure Blinkers
void configure_blinkers(int LEFT_PIN, int RIGHT_PIN) {
    // Reset pins
    // Configure for output
    gpio_reset_pin(LEFT_PIN);
    gpio_reset_pin(RIGHT_PIN);
    gpio_set_direction(LEFT_PIN, GPIO_MODE_INPUT_OUTPUT);
    gpio_set_direction(RIGHT_PIN, GPIO_MODE_INPUT_OUTPUT);
}

// Blinker Interrupt
void blinker_interrupt() {
    // This code may not be needed
    return;
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
void toggle_lights(int LIGHT_PIN) {
    // If headlights are off, turns them on
    //  otherwise turns them off
    if(gpio_get_level(LIGHT_PIN) == 0) {
        gpio_set_level(LIGHT_PIN, 1);
    }else {
        gpio_set_level(LIGHT_PIN, 0);
    }
    
}