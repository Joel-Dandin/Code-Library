/*This is a method of getting the number of ways u can get the number using the given coins
eg: coins - 2 3 5
number = 0 1 2 3 4 5 6 7 8
vlaues = 1 0 1 1 1 3 2 5 6
2 = 2
3 = 3
4 = 2+2
5 = 2+3, 3+2, 5
6 = 2+2+2, 3+3
7 = 2+3+2, 3+2+2, 5+2, 2+2+3, 2+5
....
*/

#include<stdio.h>
#include<string.h>
#define MAX 1000

void calculateVal(int *arr,int *val,int noElements,int noCoins)
{
    int temp;
    for(int i = 0;i<noElements;i++)
    {
        for(int j = 0;j<noCoins;j++)
        {
            if((i - val[j])>=0)
            {
                arr[i] = arr[i] + arr[i - val[j]];
            }
        }
    }
}

void printArray(int *arr,int noElements)
{
    for(int i=0;i<=noElements;i++)
    {
        printf("%d\t",i);
    }
    printf("\n");
    for(int i=0;i<=noElements;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int main()
{
    int noElements,noCoins,arr[MAX],val[MAX];

    printf("Enter the number of coins - ");
    scanf("%d",&noCoins);

    for(int i =0;i<noCoins;i++)
    {
        scanf("%d",&val[i]);
    }

    printf("Enter the numbers to get the value for - ");
    scanf("%d",&noElements);

    for(int i=0;i<=noElements;i++)
        arr[i] = 0;
    arr[0] = 1;
    printArray(arr,noElements);
    calculateVal(arr,val,noElements+1,noCoins);
    printArray(arr,noElements);
}
