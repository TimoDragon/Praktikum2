#include <stdio.h>
#include <stdlib.h>
struct Knoten;
struct Knoten * qinit();
void enqueue(struct Knoten * schlange, int element);
int dequeue(struct Knoten * schlange);
int isEmpty(struct Knoten * schlange);
void printQueue(struct Knoten * schlange);

int main(void){
    struct Knoten *schlange = qinit();
    enqueue(schlange,1);

    enqueue(schlange,2);

    printQueue(schlange);

    dequeue(schlange);

    printQueue(schlange);
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
        printf("Die Schlange ist Leer");
        return;
    }
    struct Knoten * tmp = schlange->next;
    while (tmp != NULL){
        printf("%d",tmp->key);
        tmp = tmp->next;
    }
}