#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} NODE;

typedef struct queue
{
    NODE *front;
    NODE *rear;
} queue;

NODE *createnode(int data)
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->link = NULL;
    return newnode;
}

queue *createqueue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

int isempty(queue *q)
{
    return (q->front == NULL);
}

void enqueue(queue *q, int data)
{
    NODE *newnode = createnode(data);
    if (isempty(q))
    {
        q->front = q->rear = newnode;
        newnode->link = newnode;
    }
    else
    {
        q->rear->link = newnode;
        newnode->link = q->front;
        q->rear = newnode;
    }
}

void dequeue(queue *q)
{
    if (isempty(q))
    {
        printf("the queue is already empty");
    }
    else if (q->front == q->rear)
    {
        NODE *temp = q->front;
        q->front = q->rear = NULL;
        printf("The dequeued element is %d", temp->data);
        free(temp);
    }
    else
    {
        NODE *temp = q->front;
        q->front = q->front->link;
        q->rear->link = q->front;
        printf("The dequeued element is %d", temp->data);
        free(temp);
    }
}

void display(queue *q)
{
    if (isEmpty(q))
        printf("the list is empty :(");
    else
    {
        NODE *temp = q->front;
        printf("%d ", q->front->data);
        temp = temp->link;
        while (temp != q->front)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
    }
    printf("\n"); // Add a newline character after printing all elements
}
