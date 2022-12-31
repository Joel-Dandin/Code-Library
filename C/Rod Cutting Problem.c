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

void dyckPath(int noElements)
{
    for(int i =2;i<noElements;i++)
    {
        for(int j = 1;j <=i/2;j++)
        {
            arr[i] = max(arr[i],max((j*(i-j)),j*arr[i-j]));
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
    int noElements;

    printf("Enter Length of rod - ");
    scanf("%d",&noElements);
    //initialise array to all 0
    memset(arr,0,noElements + 1);

    dyckPath(noElements+1);

    printArray(noElements);
}
