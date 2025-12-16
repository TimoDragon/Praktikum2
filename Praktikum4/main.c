#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Knoten{
    int key;
    struct Knoten *next;
};

int read_number_input();
void clearBuffer();

struct Knoten *qinit();

void enqueue(struct Knoten *schlange, int element);
int dequeue(struct Knoten *schlange);
int isEmpty(struct Knoten  *schlange);
int count(struct Knoten *schlange);
void printQueue(struct Knoten *schlange);
void shutdown(struct Knoten *schlange);
void menu(struct Knoten *schlange);

int main(void) {
    struct Knoten *schlange = qinit();
    while (1) {
        menu(schlange);
    }
}

struct Knoten *qinit() {
    struct Knoten *newKnoten = malloc(sizeof(struct Knoten));
    newKnoten->next = NULL;

    return newKnoten;
}

void enqueue(struct Knoten *schlange, int element) {
    struct Knoten *tmp = schlange;
    while (tmp ->next != NULL){
        tmp = tmp->next;
    }

    struct Knoten *newKnoten = malloc(sizeof(struct Knoten));
    newKnoten->key = element;
    newKnoten->next = NULL;

    tmp->next = newKnoten;
}

int dequeue(struct Knoten *schlange) {
    if (isEmpty(schlange)) {
        return -1;
    }
    struct Knoten *knoten = schlange->next;
    int element = knoten->key;

    schlange->next = knoten->next;
    free(knoten);
    return element;
}

int isEmpty(struct Knoten *schlange) {
    if (schlange->next == NULL){
        return 1;
    }
    return 0;
}

void printQueue(struct Knoten *schlange) {
    if (isEmpty(schlange)){
        printf("Die Schlange ist leer\n");
        return;
    }
    struct Knoten *tmp = schlange->next;
    while (tmp != NULL){
        printf("%d\n", tmp->key);
        tmp = tmp->next;
    }
}

int count(struct Knoten *schlange){
    if (isEmpty(schlange)){
        return 0;
    }
    return count(schlange->next)+1;
}

void menu(struct Knoten *schlange) {
    printf("Menü zur Wartenschlagenverwaltung:\n");
    printf("1. Anfügen eines Elementes\n");
    printf("2. Löschen und Ausgeben des ersten Elementes\n");
    printf("3. Ausgeben der Warteschlange\n");
    printf("4. Länge der Schlange\n");
    printf("5. Beenden des Programms\n");

    int input = read_number_input();

    switch (input) {
        case 1:
            printf("Element: \n");
            int input = read_number_input();
            enqueue(schlange,input);
            break;
        case 2:
            if (!isEmpty(schlange)){
                int element = dequeue(schlange);
                printf("%d\n", element);
            }else{
                printf("Schlange ist Leer!\n");
            }
            break;
        case 3:
            if (!isEmpty(schlange)){
                printQueue(schlange);
            }else{
                printf("Schlange ist Leer!\n");
            }
            break;
        case 4:
            printf("Länge: %d\n",count(schlange));
            break;
        case 5:
            shutdown(schlange);
        default:
            printf("Falsche Eingabe!\n");
    }
}

int read_number_input() {
    char input[4];

    fgets(input, sizeof(input), stdin);

    if (!strchr(input, '\n')){
        clearBuffer();
        return read_number_input();
    }

    return atoi(input);
}

void shutdown(struct Knoten *schlange){
    while (!isEmpty(schlange)){
        dequeue(schlange);
    }
    free(schlange);
    exit(0);
}

void clearBuffer(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
