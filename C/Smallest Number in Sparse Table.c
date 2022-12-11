#include<stdio.h>

int table[1000][1000];
int Arr[1000];

int min(int x, int y)
{
    if(x>y)
        return y;
    else
        return x;
}

int main()
{
    int n, L, R, q, answer;
    int k =16;
    printf("Enter the no of elements in array\n");
    scanf("%d",&n);
    printf("Enter elements of array\n");
    for(int i = 0; i < n; i++)
        scanf("%d",&Arr[i]);

    // build Sparse Table
    for(int i = 0; i < n; i++)
        table[i][0] = Arr[i];
    for(int j = 1; j <= k; j++) {
        for(int i = 0; i <= n - (1 << j); i++)
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }

    printf("Enter the no of Queries for array\n");
    scanf("%d",&q);
    for(int i = 0; i < q; i++)
    {
        printf("Enter the queries a b\n");
        scanf("%d %d",&L,&R);
        answer = 999;
        for(int j = k; j >= 0; j--) {
            if(L + (1 << j) - 1 <= R) {
                answer = min(answer, table[L][j]);
                L += 1 << j;
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}
