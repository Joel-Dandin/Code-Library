#include<stdio.h>
#include<string.h>
#define MAX 1000


int noElements,arr[MAX];

void swap(int *no1,int *no2)
{
    int temp = *no2;
    *no2 = *no1;
    *no1 = temp;
}

void printArray()
{
    printf("X");
    for(int i=0;i<2*noElements;i++)
    {
        if(arr[i] == 1)
            printf("X");
        else
            printf("Y");
    }
    printf("Y\n");
}

int main()
{
    printf("Enter Number - ");
    scanf("%d",&noElements);
    noElements--;
    for(int m = 0;m<noElements;m++)
    {
        arr[m] = 1;
    }

    for(int n = 0;n<noElements;n++)
    {
        arr[n + noElements] = 2;
    }
    printArray();
    printf("-----\n");
    for(int i =0;i<2*noElements;i++)
    {
        for(int j=0;j<i/2+1;j++)
        {
            swap(&arr[i],&arr[j]);
            printArray();
            swap(&arr[i],&arr[j]);
            //printArray();
        }
    }
}
