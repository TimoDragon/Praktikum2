#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numberConvert.h"

void read_number(int* number);
void read_number_system(int* number_system);
void clearBuffer();

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

void read_number(int* number) {
    char input[12];

    fgets(input, sizeof(input), stdin);
    if (!strchr(input, '\n')){
       clearBuffer();
    }

    for (int i = 0; i < (int)sizeof(input); i++) {
        if (input[i] == '\n' || input[i] == '\0') {
            break;
        }

        int num = input[i] - '0';
        if (num < 0 || num > 9) {
            printf("Es sind nur natürliche Zahlen erlaubt. Bitte versuche es erneut.\n");
            read_number(number);
            return;
        }
    }

    // 0x7FFFFFFF (Hex) = 2147483647 -> max signed int
    long checkInput = atol(input);
    if (checkInput > 0x7FFFFFFF ) {
        printf("Die Zahl darf maximal 2^31 betragen. Bitte versuche es erneut!\n");
        read_number(number);
        return;
    }

    *number = atoi(input);
}

void read_number_system(int* number_system) {
    char input[4];

    fgets(input, sizeof(input), stdin);

    if (!strchr(input, '\n')){
        clearBuffer();
    }

    int num = atoi(input);
    if (num < 2 || num > 16) {
        printf("Es sind nur Zahlen zwischen 2 und 16 erlaubt.\n");
        read_number_system(number_system);
        return;
    }

    *number_system = num;
}

void clearBuffer(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
