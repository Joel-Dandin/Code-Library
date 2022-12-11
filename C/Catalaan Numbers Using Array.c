//fing nck using pascals triangle
#include<stdio.h>
int c[100];

int min(int x, int y)
{
    if(x>y)
        return y;
    else
        return x;
}

void Catalan(int n,int k)
{
    for(int i =1;i<=n;i++)
    {
        for(int j =min(i,k); j>0 ;j--)
        {
            c[j] = c[j] + c[j-1];
        }
    }
}


void printMatrix(int n,int k)
{
    for(int i=0;i<=n;i++)
    {
        printf("%d\t",c[i]);
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
