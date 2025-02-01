#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/pio.h"
#include "ws2812.pio.h"

// ************************ LIBS ***************************
#include "lib/led.h"



// ********************* MACROS *****************************



int main() {
    stdio_init_all();
    // initialize red led
    init_led(LED_RED);




    while(true) {
        turn_led_on(LED_RED);
    }
    return 0;
}