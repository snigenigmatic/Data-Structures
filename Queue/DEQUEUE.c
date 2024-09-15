// DEQueue => Doubly Ended queue
/*
@file : DEQUEUE.c
@brief : This file contains the implementation of DEQueue.

* A DEQueue is a queue in which insertion and deletion can be performed at both the ends.
* It is also known as a double-ended queue.
* It is a generalized form of a queue.
* It is a data structure that allows insertion and deletion of elements from both the front and the rear end.
* It is a linear data structure that follows the FIFO (First In First Out) principle.
* It is a dynamic data structure that can grow or shrink in size.
* It is a versatile data structure that can be used as a stack, queue, or a combination of both.
*/

// Implementation of a DEQueue using a doubly linked list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// NODE strututre
typedef struct dnode
{
    int data;
    struct dnode *prev;
    struct dnode *next;
} DNODE;

// DEQueue structure
typedef struct dequeue
{
    DNODE *front;
    DNODE *rear;
} DEQueue;

// function prototypes
DEQueue *createDEQueue();
bool isEmpty(DEQueue *dq);
void insertFront(DEQueue *dq, int data);
void insertRear(DEQueue *dq, int data);
int deleteFront(DEQueue *dq);
int deleteRear(DEQueue *dq);
void display(DEQueue *dq);

// function to create empty dequeue
DEQueue *createDEQueue()
{
    DEQueue *deq = (DEQueue *)malloc(sizeof(DEQueue));
    deq->front = deq->rear = NULL;
    return deq;
}

// functionto check if dequeue is empty
bool isEmpty(DEQueue *deq)
{
    return deq->front == NULL;
}

// function to insert element in front of the list
void insertFront(DEQueue *deq, int data)
{
    DNODE *newNode = (DNODE *)malloc(sizeof(DNODE));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = deq->front;
    if (isEmpty(deq))
    {
        deq->front = deq->rear = newNode;
    }
    else
    {
        deq->front->prev = newNode;
        deq->front = newNode;
    }
}

// function to insert element in the rear of the list
void insertRear(DEQueue *deq, int data)
{
    DNODE *newNode = (DNODE *)malloc(sizeof(DNODE));
    newNode->data = data;
    newNode->prev = deq->rear;
    newNode->next = NULL;
    if (isEmpty(deq))
    {
        deq->front = deq->rear = newNode;
    }
    else
    {
        deq->rear->next = newNode;
        deq->rear = newNode;
    }
}

// function to delete element from the front of the list
int deleteFront(DEQueue *deq)
{
    if (isEmpty(deq))
    {
        printf("DEQueue is empty\n");
        return -1;
    }
    DNODE *temp = deq->front;
    int data = temp->data;
    deq->front = deq->front->next;
    if (deq->front == NULL)
    {
        deq->rear = NULL;
    }
    else
    {
        deq->front->prev = NULL;
    }
    free(temp);
    return data;
}

// function to delete element from the rear of the list
int deleteRear(DEQueue *deq)
{
    if (isEmpty(deq))
    {
        printf("DEQueue is Empty...\n");
        return -1;
    }
    DNODE *temp = deq->rear;
    int data = temp->data;
    deq->rear = deq->rear->prev;
    if (deq->rear == NULL)
    {
        deq->front = NULL;
    }
    else
    {
        deq->rear->next = NULL;
    }
    free(temp);
    return data;
}

// function to display the elements of the DEQueue
void display(DEQueue *deq)
{
    if (isEmpty(deq))
    {
        printf("DEQueue is empty\n");
        return;
    }
    DNODE *temp = deq->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// menu driven main function
int main()
{
    DEQueue *deq = createDEQueue();
    int choice, data;
    while (1)
    {
        printf("1. Insert element at front\n");
        printf("2. Insert element at rear\n");
        printf("3. Delete element from front\n");
        printf("4. Delete element from rear\n");
        printf("5. Display elements\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to insert at front: ");
            scanf("%d", &data);
            insertFront(deq, data);
            break;
        case 2:
            printf("Enter element to insert at rear: ");
            scanf("%d", &data);
            insertRear(deq, data);
            break;
        case 3:
            data = deleteFront(deq);
            if (data != -1)
            {
                printf("Deleted element: %d\n", data);
            }
            break;
        case 4:
            data = deleteRear(deq);
            if (data != -1)
            {
                printf("Deleted element: %d\n", data);
            }
            break;
        case 5:
            display(deq);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}