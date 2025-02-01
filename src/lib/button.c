#include "pico/stdlib.h"
#include "button.h"
#include "interrupt.h"

void init_button(uint8_t buttonGPIO) {
    gpio_init(buttonGPIO);
    gpio_set_dir(buttonGPIO, GPIO_IN);
    // add resistence to get accurate readings
    // STATES
        // 1: if not pressed
        // 0: if pressed
    gpio_pull_up(buttonGPIO);
}

void init_button_with_interrupt(uint buttonGPIO, uint32_t event, bool enabled) {
    init_button(buttonGPIO);
    gpio_set_irq_enabled_with_callback(buttonGPIO, event, true, &gpio_irq_handler);
}

bool is_button_pressed(uint8_t buttonGPIO) {
    return !gpio_get(buttonGPIO);
}

bool debouncing(uint32_t ms){
    static uint32_t last_time = 0;
    uint32_t current_time = to_ms_since_boot(get_absolute_time());
    if (current_time - last_time < ms)
        return false;
    last_time = current_time;
    return true;

}

