#include "bcm2835.h"

int main() {
    if (!bcm2835_init()) {
        printf("Init fehlgeschlagen");
        return 1;
    }

    bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_64);
    bcm2835_pwm_set_mode(0, 1, 1);
    bcm2835_pwm_set_range(0, 64);

    for (int i = 0; i < 64; i++) {
        bcm2835_pwm_set_data(0, 64-i);
        bcm2835_delay(1000);
    }

    bcm2835_close();
}