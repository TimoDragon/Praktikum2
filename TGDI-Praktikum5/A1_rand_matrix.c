// *********************************************************************
// A1_rand_matrix.c								Version 05.01.2021_S hpw
// Matrix und Vektor mit Zufallswerten erzeugen und ausgeben
// *********************************************************************
#include <stdio.h>						    // Header fuer Ein-/Ausgaben
#include <stdlib.h>						    // Header fuer Allgemeine Funktionen
#include <time.h>						    // Header fuer Datum und Zeit

#define ZEILEN 4
#define SPALTEN 4

int matrix_a[ZEILEN][SPALTEN];
int vektor_a[ZEILEN];
int vektor_b[ZEILEN];

void gen_random();
void print_matrix(int arr[ZEILEN][SPALTEN]);
void print_vector(int arr[ZEILEN]);

typedef int** matrix;

int main(void){
	gen_random();
	return 0;								// Programmende
}

void gen_random() {
    srand(time(NULL));

    for (int i = 0; i < ZEILEN; i++) {
		vektor_a[i] = (rand() % 64) - 32;
        vektor_b[i] = (rand() % 64) - 32;
		
        for (int j = 0; j < SPALTEN; j++) {
            matrix_a[i][j] = (rand() % 64) - 32;
        }
    }
}


void print_matrix(int arr[ZEILEN][SPALTEN]) {
    for (int i = 0; i < ZEILEN; i++) {
        for (int j = 0; j < SPALTEN; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void print_vector(int arr[ZEILEN]) {
    for (int i = 0; i < ZEILEN; i++) {
        printf("%d\n", arr[i]);
    }
}