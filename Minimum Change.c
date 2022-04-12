// minimum no of insert delete and replace operation to be made to get string 2
#include<stdio.h>
#include<string.h>
#define MAX 100

int arr[MAX][MAX];

int min2(int no1,int no2)
{
    if(no1<no2)
        return no1;
    else
        return no2;
}

int MinimumChange(char *str1, char *str2)
{
    int n,m;
    n = strlen(str1);
    m = strlen(str2);

    for(int i=0;i<=n;i++)
        arr[i][0] = i;
    for(int j=0;j<=m;j++)
        arr[0][j] = j;

    for(int i = 1; i<=n;i++)
    {
        for(int j = 1; j<=m;j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                arr[i][j] = arr[i - 1][j - 1];
            }
            else
            {
                arr[i][j] = 1+ min2(arr[i-1][j-1],min2(arr[i][j+1],arr[i+1][j]));
            }
        }
    }
    return arr[n][m];
}

void printMatrix(char *str1, char *str2)
{
    int n,m;
    n = strlen(str1);
    m = strlen(str2);

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            printf("%d\t",arr[i][j]);
        printf("\n");
    }
}

int main()
{
    char str1[MAX],str2[MAX];
    printf("Enter first string - ");
    scanf("%s",str1);

    printf("Enter Second string - ");
    scanf("%s",str2);

    int temp,s1end,s2end;
    temp = MinimumChange(str1,str2);

    printMatrix(str1,str2);

    printf("teh minimum no of insert delete and add operations to make %s to %s is %d",str1,str2,temp);

}
