#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int count = 0;

typedef struct pnode
{
    int info;
    int pty;
} PNODE;

void enqueue(PNODE queue[], int x, int pty)
{
    int j;

    PNODE t;
    t.info = x;
    t.pty = pty;
    if (count < MAX)
    {
        j = count - 1; // the index.
        while (j >= 0 && pty < queue[j].pty)
        {
            queue[j + 1] = queue[j]; // move lower priority further to end
            j--;
        }
        queue[++j] = t;
        count++;
    }
    else
    {
        printf("Queue is full...\n");
    }
}

void dequeue(PNODE queue[])
{
    PNODE t;
    if (count == 0)
        printf("Queue is empty :( \n it's lonely.....\n");
    else
    {
        t = queue[0];
        int j = count - 1;
        while (j >= 0)
        {
            queue[j] = queue[j - 1];
            j--;
        }
        count--;
        printf("Deleted element is %d with priority %d\n", t.info, t.pty);
    }
}

void display(PNODE queue[])
{
    int i;
    if (count == 0)
        printf("Queue is empty :( \n it's lonely.....\n");
    else
    {
        printf("Queue is:\n");
        for (i = 0; i < count; i++)
        {
            printf("%d with priority %d\n", queue[i].info, queue[i].pty);
        }
    }
}

int main()
{
    PNODE queue[MAX];
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
        {
            printf("enter element and its priority:");
            scanf("%d %d", &num, &pty);
            enqueue(queue, num, pty); // same as ordered ins here, enqueue just as its queue
            break;
        }
        case 2:
        {
            dequeue(queue);
            break;
        }
        case 3:
        {
            display(queue);
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