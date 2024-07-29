// #include<stdio.h>
// #include<stdlib.h>
// #define MAX 50

// typedef struct BinarySearchTree
// {
//     int arr[MAX];
//     int size;
// }BST;

// void init(BST*bst)
// {
//     bst->size = 0;
// }

// void insert(BST*bst,int data)
// {
//     if(bst->size >= MAX)
//     {
//         printf("The binary tree is full");
//     }
//     int i = 0;
//     while(bst->arr[i]!=0)
//     {
//         if(data<bst->arr[i])
//         {
//             i = 2*i + 1;
//         }
//         else
//         {
//             i = 2*i+2;
//         }
//         bst->arr[i] = data;
//         (bst->size)++;
//     }
// }

// int search(BST*bst, int data)
// {
//     int i = 0;
//     while(i<MAX && bst->arr[i]!=0)
//     {
//         if(bst->arr[i]==data)
//         {
//             printf("data found at index %d",i);
//         }
//         else if(data<bst->arr[i])
//         {
//             i = 2*i+1;
//         }
//         else
//         {
//             i = 2*i+2;
//         }
//     }
//     printf("Value not found bitch");
// }

// void inorder(BST*bst,int i)
// {
//     if(i<MAX && bst->arr[i]!=0)
//     {
//         inorder(bst,2*i+1);
//         printf("%d",bst->arr[i]);
//         inorder(bst,2*i+2); 
//     }
// }

#include<stdio.h>
#define MAX 50

typedef struct tree
{
    int arr[MAX];
    int size;
}tree;

void init(tree*p)
{
    p->size = 0;
}

void insert(tree*t,int data)
{
    if(t->size>=MAX)
    {
        printf("Cannot insert data as tree is already full");
    }
    int i = 0;
    while(t->arr[i]!=0)
    {
        if(data<t->arr[i])
        {
            i = 2*i+1;
        }
        
        else if(data>t->arr[i])
        {
            i = 2*i+2;
        }

        t->arr[i] = data;
        (t->size)++;
    }
}

void search(tree*t,int data)
{
    int i = 0;
    while(i<MAX && t->arr[i]!=0)
    {
        if(t->arr[i]==data)
        {
            printf("Data %d found at pos %d",data,i);
        }
        else if(data>t->arr[i])
        {
            i = 2*i+2;
        }
        else
        {
            i=2*i+1;
        }
    }
    printf("Value not found");
    return;
}