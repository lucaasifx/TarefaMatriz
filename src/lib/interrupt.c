#include "button.h"
#include "interrupt.h"
#include "matrix.h"
#include "pico/bootrom.h"
#include "pico/stdlib.h"
#include <stdio.h>

// Função que lida com eventos de interrupção
void gpio_irq_handler(uint gpio, uint32_t events) {
    // eventos de acionamento de botões
    if(gpio == BUTTON_1 || gpio == BUTTON_2 || gpio == JOYSTICK_BUTTON) {
        // tratamento de debouncing dos botões
        if(!debouncing(300))
            return;
        // Habilita a entrada do modo BOOTSELL ao pressionar JOYSTICK_BUTTON
        if(gpio == JOYSTICK_BUTTON)
            reset_usb_boot(0,0);
        // avança para o próximo número (máximo 9)
        if(gpio == BUTTON_1 && actual_number < 9)
            actual_number++;
        // recua para o número anterior (mínimo 0)
        if(gpio == BUTTON_2 && actual_number)
            actual_number--;
        // atualiza a matriz de leds
        set_one_led(numbers[actual_number], led_r, led_g, led_b);
        // log de depuração
        printf("Contador: %d\n", actual_number);
    }
}