#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}Node;

void AddNode(int position, int data, Node **head) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node *temp = *head;
    int p = 0;
    newNode->data = data;
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    while (temp != NULL) {
        if(position == p) {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        p++;
        temp = temp->next;
    }
    return;
}

void DeleteNode (int position, Node **head) {
    Node *temp = *head;
    Node *temp2 = temp;
    int p = 0;
    if(position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL) {
        if (p == position && temp->next != NULL) {
            temp2->next = temp->next;
            free (temp);
            return;
        }
        if (p == position && temp->next == NULL) {
            temp2 = NULL;
            free (temp);
            return;
        }
        p++;
        temp2 = temp;
        temp = temp->next;
    }
}

void printList (Node *head) {
    Node *temp = head;
    printf("Printing Linked list\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 9;
    head->next = NULL;
    AddNode(0, 10, &head);
    AddNode(0, 20, &head);
    AddNode(1, 30, &head);
    AddNode(0, 40, &head);
    AddNode(3, 50, &head);
    printList(head);
    DeleteNode(3, &head);
    printList(head);
    return 0;
}
