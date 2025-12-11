#include <stdio.h>
#include <stdlib.h>
struct Knoten;
struct Knoten * qinit();
void enqueue(struct Knoten * schlange, int element);
int dequeue(struct Knoten * schlange);
int isEmpty(struct Knoten * schlange);
void printQueue(struct Knoten * schlange);
void menu();

int main(void){
    struct Knoten *schlange = qinit();
    menu(schlange);
}

struct Knoten{
    int key;
    struct Knoten * next;
};

struct Knoten * qinit(){
    struct Knoten* newKnoten;
    newKnoten = (struct Knoten*)malloc(sizeof(struct Knoten));
    newKnoten->next = NULL;
    return newKnoten;
}

void enqueue (struct Knoten * schlange, int element){
    struct Knoten * tmp = schlange;
    while (tmp ->next != NULL){
        tmp = tmp->next;
    }
    struct Knoten * newKnoten = malloc(sizeof(struct Knoten));
    tmp->next = newKnoten;
    newKnoten->key = element;
    newKnoten->next = NULL;
}

int dequeue(struct Knoten * schlange){
    if (!isEmpty(schlange)){
        struct Knoten tmp = *schlange;
        schlange->next = schlange->next->next;
        return tmp.key;
    }
    return -1;
}

int isEmpty(struct Knoten * schlange){
    if (schlange->next == NULL){
        return 1;
    }
    return 0;
}

void printQueue(struct Knoten * schlange){
    if (isEmpty(schlange)){
        printf("Die Schlange ist Leer\n");
        return;
    }
    struct Knoten * tmp = schlange->next;
    while (tmp != NULL){
        printf("%d",tmp->key);
        tmp = tmp->next;
    }
}

void menu(struct Knoten *schlange){
    printf("\nMenü zur Wartenschlagenverwaltung:\n");
    printf("1. Anfügen eines Elementes\n");
    printf("2. Löschen und Ausgeben des ersten Elementes\n");
    printf("3. Ausgeben der Warteschlange\n");
    printf("4. Beenden des Programms\n");
    int input;
    scanf("\n %d", &input);
    switch (input)
    {
        case 1:
            enqueue(schlange,1);
            menu(schlange);
            break;
        case 2:
            dequeue(schlange);
            menu(schlange);
            break;
        case 3:
            printQueue(schlange);
            menu(schlange);
            break;
        case 4:
            exit(0);
        default:
            printf("Falsche Eingabe!");
            menu(schlange);
    }
}