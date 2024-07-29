#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int value) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = value;
    } else {
        printf("Stack overflow!\n");
        exit(1);
    }
}

int pop(Stack *s) {
    if (s->top >= 0) {
        return s->data[(s->top)--];
    } else {
        printf("Stack underflow!\n");
        exit(1);
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int evaluatePostfix(char postfix[]) {
    Stack stack;
    initialize(&stack);
    int i;

    for (i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0'); // Convert character to integer
        } else if (isOperator(postfix[i])) {
            if (stack.top >= 1) {
                int operand2 = pop(&stack);
                int operand1 = pop(&stack);
                int result;

                switch (postfix[i]) {
                    case '+':
                        result = operand1 + operand2;
                        break;
                    case '-':
                        result = operand1 - operand2;
                        break;
                    case '*':
                        result = operand1 * operand2;
                        break;
                    case '/':
                        if (operand2 != 0) {
                            result = operand1 / operand2;
                        } else {
                            printf("Error: Division by zero!\n");
                            exit(1);
                        }
                        break;
                }

                push(&stack, result);
            } else {
                printf("Error: Invalid postfix expression!\n");
                exit(1);
            }
        } else {
            printf("Error: Invalid character in postfix expression!\n");
            exit(1);
        }
    }

    if (stack.top == 0) {
        return pop(&stack);
    } else {
        printf("Error: Invalid postfix expression!\n");
        exit(1);
    }
}

int main() {
    char postfixExpression[MAX_SIZE];
    int result;

    printf("Enter a postfix expression: ");
    scanf("%s", postfixExpression);

    result = evaluatePostfix(postfixExpression);
    printf("Result of postfix expression %s is %d\n", postfixExpression, result);

    return 0;
}
