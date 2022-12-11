/*
we should find the max amount in the substring array
eg: arr = [-2, -3, 4, -1, -2, 1, 5, -3]
max value  = 7 => (4 - 1 - 2 + 1 + 5)
*/
#include<stdio.h>

int kadane(int *arr,int noElements)
{
    int min=0,tmin=0;

    for(int i=0;i<noElements;i++)
    {
        tmin = tmin + arr[i];
        if(tmin<0)
            tmin = 0;
        if(min>tmin)
            min = tmin;
    }
    return min;
}

int main()
{
    int noElements,arr[1000];
    printf("Enter the number of elements - ");
    scanf("%d",&noElements);

    for(int i=0;i<noElements;i++)
        scanf("%d",&arr[i]);

    int value = kadane(arr,noElements);
    printf("the maximum value that we can get is %d",value);
}
