// *********************************************************************
// A2_matrix_vektor.c							Version 05.01.2021_S hpw
// Matrix-Vektor Multiplikation mit Zeitausgabe
// *********************************************************************
#include <stdio.h>						    // Header fuer Ein-/Ausgaben
#include <stdlib.h>						    // Header fuer Allgemeine Funktionen
#include <time.h>						    // Header fuer Datum und Zeit

typedef int** matrix_typ;

void gen_random();
void print_matrix(int** matrix, int dimension);
void print_vektor(int* vektor, int dimension);
void multiply_matrix_vector(matrix_typ matrix, int* vektor, int* ergebnis, int dimension);
matrix_typ create_matrix(size_t dimension);

int main(void) {
	printf("dimension;µs\n");
	for (int i = 2; i < 201; i++) {
		int** matrix = create_matrix(i);
		int* vektor = calloc(i, sizeof(int));
		int* ergebnis = calloc(i, sizeof(int));

		gen_random(matrix, vektor, i);

		int start = clock();
		multiply_matrix_vector(matrix, vektor, ergebnis, i);
		int end = clock();

		printf("%d;%.0f\n", i, ((float) (end-start) / CLOCKS_PER_SEC) * 1000000);

		free(matrix);
		free(vektor);
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

void gen_random(matrix_typ matrix, int* vektor, int dimension) {
    srand(time(NULL));

    for (int i = 0; i < dimension; i++) {
		vektor[i] = (rand() % 64) - 32;
		
        for (int j = 0; j < dimension; j++) {
            matrix[i][j] = (rand() % 64) - 32;
        }
    }
}

void multiply_matrix_vector(matrix_typ matrix, int* vektor, int* ergebnis, int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            ergebnis[i] += matrix[i][j] * vektor[j];
        }
    }
}

void print_matrix(int** matrix, int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_vektor(int* vektor, int dimension) {
    for (int i = 0; i < dimension; i++) {
        printf("%d\n", vektor[i]);
    }
}