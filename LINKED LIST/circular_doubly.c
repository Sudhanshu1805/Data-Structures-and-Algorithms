#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * rlink;
    struct node * llink;
}NODE;

NODE*createnode(int data)
{
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->llink = NULL;
    newnode->rlink = NULL;
    return newnode;
}

void insert_front(NODE**tail, int data)
{
    NODE* newnode = createnode(data);
    if(*tail==NULL)
    {
        *tail = newnode;
    }
    else
    {
        newnode->rlink = (*tail)->rlink;
        (*tail)->rlink->llink = newnode;
        (*tail)->rlink = newnode;
    }
}

void insert_rear(NODE**tail, int data)
{
    NODE* newnode = createnode(data);
    if(*tail==NULL)
    {
        *tail = newnode;
    }
    else
    {
        newnode->rlink = (*tail)->rlink;
        (*tail)->rlink = newnode;
        newnode->llink = *tail;
        *tail = newnode;
    }
}

void delete_front(NODE**tail)
{
    if(*tail == NULL)
    {
        printf("The list is already empty");
    }
    else if((*tail)->rlink == *tail)
    {
        NODE*temp = *tail;
        *tail = NULL;
        printf("The deleted element is %d",temp->data);
    }
    else
    {
        NODE*temp = (*tail)->rlink;
        (*tail)->rlink->rlink->llink = NULL;
        (*tail)->rlink = (*tail)->rlink->rlink;
        printf("The deleted element is %d",temp->data);
        free(temp);
    }
}

//aage ka khud karle na bhai kar lega tu 