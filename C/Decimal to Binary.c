#include <stdio.h>

void dtob(int n)
{
    int binNum[50];
    int i = 0;
    int j;

    while (n > 0) {
        binNum[i] = n % 2;
        
        n = n / 2;
        i++;
    }

    for (j = i - 1; j >= 0; j--)
        printf("%d", binNum[j]);
}

int main()
{
    int n;
    scanf("%d",&n);
    dtob(n);
    return 0;
}