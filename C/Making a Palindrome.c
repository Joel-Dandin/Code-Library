#include<stdio.h>
#include<string.h>
#define MAX 100

int arr[MAX][MAX];

void strrev2(char *str1,char *str2)
{
    int i, len, temp;
    len = strlen(str1);
    for (i = 0; i < len; i++)
    {
        str2[i] = str1[len - i - 1];
    }
}

int max(int no1,int no2)
{
    if(no1>no2)
        return no1;
    else
        return no2;
}

int longestSubstring(char *str1, char *str2)
{
    int n,m;
    n = strlen(str1);
    m = strlen(str2);

    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            arr[i][j] = 0;

    for(int i = 1; i<=n;i++)
    {
        for(int j = 1; j<=m;j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                arr[i][j] = arr[i - 1][j - 1] +1;
            }
            else
            {
                arr[i][j] = max(arr[i][j - 1],arr[i - 1][j]);
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
    printf("Enter the string - ");
    scanf("%s",str1);
    strrev2(str1,str2);

    int temp = longestSubstring(str1,str2);

    printMatrix(str1,str2);

    printf("The number of characters to be added to make it a Palindrome is %d",strlen(str1)-temp);
}
