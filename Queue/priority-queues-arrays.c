// Implementataion of priority queues using arrays

/*
* @file priority-queues-arrays.c
* @brief Implementation of priority queues using arrays

* This program implements a priority queue using arrays.
* It can perform the following operations:
* 1. Enqueue
* 2. Dequeue
* 3. Display
* 4. Exit
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct node
{
    int data;
    int priority;
} NODE;

typedef struct priority_queue
{
    NODE nodes[MAX];
    int size;
} PRIORITY_QUEUE;

PRIORITY_QUEUE pq = {.size = 0};

void enqueue(int data, int priority);
int dequeue();
bool isEmpty();
void display();

int main()
{
    int choice, data, priority;
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

void enqueue(int data, int priority)
{
    if (pq.size == MAX)
    {
        printf("Queue is full\n");
        return;
    }
    NODE newNode = {.data = data, .priority = priority};
    int i = pq.size - 1;
    while (i >= 0 && pq.nodes[i].priority > priority)
    {
        pq.nodes[i + 1] = pq.nodes[i];
        i--;
    }
    pq.nodes[i + 1] = newNode;
    pq.size++;
    printf("Enqueued %d\n", data);
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    int data = pq.nodes[0].data;
    for (int i = 0; i < pq.size - 1; i++)
    {
        pq.nodes[i] = pq.nodes[i + 1];
    }
    pq.size--;
    return data;
}

bool isEmpty()
{
    return pq.size == 0;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i < pq.size; i++)
    {
        printf("%d ", pq.nodes[i].data);
    }
    printf("\n");
}
// Time Complexity: O(n)
// Space Complexity: O(n)
