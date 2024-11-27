// Quadratic Probing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// hash function : hash(key) = key%size
//                 index = (hash(key) + i^2) % size

struct element
{
    int key;
    char name[20];
    int status;
};

void display(struct element *, int);
void insert_to_hash(struct element*, int, int, char*, int*);
void delete_from_hash(struct element*, int, int, int*);
void search_in_hash(struct element*, int, int, int);

int main()
{
  struct element *table;
  int i, choice, key, size, items;
  char name[100];
  
  printf("Enter the table size: ");
  scanf("%d", &size);

  //create hash table
  table = malloc(size * sizeof(struct element));
  for(i = 0; i < size; i++)
    table[i].status = 0;
  items = 0;
  
  while(1)
  {
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Search");
    printf("\n4. Display");
    printf("\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice)
    {
      case 1: 
          printf("Enter key: ");
          scanf("%d", &key);
          printf("Enter name: ");
          scanf("%s", name);
          insert_to_hash(table, size, key, name, &items);
          break;
      case 2: 
          printf("Enter key to delete: ");
          scanf("%d", &key);
          delete_from_hash(table, size, key, &items);
          break;
      case 3: 
          printf("Enter key to search: ");
          scanf("%d", &key);
          search_in_hash(table, size, key, items);
          break;
      case 4:
          display(table, size);
          break;
      case 5:
          free(table);
          exit(0);
      default:
          printf("Invalid choice! Please try again.\n");
    }
  }
}

// functions

void insert_to_hash(struct element *table, int size, int key, char *name, int *items)
{
    if(size == *items) {
        printf("Table full\n");
        return;
    }

    int pos = key % size;
    int start_pos = pos;
    int i = 0;

    // Check for duplicate key first
    while(i < size) {
        if(table[pos].status == 1 && table[pos].key == key) {
            printf("Key already exists\n");
            return;
        }
        pos = (start_pos + i*i) % size;
        i++;
        if(pos == start_pos) break;  // We've checked all positions
    }

    // Reset for insertion
    pos = start_pos;
    i = 0;

    // Find empty slot using quadratic probing
    while(table[pos].status == 1 && i < size) {
        i++;
        pos = (start_pos + i*i) % size;
    }

    // Check if we found a slot
    if(i >= size) {
        printf("No available slot found (quadratic probing failed)\n");
        return;
    }

    table[pos].key = key;
    strcpy(table[pos].name, name);
    table[pos].status = 1;
    (*items)++;
    printf("Inserted at position %d after %d probes\n", pos, i);
}

// deletion function

void delete_from_hash(struct element *table, int size, int key, int *items)
{
    if(*items == 0)
    {
        printf("Table is empty.\n");
        return;
    }

    int pos = key % size;
    int start_pos = pos;
    int i = 0;

    while(i < size) {
        if(table[pos].status == 1 && table[pos].key == key) {
            table[pos].status = 0;  // Mark as empty
            (*items)--;
            printf("Deleted at position %d after %d probes\n", pos, i);
            return;
        }
        i++;
        pos = (start_pos + i*i) % size;
        if(pos == start_pos) break;  // We've checked all positions
    }
    
    printf("Key not found\n");
}

// display function
void display(struct element *table, int size)
{
    int i = 0;
    for(i = 0; i < size; i++)
    {
        printf("%d: ", i);
        if (table[i].status != 0)
            printf("Key = %d, Name = %s", table[i].key, table[i].name);
        printf("\n");
    }
}

// search function

void search_in_hash(struct element *table, int size, int key, int items)
{
    if(items == 0) {
        printf("Table is empty\n");
        return;
    }

    int pos = key % size;
    int start_pos = pos;
    int i = 0;

    while(i < size) {
        if(table[pos].status == 1 && table[pos].key == key) {
            printf("\nKey found. Details:\n");       
            printf("Key = %d, Name = %s\n", table[pos].key, table[pos].name);
            return;
        }
        i++;
        pos = (start_pos + i*i) % size;
        if(pos == start_pos) break;  // We've checked all positions
    }
    
    printf("Key not found\n");
}
