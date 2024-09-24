// implementing conversion of infix expression to prefix expression with a stack implementation

/*
Algorithm
- reverse given infix string
- convert to postfix expression
- reverse the postfix expression

steps :
- create a precedence list for operators
- reverse the infix expression
- convert the infix expression to postfix expression
- reverse the postfix expression

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    char stack[MAX];
    int top;
} Stack;

Stack *push(Stack *, char);
char pop(Stack *);
char seek(Stack *);
Stack *convert_to_postfix(Stack *stack, char infix[], char postfix[]);
int input_presedence(char ch);
int stack_presedence(char ch);
char reverse(char infix[]);
void reverse_string(char infix[], int start, int end);

int main()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    char infix[MAX], postfix[MAX];
    printf("Enter your Infix Expressio: ");
    scanf("%[^\n]s", infix);
    reverse(infix);
    convert_to_postfix(stack, infix, postfix);
    char prefix[] = reverse(postfix);
    printf("The Prefix Expression is: %s\n", prefix);
    return 0;
}

Stack *push(Stack *stack, char ch)
{
    if (stack->top == MAX - 1)
    {
        printf("Stack Overflow...");
    }
    else
    {
        stack->stack[++stack->top] == ch;
    }
}

char pop(Stack *stack)
{
    if (stack == NULL || stack->top == -1)
    {
        printf("Stack Underflow...");
        return '\0';
    }
    else
    {
        return stack->stack[stack->top--];
    }
}

char seek(Stack *stack)
{
    if (stack == NULL || stack->top == -1)
    {
        return '\0';
    }
    else
    {
        return stack->stack[stack->top];
    }
}

Stack *convert_to_postfix(Stack *stack, char infix[], char postfix[])
{
    int i = 0, j = 0;
    char ch;
    push(stack, '#');
    while (infix[i] != '\0')
    {
        ch = infix[i];
        while (stack_presedence(seek(stack)) >= input_presedence(ch))
        {
            postfix[j++] = pop(stack);
        }
        if (stack_presedence(seek(stack)) != input_presedence(ch))
        {
            push(stack, ch);
        }
        else
        {
            pop(stack);
        }
        i++;
    }
    while (seek(stack) != '#')
    {
        postfix[j++] = pop(stack);
    }
    postfix[j] = '\0';
    return stack;
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
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int stack_presedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 4;
    default:
        return 0;
    }
}

char reverse(char infix[])
{
    int i = 0, j = 0;
    while (infix[j] != '\0')
    {
        j++;
    }
    reverse_string(infix, i, j - 1);
    return infix;
}

void reverse_string(char infix[], int start, int end)
{
    char temp;
    while (start < end)
    {
        temp = infix[start];
        infix[start] = infix[end];
        infix[end] = temp;
        start++;
        end--;
    }
}
