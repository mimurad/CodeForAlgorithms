#include<stdio.h>
#define inf 9999999
#define V 9
int minDist(int dist[], int st[])
{
    int mn = inf, mn_ind, i;
    for(i=0;i<V;i++)
    {
        if(st[i] == 0 && dist[i] <= mn)
        {
            mn = dist[i];
            mn_ind = i;
        }
    }
    return mn_ind;
}
void dijkstra(int graph[V][V], int start)
{
    int dist[V], i;
    int st[V];
    for(i=0;i<V;i++)
    {
        dist[i] = inf;
        st[i] = 0;
    }
    dist[start] = 0;
    for(i=0;i<V-1;i++)
    {
        int u = minDist(dist, st);
        st[u] = 1;
        for(int v=0;v<V;v++)
        {
            if(st[v]==0 && graph[u][v] > 0
               && dist[u] != inf
               && dist[u] + graph[u][v]<dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    printf("Distance from source:\n");
    for(i=0;i<V;i++)
    {
        printf("%d \t %d\n", i, dist[i]);
    }
}
int main()
{
    int i, j;
    int graph[V][V];
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    /*for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }*/
    dijkstra(graph, 8);
    return 0;
}

/*
4
0 2 2 1
2 0 0 3
2 0 0 5
1 3 5 0

9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
*/
