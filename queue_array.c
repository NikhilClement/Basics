#include <stdio.h>
#include <stdlib.h>
#define Q_MAX_SIZE 100

int front;
int rear;
int queue[Q_MAX_SIZE];

void enqueue(int elem)
{
    queue[rear] = elem;
    rear++;
}

void dequeue()
{
    queue[rear--] = 0;
}

void print_queue()
{
    int i;
    for(i = 0; i < rear; i++)
    {
        printf("%d\n", queue[i]);
    }
}

int main()
{
    int i;
    for(i = 0; i < 8; i++)
    {
        enqueue(i);
    }
    print_queue();
    printf("\nDequeuing\n\n");
    dequeue();
    print_queue();
    return 0;
}
