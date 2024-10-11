#include "array.h"

Array_t* array_create(size_t initial_capacity){
  Array_t* array = (Array_t*)malloc(sizeof(Array_t));

  if(!array) return NULL;

  array->element = (Element_t*)malloc(initial_capacity * sizeof(Element_t));
  if(!array->element){
      free(array);

      return NULL;
  }
  array->size = 0;
  array->capacity = initial_capacity;

  return array;
}

int array_delete(Array_t* array){
  if(array){
    free(array->element);
    free(array);

    return 0;
  }

  return -1;
}

int array_add_element(Array_t* array, Element_t element){
  if(array->size >= array->capacity){
    size_t new_capacity = array->capacity * 2;
    Element_t* new_data = (Element_t*)realloc(array->element, new_capacity * sizeof(Element_t));

    if(!new_data) return -1;

    array->element = new_data;
    array->capacity = new_capacity;
  }
  array->element[array->size++] = element;

  return 0;
}

int array_remove_by_value(Array_t* array, Element_t element){
  for(size_t i = 0; i < array->size; i++){
    if(array->element[i].element == element.element){
      return array_remove_by_index(array, i);
    }
  }
  
  return -1;
}

int array_remove_by_index(Array_t* array, size_t index){
  if(index >= array->size) return -1;

  for(size_t i = index; i < array->size - 1; i++){
    array->element[i] = array->element[i + 1];
  }
  array->size--;

  return 0;
}

int array_update_element(Array_t* array, size_t index, Element_t element){
  if(index >= array->size) return -1;

  array->element[index] = element;
  return 0;
}

int array_search_by_value(Array_t* array, Element_t element){
  for(size_t i = 0; i < array->size; i++){
    if(array->element[i].element == element.element){
      return 0;
    }
  }

  return -1;
}

int array_search_by_index(Array_t* array, size_t index){
  if(index < array->size){
    return 0;
  }

  return -1;
}

int array_print(Array_t* array) {
  if(!array || array->size == 0) return -1;

  for(size_t i = 0; i < array->size; i++){
      printf("%d ", array->element[i].element);
  }
  printf("\n");

  return 0;
}
