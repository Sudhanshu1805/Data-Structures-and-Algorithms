// #include<stdio.h>
// #define MAX 100
// #include<stdlib.h>

// typedef struct Pqueue
// {
//     int heap[MAX];
//     int size;
// }pqueue;

// void swap(int *a,int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void heapify_up(pqueue*pq,int i)
// {
//     int parent = (i-1)/2;
//     while(i>0 && pq->heap[i]>pq->heap[parent])
//     {
//         swap(&pq->heap[i],&pq->heap[parent]);
//         i = parent;
//         parent = (i-1)/2;
//     }
// }

// void heapify_down(pqueue*pq,int i)
// {
//     int left = 2*i+1;
//     int right = 2*i+2;
//     int largest = i;
//     if(left<pq->size && pq->heap[left]>pq->heap[largest])
//     {
//         largest = left;
//     }

//     if(right<pq->size && pq->heap[right]>pq->heap[largest])
//     {
//         largest = right;
//     }

//     if(largest!=i)
//     {
//         swap(&pq->heap[largest],&pq->heap[i]);
//         heapify_down(pq,largest);
//     }
// }

// void insert(pqueue*pq,int data)
// {
//     if(pq->size>=MAX)
//     {
//         printf("Heap is full");
//     }
//     pq->heap[pq->size] = data;
//     (pq->size)++;
//     heapify_up(pq,pq->size-1);
// }

// void delete(pqueue*pq)
// {
//     if(pq->size<=0)
//     {
//         printf("The queue is already empty");
//     }
//     int max = pq->heap[0];
//     pq->heap[0] = pq->heap[pq->size-1];
//     pq->size--;
//     heapify_down(pq,0);
//     return max;
// }


#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct queue
{
    int heap[MAX];
    int size;
}pqueue;

void swap(int*a,int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(pqueue*pq,int i)
{
    int parent = (i-1)/2;
    for(i=0;i>0 && pq->heap[i]>pq->heap[parent];i++)
    {
        swap(&pq->heap[i],&pq->heap[parent]);
        i = parent;
        parent = (i-1)/2;

    }
}

void heapify_down(pqueue*pq,int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<pq->size && pq->heap[left]>pq->heap[largest])
    {
        largest = left;
    }

    if(right<pq->size && pq->heap[right]>pq->heap[largest])
    {
        largest = right;
    }

    if(largest!=i)
    {
        swap(pq->heap[i],pq->heap[largest]);
        heapify_down(pq,largest);
    }
}

void insert(pqueue*pq,int value)
{
    if(pq->size>=MAX)
    {
        printf("heap is full");
        return;
    }
    pq->heap[pq->size] = value;
    (pq->size)++;
    heapify_up(pq,pq->size-1);
}

void delete(pqueue*pq)
{
    if(pq->size<=0)
    {
        printf("The heap is empty");
    }

    int max = pq->heap[0];
    pq->heap[0] = pq->heap[MAX-1];
    printf("The deleted element is %d",max);
    pq->size--;
    heapify_down(pq,0);

}