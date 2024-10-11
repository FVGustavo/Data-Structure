/**
 * @file array.h
 * @author Gustavo Ferreira Vieira (engenharia14@tkth.com.br)
 * @brief 
 * @version 0.1
 * @date 2024-10-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#include "../element/element.h"

/**
 * @author Gustavo Ferreira Vieira
 * @brief Struct Array_t that holds element, size, capacity
 * 
 */
typedef struct _array {
    Element_t* element;
    size_t size;
    size_t capacity;
} Array_t;

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to create an array
 * 
 * @param initial_capacity Array's initial capacity
 * @return Array_t* 
 */
Array_t* array_create(size_t initial_capacity);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to delete an array
 * 
 * @param array Array to be deleted
 * @return 0 if success, -1 if error
 */
int array_delete(Array_t* array);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to add an element to an array
 * 
 * @param array Array where the element will be added
 * @param element Element to be added
 * @return int 0 if success, -1 if error
 */
int array_add_element(Array_t* array, Element_t element);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to remove an element of an array by its value
 * 
 * @param array Array where the element will be removed
 * @param element Element to be deleted
 * @return int 0 if success, -1 if error
 */
int array_remove_by_value(Array_t* array, Element_t element);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to remove an element of an array by its index
 * 
 * @param array Array where the element will be removed
 * @param index Index of the element to be deleted
 * @return int 0 if success, -1 if error
 */
int array_remove_by_index(Array_t* array, size_t index);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to update an element's value
 * 
 * @param array Array where the element will be updated
 * @param index Index of the element to be updated
 * @param element Element to update
 * @return int 0 if success, -1 if error
 */
int array_update_element(Array_t* array, size_t index, Element_t element);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to search an element by its value
 * 
 * @param array Array to search the item from
 * @param value Element to search for
 * @return int 0 if success, -1 if error
 */
int array_search_by_value(Array_t* array, Element_t element);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to search an element by its index
 * 
 * @param array Array to search the item from
 * @param index Index of the element to search for
 * @return int 0 if success, -1 if error
 */
int array_search_by_index(Array_t* array, size_t index);

/**
 * @brief Function to output the array's values
 * 
 * @param array Array to be outputed
 * @return int 0 if success, -1 if error
 */
int array_print(Array_t* array);
