#include<stdio.h>
#define MAX 100

typedef struct stack
{
    int top;
    int arr[MAX];
}STK;

void init(STK*p)
{
    p->top = -1;
}

void push(STK*p,int data)
{
    if(p->top==MAX-1)
    {
        printf("The stack is empty");
    }

    else
    {
        (p->top)++;
        p->arr[p->top] = data;
    }
}

void pop(STK*p)
{
    if(p->top==-1)
    {
        printf("The stack is already empty");
    }

    else
    {
        printf("The popped element is %d",p->arr[p->top]);
        (p->top)--;
    }
}

void peep(STK*p)
{
    if(p->top==-1)
    {
        printf("The stack is already empty");
    }
    else
    {
        printf("The top element of the stack is %d",p->arr[p->top]);
    }
}

void display(STK*p)
{
    if(p->top==-1)
    {
        printf("The stack is already empty");
    }
    else
    {
        int i = p->top;
        while(i>-1)
        {
            printf(" %d",p->arr[i]);
            i--;
        }
    }
}


// void check_palindrome(STK *p) {
//     int x;
//     printf("Enter the length of the string that you want to check: ");
//     scanf("%d", &x);

//     printf("Enter the string: ");
//     for (int i = 0; i < x; i++) {
//         scanf(" %c", &p->arr[i]);
//         p->top++;
//     }

//     int i = 0;
//     int j = x - 1;
//     while (i < j && p->arr[i] == p->arr[j]) {
//         i++;
//         j--;
//     }

//     if (i >= j) {
//         printf("The string is a palindrome\n");
//     } else {
//         printf("Not a palindrome\n");
//     }
// }
