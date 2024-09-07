// circular queue implementation in C using arrays
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

void enqueue(int *queue, int *front, int *rear, int *count, int data);
int dequeue(int *queue, int *front, int *rear, int *count);
bool isEmpty(int count);
bool isFull(int count);
void display(int *queue, int front, int rear, int count);

int main()
{
    int queue[SIZE];
    int front = 0, rear = -1, count = 0;
    int choice, data;
    while (1)
    {
        printf("\n1. Enqueue\n");
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
            enqueue(queue, &front, &rear, &count, data);
            break;
        case 2:
            data = dequeue(queue, &front, &rear, &count);
            if (data != -1)
            {
                printf("Dequeued element: %d\n", data);
            }
            break;
        case 3:
            display(queue, front, rear, count);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

void enqueue(int *queue, int *front, int *rear, int *count, int data)
{
    if (isFull(*count))
    {
        printf("Queue is full\n");
        return;
    }
    *rear = (*rear + 1) % SIZE;
    queue[*rear] = data;
    (*count)++;
    printf("Enqueued %d\n", data);
}

int dequeue(int *queue, int *front, int *rear, int *count)
{
    if (isEmpty(*count))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue[*front];
    *front = (*front + 1) % SIZE;
    (*count)--;
    return data;
}

bool isEmpty(int count)
{
    return count == 0;
}

bool isFull(int count)
{
    return count == SIZE;
}

void display(int *queue, int front, int rear, int count)
{
    if (isEmpty(count))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < count; i++)
    {
        int index = (front + i) % SIZE;
        printf("%d ", queue[index]);
    }
    printf("\n");
}