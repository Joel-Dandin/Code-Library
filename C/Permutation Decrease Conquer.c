
#include <stdio.h>
#include <stdlib.h>

int gn;

void permute(int a[], int n)
{
    if (n == 1)
    {
        int i;
        for(i = 0; i < gn; i++)
            printf("%d ", a[i]);
        printf("\n");
        return;
    }

    int i;
    int temp;
    for(i = 0; i < n; i++)
    {
        temp = a[i];
        a[i] = a[n-1];
        a[n-1] = temp;
        
        permute(a, n-1);
        
        temp = a[i];
        a[i] = a[n-1];
        a[n-1] = temp;

    }
}

int main()
{
    int a[5] = {1, 2, 3};
    int n = 3;
    gn = n;

    permute(a, n);

    return 0;
}