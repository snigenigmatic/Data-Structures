#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} NODE;

NODE *insertFront(NODE *list, int x);
void insertEnd(NODE *list, int x);
void deleteFront(NODE **list);
void deleteEnd(NODE **list);
void position_insert(NODE **list, int x, int pos);
void position_delete(NODE **list, int pos);
void display(NODE *list);
NODE *orderedins(NODE *list, int x);

void main()
{
    int choice, x;
    NODE *list = NULL;
    while (1)
    {
        printf("1. Insert Front\n");
        printf("2. Insert End\n");
        printf("3. Delete Front\n");
        printf("4. Delete End\n");
        printf("5. Position Insertion\n");
        printf("6. Position Deletion\n");
        printf("7. Ordered Insertion\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the information: ");
            scanf("%d", &x);
            list = insertFront(list, x);
            break;

        case 2:
            printf("Enter the information: ");
            scanf("%d", &x);
            insertEnd(list, x);
            break;

        case 3:
            deleteFront(&list);
            break;

        case 4:
            deleteEnd(&list);
            break;

        case 5:
            int pos;
            printf("Enter the information and position: ");
            scanf("%d %d", &x, &pos);
            position_insert(&list, x, pos);
            break;

        case 6:
            printf("Enter the position: ");
            scanf("%d", &pos);
            position_delete(&list, pos);
            break;

        case 7:
            printf(("Enter the information: "));
            scanf("%d", &x);
            ordered_insert(&list, x);
            break;

        case 8:
            display(list);
            break;

        case 9:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

NODE *insertFront(NODE *list, int x)
{
    NODE *newnode;
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
    return list;
}

void insertEnd(NODE *list, int x)
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = x;
    newnode->next = NULL;
    if (list == NULL)
    {
        list = newnode;
    }
    else
    {
        NODE *temp = list;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void display(NODE *list)
{
    if (list == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        NODE *temp;
        temp = list;
        while (temp != NULL)
        {
            printf("%d\n", temp->info);
            temp = temp->next;
        }
    }
}

void deleteFront(NODE **list)
{
    if (*list == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        NODE *temp = *list;
        *list = (*list)->next;
        free(temp);
    }
}

void deleteEnd(NODE **list)
{
    if (*list == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        NODE *temp = *list;
        if ((*list)->next == NULL)
        {
            free(temp);
            *list = NULL;
            return;
        }
        NODE *prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}
void position_insert(NODE **list, int x, int pos)
{
    int i = 1;
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = x;
    newnode->next = NULL;

    if (*list == NULL)
    {
        *list = newnode; // ignore position for first insertion - first node only
    }
    else
    {
        NODE *temp = *list;
        if (pos == 1)
        {
            newnode->next = *list;
            *list = newnode;
        }
        else
        {
            NODE *prev = NULL;
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

void position_delete(NODE **list, int pos)
{
    int i = 1;
    if (*list == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        NODE *temp = *list;
        if (pos == 1)
        {
            *list = (*list)->next;
            free(temp);
        }
        else
        {
            NODE *prev = NULL;
            while (temp->next != NULL && i < pos)
            {
                prev = temp;
                temp = temp->next;
                i++;
            }
            if (i == pos)
            {
                prev->next = temp->next;
                free(temp);
            }
            else
            {
                printf("Invalid position\n");
            }
        }
    }
}

NODE *orderedins(NODE *list, int x)
{
    NODE *newnode, *temp, *prev;
    newnode = (struct node *)(malloc(sizeof(NODE)));
    newnode->info = x;
    newnode->next = NULL;
    if (list == NULL)
        list = newnode;
    else
    {
        temp = list;
        if (newnode->info < list->info)
        {
            newnode->next = list;
            list = newnode;
        }
        else
        {
            while (temp->next != NULL && temp->info < newnode->info)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp->info > newnode->info)
            {
                newnode->next = temp;
                prev->next = newnode;
            }
            else
                temp->next = newnode;
        }
    }
    return list;
}