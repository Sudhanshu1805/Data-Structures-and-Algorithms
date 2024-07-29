#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef struct node
{
    int data;
    struct node * link;
}NODE;

typedef struct hash
{
    int count;
    struct node* head;
}hash;

void init(hash*h)
{
    for(int i=0;i<SIZE;i++)
    {
        h[i].count = 0;
        h[i].head = NULL;
    }
}

NODE*createnode(int key)
{
    NODE*nn = (NODE*)malloc(sizeof(NODE));
    nn->data = key;
    nn->link = NULL;
    return nn;
}

void insert(hash*h,int key)
{
    int hash = key%SIZE;
    NODE*nn = createnode(key);
    if(h[hash].head==NULL)
    {
        h[hash].head = nn;
        h[hash].count++;
    }
    else
    {
        NODE*temp = h[hash].head;
        while(temp->link!=NULL)
        {
            temp = temp->link;
        }
        temp->link=nn;
        h[hash].count++;
    }
}

void display(hash*h)
{
    NODE*temp;
    for(int i=0;i<SIZE;i++)
    {
        printf("\n[%d]%d => ",i,h[i].count);
        temp = h[i].head;
        while(temp!=NULL)
        {
            printf(" %d",temp->data);
            temp = temp->link;
        }
        printf("NULL");
    }
}

void search(hash*h,int key)
{
    int hash = key%SIZE;
    NODE*temp;
    int pos;
    for(temp = h[hash].head;temp!=NULL;temp = temp->link)
    {
        
        pos++;
        if(temp->data==key)
        {
            printf("The data %d is found at the hash value %d and index %d",key,hash,pos);
            return;
        }
    }
    printf("data not found");
}

