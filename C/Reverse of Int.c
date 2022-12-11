#include <stdio.h>
int main()
{
    int n, revnum = 0, temp = 0;

    printf("Enter an integer: ");
    scanf("%d", &n);

    while(n != 0)
    {
        temp = n % 10;
        revnum = revnum *10 + temp;
        n = n / 10;
    }

    printf("Reversed Number = %d", revnum);
    return 0;
}