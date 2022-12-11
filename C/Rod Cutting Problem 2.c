#include<stdio.h>
#include <string.h>
#define MAX 1000

int arr[MAX];

int max(int no1,int no2)
{
    if(no1>no2)
        return no1;
    else
        return no2;
}

void RodCutting2(int noElements,int val[])
{
    for(int i =1;i<noElements;i++)
    {
        for(int j = 0;j <i;j++)
        {
            arr[i] = max(arr[i],arr[i - (j+1)] + val[j]);
        }
    }
}

void printArray(int noElements)
{
    for(int i=0;i<=noElements;i++)
        printf("%d-%d\t",i,arr[i]);
    printf("\n");
}

int main()
{
    int noElements,val[100];

    printf("Enter no of length alloved - ");
    scanf("%d",&noElements);
    memset(arr,0,noElements + 1);
    printf("Enter values of length - \n");
    for(int i =0;i<noElements;i++)
    {
        scanf("%d",&val[i]);
    }
    RodCutting2(noElements+1,val);

    printArray(noElements);
}
