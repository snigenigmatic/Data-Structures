/*
- Title: Prirority Queue using Min Heap
- Dev : Kaustubh
- Purpose: To implement a priority queue using min heap
- Implementation:
    - The program takes the number of elements and the elements as input
    - The program then heapifies the elements
    - The program then displays the heap
    - The program then deletes the minimum element from the heap
    - The program then displays the heap
*/
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

PNODE pq[MAX];
int count = 0;

// function prototypes
void PQins(int, int);
int PQdel(PNODE[]);
void display();

int main()
{
    int ch, num, pty, min;

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
        {
            printf("enter element and its priority:");
            scanf("%d %d", &num, &pty);
            PQins(num, pty); // same as ordered ins here, enqueue just as its queue
            break;
        }
        case 2:
        {
            min = PQdel(pq);
            printf("Deleted element is: %d\n", min);
            break;
        }
        case 3:
        {
            display();
            break;
        }
        default:
        {
            exit(0);
            break;
        }
        }
    }
    return 0;
}

void PQins(int num, int pty)
{
    int i, j;
    PNODE temp, key;
    temp.data = num;
    temp.priority = pty;
    count++;
    pq[count - 1] = temp;
    i = count - 1;
    j = (i - 1) / 2;
    key = pq[i];
    while (i > 0 && pq[j].priority > key.priority)
    {
        pq[i] = pq[j];
        i = j;
        j = (i - 1) / 2;
    }
    pq[i] = key;
}

void display()
{
    int i;
    if (count == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is: ");
    for (i = 0; i < count; i++)
    {
        printf("%d(%d) ", pq[i].data, pq[i].priority);
    }
    printf("\n");
}

int PQdel(PNODE pq[])
{
    int i, j;
    PNODE key, min;
    min = pq[0];
    key = pq[count - 1];
    count--;
    i = 0;
    j = 2 * i + 1;
    while (j <= count - 1)
    {
        if (j + 1 <= count - 1)
        {
            if (pq[j].priority > pq[j + 1].priority)
            {
                j++;
            }
        }
        if (key.priority > pq[j].priority)
        {
            pq[i] = pq[j];
            i = j;
            j = 2 * i + 1;
        }
        else
        {
            break;
        }
    }
    pq[i] = key;
    return min.data;
}