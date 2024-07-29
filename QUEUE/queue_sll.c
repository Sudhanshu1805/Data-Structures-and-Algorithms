#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * link;
}NODE;

typedef struct queue
{
    NODE*front;
    NODE*rear;
}queue;

int isempty(queue*q)
{
    return(q->front==NULL);
}

NODE*createnode(int data)
{
    NODE*newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->link = NULL;
    return newnode;
}

queue*createqueue()
{
    queue*q = (queue*)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(queue*q,int data)
{
    NODE*newnode = createnode(data);
    if(isempty(q))
    {
        q->front = q->rear = newnode;
    }
    else
    {
        q->rear->link = newnode;
        q->rear = newnode;
    }
}

void dequeue(queue*q)
{
    if(isempty(q))
    {
        printf("The queue is already empty");
    }
    else if(q->front==q->rear)
    {
        NODE*temp = q->front;
        q->front=q->rear=NULL;
        printf("The dequeued element is %d",temp->data);
    }
    
    else
    {
        NODE*temp = q->front;
        q->front = q->front->link;
        printf("The dequeued element is %d",temp->data);
        free(temp);
    }
}

void display(queue*q)
{
    if(isempty(q))
    {
        printf("The queue is empty");
    }
    else
    {
        NODE*temp = q->front;
        while(temp!=NULL)
        {
            printf(" %d",temp->data);
            temp = temp->link;
        }
    }
}

