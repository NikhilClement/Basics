#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}Node;

typedef struct queue{
    int *front, *rear;
    Node *n;
}Queue;

Queue *createQueue(){
    Queue *temp = calloc(Q_SIZE, sizeof(Queue));
    return temp;
}

int main() {
Queue *q = createQueue();
enqueue();
}
