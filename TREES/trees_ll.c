#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int data;
    struct node *rlink;
    struct node *llink;
} TNODE;

TNODE *createnode(int data)
{
    TNODE *newnode = (TNODE *)malloc(sizeof(TNODE));
    newnode->data = data;
    newnode->llink = NULL;
    newnode->rlink = NULL;
    return newnode;
}

TNODE *insert(TNODE *root, int data)
{
    TNODE *newnode = createnode(data);
    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        if (data < root->data)
        {
            root->llink = insert(root->llink, data);
        }
        else if (data > root->data)
        {
            root->rlink = insert(root->rlink, data);
        }
    }
    return root;
}

void inorder(TNODE *root) //left root right
{
    if (root != NULL)
    {
        inorder(root->llink);
        printf("%d", root->data);
        inorder(root->rlink);
    }
}

void preorder(TNODE*root) //root left right
{
    if(root!=NULL)
    {
        printf("%d",root->data)
        preorder(root->llink);
        preorder(root->rlink);
    }
}

void postorder(TNODE*root) //right left root
{
    if(root!=NULL)
    {
        postorder(root->rlink);
        postorder(root->llink);
        printf("%d",root->data);
    }
}


TNODE *minvalue(TNODE *root)
{
    TNODE *temp = root;
    while (root->llink != NULL)
    {
        root = root->llink;
    }
    return root;
}

TNODE *delete(TNODE *root, int data)
{
    if (root == NULL)
    {
        printf("The tree is already empty :(");
        return;
    }
    else
    {
        if (data < root->data) //search the left subtree for the data
        {
            root->llink = delete (root->llink, data);
        }
        else if (data > root->data) //search the rigth subtree for the data
        {
            root->rlink = delete (root->rlink, data);
        }
        else // data found
        {
            // the data has only one child either left child or right child

            if (root->llink == NULL) // this means the node has a right child so assign the right child to a temp variable
            {
                TNODE *temp = root->rlink;
                free(root);
                return temp;
            }

            else if (root->rlink == NULL) // this means the node has a left child so assign the left child to a temp variable
            {
                TNODE *temp = root->llink;
                free(root);
                return temp;
            }

            else // it has 2 childs
            {
                TNODE *temp = minvalue(root->rlink);
                root->data = temp->data;
                root->rlink = delete (root->rlink, temp->data);
            }
        }
    }
    return root;
}


// #include<stdio.h>
// #include<stdlib.h>

// typedef struct treenode
// {
//     int data;
//     struct node*llink;
//     struct node*rlink;
// }TREE;

// TREE*createnode(int data)
// {
//     TREE*nn = (TREE*)malloc(sizeof(TREE));
//     nn->data = data;
//     nn->llink = NULL;
//     nn->rlink = NULL;
//     return nn;
// }

// TREE*insertnode(TREE*root,int data)
// {
//     NODE*nn = createnode(data);
//     TREE*temp = root;
//     if(root==NULL)
//     {
//         root = nn;
//     }
//     else
//     {
//         if(data<root->data)
//         {
//             root->llink = insertnode(root->llink,data);
//         }
//         else if(data>root->data)
//         {
//             root->rlink = insertnode(root->rlink,data);
//         }
//     }
//     return root;
// }

// void inorder(TREE*root)
// {
//     if(root!=NULL)
//     {
//         inorder(root->llink);
//         printf("%d",root->data);
//         inorder(root->rlink);
//     }
// }

// void preorder(TREE*root)
// {
//     if(root!=NULL)
//     {
//         printf("%d",root->data);
//         preorder(root->llink);
//         preorder(root->rlink);        
//     }
// }

// void postorder(TREE*root)
// {
//     if(root!=NULL)
//     {
//         postorder(root->llink);
//         postorder(root->rlink);
//         printf("%d",root->data);
//     }
// }

// TREE*minvalue(TREE*root)
// {
//     TREE*temp = TREE*root;
//     while(root->llink!=NULL)
//     {
//         root = root->llink;
//     }
//     return root;
// }

// TREE*delete(TREE*root,int data)
// {
//     if(root==NULL)
//     {
//         printf("The tree is already empty")
//     }

//     else
//     {
//         if(data<root->data)
//         {
//             root->llink = delete(root->llink,data);
//         }

//         else if(data>root->data)
//         {
//             root->rlink = delete(root->rlink,data);
//         }
//         else
//         {
//             if(root->llink==NULL)
//             {
//                 NODE*temp = root->rlink;
//                 free(root);
//                 return(temp);
//             }
            
//             else if(root->rlink==NULL)
//             {
//                 NODE*temp = root->llink;
//                 free(root);
//                 return(temp);
//             }

//             else
//             {
//                 NODE*temp = minvalue(root->rlink);
//                 root->data = temp->data;
//                 root->rlink = delete(root->rlink,temp->data);
//             }
//         }
//     }
//     return root;
// }