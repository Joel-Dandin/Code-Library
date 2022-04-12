#include <stdio.h>

int fibo(int n)
{
    int fib[n+1];
    int i;
    fib[0] = 0;
    fib[1] = 1;

    for (i = 2; i < n + 1; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    return fib[n];
}


int main()
{
    int no;
    printf("Enter the nth element: ");
    scanf("%d", &no);

    printf("The %d number in fibonacci series is ", no);
    if (no == 0)
        printf("0")
    else
        printf("%d",fibo(no));
    

    return 0;
}