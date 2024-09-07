// infix to postfix converter using stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void convert_to_postfix(char infix[], char postfix[]);
int input_presedence(char ch);
int stack_presedence(char ch);
void push(char stack[], int *top, char ch);
char pop(char stack[], int *top);
char seek(char stack[], int *top);

int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    convert_to_postfix(infix, postfix);
    printf("The postfix expression is: %s\n", postfix);
    return 0;
}

int input_presedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    default:
        return 7;
    }
}

int stack_presedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '^':
        return 5;
    case '(':
        return 0;
    case '#':
        return -1;
    default:
        return 8;
    }
}

void push(char stack[], int *top, char ch)
{
    if (*top < MAX - 1)
    {
        stack[++(*top)] = ch;
    }
    else
    {
        printf("Stack overflow\n");
    }
}

char pop(char stack[], int *top)
{
    if (*top >= 0)
    {
        return stack[(*top)--];
    }
    else
    {
        printf("Stack underflow\n");
        return '\0';
    }
}

char seek(char stack[], int *top)
{
    if (*top >= 0)
    {
        return stack[*top];
    }
    else
    {
        return '\0';
    }
}

void convert_to_postfix(char infix[], char postfix[])
{
    char stack[MAX];
    int top = -1;
    int i = 0, j = 0;
    char ch;

    push(stack, &top, '#');

    while (infix[i] != '\0')
    {
        ch = infix[i];
        while (stack_presedence(seek(stack, &top)) >= input_presedence(ch))
        {
            postfix[j++] = pop(stack, &top);
        }
        if (stack_presedence(seek(stack, &top)) != input_presedence(ch))
        {
            push(stack, &top, ch);
        }
        else
        {
            pop(stack, &top);
        }
        i++;
    }

    while (seek(stack, &top) != '#')
    {
        postfix[j++] = pop(stack, &top);
    }

    postfix[j] = '\0';
}