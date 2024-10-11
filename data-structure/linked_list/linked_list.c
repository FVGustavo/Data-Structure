#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

Linked_list_t* linked_list_create(){
    Linked_list_t* list = (Linked_list_t*)malloc(sizeof(Linked_list_t));
    if(!list) return NULL;
    list->head = NULL;
    list->size = 0;

    return list;
}

int linked_list_delete(Linked_list_t* list){
    if(!list) return -1;

    Node_t* current = list->head;
    Node_t* next;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    free(list);

    return 0;
}

int linked_list_insert_at_end(Linked_list_t* list, Element_t value){
    Node_t* new_node = (Node_t*)malloc(sizeof(Node_t));
    if(!new_node) return -1;

    new_node->element = value;
    new_node->next = NULL;

    if(list->head == NULL){
        list->head = new_node;
    }else{
        Node_t* current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
    }
    list->size++;

    return 0;
}

int linked_list_insert_at_beginning(Linked_list_t* list, Element_t value){
    Node_t* new_node = (Node_t*)malloc(sizeof(Node_t));
    if(!new_node) return -1;

    new_node->element = value;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;

    return 0;
}

int linked_list_remove_node(Linked_list_t* list, Element_t value){
    Node_t* current = list->head;
    Node_t* previous = NULL;

    while(current != NULL && current->element.element != value.element){
        previous = current;
        current = current->next;
    }

    if(current == NULL) return -1;

    if(previous == NULL){
        list->head = current->next;
    }else{
        previous->next = current->next;
    }
    free(current);
    list->size--;

    return 0;
}

Node_t* linked_list_search_by_value(Linked_list_t* list, Element_t value){
    Node_t* current = list->head;
    while(current != NULL){
        if(current->element.element == value.element){
            return current;
        }
        current = current->next;
    }

    return NULL;
}

Node_t* linked_list_search_by_index(Linked_list_t* list, size_t index) {
    if(index >= list->size) return NULL;

    Node_t* current = list->head;
    for(size_t i = 0; i < index; i++){
        current = current->next;
    }

    return current;
}

int linked_list_update_value(Linked_list_t* list, size_t index, Element_t new_value){
    Node_t* node = linked_list_search_by_index(list, index);
    if(node != NULL) {
        node->element = new_value;
        return 0;
    }

    return -1;
}

int linked_list_update_index(Linked_list_t* list, size_t old_index, size_t new_index){
    if(old_index >= list->size || new_index >= list->size) return -1;

    Node_t* node = linked_list_search_by_index(list, old_index);
    if(node == NULL) return -1;

    linked_list_remove_node(list, node->element);
    if(new_index == 0) {
        linked_list_insert_at_beginning(list, node->element);
    }else{
        Node_t* current = list->head;
        for(size_t i = 0; i < new_index - 1; i++){
            current = current->next;
        }
        Node_t* temp = current->next;
        current->next = node;
        node->next = temp;
    }
    return 0;
}

void linked_list_print(Linked_list_t* list){
    Node_t* current = list->head;
    while(current != NULL){
        printf("%d ", current->element.element);
        current = current->next;
    }
    printf("\n");
}
