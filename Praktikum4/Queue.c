struct Knoten;
struct Knoten * qinit();
void enqueue(struct Knoten * schlange, int element);
int dequeue(struct Knoten * schlange);
int isEmpty(struct Knoten * schlange);
void printQueue(struct Knoten * schlange);

