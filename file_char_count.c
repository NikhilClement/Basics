#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char str[2000];
    char *tok;
    if(!(fp = fopen("abc.txt", "r")))
    {
        printf("File doesn't exist\n");
        exit(1);
    }
    while(fgets(str, sizeof(str), fp))
    {
        tok = strtok(str, " ");
        strcat(str, "\n");
        fputs(str, stdout);
    }
    fclose(fp);
    return 0;
}
