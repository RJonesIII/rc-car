

#include "lights.h"


volatile uint8_t left_blinker_flag = 0;
volatile uint8_t right_blinker_flag = 0;
volatile uint8_t hazards_flag = 0;

// Configure Idle Lamps

void configure_leds() {
    // Reset pin
    // Configure it for output
    gpio_reset_pin(LIGHTS_PIN);
    gpio_set_direction(LIGHTS_PIN, GPIO_MODE_INPUT_OUTPUT);

}

// Configure Blinkers
void configure_blinkers() {
    // Reset pins
    // Configure for output
    gpio_reset_pin(LEFT_PIN);
    gpio_reset_pin(RIGHT_PIN);
    gpio_set_direction(LEFT_PIN, GPIO_MODE_INPUT_OUTPUT);
    gpio_set_direction(RIGHT_PIN, GPIO_MODE_INPUT_OUTPUT);

    // Congigure GPTimer (General Purpose Timer) for blinker timing
    gptimer_handle_t gptimer = NULL;
    gptimer_config_t timer_config = {
        .clk_src = GPTIMER_CLK_SRC_DEFAULT, // Select the default clock source
        .direction = GPTIMER_COUNT_UP,      // Counting direction is up
        .resolution_hz = 1000,  // Resolution is 1000 Hz, which is 1000 times a second (1000 ms)
    };

    gptimer_new_timer(&timer_config, &gptimer);

    gptimer_alarm_config_t alarm_config = {
        .alarm_count = 1000, // Set the actual alarm period, alarm every other second
        .flags.auto_reload_on_alarm = true, // Enables auto-reload function
    };

    gptimer_set_alarm_action(gptimer, &alarm_config); // Sets alarm action
    gptimer_event_callbacks_t cbs = {
        .on_alarm = blinker_alarm, // Call the blinker alarm function when the alarm event occurs
    };

    gptimer_register_event_callbacks(gptimer, &cbs, NULL);

    gptimer_enable(gptimer);
    gptimer_start(gptimer);
}

// Blinker Interrupt
static bool blinker_alarm(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_ctx) {
    // For the Blinkers to work, 
    //      they need to be put in an interruptable loop so that t
    //      he car can do everything else while also managing the blinkers
    // Blinkers should flash every second, so ideally I would run a background timer using a clock
    //      if the left/right flag is 1 then the light should be flicking on and off
    //      otherwise the light stays off
    //      this approach allows the blinkers to be on at the same time for hazards with no additional code
    //      every second it toggles the blinker on/off
    
    if(left_blinker_flag == 1) {
        toggle_left_blinker();
    }

    if(right_blinker_flag == 1) {
        toggle_right_blinker();
    }

    return false;
}

void toggle_left_blinker() {

    if(left_blinker_flag == 0) {
        left_blinker_flag = 1;
        right_blinker_flag = 0;
    }else {
        left_blinker_flag = 0;
    }
}

void toggle_right_blinker() {
    if(right_blinker_flag == 0) {
        right_blinker_flag = 1;
        left_blinker_flag = 0;
    }else {
        right_blinker_flag = 0;
    }
}

void toggle_hazzard_flag() {
    if(right_blinker_flag && left_blinker_flag) {
        right_blinker_flag = 0;
        left_blinker_flag = 0;
    }else {
        right_blinker_flag = 1;
        left_blinker_flag = 1;
    }

}

// Blinker Toggle
void toggle_left_led() {
    // sets blinker flag to on if off
    // else turns off
    if(gpio_get_level(LEFT_PIN) == 0) {
        gpio_set_level(LEFT_PIN, 1);
    }else {
        gpio_set_level(LEFT_PIN, 0);
    }
}

void toggle_right_led() {
    // set blinker flag to on if off
    // else turns off
    if(gpio_get_level(RIGHT_PIN) == 0) {
        gpio_set_level(RIGHT_PIN, 1);
    }else {
        gpio_set_level(RIGHT_PIN, 0);
    }
}

// Lights toggle
void toggle_lights() {
    // If headlights are off, turns them on
    //  otherwise turns them off
    if(gpio_get_level(LIGHTS_PIN) == 0) {
        gpio_set_level(LIGHTS_PIN, 1);
    }else {
        gpio_set_level(LIGHTS_PIN, 0);
    }
    
}