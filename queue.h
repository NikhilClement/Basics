#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

void store_rear(Node *n);
Node* create_node(int data);
void enqueue(Node *n);
int dequeue(Node *head);
void print_queue(Node *head);
