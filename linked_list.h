// linked_list.h

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Define the structure for a linked list node
typedef struct Node {
    void* data;  // Store generic data (use void pointer for generality)
    struct Node* next;
} Node;

// Define the structure for a linked list
typedef struct {
    Node* head;  // Points to the first node in the list
    int size;    // Keeps track of the number of nodes
} LinkedList;

// Function declarations
LinkedList* create_list();  // Create a new empty list
void add_top(LinkedList* list, void* data);
void add_tail(LinkedList* list, void* data);
void add_before(int pos, LinkedList* list, void* data);
void add_after(int pos, LinkedList* list, void* data);
void delete_node(int pos, LinkedList* list);
void update_node(int pos, LinkedList* list, void* data);
void display_list(LinkedList* list, void (*print_func)(void*));
void free_list(LinkedList* list);

#endif