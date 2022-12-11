#include <stdio.h>

int main()
{
    int n = 15;
    int no = 0;

    while(n)
    {
        no = no + 1;
        n = n & n-1;
    }

    printf("The number of set bits are %d\n", no);

    return 0;
}