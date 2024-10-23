/*
# Expression Tree inplementation in C
- An expression tree is a binary tree in which each internal node corresponds to the operator and each leaf node corresponds to the operand.
- The value of the expression tree is evaluated by traversing the tree in postorder.
- The expression tree is built using the postfix expression.
- The postfix expression is converted to an expression tree.
- The expression tree is then evaluated.
- The expression tree is then destroyed.
- The expression tree is then displayed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct etnode {
    char data;
    struct etnode *left;
    struct etnode *right;
} etnode;

// function prototypes
etnode *createetnode(char);
etnode *createexpressiontree(char *);
void inorder(etnode *);
void postorder(etnode *);
void preorder(etnode *);
int evaluate(etnode *);
void destroy(etnode *);

// helper stack functions
etnode *pop(etnode **, int *);
void push(etnode **, etnode **, int *);

// helper functions
int isoperator(char);
int precedence(char);


// menu driven main function
void main() {
    etnode *root;
    char postfix[20];
    int ch, result;

    root = NULL;

    while (1) {
        printf("\n1. Create Expression Tree");
        printf("\n2. Inorder Traversal");
        printf("\n3. Postorder Traversal");
        printf("\n4. Preorder Traversal");
        printf("\n5. Evaluate Expression Tree");
        printf("\n6. Destroy Expression Tree");
        printf("\n7. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the postfix expression: ");
                scanf("%s", postfix);
                root = createexpressiontree(postfix);
                break;

            case 2:
                printf("Inorder Traversal..\n");
                inorder(root);
                break;

            case 3:
                printf("Postorder Traversal..\n");
                postorder(root);
                break;

            case 4:
                printf("Preorder Traversal..\n");
                preorder(root);
                break;

            case 5:
                result = evaluate(root);
                printf("Result: %d\n", result);
                break;

            case 6:
                destroy(root);
                break;

            case 7:
                exit(0);
        }
    }
}

// create a new node

etnode *createetnode(char x) {
    etnode *temp;

    temp = (etnode *)malloc(sizeof(etnode));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// helper functions

etnode *pop(etnode **stack, int *top) {
    if (*top == -1)
        return NULL;
    else
        return stack[(*top)--];
}

void push(etnode **stack, etnode **node, int *top) {
    stack[++(*top)] = *node;
}

// helper functions

int isoperator(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 1;
    else
        return 0;
}

int precedence(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

// cretae expression tree