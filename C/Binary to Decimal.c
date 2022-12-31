#include <stdio.h>

void btod(int n)
{
    int dnum = 0;
    int last = 0;

    int base = 1;

    while(n)
    {
        last = n % 10;
        n = n/10;
        dnum += last*base;
        base = base*2;
    }

    printf("%d\n", dnum);
}

int main()
{
    int no = 101;
    btod(no);
    return 0;
}