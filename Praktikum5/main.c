#include <stdio.h>
#define BOARD_SIZE 8

void ausgabe(int board[BOARD_SIZE]);
int bedroht(int board[BOARD_SIZE], int x, int y);
void setze(int board[BOARD_SIZE], int column, int* counter);
void clearBoard(int board[BOARD_SIZE]);

int main(void) {
    int board[BOARD_SIZE];

    int counter = 0;
    int line = 0;
    while (line != BOARD_SIZE) {
        clearBoard(board);
        board[0] = line;

        setze(board, 1, &counter);

        line++;
    }

    printf("Counter: %d\n", counter);

    return 0;
}

void ausgabe(int board[BOARD_SIZE]) {
    printf("_________________\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("|%c", board[j] == i ? 'D' : ' ');

            if (j == 7) {
                printf("|\n");
            }
        }
    }
}

int bedroht(int board[BOARD_SIZE], int x, int y) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Horizontal
        if (board[i] == y) {
            return 1;
        }

        // diagonal
        int checkY1 = y-i;
        int checkY2 = y+i;
        int checkX = x-i;

        if (checkX < 0) {
            break;
        }

        if ((checkY1 >= 0 && board[checkX] == checkY1) || (checkY2 >= 0 && board[checkX] == checkY2)) {
            return 1;
        }
    }

    return 0;
}

void setze(int board[BOARD_SIZE], int column, int* counter) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (bedroht(board, column, i)) {
            continue;
        }

        if (column == BOARD_SIZE-1) {
            board[column] = i;
            ausgabe(board);
            board[column] = -1;
            *counter += 1;
        } else {
            board[column] = i;
            setze(board, column+1, counter);
            board[column] = -1;
        }
    }
}

void clearBoard(int board[BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = -1;
    }
}