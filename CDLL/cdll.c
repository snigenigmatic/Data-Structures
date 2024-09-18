#include <stdio.h>
#include <stdlib.h>

typedef struct dnode
{
    int info;
    struct dnode *left, *right;
} DNODE;

DNODE *frontins(DNODE *, int);
void display(DNODE *);
DNODE *endins(DNODE *, int);
DNODE *frontdel(DNODE *);
DNODE *enddel(DNODE *);

void main()
{
    DNODE *newnode, *dlist;
    int x, ch, pinfo;

    dlist = NULL;

    while (1)
    {
        printf(" Enter 1->Front Insertion\n2->Display\n3->end Insertion\n");
        printf(" Enter 4->Front deletion\n5->End Deletion\n6->exit");

        printf(" Enter YOUR CHOICE");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            printf(" Enter the information");
            scanf("%d", &x);
            dlist = frontins(dlist, x);
        }
        break;
        case 2:
        {
            display(dlist);
        }
        break;
        case 3:
        {
            printf(" Enter the information");
            scanf("%d", &x);
            dlist = endins(dlist, x);
        }
        break;
        case 4:
        {
            dlist = frontdel(dlist);
        }
        break;
        case 5:
        {
            dlist = enddel(dlist);
        }
        break;

        default:
            exit(0);
        }
    }
}

DNODE *frontins(DNODE *dlist, int x)
{
    DNODE *newnode;
    newnode = (struct dnode *)(malloc(sizeof(DNODE)));
    newnode->info = x;
    newnode->left = NULL;
    newnode->right = NULL;

    if (dlist == NULL)
    {
        dlist = newnode;
        dlist->right = dlist;
        dlist->left = dlist;
    }
    else
    {
        newnode->right = dlist;
        newnode->left = dlist->left;
        dlist->left = newnode;
        (newnode->left)->right = newnode;
        dlist = newnode;
    }
    return dlist;
}

DNODE *endins(DNODE *dlist, int x)
{
    DNODE *newnode;
    newnode = (struct dnode *)(malloc(sizeof(DNODE)));
    newnode->info = x;
    newnode->left = NULL;
    newnode->right = NULL;

    if (dlist == NULL)
    {
        dlist = newnode;
        dlist->right = dlist;
        dlist->left = dlist;
    }
    else
    {
        newnode->right = dlist;
        newnode->left = dlist->left;
        dlist->left = newnode;
        (newnode->left)->right = newnode;
    }
    return dlist;
}

void display(DNODE *dlist)
{
    DNODE *temp = dlist;
    if (dlist == NULL)
        printf("Empty List...");
    else
    {
        while (temp->right != dlist)
        {
            printf("\t%d", temp->info);
            temp = temp->right;
        }
        printf("\t%d", temp->info);
    }
}

DNODE *frontdel(DNODE *dlist)
{
    DNODE *temp;
    if (dlist == NULL)
        printf("Empty List");
    if (dlist->right == dlist)
    {
        temp = dlist;
        dlist = NULL;
        free(temp);
    }
    else
    {
        temp = dlist;
        (dlist->left)->right = dlist->right;
        (dlist->right)->left = dlist->left;
        dlist = dlist->right;
        free(temp);
    }
    return dlist;
}

DNODE *enddel(DNODE *dlist)
{
    DNODE *temp;
    if (dlist == NULL)
        printf("Empty List");
    if (dlist->right == dlist)
    {
        temp = dlist;
        dlist = NULL;
        free(temp);
    }
    else
    {
        temp = dlist->left;
        dlist->left = temp->left;
        (dlist->left)->right = dlist;
    }
    return dlist;
}
