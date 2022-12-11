#include<stdio.h>
#include<string.h>

int calculateVal(int *arr,int noElements)
{
    int temp;
    for(int i = 1;i<noElements;i++)
    {
        printf("\n->%d\n",i);
        for(int j = 0;((i<=6) && ((i-j) >=0));j++)
        {
            printf("\n=>%d-%d\n",i,j);
            arr[i] = arr[i] + arr[j];
        }
    }
    return arr[noElements - 1];
}

void printArray(int *arr,int noElements)
{
    for(int i=0;i<=noElements;i++)
    {
        printf("%d\t",arr[i]);
    }
}

int main()
{
    int noElements, arr[1000];
    printf("Enter the number to get the value for - ");
    scanf("%d",&noElements);

    //memset(arr,0,noElements);
    for(int i=0;i<=noElements;i++)
      arr[i] = 0;
    arr[0] = 1;

    printArray(arr,noElements);
    int value = calculateVal(arr,noElements);
    printf("\nThe value is %d\n",value);
    printArray(arr,noElements);
}
