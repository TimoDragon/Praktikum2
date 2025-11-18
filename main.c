#include <stdio.h>
#include "functions.h"

int main(void) {
    int input, number_system;

    printf("Geben Sie die Ausgangszahl ein: ");
    read_number(&input);

    printf("In welches Zahlensystem wollen Sie die Zahl umrechnen: ");
    read_number_system(&number_system);

    char output[32];
    numberConvert(input, number_system, output);

    printf("%s\n", output);

    return 0;
}
