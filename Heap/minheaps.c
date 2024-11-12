/*
- Min heap is a complete binary tree in which the value in each internal node is smaller than or equal to the values in the children of that node.
- The value of each parent node is less than or equal to the value of its child nodes.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void heapify(int *, int);
void display(int *, int);
void mindel(int *, int *);
void adjust(int *, int);

int main()
{
    int heap[MAX], i, count;
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    count = 0;
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &heap[i]);
    }
    count = n;
    heapify(heap, count);
    display(heap, count);
    mindel(heap, &count);
    display(heap, count);
}

void heapify(int heap[], int count)
{
    int k, key, i, j;
    for (k = 1; k < count; k++)
    {
        i = k;
        key = heap[i];
        j = (i - 1) / 2;
        while (i > 0 && heap[j] > key)
        {
            heap[i] = heap[j];
            i = j;
            j = (i - 1) / 2;
        }
        heap[i] = key;
    }
}

void display(int heap[], int count)
{
    int i = 0;
    if (count == 0)
    {
        printf("Heap is empty\n");
        return;
    }
    printf("Heap is: ");
    for (i = 0; i < count; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

void adjust(int heap[], int count)
{
    int i, j, key;
    j = 0;
    i = 2 * j + 1;
    key = heap[j];
    while (i <= count - 1)
    {
        if (i + 1 <= count - 1) // if right child exists
        {
            if (heap[i] > heap[i + 1])
            {
                i++;
            }
        }
        if (key > heap[i])
        {
            heap[j] = heap[i];
            j = i;
            i = 2 * j + 1;
        }
        else
        {
            break;
        }
    }
    heap[j] = key;
}

void mindel(int heap[], int *count)
{
    int min = heap[0];
    heap[0] = heap[*count - 1];
    (*count)--;
    printf("Min element is: %d\n", min);
    adjust(heap, *count);
}