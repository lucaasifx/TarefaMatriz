#include "pico/stdlib.h"
#include "button.h"


void init_button(uint8_t buttonGPIO) {
    gpio_init(buttonGPIO);
    gpio_set_dir(buttonGPIO, GPIO_IN);
    // add resistence to get accurate readings
    // STATES
        // 1: if not pressed
        // 0: if pressed
    gpio_pull_up(buttonGPIO);
}

bool is_button_pressed(uint8_t buttonGPIO) {
    return !gpio_get(buttonGPIO);
}

