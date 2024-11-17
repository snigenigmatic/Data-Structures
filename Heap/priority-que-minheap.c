#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

// typedef for struct
typedef struct pnode
{
    int data;
    int priority;
} PNODE;

// Function prototypes
void PQins(PNODE pq[], int *count, int num, int pty);
int PQdel(PNODE pq[], int *count);
void display(PNODE pq[], int count);

int main()
{
    PNODE pq[MAX]; // Priority queue array
    int count = 0; // Number of elements in the queue
    int ch, num, pty;

    while (1)
    {
        printf("\n1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element and its priority: ");
            scanf("%d %d", &num, &pty);
            PQins(pq, &count, num, pty);
            break;
        case 2:
            if (count == 0)
            {
                printf("Queue is empty, cannot dequeue.\n");
            }
            else
            {
                int min = PQdel(pq, &count);
                printf("Deleted element is: %d\n", min);
            }
            break;
        case 3:
            display(pq, count);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void PQins(PNODE pq[], int *count, int num, int pty)
{
    if (*count >= MAX)
    {
        printf("Queue overflow! Cannot insert new element.\n");
        return;
    }

    PNODE temp;
    temp.data = num;
    temp.priority = pty;
    pq[*count] = temp; // Insert new element
    (*count)++;        // Increment count

    // Heapify up (adjust to maintain minheap property)
    int i = *count - 1;
    while (i > 0)
    {
        int j = (i - 1) / 2;// defining parent index
        if (pq[j].priority <= pq[i].priority)// if parent priority is less than child priority
        {
            break; // Heap property satisfied
        }
        // Swap
        PNODE tempNode = pq[j];
        pq[j] = pq[i];
        pq[i] = tempNode;
        i = j;
    }
}

void display(PNODE pq[], int count)
{
    if (count == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue is: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d(%d) ", pq[i].data, pq[i].priority);
    }
    printf("\n");
}

int PQdel(PNODE pq[], int *count)
{
    PNODE minNode = pq[0];  // Store the minimum node
    pq[0] = pq[--(*count)]; // Move last node to root

    // Heapify down
    int i = 0;
    while (true)
    {
        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;
        int smallestIndex = i;

        if (leftChildIndex < *count && pq[leftChildIndex].priority < pq[smallestIndex].priority)
        {
            smallestIndex = leftChildIndex;
        }

        if (rightChildIndex < *count && pq[rightChildIndex].priority < pq[smallestIndex].priority)
        {
            smallestIndex = rightChildIndex;
        }

        if (smallestIndex == i)
        {
            break; // Heap property satisfied
        }

        // Swap
        PNODE tempNode = pq[i];
        pq[i] = pq[smallestIndex];
        pq[smallestIndex] = tempNode;

        i = smallestIndex; // Move down to child index
    }

    return minNode.data; // Return deleted minimum element
}