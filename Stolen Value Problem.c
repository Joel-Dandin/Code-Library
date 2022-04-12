#include<stdio.h>
#include<string.h>
#define MAX 100

int arr[MAX],val[MAX];

int max2(int no1,int no2)
{
    if(no1>no2)
        return no1;
    else
        return no2;
}

void initialiseArray(int noElements)
{
    memset(arr,0,noElements);
    //for(int i=0;i<=noElements;i++)
    //  arr[i] = 0;
}

void initialiseValue(int noElements)
{
    printf("Enter values - \n");
    for(int i=1;i<=noElements;i++)
        scanf("%d",&val[i]);
}

int LongestIncSeq(int noElements)
{
    int loc,temp,max = -1;
    arr[0] = 0;
    arr[1] = val[1];
    for(int j = 2;j<=noElements;j++)
    {
        arr[j] = max2(arr[j-1],(arr[j-2] + val[j]));
    }
    return arr[noElements];
}

void printArray(int noElements)
{

    for(int i=0;i<=noElements;i++)
    {
        printf("%d\t",val[i]);
    }
    printf("\n");
    for(int i=0;i<=noElements;i++)
    {
        printf("%d\t",arr[i]);
    }

}

int main()
{
    int noElements;
    printf("Enter number of elements - ");
    scanf("%d",&noElements);

    initialiseArray(noElements);

    initialiseValue(noElements);

    int temp = LongestIncSeq(noElements);
    printArray(noElements);
    printf("\nThe highest robbed value is %d",temp);


}
