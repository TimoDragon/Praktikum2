#include <stdio.h>

int split(char *string, char splitChar, char **parts, int maxParts, int maxLength);

int main(void) {
    char partsbuf[10][200];
    char *parts[10];

    for (int i = 0; i < 10; i++) {
        parts[i] = partsbuf[i];
    }

    int k = split("Blau;Gelb;Rot", ';', parts, 5, 200);

    printf("%d\n", k);

    for (int i = 0; i < k; i++) {
        printf("%s\n", parts[i]);
    }

    return 0;
}

int split(char *string, char splitChar, char **parts, int maxParts, int maxLength) {
    int partCounter = 0;

    for (int i = 0, j = 0; i < maxLength; i++) {
        char c = string[i];

        if (c == '\0') {
            parts[partCounter][j] = '\0';
            partCounter += 1;
            break;
        }

        if (partCounter == maxParts) {
            break;
        }

        if (c == splitChar) {
            parts[partCounter][j] = '\0';
            partCounter += 1;
            j = 0;
            continue;
        }

        parts[partCounter][j] = c;
        j++;
    }

    return partCounter;
}
