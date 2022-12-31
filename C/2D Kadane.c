#include <limits.h>
#include <stdio.h>
#include <string.h>
#define ROW 50
#define COL 50


int kadane(int* arr, int* start,int* finish, int n)
{
    int sum = 0, maxSum = INT_MIN, i;
    *finish = -1;

    int local_start = 0;

    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
            local_start = i + 1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }

    if (*finish != -1)
        return maxSum;

    maxSum = arr[0];
    *start = *finish = 0;

    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}

void findMaxSum(int M[][COL])
{
    int maxSum = INT_MIN,finalLeft,finalRight,finalTop,finalBottom;

    int left, right, i;
    int temp[ROW], sum, start, finish;

    for (left = 0; left < COL; ++left)
    {
        memset(temp, 0, sizeof(temp));

        for (right = left; right < COL; ++right) {
            for (i = 0; i < ROW; ++i)
                temp[i] += M[i][right];

            sum = kadane(temp, &start, &finish, ROW);

            if (sum > maxSum)
            {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }

    printf("(Top, Left) (%d, %d)\n", finalTop, finalLeft);
    printf("(Bottom, Right) (%d, %d)\n", finalBottom,finalRight);
    printf("Max sum is: %d\n", maxSum);
}

// Driver Code
int main()
{
    int M[ROW][COL];
    int n,m;
    printf("Enter size of matrix: N M\n");
    scanf("%d %d",&n,&m);
    printf("Enter matrix:\n");
    for(int i =0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&M[i][j]);
    findMaxSum(M);

    return 0;
}
