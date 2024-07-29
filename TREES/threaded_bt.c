// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node
// {
//     int data;
//     struct node *rlink;
//     struct node *llink;
//     int lthread;
//     int rthread;
// } NODE;

// NODE *createnode(int data)
// {
//     NODE *newnode = (NODE *)malloc(sizeof(NODE));
//     newnode->data = data;
//     return newnode;
// }

// NODE *insert(NODE *root, int data)
// {
//     NODE *temp = root;
//     NODE *parent = NULL;
//     NODE *newnode = createnode(data);
//     if (temp == NULL)
//     {
//         newnode->lthread = 1;
//         newnode->rthread = 1;
//         newnode->rlink = NULL;
//         newnode->llink = NULL;
//         root = newnode;
//         return root;
//     }
//     while (temp != NULL)
//     {
//         parent = temp;
//         if (data < temp->data)
//         {
//             if (temp->lthread == 0)
//             {
//                 temp = temp->llink;
//             }
//             else
//                 break;
//         }
//         else if (data > temp->data)
//         {
//             if (temp->rthread == 0)
//             {
//                 temp = temp->rlink;
//             }
//             else
//                 break;
//         }
//         else
//         {
//             printf("duplicate key");
//             return root;
//         }
//     }
//     if (data < parent->data)
//     {
//         newnode->lthread = 1;
//         newnode->rthread = 1;
//         newnode->data = data;
//         newnode->llink = parent->llink;
//         newnode->rlink = parent;
//         parent->llink = newnode;
//         parent->lthread = 0;
//     }
//     else
//     {
//         newnode->lthread = 1;
//         newnode->rthread = 1;
//         newnode->data = data;
//         newnode->llink = parent;
//         newnode->rlink = parent->rlink;
//         parent->rlink = newnode;
//         parent->rthread = 0;
//     }
//     return root;
// }

// NODE *inorderSuccessor(NODE *t)
// {
//     if (t->rthread == 1) // if it doesn't has a right child
//         return t->rlink; // inorder successor link is present in the right link

//     t = t->rlink;
//     while (t->lthread == 0)
//         t = t->llink;
//     return t;
// }
// void inorder(NODE *root)
// {
//     NODE *t = root;
//     if (root != NULL)
//     {
//         while (t->lthread == 0) // t->left!=NULL
//             t = t->llink;
//         while (t != NULL)
//         {
//             printf("%d ", t->data);
//             t = inorderSuccessor(t);
//         }
//     }
// }


#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    int lthread;
    int rthread;
    struct node * rlink;
    struct node *llink;
}NODE;

NODE*createnode(int data)
{
    NODE*nn = (NODE*)malloc(sizeof(NODE));
    nn->data = data;
    return nn;
}

void insert(NODE*root,int data)
{
    NODE*temp = root;
    NODE*parent = NULL;
    NODE*nn = createnode(data);
    if(temp==NULL)
    {
        nn->lthread = 1;
        nn->rthread = 1;
        nn->llink = NULL;
        nn->rlink = NULL;
        root = nn;
        return root;
    }
    while(temp!=NULL)
    {
        parent = temp;
        if(data<parent->data)
        {
            if(temp->lthread == 0)
            {
                temp = temp->llink;
            }
            else
            break;
        }
        if(data>parent->data)
        {
            if(temp->rthread==0)
            {
                temp = temp->rlink;
            }
            else
            break;
        }
        else
        {
            printf("Duplicate key");
            return root;
        }

        if(data<parent->data)
        {
            nn->lthread = 1;
            nn->rthread = 1;
            nn->data = data;
            nn->llink = parent->llink;
            nn->rlink = parent;
            parent->llink = nn;
            parent->lthread = 0;
        }

        else
        {
            nn->lthread = 1;
            nn->rthread = 1;
            nn->data = data;
            nn->llink = parent;
            nn->rlink = parent->rlink;
            parent->rlink = nn;
            parent->rthread = 0;
        }
        return root;
    }
}