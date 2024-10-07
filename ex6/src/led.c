#include "pico/stdlib.h"
#include "../inc/led.h"

int main() {
    const uint LED_PIN = PIN_NUM;  // Define the onboard LED pin
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    static uint counter = 0;
    static uint state = 0;

    while (true) {
	counter++;
	state = counter % 2;
        gpio_put(LED_PIN, state);
        sleep_ms(500);
    }
}

