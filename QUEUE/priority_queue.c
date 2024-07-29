#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    int priority;
    struct node  * link;
}NODE;

typedef struct Pqueue
{
    NODE*front
}pqueue;

pqueue*createqueue()
{
    pqueue*pq = (pqueue*)malloc(sizeof(pqueue));
    pq->front = NULL;
    return pq;
}

int isempty(pqueue*pq)
{
    return(pq->front==NULL);
}

NODE*createnode(int data,int priority)
{
    NODE*newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->link = NULL;
    newnode->priority = priority;
    return newnode;
}

void enqueue(pqueue*pq,int priority,int data)
{
    NODE*newnode = createnode(data,priority);
    if(isempty(pq))
    {
        pq->front = newnode;
    }

    else if((pq->front != NULL) && (priority<pq->front->priority))
    {
        newnode->link = pq->front;
        pq->front = newnode;
    }

    else
    {
        NODE*temp = pq->front;
        while((temp->link!=NULL) && priority>temp->priority)
        {
            temp = temp->link;
        }
        newnode->link = temp->link;
        temp->link = newnode;
    }
}

void dequeue(pqueue*pq,int priority)
{
    if(isempty(pq))
    {
        printf("The list is already empty");
    }
    else if(pq->front->link==NULL)
    {
        NODE*temp = pq->front;
        pq->front = NULL;
        printf("The dequeued data is : %d",temp->data);
        free(temp);
    }
    else
    {
        NODE*temp = pq->front;
        pq->front = pq->front->link;
        printf("The dequeued data is : %d",temp->data);
        free(temp);
    }
}