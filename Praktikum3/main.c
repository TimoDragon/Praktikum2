#include <stdio.h>

int split(char *string, char splitChar, char **parts, int maxParts, int maxLength);
int strLen(char *string);

int main(void) {
    char partsbuf[10][200];
    char *parts[10];

    for (int i = 0; i < 10; i++) {
        parts[i] = partsbuf[i];
    }

    int k = split("Blau;;Gelb;Rot", ';', parts, 2, 20);

    printf("Anzahl Parts: %d\n", k);

    for (int i = 0; i < k; i++) {
        printf("%s\n", parts[i]);
    }

    return 0;
}

int split(char *string, char splitChar, char **parts, int maxParts, int maxLength) {
    if (maxParts <= 0 || maxLength <= 0){
        return 0;
    }
    int partCounter = 0;

    int strLength = strLen(string)+1;
    for (int i = 0, j = 0; i < strLength; i++) {
        char c = string[i];

        if (c == '\0') {
            if (j != 0){
                parts[partCounter][j] = '\0';
                partCounter += 1;
            }
            break;
        }

        if (partCounter == maxParts) {
            break;
        }

        if (c == splitChar) {
            if (j != 0){
                parts[partCounter][j] = '\0';
                partCounter += 1;
                j = 0;
            }
            continue;
        }

        if (j+1 == maxLength) {
            parts[partCounter][j] = '\0';
            partCounter += 1;
            j = 0;

            // skippe bis zum ende vom string oder bis neuer Part anfängt
            while (string[i] != '\0' && string[i] != splitChar) {
                i += 1;
            }
            continue;
        }

        parts[partCounter][j] = c;
        j++;
    }

    return partCounter;
}

int strLen(char *string){
    int i = 0;
    while (*string != '\0'){
        string++;
        i += 1;
    }
    return i;
}