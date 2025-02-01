#include "button.h"
#include "interrupt.h"
#include "pico/bootrom.h"

void gpio_irq_handler(uint gpio, uint32_t events) {
    // Habilita a entrada do modo BOOTSELL ao pressionar JOYSTICK_BUTTON
    if(gpio == JOYSTICK_BUTTON)
        reset_usb_boot(0,0);
}