/**
 * @file linked_list.h
 * @author Gustavo Ferreira Vieira (engenharia14@tkth.com.br)
 * @brief 
 * @version 0.1
 * @date 2024-10-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stddef.h>

#include "../element/element.h"

/**
 * @author Gustavo Ferreira Vieira
 * @brief Struct Node_t that holds: element, next
 * 
 */
typedef struct _node {
    Element_t element;
    struct _node* next;
} Node_t;

/**
 * @author Gustavo Ferreira Vieira
 * @brief Struct Linked_list_t that holds: head, size
 * 
 */
typedef struct _linked_list {
    Node_t* head;
    size_t size;
} Linked_list_t;

/**
 * @author Gustavo Ferreira Vieira
 * @brief Create a list object
 * 
 * @return Linked_list_t* 
 */
Linked_list_t* linked_list_create();

/**
 * @author Gustavo Ferreira Vieira
 * @brief Deletes a list object
 * 
 * @param list List to be deleted
 * @return int 0 if success, -1 if error
 */
int linked_list_delete(Linked_list_t* list);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to insert an item at the end of the list
 * 
 * @param list List to insert the item into
 * @param value Item to be inserted
 * @return int 0 if success, -1 if error 
 */
int linked_list_insert_at_end(Linked_list_t* list, Element_t value);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to insert an item at the beginning of the list
 * 
 * @param list List to insert the item into
 * @param value Item to be inserted
 * @return int 0 if success, -1 if error 
 */
int linked_list_insert_at_beginning(Linked_list_t* list, Element_t value);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to remove node from the list
 * 
 * @param list List to delete node from
 * @param value Node to be deleted
 * @return int 0 if success, -1 if error
 */
int linked_list_remove_node(Linked_list_t* list, Element_t value);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to search an item by its value
 * 
 * @param list List to search the item from
 * @param value Item to search for
 * @return Node_t* 
 */
Node_t* linked_list_search_by_value(Linked_list_t* list, Element_t value);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to search an item by its index
 * 
 * @param list List to search the item from
 * @param index Item index to search for
 * @return Node_t* 
 */
Node_t* linked_list_search_by_index(Linked_list_t* list, size_t index);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to update the value of an item
 * 
 * @param list List where the item to be updated is 
 * @param index Index of the item to be updated
 * @param new_value New value of the item
 * @return int 0 if success, -1 if error
 */
int linked_list_update_value(Linked_list_t* list, size_t index, Element_t new_value);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to update the index/position of an item
 * 
 * @param list List where the item to be updated is 
 * @param index Index of the item to be updated
 * @param new_index New index of the item
 * @return int 0 if success, -1 if error
 */
int linked_list_update_index(Linked_list_t* list, size_t old_index, size_t new_index);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to output all the values of the list
 * 
 * @param list List to be outputted
 */
void linked_list_print(Linked_list_t* list);
