
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    long int i,j;
    int n = 100;
    int *primes;

    primes = (int *)malloc(sizeof(int) * n);
    memset(primes, 1, n*sizeof(int));

    for (i = 2;i < n; i++){
        if (primes[i]) {
            for (j = i; i * j < n; j++)
                primes[i * j] = 0;
        }
    }

    printf("\nPrime numbers in range 1 to %d are: \n", n);
    for (i = 2;i < n; i++){
        if (primes[i])
            printf("%ld ", i);
    }

return 0;
}