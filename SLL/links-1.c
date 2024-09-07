#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} NODE;

NODE *newnode, *list, *temp, *prev;

void insertFront(int x);
void insertEnd(int x);
void deleteFront();
void deleteEnd();
void position_insert(int x, int pos);
void display();

void main()
{
    int choice, x;
    list = NULL;
    while (1)
    {
        printf("1. Insert Front\n");
        printf("2. Insert End\n");
        printf("3. Delete Front\n");
        printf("4. Delete End\n");
        printf("5. position Insertion\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the information: ");
            scanf("%d", &x);
            insertFront(x);
            break;

        case 2:
            printf("Enter the information: ");
            scanf("%d", &x);
            insertEnd(x);
            break;

        case 3:
            deleteFront();
            break;

        case 4:
            deleteEnd();
            break;

        case 5:
            int pos;
            printf("Enter the information and position: ");
            scanf("%d %d", &x, &pos);
            position_insert(x, pos);
            break;

        case 6:
            display();
            break;

        case 7:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

void insertFront(int x)
{
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = x;
    newnode->next = NULL;
    if (list == NULL)
    {
        list = newnode;
    }
    else
    {
        newnode->next = list;
        list = newnode;
    }
}

void insertEnd(int x)
{
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = x;
    newnode->next = NULL;
    if (list == NULL)
    {
        list = newnode;
    }
    else
    {
        temp = list;
        while (temp->next == NULL)
        {
            temp->next = newnode;
        }
    }
}

void display()
{
    if (list == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = list;
        while (temp != NULL)
        {
            printf("%d\n", temp->info);
            temp = temp->next;
        }
    }
}

void deleteFront()
{
    if (list == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = list;
        list = list->next;
        free(temp);
    }
}

void deleteEnd()
{
    if (list == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = list;
        if (list->next == NULL)
        {
            free(temp);
            list = NULL;
            return;
        }
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}

void position_insert(int x, int pos)
{
    int i = 1;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = x;
    newnode->next = NULL;

    if (list == NULL)
    {
        list = newnode; // ignore position for first inseration - first node only
    }
    else
    {
        temp = list;
        if (pos == 1)
        {
            newnode->next = list;
            list = newnode;
        }
        else
        {
            while (temp->next != NULL && i < pos)
            {
                prev = temp;
                temp = temp->next;
                i++;
            }
            if (i == pos)
            {
                prev->next = newnode;
                newnode->next = temp;
            }
            else if (pos == i + 1)
            {
                temp->next = newnode;
            }
            else
            {
                printf("Invalid position\n");
            }
        }
    }
}

/*
Application of linked-lsists

*/