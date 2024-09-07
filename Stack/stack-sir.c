#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void push(int stack[], int *top, int x, int n);
void display(int stack[], int *top);
void pop(int stack[], int *top);

int main()
{
    int ch, x, n;
    int top = -1;
    int stack[MAX_SIZE];

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE)
    {
        printf("Error: Number of elements cannot exceed %d\n", MAX_SIZE);
        return 1;
    }

    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Peep\n5. Seek\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &x);
            push(stack, &top, x, n);
            break;
        case 2:
            pop(stack, &top);
            break;
        case 3:
            printf("The elements in stack are:\n");
            display(stack, &top);
            break;
        /*case 4:
            printf("Peep functionality not implemented yet.\n");
            break;
        case 5:
            printf("Seek functionality not implemented yet.\n");
            break;*/
        case 6:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void push(int stack[], int *top, int x, int n)
{
    if (*top >= n - 1)
    {
        printf("Stack overflow. Cannot push %d\n", x);
    }
    else
    {
        (*top)++;
        stack[*top] = x;
        printf("%d pushed to stack.\n", x);
    }
}

void display(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        for (int i = *top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack underflow. Cannot pop.\n");
    }
    else
    {
        printf("%d popped from stack.\n", stack[*top]);
        (*top)--;
    }
}