#include "button.h"
#include "interrupt.h"
#include "matrix.h"
#include "pico/bootrom.h"
#include "pico/stdlib.h"
#include <stdio.h>

void gpio_irq_handler(uint gpio, uint32_t events) {
    if(!debouncing(400))
        return;
    // Habilita a entrada do modo BOOTSELL ao pressionar JOYSTICK_BUTTON
    if(gpio == JOYSTICK_BUTTON)
        reset_usb_boot(0,0);
    if(gpio == BUTTON_1 && actual_number < 9)
        actual_number++;
    if(gpio == BUTTON_2 && actual_number)
        actual_number--;
    printf("Contador: %d\n", actual_number);
}