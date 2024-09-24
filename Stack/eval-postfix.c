#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

void push(int stack[], int *top, int x);
int pop(int stack[], int *top);
int evaluate_postfix(char postfix[]);
int isOperator(char ch);

int main()
{
    char postfix[MAX];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    int result = evaluate_postfix(postfix);
    printf("The result is: %d\n", result);
    return 0;
}

void push(int stack[], int *top, int x)
{
    if (*top == MAX - 1)
    {
        printf("Stack Overflow...\n");
        return;
    }
    else
    {
        stack[++(*top)] = x;
    }
}

int pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow...\n");
        exit(1); // Exit the program on stack underflow
    }
    else
    {
        return stack[(*top)--];
    }
}

int evaluate_postfix(char postfix[])
{
    int stack[MAX];
    int top = -1;
    int i = 0;
    while (postfix[i] != 0)
    {
        if (isdigit(postfix[i]))
        {
            push(stack, &top, postfix[i] - '0');
        }
        else if (isOperator(postfix[i]))
        {
            int op2 = pop(stack, &top); // Note: op2 is popped first
            int op1 = pop(stack, &top);
            switch (postfix[i])
            {
            case '+':
                push(stack, &top, op1 + op2);
                break;
            case '-':
                push(stack, &top, op1 - op2);
                break;
            case '*':
                push(stack, &top, op1 * op2);
                break;
            case '/':
                push(stack, &top, op1 / op2);
                break;
            }
        }
        i++;
    }
    return pop(stack, &top);
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}