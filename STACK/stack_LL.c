#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} NODE;

typedef struct stack
{
    NODE *head;
} STK;

void init(STK *p)
{
    p->head = NULL;
}

NODE *createnode(int data)
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->link = NULL;
    return newnode;
}

void push(STK *p, int data)
{
    NODE *newnode = createnode(data);
    if (p->head == NULL)
    {
        p->head = newnode;
    }
    else
    {
        newnode->link = p->head;
        p->head = newnode;
    }
}

int pop(STK *p)
{
    if (p->head == NULL)
    {
        printf("The stack is already empty");
    }
    else
    {
        NODE *temp = p->head;
        p->head = p->head->link;
        return (temp->data);
        free(temp);
    }
}

int peep(STK *p)
{
    if (p->head == NULL)
    {
        printf("The stack is already empty");
    }
    else
    {
        int x = p->head->data;
        return x;
    }
}

void display(STK *p)
{
    if (p->head == NULL)
    {
        printf("The stack is empty");
    }
    else
    {
        NODE *temp = p->head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
    }
}
