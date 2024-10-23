/*
# Array Implementation of a Binary Search Tree
- The array implementation of a binary search tree is a simple and efficient way to store the elements of a binary search tree in an array.
- The array implementation of a binary search tree is a complete binary tree.
- The array implementation of a binary search tree is a space-efficient way to store the elements of a binary search tree.
*/

// Implementation of an Array Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// function prototypes
int insert(int *, int, int);
void inorder(int *, int, int);
void preorder(int *, int, int);
void postorder(int *, int, int);

// menu driven main function

int main()
{
    int tree[MAX], ch, num, i, n;

    for (i = 0; i < MAX; i++)
        tree[i] = -1;

    n = 0;

    while (1)
    {
        printf("\n1. Insert");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &num);
            n = insert(tree, num, n);
            break;

        case 2:
            printf("Inorder Traversal..\n");
            inorder(tree, 0, n);
            break;

        case 3:
            printf("Preorder Traversal..\n");
            preorder(tree, 0, n);
            break;

        case 4:
            printf("Postorder Traversal..\n");
            postorder(tree, 0, n);
            break;
        case 5:
            return 0;
        }
    }
}

// function to insert an element into the array binary search tree

int insert(int *tree, int x, int n)
{
    int i = 0;
    if (n == 0)
    {
        tree[0] = x;
        return 1;
    }
    // recursive calls
    while (i < MAX && tree[i] != -1)
    {
        if (x < tree[i])
            i = 2 * i + 1;
        else
            i = 2 * i + 2;
    }
    if (i < MAX)
    {
        tree[i] = x;
        return n + 1;
    }
    else
    {
        printf("Tree is full..\n");
        return n;
    }
}

// function for inorder traversal - left, root, right - displays in ascending order

void inorder(int *tree, int i, int n)
{
    if (i < n && tree[i] != -1)
    {
        inorder(tree, 2 * i + 1, n);
        printf("%d ", tree[i]);
        inorder(tree, 2 * i + 2, n);
    }
}

// function for preorder traversal - root, left, right

void preorder(int *tree, int i, int n)
{
    if (i < n && tree[i] != -1)
    {
        printf("%d ", tree[i]);
        preorder(tree, 2 * i + 1, n);
        preorder(tree, 2 * i + 2, n);
    }
}

// function for postorder traversal - left, right, root

void postorder(int *tree, int i, int n)
{
    if (i < n && tree[i] != -1)
    {
        postorder(tree, 2 * i + 1, n);
        postorder(tree, 2 * i + 2, n);
        printf("%d ", tree[i]);
    }
}