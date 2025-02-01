#include <stdio.h>


#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/pio.h"
#include "ws2812.pio.h"


// ************************ LIBS ***************************
#include "lib/led.h"
#include "button.h"
#include "interrupt.h"

// ********************* MACROS *****************************


int main() {
    stdio_init_all();
    // Inicializa o led vermelho
    init_led(LED_RED);
    
    // Inicialização do botões e configuração de eventos de interrupção
    init_button_with_interrupt(BUTTON_1, GPIO_IRQ_EDGE_FALL, true);
    init_button_with_interrupt(BUTTON_2, GPIO_IRQ_EDGE_FALL, true);
    init_button_with_interrupt(JOYSTICK_BUTTON, GPIO_IRQ_EDGE_FALL, true);
  
    turn_led_on(LED_RED);
    while(true) {

    }
    return 0;
}