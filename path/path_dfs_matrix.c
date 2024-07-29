#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int a[SIZE][SIZE];
int n, p = 0;

void read_adj_mat()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void print_all(int u, int d, int visited[SIZE], int path[SIZE])
{
    visited[u] = 1;
    path[p] = u;
    p++;
    if (u == d)
    {
        for (int i = 0; i < p; i++)
        {
            printf("%d ", path[i]);
        }
        printf("\n");
    }
    else
    {
        for (int v = 0; v < n; v++)
        {
            if (a[u][v] == 1 && visited[v] == 0)
            {
                print_all(v, d, visited, path);
            }
        }
    }
    p--;
    visited[u] = 0;
}

void printpath(int s, int d)
{
    int visited[SIZE];
    int path[SIZE];
    int p = 0;
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    print_all(s, d, visited, path);
}
