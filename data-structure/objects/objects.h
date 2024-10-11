typedef struct _element_object{
  Element_object_t* previous;
  Element_t element;
  Element_object_t* next;
} Element_object_t;

typedef struct _doubly_linked_list{
  Element_object_t* head;
  size_t size;
} Doubly_linked_list_t;