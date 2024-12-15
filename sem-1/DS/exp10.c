#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10 // Size of the hash table

// Structure for the linked list node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Hash table with chaining (array of linked lists)
Node *hashTable[TABLE_SIZE];

// Simple hash function (using modulo)
int hashFunction(int key)
{
    return key % TABLE_SIZE; // Index is key % table size
}

// Insert an element into the hash table
void insert(int key)
{
    int index = hashFunction(key);                // Find index
    Node *newNode = (Node *)malloc(sizeof(Node)); // Create a new node
    newNode->data = key;
    newNode->next = hashTable[index]; // Insert at the beginning of the linked list
    hashTable[index] = newNode;       // Update hash table
    printf("Inserted %d at index %d\n", key, index);
}

// Search for an element in the hash table
int search(int key)
{
    int index = hashFunction(key);    // Find index
    Node *current = hashTable[index]; // Traverse linked list at that index

    while (current != NULL)
    {
        if (current->data == key)
        {
            return 1; // Element found
        }
        current = current->next; // Move to next node
    }
    return 0; // Element not found
}

// Display the hash table contents
void display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Index %d: ", i);
        Node *current = hashTable[i];
        while (current != NULL)
        {
            printf("%d -> ", current->data);
            current = current->next; // Move to next node
        }
        printf("NULL\n");
    }
}

int main()
{
    // Initialize hash table with NULL values
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = NULL;
    }

    // Insert some elements
    insert(15);
    insert(25);
    insert(35);
    insert(5);
    insert(11);
    insert(21);

    // Display hash table after insertions
    printf("\nHash Table after insertions:\n");
    display();

    // Search for some elements
    int searchKey = 25;
    if (search(searchKey))
    {
        printf("\nElement %d found in the hash table.\n", searchKey);
    }
    else
    {
        printf("\nElement %d not found in the hash table.\n", searchKey);
    }

    searchKey = 50;
    if (search(searchKey))
    {
        printf("Element %d found in the hash table.\n", searchKey);
    }
    else
    {
        printf("Element %d not found in the hash table.\n", searchKey);
    }

    return 0;
}