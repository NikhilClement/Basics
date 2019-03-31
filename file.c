#include<stdio.h>
#include<stdlib.h>

typedef struct emp{
    char text[50];
    int age;
}Emp;

int main()
{
    FILE *fp = fopen("abc.txt", "w");
    char ch;
    Emp e;
    printf("Enter data ...\n");
    while((ch = getchar())!= '#')
    {
        putc(ch, fp);
    }
    fclose(fp);
    fp = fopen("abc.txt", "r");
    while((ch = getc(fp))!= EOF)
        printf("%c", ch);
    printf("\n");
    fclose(fp);
    fp = fopen("abc.txt", "r");
    fscanf(fp, "%s %d", e.text, &e.age);
    fprintf(stdout, "%s %d\n", e.text, e.age);
    return 0;
}
