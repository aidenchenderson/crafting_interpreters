#include <stdio.h>
#include <string.h>

#include "doubly_linked_list.h"


list_node* dll_create_list_node(const char* value) {
    list_node* node = malloc(sizeof(list_node));
    if (!node) {
        printf("Error creating list node: node memory allocation failed\n");
        return NULL;
    }

    if (!value) {
        free(node);
        printf("Error creating list node: invalid input value\n");
        return NULL;
    }

    node->val = malloc(strlen(value) + 1);
    if (!node->val) {
        printf("Error creating list node: value memory allocation failed\n");
        free(node);
        return NULL;
    }
    strcpy(node->val, value);

    node->next = NULL;
    node->prev = NULL;

    return node;
}


int dll_insert(list_node** head, list_node* input_node, dll_position pos) {
    if (!input_node) {
        printf("Error inserting list node: invalid input\n");
        return -1;
    }

    if (*head == NULL) { // handle empty list cases first
        *head = input_node;
        return 0;
    }

    else if (pos == DLL_FRONT) {
        input_node->next = *head;
        input_node->prev = NULL;

        (*head)->prev = input_node;
        
        *head = input_node;
        return 0;
    } 
    // NOTE: insertion at the end could be improved by keeping track of the index of the last node
    // for this exercise the runtime is negligible.
    else if (pos == DLL_BACK) {
        list_node* current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = input_node;
        input_node->prev = current;
        return 0;
    }
    else {
        printf("Error inserting list node: invalid position\n");
        return -1;
    }
}


int dll_delete(list_node** head, const char* value) {
    if (!value) {
        printf("Error deleting list node: invalid input value\n");
        return -1;
    }

   if (!head) {
        printf("Error deleting list node: invalid head pointer\n");
        return -1;
    }

    if (!*head) {
        printf("Error deleting list node: empty list\n");
        return -1;
    }

    list_node* current = *head;

    while (current) {
        if (strcmp(current->val, value) == 0) {
            // special case for deleting head
            if (current == *head) { 
                (*head) = (*head)->next;
                if (*head) {
                    (*head)->prev = NULL;
                }
            } else {
                // make neighboring nodes link to each other
                if (current->prev) {
                    current->prev->next = current->next;
                } 
                if (current->next) {
                    current->next->prev = current->prev;
                }
            }
            free(current->val);
            free(current);
            return 0;
        }
        current = current->next;
    }

    printf("Error deleting list node: not found\n");
    return -1;
}


list_node* dll_find(list_node* head, const char* value) {
    if (!value) {
        printf("Error finding list node: invalid input value\n");
        return NULL;
    }

    list_node* current = head;
    int i = 0;

    while (current) {
        if (strcmp(value, current->val) == 0) {
            printf("Node \"%s\" found at index %d\n", value, i);
            return current;
        }
        current = current->next;
        i++;
    }

    printf("Node not found\n");
    return NULL;
}


void dll_print_list(list_node* head) { // could also work with the head pointer
    list_node* current = head;
    int i = 0; // "index" the list while displaying it's members

    while (current) {
        printf("%d: %s\n", i, current->val);
        current = current->next;

        i++;
    }
}


void dll_free(list_node** head) {
    if (!head) {
        printf("Error deleting linked list: invalid head pointer");
        return;
    }

    list_node* current = *head;
    list_node* next;

    while (current) {
        next = current->next;
        free(current->val); // values are heap allocated so must be freed as well as the node itself
        free(current);
        current = next;
    }

    *head = NULL;
}