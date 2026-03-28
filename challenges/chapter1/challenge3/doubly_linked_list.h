#ifndef __DLL_H__
#define __DLL_H__

#include <stdlib.h>

typedef enum {
    DLL_FRONT = 0,
    DLL_BACK = 1,
} dll_position;

typedef struct list_node {
    struct list_node* next;
    struct list_node* prev;
    char* val;
} list_node;

list_node* dll_create_list_node(const char* value);
int dll_insert(list_node** head, list_node* node, dll_position pos);
int dll_delete(list_node** head, const char* value);
list_node* dll_find(list_node* head, const char* value);
void dll_print_list(list_node* head);
void dll_free(list_node** head);

#endif // __DLL_H__