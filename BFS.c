
#include <stdio.h>
#include <stdlib.h>

void bfs(int m[10][10], int v, int source)
{
    int queue[20];
    int front = 0;
    int rear = 0;

    int u;
    int i;

    int visited[10];

    for (i= 0; i < v; i ++)
        visited[i] = 0;

    queue[rear] = source;
    visited[source] = 1;

    printf("The BFS Traversal is... \n");

    while (front <= rear)
    {
        u = queue[front];
        printf("%d\t", u);
        front = front + 1;

        for(i=0;i<v;i++)
        {
            if(m[u][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                rear = rear + 1;
                queue[rear] = i;
            }
        }
    }
}

int main()
{
    int v = 5;

    int m[10][10];
    
    for(int i =0;i<10;i++)
        for(int j=0;j<10;j++)
            scanf("%d",&m[i][j])

    int source = 4;

    bfs(m, v, source);

    return 0;
}