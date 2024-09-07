#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dnode
{
    int info;
    struct dnode *left, *right;
} DNODE;

DNODE *frontins(DNODE *dlist, int x);
DNODE *endins(DNODE *dlist, int x);
DNODE *afterins(DNODE *dlist, int x, int pinfo);
DNODE *frontdel(DNODE *dlist);
DNODE *enddel(DNODE *dlist);
DNODE *infodel(DNODE *dlist, int pinfo);
void display(DNODE *dlist);

DNODE *last = NULL;

int main()
{
    DNODE *dlist = NULL;
    int choice, x, pinfo;

    while (true)
    {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Front Insertion\n2. Display\n3. End Insertion\n");
        printf("4. Front Deletion\n5. End Deletion\n6. After Insertion\n");
        printf("7. Information Deletion\n8. Exit\n");
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
            printf("Enter the information and after position: ");
            scanf("%d %d", &x, &pinfo);
            dlist = afterins(dlist, x, pinfo);
            break;
        case 7:
            printf("Enter the information of the node to be deleted: ");
            scanf("%d", &pinfo);
            dlist = infodel(dlist, pinfo);
            break;
        case 8:
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
    DNODE *newnode = (DNODE *)malloc(sizeof(DNODE));
    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newnode->info = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

DNODE *frontins(DNODE *dlist, int x)
{
    DNODE *newnode = createNode(x);
    if (dlist == NULL)
    {
        last = dlist = newnode;
    }
    else
    {
        newnode->right = dlist;
        dlist->left = newnode;
        dlist = newnode;
    }
    return dlist;
}

DNODE *endins(DNODE *dlist, int x)
{
    DNODE *newnode = createNode(x);
    if (dlist == NULL)
    {
        last = dlist = newnode;
    }
    else
    {
        last->right = newnode;
        newnode->left = last;
        last = newnode;
    }
    return dlist;
}

DNODE *afterins(DNODE *dlist, int x, int pinfo)
{
    if (dlist == NULL)
    {
        printf("List is empty. Inserting at the beginning.\n");
        return frontins(dlist, x);
    }

    DNODE *temp = dlist;
    while (temp != NULL && temp->info != pinfo)
    {
        temp = temp->right;
    }

    if (temp == NULL)
    {
        printf("Predecessor not found. Inserting at the end.\n");
        return endins(dlist, x);
    }

    DNODE *newnode = createNode(x);
    newnode->right = temp->right;
    newnode->left = temp;
    if (temp->right != NULL)
    {
        temp->right->left = newnode;
    }
    else
    {
        last = newnode;
    }
    temp->right = newnode;

    return dlist;
}

DNODE *frontdel(DNODE *dlist)
{
    if (dlist == NULL)
    {
        printf("Empty List\n");
        return NULL;
    }

    DNODE *temp = dlist;
    dlist = dlist->right;
    if (dlist != NULL)
    {
        dlist->left = NULL;
    }
    else
    {
        last = NULL;
    }
    free(temp);
    return dlist;
}

DNODE *enddel(DNODE *dlist)
{
    if (dlist == NULL)
    {
        printf("Empty List\n");
        return NULL;
    }

    if (dlist->right == NULL)
    {
        free(dlist);
        last = NULL;
        return NULL;
    }

    DNODE *temp = last;
    last = last->left;
    last->right = NULL;
    free(temp);
    return dlist;
}

DNODE *infodel(DNODE *dlist, int pinfo)
{
    if (dlist == NULL)
    {
        printf("Empty List\n");
        return NULL;
    }

    DNODE *temp = dlist;
    if (temp->info == pinfo)
    {
        dlist = dlist->right;
        if (dlist != NULL)
        {
            dlist->left = NULL;
        }
        else
        {
            last = NULL;
        }
        free(temp);
        return dlist;
    }

    while (temp != NULL && temp->info != pinfo)
    {
        temp = temp->right;
    }

    if (temp == NULL)
    {
        printf("Element not found\n");
        return dlist;
    }

    if (temp->right == NULL)
    {
        temp->left->right = NULL;
        last = temp->left;
    }
    else
    {
        temp->left->right = temp->right;
        temp->right->left = temp->left;
    }

    free(temp);
    return dlist;
}

void display(DNODE *dlist)
{
    if (dlist == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    DNODE *temp = dlist;
    printf("List contents: ");
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->right;
    }
    printf("\n");
}