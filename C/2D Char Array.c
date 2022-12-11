#include <stdio.h>
#include <stdlib.h>

int main()
{

    int rows =  10;
    int cols = 50;
    int i;
    
    char **string = malloc(rows * sizeof(char *));
    for(i = 0; i < rows; i++)
        string[i] = malloc(cols * sizeof(char));

    return 0;
}