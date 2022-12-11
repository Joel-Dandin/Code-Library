#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 4;
    int i, j, k;
    int D[10][10];

    for(i = 1; i <= n; i++){
        for(j = 1; j<= n; j++){
            scanf("%d",&D[i][j]);
        }
    }

     printf("The input are\n");
     for(i = 1; i <= n; i++){
        for(j = 1; j<= n; j++){
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }


    for(k = 1; k <= n; k++) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if((D[i][k] + D[k][j]) < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
            }
        }
    }

    printf("Shortest paths:\n");
    for(i = 1; i <= n; i++){
        for(j = 1; j<= n; j++){
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
    return 0;
}