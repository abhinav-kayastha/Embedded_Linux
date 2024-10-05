#include "pico/stdlib.h"
#include "../inc/led.h"

int main() {
    const uint LED_PIN = PIN_NUM;  // Define the onboard LED pin
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    int counter = 0;
    int state = 0;

    while (true) {
	counter++;
	state = counter % 2;
        gpio_put(LED_PIN, 1);
        sleep_ms(500);
        gpio_put(LED_PIN, 0);
        sleep_ms(500);
    }
}

