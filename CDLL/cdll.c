#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dnode
{
    int info;
    struct dnode *left, *right;
} DNODE;

DNODE *createNode(int x);
DNODE *frontins(DNODE *dlist, int x);
DNODE *endins(DNODE *dlist, int x);
DNODE *frontdel(DNODE *dlist);
DNODE *enddel(DNODE *dlist);
void display(DNODE *dlist)
{
    DNODE *temp = dlist;
    if (dlist == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    else
    {
        printf("The list is: ");
        do
        {
            printf("%d ", temp->info);
            temp = temp->right;
        } while (temp != dlist);
        printf("\n");
    }
}

int main()
{
    DNODE *dlist = NULL;
    int choice, x, pinfo;

    while (true)
    {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Front Insertion\n2. Display\n3. End Insertion\n");
        printf("4. Front Deletion\n5. End Deletion\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the information for the node: ");
            scanf("%d", &x);
            dlist = frontins(dlist, x);
            break;
        case 2:
            display(dlist);
            break;
        case 3:
            printf("Enter the information: ");
            scanf("%d", &x);
            dlist = endins(dlist, x);
            break;
        case 4:
            dlist = frontdel(dlist);
            break;
        case 5:
            dlist = enddel(dlist);
            break;
        case 6:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

DNODE *createNode(int x)
{
    DNODE *newNode = (DNODE *)malloc(sizeof(DNODE));
    newNode->info = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

DNODE *frontins(DNODE *dlist, int x)
{
    DNODE *newNode = createNode(x);
    if (dlist == NULL)
    {
        dlist = newNode;
    }
    else
    {
        newNode->right = dlist;
        dlist->left = newNode;
        newNode->left = dlist->left;
        dlist->left->right = newNode;
        dlist->left = newNode;
        dlist = newNode;
    }
    return dlist;
}

DNODE *endins(DNODE *dlist, int x)
{
    DNODE *newNode = createNode(x);
    if (dlist == NULL)
    {
        dlist = newNode;
    }
    else
    {
        newNode->right = dlist;
        newNode->left = dlist->left;
        dlist->left->right = newNode;
        dlist->left = newNode;
        dlist->left->right = newNode;
        dlist->left = newNode;
    }
    return dlist;
}


DNODE *frontdel(DNODE *dlist)
{
    DNODE *temp = dlist;
    if (dlist == NULL)
    {
        printf("The list is empty.\n");
        return dlist;
    }
    if (dlist->right == dlist)
    {
        dlist = NULL;
        free(temp);
    }
    else
    {
        (dlist->left)->right = dlist->right;
        (dlist->right)->left = dlist->left;
        dlist = dlist->right;
        free(temp);
    }
    return dlist;
}

DNODE *enddel(DNODE *dlist)
{
    if (dlist == NULL)
    {
        printf("List is empty\n");
        return dlist;
    }
    DNODE *last = dlist->left;
    if (dlist->right == dlist)
    {
        dlist = NULL;
        free(last);
    }
    else
    {
        last->left->right = dlist;
        dlist->left = last->left;
        free(last);
    }
    return dlist;
}
