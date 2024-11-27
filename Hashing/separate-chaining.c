//program to implement separate chaining
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
   int key;
   char name[100];
   struct node *next;
};

struct hash
{
  struct node *head;
  int count;
};

void display(struct hash *, int);
void insert_to_hash(struct hash *,int,int, char *);
void delete_from_hash(struct hash*,int,int);
void search_in_hash(struct hash *ht,int size,int key);
void cleanup_hash(struct hash *ht, int size);

int main()
{
  struct hash *hashtable;
  int i,ch,key;
  char name[100];
  int tablesz;
  
  printf("Enter the table size: ");
  scanf("%d",&tablesz);
  
  if(tablesz <= 0) {
      printf("Table size must be positive!\n");
      return 1;
  }

  //create hash table
  hashtable = malloc(tablesz * sizeof(struct hash));
  if(hashtable == NULL) {
      printf("Memory allocation failed!\n");
      return 1;
  }

  for(i=0; i<tablesz; i++)
  {
    hashtable[i].head = NULL;
    hashtable[i].count = 0;
  }

  while(1)
  {
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Search");
    printf("\n4. Display");
    printf("\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);

    switch(ch)
    {
      case 1: 
          printf("Enter key: ");
          scanf("%d",&key);
          printf("Enter name: ");
          scanf("%s",name);
          insert_to_hash(hashtable,tablesz,key,name);
          break;
      case 2: 
          printf("Enter the key for deletion: ");
          scanf("%d",&key);
          delete_from_hash(hashtable,tablesz,key);
          break;
      case 3: 
          printf("Enter the key to search: ");
          scanf("%d",&key);
          search_in_hash(hashtable,tablesz,key);
          break;
      case 4:
          display(hashtable,tablesz);
          break;
      case 5:
          cleanup_hash(hashtable, tablesz);
          free(hashtable);
          return 0;
      default:
          printf("Invalid choice! Please try again.\n");
    }
  }
}

void delete_from_hash(struct hash *ht, int size, int key)
{
   if(ht == NULL) return;

   struct node *prev, *temp;
   int index = key % size;
   
   prev = NULL;
   temp = ht[index].head;

   while(temp != NULL && temp->key != key)
   {
     prev = temp;
     temp = temp->next;
   }

   if(temp != NULL) // key found
   {
     if(prev == NULL) // first node
         ht[index].head = temp->next;
     else
         prev->next = temp->next;
     
     free(temp);
     ht[index].count--;
     printf("Record deleted successfully\n");
   }
   else
     printf("Record not found\n");
}

void insert_to_hash(struct hash *ht, int size, int key, char *name)
{
   if(ht == NULL || name == NULL) return;

   struct node *temp = malloc(sizeof(struct node));
   if(temp == NULL) {
       printf("Memory allocation failed!\n");
       return;
   }

   temp->key = key;
   strncpy(temp->name, name, sizeof(temp->name) - 1);
   temp->name[sizeof(temp->name) - 1] = '\0';  // Ensure null termination

   int index = key % size;

   temp->next = ht[index].head;
   ht[index].head = temp;
   ht[index].count++;
   printf("Record inserted successfully\n");
}

void display(struct hash *ht, int size)
{
    if(ht == NULL) return;

    int i;
    struct node *temp;
    int empty = 1;

    printf("\nHash Table Contents:\n");
    for(i = 0; i < size; i++)
    {
        printf("Bucket %d: ", i);
        if(ht[i].head != NULL)
        {
            empty = 0;
            temp = ht[i].head;
            while(temp != NULL)
            {
                printf("[Key: %d, Name: %s] -> ", temp->key, temp->name);
                temp = temp->next;
            }
            printf("NULL");
        }
        else
        {
            printf("Empty");
        }
        printf("\n");
    }
    
    if(empty) {
        printf("Hash table is empty\n");
    }
}

void search_in_hash(struct hash *ht, int size, int key)
{
    if(ht == NULL) return;

    int index = key % size;
    struct node *temp = ht[index].head;

    while(temp != NULL && temp->key != key)
        temp = temp->next;
   
    if(temp != NULL)
    {
        printf("\nRecord found! Details:\n");
        printf("Key: %d\n", temp->key);
        printf("Name: %s\n", temp->name);     
    }
    else
        printf("Record not found\n");
}

void cleanup_hash(struct hash *ht, int size)
{
    if(ht == NULL) return;

    for(int i = 0; i < size; i++) {
        struct node *current = ht[i].head;
        while(current != NULL) {
            struct node *temp = current;
            current = current->next;
            free(temp);
        }
        ht[i].head = NULL;
        ht[i].count = 0;
    }
}
