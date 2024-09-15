// paranthesis matching

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct
{
    char a[MAX];
    int top;
} STACK;

void init(STACK *s)
{
    s->top = -1;
}

int isEmpty(STACK *s)
{
    return s->top == -1;
}

int isFull(STACK *s)
{
    return s->top == MAX - 1;
}

void push(STACK *s, char x)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->a[++s->top] = x;
}

char pop(STACK *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->a[s->top--];
}

int isMatchingParenthesis(char *exp)
{
    STACK s;
    init(&s);
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(&s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(&s))
            {
                return 0; // Invalid expression
            }
            char temp = pop(&s);
            if ((temp == '(' && exp[i] != ')') || (temp == '[' && exp[i] != ']') || (temp == '{' && exp[i] != '}'))
            {
                return 0; // Invalid expression
            }
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(&s))
            {
                return 0; // Invalid expression
            }
            pop(&s);
        }
    }
    return isEmpty(&s); // Valid if stack is empty
}

int main()
{
    char exp[MAX];
    printf("Enter an expression: ");
    fgets(exp, MAX, stdin);
    if (isMatchingParenthesis(exp))
    {
        printf("Valid expression\n");
    }
    else
    {
        printf("Invalid expression\n");
    }
    return 0;
}

/*

*/