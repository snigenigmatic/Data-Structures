// priority queue implementation in C using linked list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    int priority;
    struct node *next;
} NODE;

NODE *front = NULL;

NODE *createNode(int x, int pty);
void enqueue(int data, int priority);
int dequeue();
bool isEmpty();
void display();

int main()
{
    int choice, data, priority;
    while (1)
    {
        printf("\n1. Enqueue\n")
        ;
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Data to Enqueue: ");
            scanf("%d", &data);
            printf("Enter Priority: ");
            scanf("%d", &priority);
            enqueue(data, priority);
            break;
        case 2:
            data = dequeue();
            if (data != -1)
            {
                printf("Dequeued element: %d\n", data);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

NODE *createNode(int x, int pty)
{
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = x;
    newNode->priority = pty;
    newNode->next = NULL;
    return newNode;
}


void enqueue(int data, int priority)
{
    NODE *newNode = createNode(data, priority);
    if (front == NULL || priority < front->priority)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        NODE *temp = front;
        while (temp->next != NULL && temp->next->priority <= priority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Enqueued %d\n", data);
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    NODE *temp = front;
    int data = temp->data;
    front = front->next;
    free(temp);
    return data;
}

bool isEmpty()
{
    return front == NULL;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    NODE *temp = front;
    printf("Queue: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}