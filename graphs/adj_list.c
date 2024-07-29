#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct node
{
    int data;
    struct node *link;
} NODE;

int n, ch, v, i;
NODE *a[MAX];
int visit[MAX];

void insert(NODE *a[], int i, int j)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = j;
    temp->link = NULL;
    NODE *curr = a[i];
    if (curr == NULL)
    {
        a[i] = temp;
        return;
    }
    while (curr->link != NULL)
    {
        curr = curr->link;
    }
    curr->link = temp;
}

void create_graph(NODE *a[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        a[i] = NULL;
    }
    while (1)
    {
        printf("enter the source and the destination of the edge");
        scanf("%d%d", &i, &j);
        if (i < 0 || j < 0 || j > n || i > n)
        {
            break;
        }
        else
        {
            insert(a, i, j);
        }
    }
}

void display(NODE *a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        NODE *curr = a[i];
        while (curr->link != NULL)
        {
            printf(" %d", curr->data);
            curr = curr->link;
        }
        printf("\n");
    }
}

int indegree(NODE *a[], int n, int v)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        NODE *curr = a[i];
        while (curr != NULL)
        {
            if (curr->data = v)
                ++count;
            curr = curr->link;
        }
    }
    return count;
}

int outdegree(NODE *a[], int v)
{
    int count = 0;
    NODE *curr = a[v];
    while (curr != NULL)
    {
        ++count;
        curr = curr->link;
    }
    return count;
}

NODE *insertatrear(int v, NODE *q)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = v;
    temp->link = NULL;
    if (q == NULL)
    {
        q = temp;
        return (q);
    }
    NODE *cur = q;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return (q);
}

NODE *deleteatfront(NODE *q)
{
    if (q->link == NULL)
    {
        free(q);
        return (NULL);
    }
    NODE *first = q;
    NODE *second = first->link;
    free(first);
    return (second);
}

void bfs(int v)
{

    NODE *q = NULL, *list;
    visit[v] = 1;
    int u;
    q = insertatrear(v, q);
    printf("%d is visited", v);
    while (q != NULL)
    {
        u = q->data;
        q = deleteatfront(q);
        list = a[u];
        while (list != NULL)
        {
            v = list->data;
            if (visit[v] == 0)
            {
                printf("%d\t", v);
                visit[v] = 1;
                q = insertatrear(v, q);
            }
            list = list->link;
        }
    }
}
void dfs(int v)
{
    NODE *temp;
    visit[v] = 1;
    printf("%d is visited\n", v);
    temp = a[v];
    while (temp != NULL)
    {
        if (visit[temp->data] == 0)
            dfs(temp->data);
        temp = temp->link;
    }
}
