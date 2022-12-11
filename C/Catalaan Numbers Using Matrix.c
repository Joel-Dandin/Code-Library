//fing nck using pascals triangle
#include<stdio.h>
int arr[100][100];

int min(int x, int y)
{
    if(x>y)
        return y;
    else
        return x;
}
void Catalan(int n,int k)
{
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<min(i,k);j++)
        {
            if(j==0 || j==i)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
    }
}

void printMatrix(int n,int k)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
            printf("%d\t",arr[i][j]);
        printf("\n");
    }
}

int main()
{
    int n,k;
    printf("Enter numbers n and k -");
    scanf("%d %d",&n,&k);
    Catalan(n,k);
    printMatrix(n,k);

}
