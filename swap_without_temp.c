#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("Before swapping\n"
    "a = %d b = %d\n", a, b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("After swapping\na = %d b = %d\n", a, b);
    return 0;
}
