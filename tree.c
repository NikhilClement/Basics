#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
}Node;

Node *createNode(int data)
{
    Node *temp = calloc(1, sizeof(Node));
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(Node *head)
{
    if(!head)
        return;
    inorder(head->left);
    printf("%d\n", head->key);
    inorder(head->right);
}

int height(Node *node)
{
    if(!node)
        return 0;
    else {
        int rheight = height(node->right);
        int lheight = height(node->left);
        if(rheight>lheight)
            return (rheight + 1);
        else
            return (lheight + 1);
    }
}

int main()
{
    Node *node = createNode(0);
    node->left = createNode(1);
    node->right = createNode(2);
    node->left->left = createNode(3);
    node->left->right = createNode(4);
    inorder(node);
    printf("Height of the binary tree = %d\n", height(node));
    free( node->left->left);
    free(node->left->right);
    free(node->right);
    free(node->left);
    free(node);
    return 0;
}
