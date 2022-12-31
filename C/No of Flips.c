/*
this program tells no of bits to flip to make both same
a = 5,b = 4
a = 1001
b = 1000
no of bits to flip = 1
*/
#include<stdio.h>

int task(int a,int b)
{
    int n = a^b;
    int count=0;
    while(n>0)
    {
        count++;
        n&=(n-1);
    }
    return count;
}

int main()
{
    int a,b;
    printf("Enter the number a - ");
    scanf("%d",&a);

    printf("Enter the number b - ");
    scanf("%d",&b);

    int value = task(a,b);
    printf("the value that we can get is %d",value);
}
