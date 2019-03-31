#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 10

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}Node;

Node **createQueue(int *front, int *rear)
{
    Node **temp = calloc(Q_SIZE, sizeof(Node*));
    *front = *rear = 0;
    return temp;
}

Node *createNode(int data)
{
    Node *temp = calloc(1, sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void enqueue(Node **q, int *rear, Node *n)
{
    q[*rear] = n;
    (*rear)++;
}

Node *dequeue(Node **q, int *front)
{
    Node *temp =  q[*front];
    (*front)++;
    return temp;
}

void bfs(Node *n)
{
    Node *temp = n;
    int front, rear;
    Node **queue = createQueue(&front, &rear);
    while(temp) {
        printf("%d\n", temp->data);
        if(temp->left)
            enqueue(queue, &rear, temp->left);
        if(temp->right)
            enqueue(queue, &rear, temp->right);
        temp = dequeue(queue, &front);
    }
}

int main()
{
    Node *node = createNode(0);
    node->left = createNode(1);
    node->right = createNode(2);
    node->left->left = createNode(3);
    node->left->right = createNode(4);
    bfs(node);
    free( node->left->left);
    free(node->left->right);
    free(node->right);
    free(node->left);
    free(node);
    return 0;
}
