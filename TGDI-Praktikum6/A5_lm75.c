#include <stdio.h>
#include "bcm2835.h"

#define I2C_SLAVE_ADR 11
#define LED RPI_GPIO_P1_18

float convertTemperature(uint8_t msb, uint8_t lsb);

int main() {
    if (!bcm2835_init()) {
        printf("Init fehlgeschlagen");
        return 1;
    }

    if (!bcm2835_i2c_begin()) {
        printf("I2C fehlgeschlagen");
        return 1;
    }

    bcm2835_i2c_setSlaveAddress(I2C_SLAVE_ADR);
    bcm2835_i2c_setClockDivider(BCM2835_I2C_CLOCK_DIVIDER_2500);
    bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP);

    while (1) {
        char output[2];

        bcm2835_i2c_read(&output, 2);
        float temp = convertTemperature(output[0], output[1]);

        printf("Temperatur: %f°C", temp);

        if (temp < 0.0f) {
            bcm2835_gpio_set(LED);
        } else {
            bcm2835_gpio_clr(LED);
        }

        bcm2835_delay(1000);
    }

    bcm2835_close();
}

float convertTemperature(uint8_t msb, uint8_t lsb) {
    uint16_t raw = ((uint16_t) msb << 4) | (lsb >> 4);

    //TEMP: 0000 0110 0111 0001
    //AND : 0000 0100 0000 0000
    //      0000 0100 0000 0000  != 0, also Wert negativ


    //      1111 1000 0000 0000 (0xF800)
    // OR:  1111 1110 0111 0001


    if (raw & 0x400) {
        raw |= 0xF800;
    }

    int16_t temp_raw = (int16_t)raw;

    return temp_raw * 0.125f;
}