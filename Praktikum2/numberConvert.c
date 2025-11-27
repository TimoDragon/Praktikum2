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