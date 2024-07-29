#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Define a stack structure
struct Stack
{
    int top;
    char items[MAX_SIZE];
};

// Function to initialize the stack
void initialize(struct Stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

// Function to push an item onto the stack
void push(struct Stack *stack, char item)
{
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->items[stack->top--];
    }
    return '\0'; // Return null character for an empty stack
}

// Function to get the top item from the stack without popping it
char peek(struct Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->items[stack->top];
    }
    return '\0'; // Return null character for an empty stack
}

// Function to check if a character is an operator
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// Function to determine the precedence of an operator
int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/' || c == '%')
        return 2;
    return 0;
}

// // Function to convert infix expression to postfix expression
// void infixToPostfix(char* infix, char* postfix) {
//     struct Stack stack;
//     initialize(&stack);
//     int i = 0, j = 0;

//     while (infix[i] != '\0') {
//         char c = infix[i];

//         if (isalnum(c)) {
//             postfix[j++] = c;
//         } else if (c == '(') {
//             push(&stack, c);
//         } else if (c == ')') {
//             while (peek(&stack) != '(') {
//                 postfix[j++] = pop(&stack);
//             }
//             pop(&stack); // Pop the '('
//         } else if (isOperator(c)) {
//             while (!isEmpty(&stack) && precedence(c) <= precedence(peek(&stack))) {
//                 postfix[j++] = pop(&stack);
//             }
//             push(&stack, c);
//         }
//         i++;
//     }

//     while (!isEmpty(&stack)) {
//         postfix[j++] = pop(&stack);
//     }

//     postfix[j] = '\0';
// }

void infix_postfix(char *infix, char *postfix)
{
    struct Stack stack;
    initialize(&stack);
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        char c = infix[i];
        if (isalnum(c))
        {
            postfix[j++] = c; //if its a number update it to postfix
        }
        else if(c=='(')
        {
            push(&stack,c);
        }
        else if(c==')')
        {
            while(peek(&stack)!='(')
            {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        }
        else if(isOperator(c))
        {
            while(!isEmpty(&stack) && precedence(c)<=precedence(peek(&stack)))
            {
                postfix[j++] = pop(&stack);
            }
            push(&stack,c);
        }
        i++;
    }
    while(!isEmpty(&stack))
    {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[100];
    char postfix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
