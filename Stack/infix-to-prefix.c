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
#include <string.h>

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
int input_precedence(char ch);
int stack_precedence(char ch);
char *reverse(char infix[]);
void reverse_string(char infix[], int start, int end);
int is_operand(char ch);

int main()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    char infix[MAX], postfix[MAX];
    printf("Enter your Infix Expression: ");
    scanf("%[^\n]s", infix);
    reverse(infix);
    convert_to_postfix(stack, infix, postfix);
    reverse(postfix);
    printf("The Prefix Expression is: %s\n", postfix);
    return 0;
}

Stack *push(Stack *stack, char ch)
{
    if (stack->top == MAX - 1)
    {
        printf("Stack Overflow...\n");
    }
    else
    {
        stack->stack[++stack->top] = ch;
    }
    return stack;
}

char pop(Stack *stack)
{
    if (stack == NULL || stack->top == -1)
    {
        printf("Stack Underflow...\n");
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
    push(stack, '#'); // Push a sentinel value to mark the bottom of the stack

    while (infix[i] != '\0')
    {
        ch = infix[i];
        if (is_operand(ch))
        {
            postfix[j++] = ch; // If it's an operand, add it directly to the postfix expression
        }
        else if (ch == ')') // Handle closing parentheses when reversing
        {
            push(stack, ch);
        }
        else if (ch == '(') // Handle opening parentheses
        {
            while (seek(stack) != ')' && seek(stack) != '#')
            {
                postfix[j++] = pop(stack);
            }
            pop(stack); // Remove the closing parenthesis from the stack
        }
        else
        {
            while (stack_precedence(seek(stack)) >= input_precedence(ch))
            {
                postfix[j++] = pop(stack);
            }
            push(stack, ch); // Push the current operator to the stack
        }
        i++;
    }

    while (seek(stack) != '#')
    {
        postfix[j++] = pop(stack); // Pop all remaining operators from the stack
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
    return stack;
}

int input_precedence(char ch)
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
    case ')':
        return 0; // Lowest precedence for closing parenthesis
    default:
        return 0;
    }
}

int stack_precedence(char ch)
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
        return 4; // Higher precedence for stack as '^' is right associative
    case ')':
        return 0; // Lowest precedence for closing parenthesis
    default:
        return 0;
    }
}

int is_operand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

char *reverse(char infix[])
{
    int i = 0, j = 0;
    while (infix[j] != '\0')
    {
        j++;
    }
    reverse_string(infix, i, j - 1);
    // After reversing, switch '(' with ')' and vice versa
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
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
