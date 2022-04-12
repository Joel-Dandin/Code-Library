#include <stdio.h>
#define MAX 100

int arr[MAX];

void initialiseArray(int noElements)
{
    arr[0] = 1;
    for(int i=1;i<=noElements;i++)
        arr[i] = 0;
}

void waysToReach(int noElements,int number)
{
    for(int i=0;i <= noElements - number;i++)
        arr[i + number] += arr[i];
}

void printArray(int noElements)
{
    for(int i=0;i<=noElements;i++)
        printf("%d-%d\t",i,arr[i]);
}

int main()
{
    int noElements,elements,individualElement[MAX];

    printf("Enter Number of elements TO rum program on - ");
    scanf("%d",&noElements);
    initialiseArray(noElements);

    printf("Enter number of weights - ");
    scanf("%d",&elements);

    printf("Enter weights - \n");
    for(int i = 0; i<elements;i++)
    {
        scanf("%d",&individualElement[i]);
    }

    for(int i = 0; i<elements;i++)
    {
        printf("\nReaching Numbers using %d and previous numbers\n",individualElement[i]);
        waysToReach(noElements,individualElement[i]);
        printArray(noElements);
    }
}
