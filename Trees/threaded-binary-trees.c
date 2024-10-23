/*
# Threaded Binary Trees
- Right-in Threaded Binary Tree : In this type of threaded binary tree, the right child of a leaf node points to the inorder successor of the node.
- Left-in Threaded Binary Tree : In this type of threaded binary tree, the left child of a leaf node points to the inorder predecessor of the node.
- In Thread Binary Tree : In this type of threaded binary tree, both the left and right child of a leaf node points to the inorder predecessor and inorder successor of the node respectively.
- Not memory efficient
- Not time efficient
- Not space efficient
*/

// Implementation of an In Threaded Binary Search Tree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct tnode {
    int data;
    struct tnode *left;
    struct tnode *right;
    bool lthread;
    bool rthread;
};

// function prototypes
struct tnode *insert(struct tnode *, int);
void inorder(struct tnode *);
struct tnode *inordersuccessor(struct tnode *);

void main() {
    struct tnode *root;
    int ch, num;

    root = NULL;

    while (1) {
        printf("\n1. Insert");
        printf("\n2. Inorder Traversal");
        printf("\n3. Exit");

        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &num);
                root = insert(root, num);
                break;

            case 2:
                printf("Inorder traversal..\n");
                inorder(root);
                break;

            case 3:
                exit(0);
        }
    }
}

struct tnode *insert(struct tnode *t, int x) {
    struct tnode *curr, *temp;
    curr = t;

    temp = (struct tnode *)(malloc(sizeof(struct tnode)));
    temp->data = x;
    temp->lthread = true;
    temp->rthread = true;
    temp->left = NULL;
    temp->right = NULL;

    // search for the position of the node to be inserted
    if (curr == NULL)
        return temp;

    while (curr != NULL) {
        if (x < curr->data) {
            if (curr->lthread == false)
                curr = curr->left;
            else
                break;
        } else {
            if (curr->rthread == false)
                curr = curr->right;
            else
                break;
        }
    }

    // Assign the node
    if (x < curr->data) {
        temp->left = curr->left;
        temp->right = curr;
        curr->lthread = false;
        curr->left = temp;
    } else {
        temp->right = curr->right;
        temp->left = curr;
        curr->rthread = false;
        curr->right = temp;
    }
    return t;
}

void inorder(struct tnode *t) {
    printf("Inside Inorder...");
    struct tnode *curr;
    if (t == NULL)
        printf("Empty Tree..");
    else {
        curr = t;
        while (curr->lthread == false)
            curr = curr->left;

        while (curr != NULL) {
            printf("\t%d", curr->data);
            curr = inordersuccessor(curr);
        }
    }
}

struct tnode *inordersuccessor(struct tnode *t) {
    if (t->rthread == true)
        return t->right; // go to the right node
    t = t->right;
    while (t->lthread == false) // go to the left most node in the tree.
        t = t->left;
    return t;
}