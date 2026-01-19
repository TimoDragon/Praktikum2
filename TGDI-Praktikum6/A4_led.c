#include "bcm2835.h"
#include <stdio.h>

#define PIN RPI_GPIO_P1_18

int main() {
    if (!bcm2835_init()) {
        printf("Init fehlgeschlagen");
        return 1;
    }

    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

    while (1) {
        bcm2835_gpio_set(PIN);
        bcm2835_delay(1000);
        bcm2835_gpio_clr(PIN);
        bcm2835_delay(1000);
    }

    bcm2835_close();
}