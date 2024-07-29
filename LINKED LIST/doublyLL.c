#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * rlink;
    struct node * llink;
}NODE;

typedef struct list
{
    NODE*head
}LIST;

void init(LIST*p)
{
    p->head == NULL;
}

NODE*createnode(int data)
{
    NODE*newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->llink = NULL;
    newnode->rlink = NULL;
    return newnode;
}

void insert_front(LIST*p,int data)
{
    NODE*newnode = createnode(data);
    if(p->head == NULL)
    {
        p->head = newnode;
    }
    else
    {
        newnode->rlink = p->head;
        p->head->llink = newnode;
        p->head = newnode;
    }
}

void insert_rear(LIST*p,int data)
{
    NODE*newnode = createnode(data);
    if(p->head==NULL)
    {
        p->head = newnode;
    }
    else
    {
        NODE*temp = p->head;
        while(temp->rlink!=NULL)
        {
            temp = temp->rlink;
        }
        temp->rlink = newnode;
        newnode->llink = temp;
    }
}

void delete_front(LIST*p)
{
    if(p->head==NULL)
    {
        printf("The list is already empty");
    }
    else if(p->head->rlink==NULL) //single node
    {
        NODE*temp = p->head;
        p->head = NULL;
        printf("The deleted element is %d",temp->data);
        free(temp);
    }
    else
    {
        NODE*temp = p->head;
        p->head = p->head->rlink;
        p->head->llink = NULL;
        printf("The deleted element is %d",temp->data);
        free(temp);
    }
    
}

void delete_rear(LIST*p)
{
    if(p->head==NULL)
    {
        printf("The list is already empty");
    }
    else if(p->head->rlink==NULL) //single node
    {
        NODE*temp = p->head;
        p->head = NULL;
        printf("The deleted element is %d",temp->data);
        free(temp);
    }
    else
    {
        NODE*temp = p->head;
        while(temp->rlink!=NULL)
        {
            temp = temp->rlink;
        }
        temp->llink->rlink = NULL;
        printf("The deleted element is %d",temp->data);
    }
}

void insert_at_pos(LIST*p,int data,int pos)
{
    NODE*newnode = createnode(data);
    int count = 1;
    if(pos==1)
    {
        insert_front(p,data);
    }
    else
    {
        NODE*temp = p->head;
        while(temp!=NULL && count !=pos)
        {
            temp = temp->rlink;
            count++;
        }
        if(temp==NULL)
        {
            insert_rear(p,data);
        }
        else
        {
            temp->llink->rlink = newnode;
            newnode->llink = temp->llink;
            newnode->rlink = temp;
            temp->llink = newnode;
        }
    }
}
