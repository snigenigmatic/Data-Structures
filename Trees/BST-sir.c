#include <stdio.h>
#include <stdlib.h>

// when adding in order after a root node, we end up having to search only half of the tree basically(left or right, left or right)

// BST Inorder insert: also called Lexical Insert
typedef struct node
{
    int info;
    struct node *left;
    struct node *right;
} TREE;

TREE *BST_insert(TREE *, int);
void preorder(TREE *);
void inorder(TREE *);
void postorder(TREE *);
TREE *BST_delete(TREE *, int);
TREE *search(TREE *, int);
void countelements(TREE *);
int smallest(TREE *);
int largest(TREE *);
void inorder_iterative(TREE *);

int count = 0;

void main()
{
    TREE *root = NULL;
    int x;
    int ch;
    int key;

    while (1)
    {
        printf("\n1.BST Insertion \n2.Preorder \n3.Inorder \n4.Postorder \n5.BST Deletion \n6.Search \n7.Count \n8.Min and Max element \n9.Iterative Inorder Traversal \n10.Exit ");
        printf("\nEnter your choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("Enter the element :");
            scanf("%d", &x);
            root = BST_insert(root, x); // Update root after insertion
            break;
        }
        case 2:
        {
            preorder(root);
            break;
        }
        case 3:
        {
            inorder(root);
            break;
        }
        case 4:
        {
            postorder(root);
            break;
        }
        case 5:
        {
            printf("Enter the element to be deleted :");
            scanf("%d", &key);
            root = BST_delete(root, key);
            break;
        }
        case 6:
        {
            printf("Enter the element to be searched :");
            scanf("%d", &x);
            search(root, x);
            break;
        }
        case 7:
        {
            countelements(root);
            printf("Number of elements in the tree : %d\n", count);
            break;
        }
        case 8:
        {
            printf("Smallest element in the tree : %d\n", smallest(root));
            printf("Largest element in the tree : %d\n", largest(root));
            break;
        }
        case 9:
        {
            inorder_iterative(root);
            break;
        }
        case 10:
        {
            exit(0);
        }
        default:
        {
            printf("Invalid choice!\n");
            break;
        }
        }
    }
}

TREE *BST_insert(TREE *root, int x)
{
    TREE *newnode = (TREE *)malloc(sizeof(TREE));
    newnode->info = x;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        TREE *temp = root;
        int flag = 1;
        while (flag)
        {
            if (x < temp->info)
            {
                if (temp->left == NULL)
                {
                    temp->left = newnode;
                    flag = 0;
                }
                else
                    temp = temp->left;
            }
            else // x >= temp->info
            {
                if (temp->right == NULL)
                {
                    temp->right = newnode;
                    flag = 0;
                }
                else
                    temp = temp->right;
            }
        }
    }
    return root;
}

void preorder(TREE *root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TREE *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

void postorder(TREE *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

TREE *search(TREE *root, int x)
{
    TREE *temp = root;
    while (temp != NULL)
    {
        if (x == temp->info)
        {
            printf("Element found!\n");
            return temp;
        }
        else if (x < temp->info)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    printf("Element not found!\n");
    return NULL;
}

void countelements(TREE *root)
{
    if (root != NULL)
    {
        countelements(root->left);
        count++;
        countelements(root->right);
    }
}

// BST deletion - logic
// 1. If the node to be deleted is a leaf node, simply delete it.
// 2. If the node to be deleted has only one child, copy the child to the node and delete the child.
// 3. If the node to be deleted has two children, find the inorder successor of the node. Copy contents of the inorder successor to the node and delete the inorder successor. Note that inorder predecessor can also be used.
// The important thing to note is, inorder successor is needed only when the right child is not empty. In this particular case, inorder successor can be obtained by finding the minimum value in the right child of the node.

TREE *BST_delete(TREE *root, int key)
{
    TREE *temp = root;
    TREE *parent = NULL;
    TREE *q = NULL;
    TREE *inorder_successor = NULL;
    while (temp != NULL && temp->info != key)
    {
        parent = temp;
        if (key < temp->info)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (temp == NULL)
    {
        printf("Element not found!\n");
        return root;
    }
    else
    {
        // Case 1 : If node to be deleted is a leaf node
        if (temp->right == NULL)
        {
            q = temp->left;
        }
        else if (temp->left == NULL)
        {
            q = temp->right;
        }
        else
        {
            inorder_successor = temp->right;
            while (inorder_successor->left != NULL)
            {
                inorder_successor = inorder_successor->left;
            }
            inorder_successor->left = temp->left;
            q = temp->right;
        }
        if (parent == NULL)
        {
            root = q;
        }
        else if (parent->left == temp)
        {
            parent->left = q;
        }
        else if (parent->right == temp)
        {
            parent->right = q;
        }
    }
    free(temp);
    return root;
}

// Traverson of BST in interative inorder fashion
// 1. Create an empty stack S.
// 2. Initialize current node as root
// 3. Push the current node to S and set current = current->left until current is NULL
// 4. If current is NULL and stack is not empty then

int smallest(TREE *root) // helper function to find least element in the tree
{
    TREE *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->info;
}

int largest(TREE *root) // helper function to find largest element in the tree
{
    TREE *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->info;
}

void inorder_iterative(TREE *root)
{
    int top = -1;
    TREE *temp = root;
    TREE *stack[20];
    while (1)
    {
        while (temp != NULL)
        {
            stack[++top] = temp;
            temp = temp->left;
        }
        if (top != -1)
        {
            temp = stack[top--];
            printf("%d ", temp->info);
            temp = temp->right;
        }
        else
        {
            break;
        }
    }
}