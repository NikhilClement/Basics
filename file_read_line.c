#include <stdio.h>
#include <stdlib.h>
int main()
{
    char c[1000];
    FILE *fp;
    fp = fopen("abc.txt", "r");
    if(!fp)
    {
        printf("File doesn't exist\n");
        exit(1);
    }
    fscanf(fp, "%[^,]", c);
    printf("Data from the file:\n%s\n", c);
    fclose(fp);

    return 0;
}
