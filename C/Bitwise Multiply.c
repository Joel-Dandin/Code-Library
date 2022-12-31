/*
this program multiplies hte numbers bitwise
eg: a = 9, b = 6
value = 54
*/
#include<stdio.h>

int process(int a,int b)
{
    int res = 0;
    while(b>0)
    {
        if(b&1)
            res = res + a;
        a = a << 1;
        b = b >> 1;
    }
    return res;
}

int main()
{
    int a,b;
    printf("Enter the number a - ");
    scanf("%d",&a);

    printf("Enter the number b - ");
    scanf("%d",&b);

    int value = process(a,b);
    printf("the value that we can get is %d",value);
}
