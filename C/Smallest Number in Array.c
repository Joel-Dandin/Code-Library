#include <stdio.h>
int lookup[10000][10000];

void populateLookupTable(int arr[],int shops)
{
    int minIndex,min =999;
    for(int i =0;i<shops;i++)
    {
        min =999;
        minIndex = -1;
        for(int j=i;j<shops;j++)
        {
            if(arr[j] < min)
            {
                min =arr[j];
                minIndex = j;
                lookup[i][j] = j;
            }
            else
            {
                lookup[i][j] = minIndex;
            }
        }
    }
}

void arrayprint(int arr[],int n)
{
    printf("Matrix\n");
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",lookup[i][j]);
        }
        printf("\n");
    }
    printf("Array\n");
    for(int j=0;j<n;j++)
    {
        printf("%d ",arr[j]);
    }
    printf("\n");
}
int main()
{
    int shops,quary,arr[10000];
    printf("Enter the no of elements and no of queries\n");
    scanf("%d %d",&shops,&quary);
    printf("Enter elements\n");
    for(int i =0;i<shops;i++)
    {
        scanf("%d",&arr[i]);
    }

    populateLookupTable(arr,shops);
    arrayprint(arr,shops);
    int a,b;
    printf("Enter Queries\n");
    for(int i=0;i<quary;i++)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",arr[lookup[a][b]]);
    }
}
