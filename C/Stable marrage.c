#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Preference
{
    int menPref;
    int womenPref;
    int selected;
};


long long int matrix[MAX][MAX];

void getData(int noPeople)
{
    printf("Enter Preference of Men and Women in order speprated by comma(pp,pp)");
    for(int i = 0;i<noPeople;i++)
    {
        for(int j = 0;j<noPeople;j++)
        {
            struct Preference *temp= malloc(sizeof *temp);
            scanf("%d,%d",&temp->menPref,&temp->womenPref);
            matrix[i][j] = &temp;
        }
    }

    for(int i = 0;i<noPeople;i++)
        matrix[i][noPeople] = -1;

    for(int j = 0;j<noPeople;j++)
        matrix[noPeople][j] = -1;
}

void PrintData(int noPeople)
{
    printf("Data\n");
    for(int i = 0;i<noPeople;i++)
    {
        for(int j = 0;j<noPeople;j++)
        {
            struct Preference *temp= malloc(sizeof *temp);
            &temp = matrix[i][j];
            printf("%d,%d\t",temp->menPref,temp->womenPref);

        }
        printf("%d\n",matrix[i][noPeople]);
    }

    for(int j = 0;j<noPeople;j++)
        printf("%d\t",matrix[noPeople][j]);
}

int main()
{
    getData(2);
    PrintData(2);
}
