/*
Separate chaining

- create buckets
- we calculate index and store the element in the bucket
- table size is fixed
- hash function  : h(x) = (key % table_size) + 1
- every node is of the same tyoe
struct node {
    int key;
    char name[20];
    struct node *next;
};

struct hash {
    struct node *head;
    int count;
};
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct node
{
    int key;
    char name[20];
    struct node *next;
};

struct hash
{
    struct node *head;
    int count;
};

// function prototypes

void display(struct hash *, int);
void insert_to_has(struct hash *, int, int, char *);
void delete_from_hash(struct hash *, int, int);
int search_in_hash(struct hash *, int, int, char *);

// menu driven main function

int main()
{
    struct hash *hash_table = (struct hash *)malloc(sizeof(struct hash) * MAX);
    for (int i = 0; i < MAX; i++)
    {
        hash_table[i].head = NULL;
        hash_table[i].count = 0;
    }

    int key, rNo;
    char name[20];
    int choice;

    while (1)
    {
        printf("\n1. Insert a record\n");
        printf("2. Delete a record\n");
        printf("3. Search a record\n");
        printf("4. Display the table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the roll number: ");
            scanf("%d", &rNo);
            printf("Enter the name: ");
            scanf("%s", name);
            key = rNo % MAX;
            insert_to_has(hash_table, key, rNo, name);
            break;
        case 2:
            printf("Enter the roll number to be deleted: ");
            scanf("%d", &rNo);
            key = rNo % MAX;
            delete_from_hash(hash_table, key, rNo);
            break;
        case 3:
            printf("Enter the roll number to be searched: ");
            scanf("%d", &rNo);
            key = rNo % MAX;
            if (search_in_hash(hash_table, key, rNo, name))
            {
                printf("Roll number: %d, Name: %s\n", rNo, name);
            }
            else
            {
                printf("Record not found!\n");
            }
            break;
        case 4:
            for (int i = 0; i < MAX; i++)
            {
                display(hash_table, i);
            }
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

// function to display the hash table

void display(struct hash *hash_table, int index)
{
    struct node *temp = hash_table[index].head;
    if (temp == NULL)
    {
        printf("Index %d is empty\n", index);
    }
    else
    {
        printf("Index %d has elements: \n", index);
        while (temp != NULL)
        {
            printf("Roll number: %d, Name: %s\n", temp->key, temp->name);
            temp = temp->next;
        }
    }
    return;
}

// function to insert a record into the hash table

void insert_to_has(struct hash *hash_table, int key, int rNo, char *name)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = rNo;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (hash_table[key].head == NULL)
    {
        hash_table[key].head = newNode;
        hash_table[key].count = 1;
    }
    else
    {
        newNode->next = hash_table[key].head;
        hash_table[key].head = newNode;
        hash_table[key].count++;
    }
    return;
}

// function to delete a record from the hash table

void delete_from_hash(struct hash *hash_table, int key, int rNo)
{
    struct node *temp, *prev;
    temp = hash_table[key].head;

    if (temp == NULL)
    {
        printf("Record not found!\n");
        return;
    }

    prev = NULL;
    while (temp != NULL)
    {
        if (temp->key == rNo)
        {
            if (prev == NULL)
            {
                hash_table[key].head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            hash_table[key].count--;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Record not found!\n");
    return;
}

// function to search a record in the hash table

int search_in_hash(struct hash *hash_table, int key, int rNo, char *name)
{
    struct node *temp;
    temp = hash_table[key].head;

    if (temp == NULL)
    {
        return 0;
    }

    while (temp != NULL)
    {
        if (temp->key == rNo)
        {
            strcpy(name, temp->name);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// end of program

// Output: