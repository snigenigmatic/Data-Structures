/*
Closed Chain Hashing - Open Hashing
- In closed chain hashing, each bucket is independent, and has some sort of list of entries with the same index.
- The time complexity of closed chain hashing is O(1) for search, insert and delete operations.
- The space complexity of closed chain hashing is O(n) where n is the number of elements to be stored.
- The main advantage of closed chain hashing is that it is simple to implement.
- The main disadvantage of closed chain hashing is that it requires extra space to store the linked lists.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

// Node structure
typedef struct element
{
    int rNo;
    char name[20];
    struct element *next;
} NODE;

// initializing the hash table
void init_table(NODE *table[MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        table[i] = NULL;
    }
}

NODE *create_node(int rN0, char *name)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->rNo = rN0;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// insert an element into the hash table
void insert(NODE *table[MAX], int rNo, char *name)
{
    int index = rNo % MAX;

    NODE *newNode = create_node(rNo, name);
    if (table[index] == NULL)
    {
        table[index] = newNode;
    }
    else
    {
        NODE *temp = table[index];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return;
}

// deleting an elememt from the hash table

int delete_element(NODE *table[MAX], int rNo)
{
    int index = rNo % MAX;

    // creating two nodes p and q
    //  p will hold the current node
    //  q will have the previous node
    NODE *p, *q;

    p = table[index];
    q = NULL;

    while (p != NULL && p->rNo != rNo)
    {
        q = p;
        p = p->next;
    }

    if (p != NULL)
    {
        if (q == NULL)
        {
            table[index] = p->next;
        }
        else
        {
            q->next = p->next;
        }
        free(p);
        return 1;
    }
    return 0;
}

// searching for am element in the hash table - table lookup - most important operation

int search(NODE *table[MAX], int rNo, char *name)
{
    int index = rNo % MAX;

    NODE *p; // p will hold the current node
    p = table[index];

    while (p != NULL)
    {
        if (p->rNo == rNo)
        {
            strcpy(name, p->name);
            return 1;
        }
        p = p->next;
    }
    return 0;
}

// display the contents of the hash table
void display(NODE *table[MAX])
{
    NODE *temp;
    for (int i = 0; i < MAX; i++)
    {
        temp = table[i];
        printf("table[%d]-->", i);
        while (temp != NULL)
        {
            printf("%d %s-->", temp->rNo, temp->name);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// menu driven main function

int main()
{
    NODE *table[MAX];
    init_table(table);

    int ch, rNo;
    char name[20];
    int flag;

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the roll number: ");
            scanf("%d", &rNo);
            printf("Enter the name: ");
            scanf("%s", name);
            insert(table, rNo, name);
            break;

        case 2:
            printf("Enter the roll number to be deleted: ");
            scanf("%d", &rNo);
            flag = delete_element(table, rNo);
            if (flag == 0)
            {
                printf("Element not found\n");
            }
            else
            {
                printf("Element deleted successfully\n");
            }
            break;

        case 3:
            printf("Enter the roll number to be searched: ");
            scanf("%d", &rNo);
            flag = search(table, rNo, name);
            if (flag == 0)
            {
                printf("Element not found\n");
            }
            else
            {
                printf("Element found with name: %s\n", name);
            }
            break;

        case 4:
            display(table);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}