#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    int link;
}NODE;

NODE*createnode(int data)
{
    NODE*newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->link = NULL;
    return newnode;
}

void insertfront(NODE**head,int data)
{
    NODE*newnode = createnode(data);
    if(*head==NULL)
    {
        *head = newnode;
    }
    else
    {
        newnode->link = *head;
        *head = newnode;
    }
}

void insertrear(NODE**head,int data)
{
    NODE*newnode = createnode(data);
    if(*head==NULL)
    {
        *head = newnode;
    }
    else
    {
        NODE*temp = *head;
        while(temp->link!=NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }
}

void deletefront(NODE**head)
{
    if(*head==NULL)
    {
        printf("The list is already empty");
    }
    else
    {
        NODE*temp = *head;
        *head = (*head)->link;
        printf("The deleted data is %d",temp->data);
        free(temp);
    }
}

void delete_end(NODE**head)
{
    if(*head==NULL)
    {
        printf("The list is already empty");
    }
    else
    {
        NODE*temp = *head;
        NODE*prev = NULL;
        while(temp->link!=NULL)
        {
            prev = temp;
            temp = temp->link;
        }
        prev->link=NULL;
        printf("The deleted data is : %d",temp->data);
        free(temp);
    }
}

void insert_at_pos(NODE**head,int data,int pos)
{
    NODE*newnode = createnode(data);
    NODE*prev = NULL;
    if(pos==1)
    {
        insertfront(*head,data);
    }
    else
    {
        NODE*temp = *head;
        int i = 1;
        while(temp->link!=NULL && i<pos)
        {
            prev = temp;
            temp = temp->link;
            i++;
        }
        if(pos==i)
        {
            newnode->link = temp;
            prev->link = newnode;
        }
        else if(++i==pos)
        {
            insertrear(*head,data);
        }
        else
        {
            printf("invalid position");
        }
    }
}

void delete_at_pos(NODE**head,int pos)
{
    int i =1;
    NODE*temp = *head;
    NODE*prev = NULL;
    if(*head==NULL)
    {
        printf("The list is already empty");
    }
    else
    {
        if(pos==1)
        {
            deletefront(*head);
        }
        else
        {
            while(temp->link!=NULL && i<pos)
            {
                prev = temp;
                temp = temp->link;
                i++;
            }
            if(pos==i)
            {
                prev->link = temp->link;
                printf("The deleted data is %d at position %d",temp->data,pos);
                free(temp);
            }
            else
            {
                printf("invalid position");
            }
        }
    }
}

void display(NODE**head)
{
    if(*head==NULL)
    {
        printf("The list is empty");
    }
    else
    {
        NODE*temp = *head;
        while(temp!=NULL)
        {
            printf(" %d",temp->data);
            temp = temp->link;
        }
    }
}
