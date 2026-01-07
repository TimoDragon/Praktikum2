// *********************************************************************
// A3_matrix_matrix.c							Version 05.01.2021_S hpw
// Matrix-Matrix Multiplikation mit Zeitausgabe
// *********************************************************************
#include <stdio.h>						    // Header fuer Ein-/Ausgaben
#include <stdlib.h>						    // Header fuer Allgemeine Funktionen
#include <time.h>						    // Header fuer Datum und Zeit

typedef int** matrix_typ;

void gen_random(int** matrix_a, int** matrix_b, int dimension);
void multiply_matrix_matrix(int** matrix_1, int** matrix_2, int** ergebnis, int dimension);
void print_matrix(int** arr, int zeilen, int spalten);
matrix_typ create_matrix(size_t dimension);

int main(void){
	printf("dimension;µs\n");
	for (int i = 2; i < 201; i++) {
		matrix_typ matrix_a = create_matrix(i);
		matrix_typ matrix_b = create_matrix(i);
		matrix_typ ergebnis = create_matrix(i);

		gen_random(matrix_a, matrix_b, i);

		int start = clock();
		multiply_matrix_matrix(matrix_a, matrix_b, ergebnis, i);
		int end = clock();

		printf("%d;%.0f\n", i, ((float) (end-start) / CLOCKS_PER_SEC) * 1000000);

		free(matrix_a);
		free(matrix_b);
		free(ergebnis);
	}

	return 0;								// Programmende
}

matrix_typ create_matrix(size_t dimension) {
	size_t len = dimension * dimension * sizeof(int) + dimension * sizeof(int*);

	matrix_typ mat = malloc(len);

	int *data = (int*) (mat + dimension);
	for (int i = 0; i < dimension; i++) {
		mat[i] = data+i*dimension;
	}

	return mat;
}

void gen_random(int** matrix_a, int** matrix_b, int dimension) {
    srand(time(NULL));

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            matrix_a[i][j] = (rand() % 64) - 32;
			matrix_b[i][j] = (rand() % 64) - 32;
        }
    }
}

void multiply_matrix_matrix(int** matrix_1, int** matrix_2, int** ergebnis, int dimension) {
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			for (int k = 0; k < dimension; k++) {
				ergebnis[i][j] += matrix_1[i][k] * matrix_2[k][j];
			}
		}
	}
}

void print_matrix(int** arr, int zeilen, int spalten) {
    for (int i = 0; i < zeilen; i++) {
        for (int j = 0; j < spalten; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
