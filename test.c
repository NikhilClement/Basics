#include <stdio.h>

void printSetBits(int);
int main() {
    int tc, i, num;
    scanf("%d", &tc);
    for(i = 0; i < tc; i++)
    {
        scanf("%d", &num);
        printSetBits(num);
    }
    return 0;
}

void printSetBits(int num)
{
    int count = 0, i, temp = 0;
    for(i = 0; i <= num; i++)
    {
        printf("i = %d\n", i);
        temp = i;
        while(temp)
        {
            if(temp & 1)
            {
                count++;
            }
            temp >>= 1;
        }
    }
    printf("%d\n", count);
}
