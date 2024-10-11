#include "queue.h"

Queue_t* queue_create(int capacity){
    Queue_t *queue = (Queue_t *)malloc(sizeof(Queue_t));
    if(!queue) return NULL;

    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = (Element_t *)malloc(queue->capacity * sizeof(Element_t));

    if(!queue->data){
        free(queue);
        return NULL;
    }

    return queue;
}

int queue_delete(Queue_t *queue){
    if (!queue) return -1;
    free(queue->data);
    free(queue);

    return 0;
}

int queue_full(Queue_t *queue) {
    if (!queue) return -1;

    return queue->size == queue->capacity;
}

int queue_empty(Queue_t *queue){
    if(!queue) return -1;

    return queue->size == 0;
}

int queue_enqueue(Queue_t *queue, Element_t item){
    if(!queue || queue_full(queue)) return -1;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size += 1;

    return 0;
}

Element_t queue_dequeue(Queue_t *queue){
    Element_t invalid_element = { -1 };
    
    if(!queue || queue_empty(queue)) return invalid_element;

    Element_t item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size -= 1;

    return item;
}

Element_t queue_front(Queue_t *queue){
    Element_t invalid_element = { -1 };

    if(!queue || queue_empty(queue)) return invalid_element;

    return queue->data[queue->front];
}

Element_t queue_rear(Queue_t *queue){
    Element_t invalid_element = { -1 };

    if(!queue || queue_empty(queue)) return invalid_element;

    return queue->data[queue->rear];
}
