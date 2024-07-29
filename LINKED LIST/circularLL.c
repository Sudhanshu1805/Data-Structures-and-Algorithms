#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} NODE;

typedef struct list
{
    NODE *tail;
} LIST;

void init(LIST *p)
{
    p->tail = NULL;
}

NODE *createnode(int data)
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->link = newnode;
    return newnode;
}

void insert_front(LIST *p, int data)
{
    NODE *newnode = createnode(data);
    if (p->tail == NULL)
    {
        p->tail = newnode;
        newnode->link = p->tail;
    }
    else
    {
        newnode->link = p->tail->link;
        p->tail->link = newnode;
    }
}

void insert_rear(LIST *p, int data)
{
    NODE *newnode = createnode(data);
    if (p->tail == NULL)
    {
        p->tail = newnode;
        newnode->link = p->tail;
    }
    else
    {
        newnode->link = p->tail->link;
        p->tail->link = newnode;
        p->tail = newnode;
    }
}

void delete_front(LIST *p)
{
    if (p->tail == NULL)
    {
        printf("The list is already empty");
    }
    else if (p->tail->link == p->tail)
    {
        NODE *temp = p->tail;
        p->tail = NULL;
        printf("The deleted element is %d", temp->data);
        free(temp);
    }
    else
    {
        NODE *temp = p->tail->link;
        p->tail->link = temp->link;
        printf("The deleted element is %d", temp->data);
        free(temp);
    }
}

void delete_rear(LIST *p)
{
    if (p->tail == NULL)
    {
        printf("The list is already empty");
    }
    else if (p->tail->link == p->tail)
    {
        NODE *temp = p->tail;
        p->tail = NULL;
        printf("The deleted element is %d", temp->data);
        free(temp);
    }
    else
    {
        NODE *temp = p->tail->link;
        NODE *prev = NULL;
        while (temp != p->tail)
        {
            prev = temp;
            temp = temp->link;
        }
        prev->link = p->tail->link;
        p->tail = prev;
        printf("The deleted element is %d", temp->data);
        free(temp);
    }
}
void display(LIST*p)
{
    if(p->tail == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        NODE*temp = p->tail->link;
        while(temp!=p->tail)
        {
            printf("%d ");
        }
    }
}