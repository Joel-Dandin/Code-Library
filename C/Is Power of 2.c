#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, ans;

    n = 8;
    ans = n & (n-1);
    printf("%d\n", !ans);

    n = 7;
    ans = n & (n-1);
    printf("%d\n", !ans);

}