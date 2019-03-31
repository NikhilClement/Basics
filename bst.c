#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node *createNode(int data)
{
    Node *temp = calloc(1, sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void bst(Node *root, int data)
{
    if(root == NULL) {
        printf("Element not found\n");
        return;
    }
    if(root->data == data) {
        printf("Input key %d found\n", data);
        return;
    }
    if(data < root->data)
        bst(root->left, data);
    else
        bst(root->right, data);
}

int main(int argc, char **argv)
{
    Node *root = createNode(30);
    root->left = createNode(29);
    root->right = createNode(39);
    root->right->left = createNode(38);
    root->right->right = createNode(40);
    int data = strtol(argv[1], NULL, 10);
    bst(root, data);
    return 0;
}
