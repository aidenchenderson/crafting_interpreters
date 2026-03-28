#include <stdio.h>

#include "doubly_linked_list.h"

int main() {
    // initialize some test nodes
    list_node* n1 = dll_create_list_node("Node 1");
    list_node* n2 = dll_create_list_node("Node 2");
    list_node* n3 = dll_create_list_node("Node 3");

    // reference to linked list start
    list_node** head_ref = &n1;

    dll_insert(head_ref, n2, DLL_BACK);
    dll_insert(head_ref, n3, DLL_FRONT);

    // show the current head of the linked list
    char* curr_head = (*head_ref)->val;
    printf("Current head: %s\n", curr_head);

    dll_print_list(n3);

    dll_find(n3, "Node 2");

    dll_delete(head_ref, "Node 1");
    dll_print_list(n3);

    return 0;
}