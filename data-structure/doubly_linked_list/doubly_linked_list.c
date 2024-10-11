#include <stdio.h>
#include <stdlib.h>

#include "doubly_linked_list.h"

Doubly_linked_list_t *dlinked_list_create(){
    Doubly_linked_list_t *list = (Doubly_linked_list_t *)malloc(sizeof(Doubly_linked_list_t));
    if(!list) return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

int dlinked_list_delete(Doubly_linked_list_t *list){
    if(!list) return -1;

    Node_t *current = list->head;
    Node_t *next;

    while(current){
        next = current->next;
        free(current);
        current = next;
    }

    free(list);

    return 0;
}

int dlinked_list_insert_at_end(Doubly_linked_list_t *list, Element_t element){
    if(!list) return -1;

    Node_t *new_node = (Node_t *)malloc(sizeof(Node_t));
    if(!new_node) return -1;

    new_node->element = element;
    new_node->next = NULL;

    if(list->size == 0){
        new_node->prev = NULL;
        list->head = new_node;
        list->tail = new_node;
    }else{
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;

    return 0;
}

int dlinked_list_insert_at_beginning(Doubly_linked_list_t *list, Element_t element){
    if(!list) return -1;

    Node_t *new_node = (Node_t *)malloc(sizeof(Node_t));
    if(!new_node) return -1;

    new_node->element = element;
    new_node->prev = NULL;

    if(list->size == 0){
        new_node->next = NULL;
        list->head = new_node;
        list->tail = new_node;
    }else{
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }

    list->size++;

    return 0;
}

int dlinked_list_insert_at_index(Doubly_linked_list_t *list, Element_t element, size_t index){
    if(!list || index > list->size) return -1;

    if(index == 0){
        return dlinked_list_insert_at_beginning(list, element);
    }else if(index == list->size){
        return dlinked_list_insert_at_end(list, element);
    }

    Node_t *new_node = (Node_t *)malloc(sizeof(Node_t));
    if(!new_node) return -1;

    new_node->element = element;
    Node_t *current = list->head;

    for(size_t i = 0; i < index; i++){
        current = current->next;
    }

    new_node->prev = current->prev;
    new_node->next = current;
    current->prev->next = new_node;
    current->prev = new_node;

    list->size++;

    return 0;
}

int dlinked_list_remove_by_value(Doubly_linked_list_t *list, Element_t element){
    if(!list || list->size == 0) return -1;

    Node_t *current = list->head;

    while(current){
        if(current->element.element == element.element){
            if(current->prev){
                current->prev->next = current->next;
            }else{
                list->head = current->next;
            }

            if(current->next){
                current->next->prev = current->prev;
            }else{
                list->tail = current->prev;
            }

            free(current);
            list->size--;

            return 0;
        }
        current = current->next;
    }
    return -1;
}

int dlinked_list_remove_by_index(Doubly_linked_list_t *list, size_t index){
    if(!list || index >= list->size) return -1;

    Node_t *current = list->head;

    for(size_t i = 0; i < index; i++){
        current = current->next;
    }

    if(current->prev){
        current->prev->next = current->next;
    }else{
        list->head = current->next;
    }

    if(current->next){
        current->next->prev = current->prev;
    }else{
        list->tail = current->prev;
    }

    free(current);
    list->size--;

    return 0;
}

Node_t *dlinked_list_search_by_value(Doubly_linked_list_t *list, Element_t element){
    if(!list) return NULL;

    Node_t *current = list->head;

    while(current){
        if(current->element.element == element.element){
            return current;
        }
        current = current->next;
    }

    return NULL;
}

Node_t *dlinked_list_search_by_index(Doubly_linked_list_t *list, size_t index){
    if(!list || index >= list->size) return NULL;

    Node_t *current = list->head;

    for(size_t i = 0; i < index; i++){
        current = current->next;
    }

    if(!current) return NULL;

    return current;
}

int dlinked_list_update_value(Doubly_linked_list_t *list, size_t index, Element_t new_element){
    if(!list || index >= list->size) return -1;

    Node_t *current = list->head;

    for(size_t i = 0; i < index; i++){
        current = current->next;
    }

    current->element = new_element;

    return 0;
}

int dlinked_list_alter_index(Doubly_linked_list_t *list, size_t old_index, size_t new_index){
    if(!list || old_index >= list->size || new_index >= list->size) return -1;

    Node_t *current = dlinked_list_search_by_index(list, old_index);
    if(!current) return -1;

    dlinked_list_remove_by_index(list, old_index);

    return dlinked_list_insert_at_index(list, current->element, new_index);
}

int dlinked_list_print(Doubly_linked_list_t *list){
    if(!list) return -1;

    Node_t *current = list->head;

    while(current){
        printf("%d ", current->element.element);
        current = current->next;
    }
    printf("\n");

    return 0;
}
