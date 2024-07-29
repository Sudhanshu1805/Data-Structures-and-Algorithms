#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Assuming a simple stack structure
typedef struct trienode
{
    struct trienode *child[255];
    int eos; // End of word
} trie;

struct stack
{
    struct trienode *m;
    int index;
};

// Assuming the trienode structure is modified to include endofword

// Function to create a new trienode
trie *createnode()
{
    trie *nn = (trie *)malloc(sizeof(trie));
    for (int i = 0; i < 255; i++)
    {
        nn->child[i] = NULL;
    }
    nn->eos = 0;
    return nn;
}

// Assuming a simple stack structure and necessary push/pop functions
struct stack stack[255];
int top = -1;

void push(trie *m, int index)
{
    top++;
    stack[top].m = m;
    stack[top].index = index;
}

struct stack pop()
{
    struct stack x;
    x = stack[top];
    top--;
    return x;
}

// Function to check if a node has children
int check(trie *m)
{
    int count = 0;
    for (int i = 0; i < 255; i++)
    {
        if (m->child[i] != NULL)
            count++;
    }
    return count;
}

// Function to delete a word from the trie
void delete_trie(trie *root, char *key)
{
    int i, index, k;
    trie *curr;
    struct stack x;
    curr = root;

    for (i = 0; key[i] != '\0'; i++)
    {
        index = key[i];
        if (curr->child[index] == NULL)
        {
            printf("The word not found..\n");
            return;
        }
        push(curr, index);
        curr = curr->child[index];
    }

    curr->eos = 0;
    push(curr, -1);

    while (1)
    {
        x = pop();
        if (x.index != -1)
            x.m->child[x.index] = NULL;

        if (x.m == root) // if root
            break;

        k = check(x.m);
        if ((k >= 1) || (x.m->eos == 1))
            break;
        else
            free(x.m);
    }
    return;
}
int search(struct trienode *root, char *key)
{
    int i, index;
    struct trienode *curr;
    curr = root;
    for (i = 0; key[i] != '\0'; i++)
    {
        index = key[i];
        if (curr->child[index] == NULL)
            return 0;
        curr = curr->child[index];
    }
    if (curr->eos == 1)
        return 1;
    return 0;
}
