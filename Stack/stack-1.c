#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *top = NULL;

void push(int data);
void pop();
void peek();
void display();
void seek(int data);

int main()
{
    int choice, data;
    while (1)
    {
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Seek\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Enter data to seek: ");
            scanf("%d", &data);
            seek(data);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

void push(int data)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    NODE *temp = top;
    top = top->next;
    free(temp);
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("Top element is %d\n", top->data);
    }
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    NODE *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void seek(int data)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    NODE *temp = top;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }
}