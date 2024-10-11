/**
 * @file queue.h
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
 * @brief Struct Queue_t that holds data, front, rear, capacity, size
 * 
 */
typedef struct _queue {
    Element_t *data;
    int front;
    int rear;
    int capacity;
    int size;
} Queue_t;

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to create a queue
 * 
 * @param capacity Queue's capacity
 * @return Queue_t* 
 */
Queue_t* queue_create(int capacity);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to delete a queue
 * 
 * @param queue Queue to be deleted
 * @return int 0 if success, -1 if error
 */
int queue_delete(Queue_t *queue);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to check if the queue is full
 * 
 * @param queue Queue to be checked
 * @return int 0 if success, -1 if error
 */
int queue_full(Queue_t *queue);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to check if the queue is empty
 * 
 * @param queue Queue to be checked
 * @return int 0 if success, -1 if error
 */
int queue_empty(Queue_t *queue);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to add an item to the rear of the queue
 * 
 * @param queue Queue to add the item into
 * @param item Item to be added
 * @return int 0 if success, -1 if error
 */
int queue_enqueue(Queue_t *queue, Element_t item);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to take an item out a queue
 * 
 * @param queue Queue to have its item enqueued
 * @return Element_t 
 */
Element_t queue_dequeue(Queue_t *queue);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to get the front of a queue without removing it
 * 
 * @param queue Queue to get the front from
 * @return Element_t 
 */
Element_t queue_front(Queue_t *queue);

/**
 * @author Gustavo Ferreira Vieira
 * @brief Function to get the rear of a queue without removing it
 * 
 * @param queue Queue to get the rear from
 * @return Element_t 
 */
Element_t queue_rear(Queue_t *queue);
