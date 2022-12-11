/*
in this example the minimum no of coins needed to get the value is claculated using given coins
eg: coins - 1 5 7
result 
no = 0 1 2 3 4 5 6 7 8 9 10 11 12 13
val= 0 1 2 3 4 1 2 1 2 3 4  5  2  3
1 = 1
2 = 1 + 1
3 = 1 + 1 + 1
4 = 1 + 1 + 1 + 1
5 = 5
6 = 5 + 1
7 = 7
8 = 7 + 1
9 = 7 + 1 + 1
10= 7 + 1 + 1 + 1
11= 7 + 1 + 1 + 1 + 1
12= 7 + 5
13= 7 + 5 + 1 
*/

#include<stdio.h>
#include<string.h>
#define MAX 1000

int min2(int no1,int no2)
{
    if(no1<no2)
        return no1;
    else
        return no2;
}

void calculateVal(int *arr,int *val,int noElements,int noCoins)
{
    int temp;
    for(int i = 1;i<noElements;i++)
    {
        for(int j = 0;j<=noCoins;j++)
        {
            if((i - val[j])>=0)
            {
                arr[i] = min2(arr[i],arr[i - val[j]] + 1);
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

    //memset(arr,0,noElements);
    for(int i=0;i<=noElements;i++)
        arr[i] = MAX;
    arr[0] = 0;

    calculateVal(arr,val,noElements+1,noCoins);
    printArray(arr,noElements);
}
