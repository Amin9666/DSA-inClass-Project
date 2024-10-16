
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* create_node(void* data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

LinkedList* create_list() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (!list) {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void add_top(LinkedList* list, void* data) {
    Node* new_node = create_node(data);
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void add_tail(LinkedList* list, void* data) {
    Node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    list->size++;
}

void add_before(int pos, LinkedList* list, void* data) {
    if (pos < 1 || pos > list->size) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        add_top(list, data);
        return;
    }

    Node* new_node = create_node(data);
    Node* temp = list->head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    list->size++;
}

// Add a node after a given position
void add_after(int pos, LinkedList* list, void* data) {
    if (pos < 1 || pos > list->size) {
        printf("Invalid position!\n");
        return;
    }

    Node* new_node = create_node(data);
    Node* temp = list->head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    list->size++;
}

void delete_node(int pos, LinkedList* list) {
    if (pos < 1 || pos > list->size) {
        printf("Invalid position!\n");
        return;
    }

    Node* temp = list->head;
    if (pos == 1) {
        list->head = temp->next;
        free(temp);
    } else {
        Node* prev = NULL;
        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
    list->size--;
}

void update_node(int pos, LinkedList* list, void* data) {
    if (pos < 1 || pos > list->size) {
        printf("Invalid position!\n");
        return;
    }

    Node* temp = list->head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }
    temp->data = data;
}

void display_list(LinkedList* list, void (*print_func)(void*)) {
    Node* temp = list->head;
    while (temp != NULL) {
        print_func(temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void free_list(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);
}