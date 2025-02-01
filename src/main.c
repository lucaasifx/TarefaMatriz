#include <stdio.h>


#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/pio.h"
#include "ws2812.pio.h"


// ************************ LIBS ***************************
#include "lib/led.h"
#include "lib/button.h"
#include "lib/interrupt.h"
#include "lib/matrix.h"

// ********************* MACROS *****************************


int main() {
    stdio_init_all();
    // Inicializa o led vermelho
    init_led(LED_RED);
    
    // Inicialização do botões e configuração de eventos de interrupção
    init_button_with_interrupt(BUTTON_1, GPIO_IRQ_EDGE_FALL, true);
    init_button_with_interrupt(BUTTON_2, GPIO_IRQ_EDGE_FALL, true);
    init_button_with_interrupt(JOYSTICK_BUTTON, GPIO_IRQ_EDGE_FALL, true);
  
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
    turn_led_on(LED_RED);
    while(true) {
        set_one_led(numbers[actual_number], led_r, led_g, led_b);
        sleep_ms(100);
    }
    return 0;
}