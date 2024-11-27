//program to implement Linear probing

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct element
{
   int key;
   char name[100];
   int status;  // 0: empty, 1: occupied
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
    }
  }
}

void search_in_hash(struct element *table, int size, int key, int items)
{
    int pos, probes; // probes = no. of collisions
    if(items == 0)
    {
        printf("Table empty\n");
        return;
    }
    pos = key % size;
    probes = 0;
    while((table[pos].key != key) && (probes < items))
    {
        pos = (pos + 1) % size;
        if(table[pos].status == 1)
            probes++;
    }
    if(table[pos].key == key)
    {
        printf("\nKey found. Details:\n");       
        printf("Key = %d, Name = %s\n", table[pos].key, table[pos].name);
    }
    else
        printf("Key not found\n");
}

void delete_from_hash(struct element *table, int size, int key, int *items)
{
    int pos, probes;
    if(*items == 0)
    {
        printf("Table empty\n");
        return;
    }
    pos = key % size;
    probes = 0;
    while((table[pos].key != key) && (probes < *items))
    {
        pos = (pos + 1) % size;
        if(table[pos].status == 1)
            probes++;
    }
    if(table[pos].key == key)
    {
        table[pos].status = 0;
        (*items)--;
    }
    else
        printf("Key not found\n");
}

void display(struct element *table, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d: ", i);
        if (table[i].status != 0)
            printf("Key = %d, Name = %s", table[i].key, table[i].name);
        printf("\n");
    }
}

void insert_to_hash(struct element *table, int size, int key, char *name, int *items)
{
    int pos;
    if(size == *items)
    {
        printf("Table full\n");
        return;
    }
    pos = key % size;

    while(table[pos].status != 0)
        pos = (pos + 1) % size;

    table[pos].key = key;
    strcpy(table[pos].name, name);
    table[pos].status = 1;
    (*items)++;
}