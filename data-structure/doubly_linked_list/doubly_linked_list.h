/**
 * @file doubly_linked_list.h
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
 * @brief Struct Note_t that holds previous element, next element, element
 * 
 */
typedef struct _node {
    struct _node *prev;
    struct _node *next;
    Element_t element; // You can change the type if needed
} Node_t;

/**
 * @author Gustavo Ferreira Vieira
 * @brief Struct Doubly_linked_list_t that holds head, tail, size
 * 
 */
typedef struct _doubly_linked_list {
    Node_t *head;
    Node_t *tail;
    size_t size;
} Doubly_linked_list_t;

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to create a doubly linked list
 * 
 * @return Doubly_linked_list_t* 
 */
Doubly_linked_list_t *dlinked_list_create();

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to delete a doubly linked list
 * 
 * @param list List to be deleted
 * @return int 0 if success, -1 if error
 */
int dlinked_list_delete(Doubly_linked_list_t *list);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to insert an item at the end of a doubly linked list
 * 
 * @param list List to insert the item into
 * @param element Item to be inserted
 * @return int 0 if success, -1 if error
 */
int dlinked_list_insert_at_end(Doubly_linked_list_t *list, Element_t element);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to insert an item at the beginning of a doubly linked list
 * 
 * @param list List to insert the item into
 * @param element Item to be inserted
 * @return int 0 if success, -1 if error
 */
int dlinked_list_insert_at_beginning(Doubly_linked_list_t *list, Element_t element);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to insert an item at a given index of a doubly linked list
 * 
 * @param list List to insert the item into
 * @param element Item to be inserted
 * @param index Where to insert the item
 * @return int 0 if success, -1 if error
 */
int dlinked_list_insert_at_index(Doubly_linked_list_t *list, Element_t element, size_t index);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to remove an item from a doubly linked list by its value
 * 
 * @param list List to delete the item from
 * @param element Item to delete
 * @return int 0 if success, -1 if error
 */
int dlinked_list_remove_by_value(Doubly_linked_list_t *list, Element_t element);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to remove an item from a doubly linked list by its index
 * 
 * @param list List to delete the item from
 * @param index Index of item to delete
 * @return int 0 if success, -1 if error
 */
int dlinked_list_remove_by_index(Doubly_linked_list_t *list, size_t index);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to search an item by its value
 * 
 * @param list List to search the item from
 * @param element Item to search for
 * @return Node_t* 
 */
Node_t *dlinked_list_search_by_value(Doubly_linked_list_t *list, Element_t element);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to search an item by its index
 * 
 * @param list List to search the item from
 * @param index Index of the item to search for
 * @return Node_t* 
 */
Node_t *dlinked_list_search_by_index(Doubly_linked_list_t *list, size_t index);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to update an item's value
 * 
 * @param list Item's list
 * @param index Item's index
 * @param new_value Item's new value
 * @return int 0 if success, -1 if error
 */
int dlinked_list_update_value(Doubly_linked_list_t *list, size_t index, Element_t new_element);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to alter an item's index
 * 
 * @param list Item's list
 * @param old_index Item's old index
 * @param new_index Item's new index
 * @return int 0 if success, -1 if error
 */
int dlinked_list_alter_index(Doubly_linked_list_t *list, size_t old_index, size_t new_index);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to output doubly linked list values
 * 
 * @param list List to be outputed
 * @return int 0 if success, -1 if error
 */
int dlinked_list_print(Doubly_linked_list_t *list);
