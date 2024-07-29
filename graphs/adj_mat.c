#include<stdio.h>
#define MAX 100

typedef struct graph
{
    int n;
    int adj[MAX][MAX];
    int visited[MAX];
}graph;

void create_graph(graph*adj_mat)
{
    int i,j;
    for(int i=0;i<adj_mat->n;++i)
    {
        for(int j=0;j<adj_mat->n;++j)
        {
            adj_mat->adj[i][j] = 0;
        }
    }

    //what this above code does is initializes the enitre matrix with 0 so that when we want to enter a element at 

    while(1)
    {
        printf("Enter the source and the destination");
        scanf("%d %d",&i,&j);
        if(i<0 || j<0 || i>=adj_mat->n || j>=adj_mat->n)
        {
            break;
        }
        adj_mat->adj[i][j] = 1;
    }
}

int indegree(graph*adj_mat,int v)
{
    int count =0;
    for(int i=0;i<adj_mat->n;++i)
    {
        if(adj_mat->adj[i][v]==1)
        {
            ++count;
        }
    }
    return count;
}

int outdegree(graph*adj_mat,int v)
{
    int count =0;
    for(int i=0;i<adj_mat->n;++i)
    {
        if(adj_mat->adj[v][i]==1)
        {
            ++count;
        }
    }
    return count;
}

void dfs(graph*g,int start)
{
    printf("%d",start);
    g->visited[start]=1;
    for(int i=0;i<=g->n;i++)
    {
        if(g->adj[start][i]==1 && g->visited[i]==0)
            dfs(g,i);
    }
}