#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_number_of_ways(int score)
{
    int i;
    int result[score+1];

    memset(result, 0, sizeof(int) * (score+1));

    result[0] = 1;

    for(i = 3; i <= score; i++)
        result[i] = result[i] + result[i-3];

    for(i = 5; i <= score; i++)
        result[i] = result[i] + result[i-5];

    for(i = 10; i <= score; i++)
        result[i] = result[i] + result[i-10];

    return result[score];
}

int main()
{
    int score = 15;
    int result = count_number_of_ways(score);
    printf("The number of ways are:\n");
    printf("%d\n", result);

    return 0;
}