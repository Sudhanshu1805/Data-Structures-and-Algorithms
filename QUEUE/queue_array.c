#include <stdio.h>
#define MAX 100

typedef struct queue
{
    int arr[MAX];
    int front;
    int rear;
} queue;

void init(queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isempty(queue *q)
{
    return (q->front == -1 && q->rear == -1);
}

int isfull(queue *q)
{
    return (q->front == 0 && q->rear == MAX - 1);
}

void enqueue(queue *q, int data)
{
    if (isfull(q))
    {
        printf("The queue is already full");
    }

    if (isempty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        (q->rear)++;
    }
    q->arr[q->rear] = data;
}

void dequeue(queue *q)
{
    if (isempty(q))
    { 
        printf("The queue is already empty");
    }
    else if (q->front == 0 && q->rear == 0)
    {
        int x = q->arr[q->front];
        printf("The dequeued element is %d", x);
        q->front = q->rear = -1;
    }
    else
    {
        int x = q->arr[q->front];
        printf("The dequeued element is %d", x);
        q->front++;
    }
}

void peek(queue *q)
{
    if (isempty(q))
    {
        printf("The queue is already empty");
    }
    else
    {
        int x = q->arr[q->front];
        printf("%d", x);
    }
}

void display(queue *q)
{
    if (isempty(q))
    {
        printf("The queue is already empty");
    }
    else
    {
        int temp = q->front;
        while(temp<=q->rear)
        {
            printf("%d",q->arr[temp]);
            temp++;
        }
    }
}