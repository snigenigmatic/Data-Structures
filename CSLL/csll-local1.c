#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} NODE;

NODE *insertFront(NODE *list, int x);
NODE *insertEnd(NODE *list, int x);
void deleteFront(NODE **list);
void deleteEnd(NODE **list);
void position_insert(NODE **list, int x, int pos);
void position_delete(NODE **list, int pos);
void display(NODE *list);
NODE *ordered_insert(NODE *list, int x);

int main() {
    int choice, x, pos;
    NODE *list = NULL;
    
    while (1) {
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

        switch (choice) {
            case 1:
                printf("Enter the information: ");
                scanf("%d", &x);
                list = insertFront(list, x);
                break;
            case 2:
                printf("Enter the information: ");
                scanf("%d", &x);
                list = insertEnd(list, x);
                break;
            case 3:
                deleteFront(&list);
                break;
            case 4:
                deleteEnd(&list);
                break;
            case 5:
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
                printf("Enter the information: ");
                scanf("%d", &x);
                list = ordered_insert(list, x);
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
    return 0;
}

NODE *insertFront(NODE *list, int x) {
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = x;
    if (list == NULL) {
        newnode->next = newnode;
    } else {
        NODE *temp = list;
        while (temp->next != list) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = list;
    }
    list = newnode;
    return list;
}

NODE *insertEnd(NODE *list, int x) {
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = x;
    if (list == NULL) {
        newnode->next = newnode;
        return newnode;
    } else {
        NODE *temp = list;
        while (temp->next != list) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = list;
    }
    return list;
}

void display(NODE *list) {
    if (list == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE *temp = list;
    do {
        printf("%d\n", temp->info);
        temp = temp->next;
    } while (temp != list);
}

void deleteFront(NODE **list) {
    if (*list == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE *temp = *list;
    if (temp->next == *list) {
        free(temp);
        *list = NULL;
    } else {
        NODE *last = *list;
        while (last->next != *list) {
            last = last->next;
        }
        *list = (*list)->next;
        last->next = *list;
        free(temp);
    }
}

void deleteEnd(NODE **list) {
    if (*list == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE *temp = *list;
    if (temp->next == *list) {
        free(temp);
        *list = NULL;
    } else {
        NODE *prev = NULL;
        while (temp->next != *list) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *list;
        free(temp);
    }
}

void position_insert(NODE **list, int x, int pos) {
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = x;
    if (*list == NULL || pos == 1) {
        if (*list == NULL) {
            newnode->next = newnode;
        } else {
            NODE *temp = *list;
            while (temp->next != *list) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = *list;
        }
        *list = newnode;
    } else {
        NODE *temp = *list;
        for (int i = 1; i < pos - 1 && temp->next != *list; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void position_delete(NODE **list, int pos) {
    if (*list == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE *temp = *list;
    if (pos == 1) {
        if (temp->next == *list) {
            free(temp);
            *list = NULL;
        } else {
            NODE *last = *list;
            while (last->next != *list) {
                last = last->next;
            }
            *list = (*list)->next;
            last->next = *list;
            free(temp);
        }
    } else {
        NODE *prev = NULL;
        for (int i = 1; i < pos && temp->next != *list; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp->next == *list) {
            printf("Invalid position\n");
        } else {
            prev->next = temp->next;
            free(temp);
        }
    }
}

NODE *ordered_insert(NODE *list, int x) {
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = x;
    if (list == NULL || x < list->info) {
        if (list == NULL) {
            newnode->next = newnode;
            return newnode;
        } else {
            NODE *temp = list;
            while (temp->next != list) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = list;
            return newnode;
        }
    } else {
        NODE *temp = list;
        while (temp->next != list && temp->next->info < x) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return list;
}
