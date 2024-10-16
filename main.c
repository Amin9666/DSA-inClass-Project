#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

// Function to print strings (used with display_list)
void print_string(void* data) {
    printf("%s ", (char*)data);
}

// Function to print integers (used with display_list)
void print_int(void* data) {
    printf("%d ", *(int*)data);
}

int main() {
    // Create list L1 (list of words)
    LinkedList* L1 = create_list();
    LinkedList* L2 = create_list();

    int choice, num, pos;
    char word[100];
    
    // Input words into L1
    printf("Enter words for L1 (type 'stop' to end): \n");
    while (1) {
        printf("Enter a word: ");
        scanf("%s", word);
        if (strcmp(word, "stop") == 0) {
            break;
        }
        add_tail(L1, strdup(word));  // Add a copy of the word to the list
    }

    // Input integers into L2
    printf("\nEnter integers for L2 (type -1 to end): \n");
    while (1) {
        printf("Enter a number: ");
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        int* pnum = malloc(sizeof(int));
        *pnum = num;
        add_tail(L2, pnum);  // Add the integer to the list
    }

    // Test functions on L1 (words)
    printf("\nTesting linked list L1 (words):\n");
    printf("Enter position to add a word after: ");
    scanf("%d", &pos);
    printf("Enter word to add after position %d: ", pos);
    scanf("%s", word);
    add_after(pos, L1, strdup(word));

    printf("Enter position to add a word before: ");
    scanf("%d", &pos);
    printf("Enter word to add before position %d: ", pos);
    scanf("%s", word);
    add_before(pos, L1, strdup(word));

    printf("Enter position of word to delete: ");
    scanf("%d", &pos);
    delete_node(pos, L1);

    // Display L1
    printf("\nList L1 (words): ");
    display_list(L1, print_string);

    // Test functions on L2 (integers)
    printf("\nTesting linked list L2 (integers):\n");
    printf("Enter position to add a number after: ");
    scanf("%d", &pos);
    printf("Enter number to add after position %d: ", pos);
    scanf("%d", &num);
    int* pnum = malloc(sizeof(int));
    *pnum = num;
    add_after(pos, L2, pnum);

    printf("Enter position to add a number before: ");
    scanf("%d", &pos);
    printf("Enter number to add before position %d: ", pos);
    scanf("%d", &num);
    pnum = malloc(sizeof(int));
    *pnum = num;
    add_before(pos, L2, pnum);

    printf("Enter position of number to delete: ");
    scanf("%d", &pos);
    delete_node(pos, L2);

    // Display L2
    printf("\nList L2 (integers): ");
    display_list(L2, print_int);

    // Free both lists
    free_list(L1);
    free_list(L2);

    return 0;
}