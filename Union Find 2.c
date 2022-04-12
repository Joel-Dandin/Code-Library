#include<stdio.h>
#define n 10

int arr[n];

void initialize()
{
    int i;
    for(i = 0; i<n; i++)
        arr[i] = i;
}

int root(int i)
{
    while(arr[i] != i)
        i = arr[i];
    return i;
}

int Find(int a, int b)
{
    if(root(a) == root(b))
        return 1;
    else
        return 0;
}

int Union(int a ,int b)
{
    int root_a;
    int root_b;
    root_a = root(a);
    root_b = root(b);
    arr[ root_a ] = root_b ;
}

int main()
{
    initialize();
    Union(1,0);
    Union(0,2);
    Union(3,4);
    Union(1,4);

    int i;
    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    int status;
    status = Find(2,5);
    
    printf("\n%d", status);

    status = Find(1,4);
    
    printf("\n%d", status);

    return 0;
}