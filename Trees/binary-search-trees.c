// implementation of a binary search tree using linked list in C
// A binary search tree is a binary tree in which the child node to the left is lesser than the parent node,
// and the child node to the right is greater than the parent node.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} TREE;

// function prototypes
TREE *BSTInsert(TREE *, int);
TREE *createNode(int);
void inOrder(TREE *);
void preOrder(TREE *);
void postOrder(TREE *);
TREE *BSTDelete(TREE *, int);
int BSTSearch(TREE *, int);

void main()
{
    TREE *root = NULL; // initialise the root node to NULL
    int choice, data;
    printf("Binary Search Tree Operations\n");
    while (1)
    {
        printf("\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Delete\n6. Search\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            root = BSTInsert(root, data);
            break;
        case 2:
            preOrder(root);
            break;
        case 3:
            inOrder(root);
            break;
        case 4:
            postOrder(root);
            break;
        case 5:
            // printf("Enter the data to be deleted: ");
            // scanf("%d", &data);
            // root = BSTDelete(root, data);
            // break;
        case 6:
            printf("Enter the data to be searched: ");
            scanf("%d", &data);
            if (BSTSearch(root, data))
                printf("Element found\n");
            else
                printf("Element not found\n");
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}

// create node
TREE *createNode(int data)
{
    TREE *newNode = (TREE *)malloc(sizeof(TREE));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// insertion of a node
TREE *BSTInsert(TREE *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = BSTInsert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = BSTInsert(root->right, data);
    }
    return root;
}

/*
TREE *temp;
int flag = 1;
if (root == NULL)
{
    root = createNode(data);
    return root;
}

else{
    temp = root;
    while(flag)
    {
        if(data<temp->info)
        {
            if(temp->left == NULL)
            {
                temp->left = newNode;
                flag = 0;
            }
            else
            {
                temp = temp->left;
            }
        }
    }
}

*/

// preorder traversal
void preOrder(TREE *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// inorder traversal
void inOrder(TREE *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// postorder traversal
void postOrder(TREE *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}


//search logic
int BSTSearch(TREE *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == data)
    {
        return 1;
    }
    if (data < root->data)
    {
        return BSTSearch(root->left, data);
    }
    else
    {
        return BSTSearch(root->right, data);
    }
}
