#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

typedef struct node
{
    char c;
    struct node * llink;
    struct node * rlink;
}NODE;

NODE*getnode()
{
    NODE*newnode = (NODE*)malloc(sizeof(NODE));
    newnode->llink = NULL;
    newnode->rlink = NULL;
}

NODE*create_tree(char postfix[])
{
    NODE*temp;
    NODE*s[70];
    char symb;
    int top =-1;
    for(int i=0;postfix[i]!='\0';i++)
    {
        symb = postfix[i];
        temp = getnode();
        temp->c = symb;
        if(isalnum(symb))
        {
            s[++top] = temp; //if its a number the push it onto the stack
        }
        else
        {
            temp->rlink = s[top--];  //if it is a operand then make the top two elements of the stack as left and right child and pop from the stack
            temp->llink = s[top--];
            s[++top] = temp;
        }
    }
    return s[top--];
}

float evaluate(NODE*root)
{
	float num;
	switch(root->c)
	{
		case '+': return evaluate(root->llink) + evaluate(root->rlink);
		case '-': return evaluate(root->llink) - evaluate(root->rlink);
		case '*': return evaluate(root->llink) * evaluate(root->rlink);
		case '/': return evaluate(root->llink) / evaluate(root->rlink);
		case '^':
		case '$':return pow(evaluate(root->llink), evaluate(root->rlink));
		default: 
		if(isalpha(root->c))
		{
			printf("\n%c", root->c);
			scanf("%f", &num);
			return num;
		}
		else
			return root->c-'0';
	}
}