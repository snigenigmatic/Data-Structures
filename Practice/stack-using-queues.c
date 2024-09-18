#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int queue1[MAX];
    int queue2[MAX];
    int front1, rear1;
    int front2, rear2;
} MyStack;

MyStack *myStackCreate()
{
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    stack->front1 = stack->rear1 = -1;
    stack->front2 = stack->rear2 = -1;
    return stack;
}

void myStackPush(MyStack *stack, int x)
{
    if (stack->front1 == -1)
    {
        stack->queue1[++stack->front1] = x;
        stack->rear1++;
    }
    else
    {
        while (stack->front1 <= stack->rear1)
        {
            stack->queue2[++stack->front2] = stack->queue1[stack->front1++];
        }
        stack->front1 = stack->rear1 = -1;
        stack->queue1[++stack->front1] = x;
        stack->rear1++;
        while (stack->front2 >= 0)
        {
            stack->queue1[++stack->rear1] = stack->queue2[stack->front2--];
        }
        stack->front2 = stack->rear2 = -1;
    }
}

int myStackPop(MyStack *stack)
{
    if (stack->front1 == -1)
    {
        return -1; // Stack is empty
    }
    int poppedValue = stack->queue1[stack->front1];
    for (int i = stack->front1; i < stack->rear1; i++)
    {
        stack->queue1[i] = stack->queue1[i + 1];
    }
    stack->rear1--;
    if (stack->rear1 == -1)
    {
        stack->front1 = -1;
    }
    return poppedValue;
}

int myStackTop(MyStack *stack)
{
    if (stack->front1 == -1)
    {
        return -1; // Stack is empty
    }
    return stack->queue1[stack->front1];
}

bool myStackEmpty(MyStack *stack)
{
    return stack->front1 == -1;
}

void myStackFree(MyStack *stack)
{
    free(stack);
}