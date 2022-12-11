/*
In this example 2 palyers select the largest no in an array and remove the right most elements the person who removed the number last wins hte game.
eg: arr =   7       3       1       4       8
player 1 -  7       3       1       4       [8]->
player 2 -  [7]->   3       1       4
result player 2 wins

eg: arr =   5       3       1       6       7       0       2       3
player 1 -  5       3       1       6       [7]->   0       2       3
player 2 -  5       3       1       [6]->
player 1 -  [5]->
result player 1 wins
*/
/*
//Method 1
#include<stdio.h>
#include<string.h>

void printArray(int *arr,int noElements)
{
    for(int i=0;i<=noElements;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int calculateVal(int *val,int noElements)
{
    int min =0,no=0,arr[100];
    for(int i=0;i<noElements;i++)
    {
        if(val[i]>min)
        {
            min = val[i];
            arr[no] = val[i];
            no++;
        }
    }
    printf("Removed numbers are ");
    printArray(arr,no-1);
    return (no-1);
}

int main()
{
    int noElements,val[1000];
    printf("Enter no of numbers -");
    scanf("%d",&noElements);
    for(int i=0;i<noElements;i++)
        scanf("%d",&val[i]);

    int value = calculateVal(val,noElements);
    if(value%2)
        printf("Player 2 Wins\n");
    else
        printf("Player 1 Wins\n");
}
*/
#include<stdio.h>
#include<string.h>

int calculateVal(int *val,int noElements)
{
    int min =0,no=0;
    for(int i=0;i<noElements;i++)
    {
        if(val[i]>min)
        {
            min = val[i];
            no++;
        }
    }
    return (no-1);
}

int main()
{
    int noElements,val[1000];
    printf("Enter no of numbers -");
    scanf("%d",&noElements);
    for(int i=0;i<noElements;i++)
        scanf("%d",&val[i]);

    int value = calculateVal(val,noElements);
    if(value%2)
        printf("Player 2 Wins\n");
    else
        printf("Player 1 Wins\n");
}
