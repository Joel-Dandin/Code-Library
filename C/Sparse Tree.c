#include<stdio.h>
#include<math.h>

int lookup[50][50];

void sparseTree(int a[],int n)
{

    for(int i=0;i<n;i++)
    {
        lookup[i][0] = i;

    }

    for(int j=0;(1<<j)<=n;j++)
    {
        for(int i=0;(i+(1<<j)-1)<n;i++)
        {
            if(a[lookup[i][j-1]] < a[lookup[i+(1<<(j+1))][j-1]])
                lookup[i][j] = lookup[i][j-1];
            else
                lookup[i][j] = a[lookup[i+(1<<(j+1))][j-1]];
        }
    }
}
int query(int a[],int l,int r)
{
    int j = (int)log2(r-l+1);
    if(a[lookup[l][j]] <= a[lookup[r-(1<<j) + 1][j]])
        return a[lookup[l][j]];
    else
        return a[lookup[r-(1<<j) + 1][j]];
}

void printMatrix(int n)
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d\t",&lookup[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{

    int i,j,n,q,b,c;
    int a[100];

    printf("Enter no of elements: ");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    sparseTree(a,n);

    printMatrix(n);

    printf("Enter no of Queries: ");
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        printf("Enter limit :");
        scanf("%d %d",&b,&c);
        printf("%d\n",query(a,b,c));
    }


    return 0;
}
