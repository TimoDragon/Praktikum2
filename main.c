#include <stdio.h>
#include <stdlib.h>

void numberConvert(int zahl, int zielsystem, char ausgabe[]);
void read_number(int* number);
void read_number_system(int* number_system);
char* itc(int number[], int end, char ausgabe[]);

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

void numberConvert(int zahl, int zielsystem, char ausgabe[]) {
    int rest[32];

    for (int i = 0; i < 32; i++) {
        rest[i] = 0;
    }

    int i = 0;
    while (zahl > 0) {
        rest[i] = zahl % zielsystem;
        zahl = zahl / zielsystem;
        i++;
    }

    itc(rest, i, ausgabe);
}

char* itc(int number[], int end, char ausgabe[]) {
    for (int j = end - 1, a = 0; j >= 0; j--, a++) {
        if (number[j] < 10) {
            ausgabe[a] = (char) (number[j] + '0');
        } else {
            ausgabe[a] = (char) (number[j] - 10 + 'A');
        }
    }
    ausgabe[end] = '\0';
}

void read_number(int* number) {
    char input[100];

    fgets(input, sizeof(input), stdin);

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

    int num = atoi(input);

    if (num < 2 || num > 16) {
        printf("Es sind nur Zahlen zwischen 2 und 16 erlaubt.\n");
        read_number_system(number_system);
        return;
    }

    *number_system = num;
}
