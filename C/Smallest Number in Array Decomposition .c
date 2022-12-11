#include <stdio.h>
#include <math.h>
int lookup[100];
int blockSize;

void populateDecompoTable(int arr[],int shops)
{
    /*int minIndex,min =999;
    int blockSize = sqrt(shops);
    for(int i =0;i<=(shops/blockSize);i++)
    {
        min =999;
        minIndex = -1;
        for(int j=0;j<blockSize;j++)
        {
            if(arr[j+ (i)*blockSize]<min)
            {
                min = arr[j+ (i*blockSize)];
                minIndex = j+ (i*blockSize);
            }
        }
        lookup[i] = minIndex;
    }*/
    int min =999;
    int blockIndex = -1;
    blockSize = sqrt(shops);
    for (int i=0; i<shops; i++)
    {
        if (i%blockSize == 0)
        {
            blockIndex++;
            min =999;
            //printf("next block\n");
        }
        if(arr[i]<min)
        {
            min = arr[i];
            //printf("Compared %d %d\n",arr[i],min);
            lookup[blockIndex] = i;

        }

    }
}
int query(int arr[],int l, int r)
{
    int min = 9999;
    while (l<r && l%blockSize!=0 && l!=0)
    {
        if(min > arr[l])
            min = arr[l];

        l++;
    }
    while (l+blockSize <= r)
    {
        if(min > lookup[l/blockSize])
            min = lookup[l/blockSize];
        l += blockSize;
    }
    while (l<=r)
    {
        if(min > arr[l])
            min = arr[l];

        l++;
    }
    return min;
}

void arrayprint(int arr[],int n)
{
    printf("Matrix\n");
    for(int i =0;i<n;i++)
    {
        printf("%d ",lookup[i]);

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

    populateDecompoTable(arr,shops);
    arrayprint(arr,shops);
    int a,b;
    printf("Enter Queries\n");
    for(int i=0;i<quary;i++)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",query(arr,a,b));
    }
}
