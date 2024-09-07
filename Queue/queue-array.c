// implementation of a queue using an array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

void enqueue(int *queue, int *front, int *rear, int data);
int dequeue(int *queue, int *front, int *rear);
bool isEmpty(int *front, int *rear);
bool isFull(int *rear);
void display(int *queue, int *front, int *rear);

int main()
{
    int queue[SIZE];
    int front = -1, rear = -1;
    int choice, data;
    while (1)
    {
        printf("1. Enqueue\n");
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
            enqueue(queue, &front, &rear, data);
            break;
        case 2:
            data = dequeue(queue, &front, &rear);
            if (data != -1)
            {
                printf("Dequeued element: %d\n", data);
            }
            break;
        case 3:
            display(queue, &front, &rear);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

void enqueue(int *queue, int *front, int *rear, int data)
{
    if (isFull(rear))
    {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(front, rear))
    {
        *front = *rear = 0;// increment both pointers to 0 for initial insertion operation
    }
    else
    {
        (*rear)++;
    }
    queue[*rear] = data;
}

int dequeue(int *queue, int *front, int *rear)
{
    if (isEmpty(front, rear))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue[*front];
    if (*front == *rear)
    {
        *front = *rear = -1;
    }
    else
    {
        (*front)++;
    }
    return data;
}

bool isEmpty(int *front, int *rear)
{
    return *front == -1 && *rear == -1;
}

bool isFull(int *rear)
{
    return *rear == SIZE - 1;
}

void display(int *queue, int *front, int *rear)
{
    if (isEmpty(front, rear))
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = *front; i <= *rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}