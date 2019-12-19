#include "queue.h"

Node *rear;

void store_rear(Node *n)
{
    rear = n;
}

Node* create_node(int data)
{
    Node *n = calloc(1, sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void enqueue(Node *n)
{
    if(!n)
    {
        return;
    }
    rear->next = n;
    rear = n;
}

int dequeue(Node *head)
{
    Node* temp = head;
    Node* temp2 = NULL;
    int dequeued_data;
    while(temp && temp->next != rear)
    {
        temp = temp->next;
    }
    if(!temp)
    {
        printf("Invalid rear pointer\n");
    }
    dequeued_data = rear->data;
    temp2 = rear;
    rear = temp;
    free(temp2);
    temp2 = NULL;
    temp->next = NULL;
    return dequeued_data;
}

void print_queue(Node *head)
{
    Node *temp = head;
    while(temp)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

#if 0
//Driver code for queue
int main()
{
    int i;
    Node *head = NULL;
    head = create_node(0);
    rear = head;
    for(i = 2; i < 10; i+=2)
    {
        Node *n = create_node(i);
        enqueue(n);
    }
    print_queue(head);
    dequeue(head);
    printf("\nChecking if dequeue worked\n\n");
    print_queue(head);
    dequeue(head);
    printf("\nChecking if dequeue worked\n\n");
    print_queue(head);
    return 0;
}
#endif
