
#include<stdio.h>
#include<string.h>
#define MAX 100

int arr[MAX][MAX];

void MinimumChange(int a[],int n,int sum)
{
    for(int i=0;i<=n;i++)
        arr[i][0] = 1;
    for(int j=0;j<=n;j++)
        arr[0][j] = 1;

    for(int i = 1; i<=n;i++)
    {
        for(int j = 1; j<=sum;j++)
        {
            if(arr[i-1][j] == 1)
            {
                arr[i][j] =1;
            }
            else
            {
                if(a[i-1] >j)
                {
                    arr[i][j] = 0;
                }
                else
                {
                    arr[i][j] = arr[i-1][j-a[i-j]];
                }
            }
        }
    }
}

void printMatrix(int n)
{


    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            printf("%d\t",arr[i][j]);
        printf("\n");
    }
}

int main()
{
    int no,arr[50];
    printf("Enter no of elements ");
    scanf("%d",&no);
    for(int i =0;i<no;i++)
    {
        scanf("%d",&arr[i]);
    }
    MinimumChange(arr,no,no);
    printMatrix(no);


}
