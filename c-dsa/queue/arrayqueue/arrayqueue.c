#include "arrayqueue.h"

static const int defaultCapacity = 16;
static const int shrinkFactor = 4;
static const int scaleFactor = 2; 

void print_queue(_array_queue_t *queue)
{
    if (is_empty(queue))
        return;
    for (int i = 0; i < queue->size; i++)
    {
        int idx = (queue->first + i) % queue->capacity;
        printf("%d ", *(queue->data + idx));
    }
    printf("\n");
}

void _resize(_array_queue_t **queue,int capacity)
{
    int *newdata = malloc(sizeof(int) * capacity);
    for (int i = 0; i < (*queue)->size; i++)
    {
        int idx = ((*queue)->first + i) % (*queue)->capacity;
        *(newdata + i) = *((*queue)->data + idx);
    }

    free((*queue)->data);
    (*queue)->data = newdata;
    (*queue)->capacity = capacity;
    (*queue)->first = 0;
}

_array_queue_t *new_arrayqueue()
{
    _array_queue_t *q = malloc(sizeof(_array_queue_t));
    q->capacity = defaultCapacity;
    q->data = malloc(sizeof(int) * q->capacity);
    q->first = 0;
    q->size = 0; 
    return q;
}

bool is_empty(_array_queue_t *queue)
{
    return queue->size == 0;
}

bool is_full(_array_queue_t *queue)
{
    return queue->capacity == queue->size;
}

int get_size(_array_queue_t *queue)
{
    return queue->size; 
}

int get_front(_array_queue_t *queue)
{
    if (is_empty(queue))
        exit(EXIT_FAILURE);
    return *(queue->data + queue->first);
}

void enqueue(_array_queue_t **queue, int item)
{
    if ((*queue)->size == (*queue)->capacity)
        _resize(queue,(*queue)->capacity * scaleFactor);
    int idx = ((*queue)->first + (*queue)->size) % (*queue)->capacity;
    *((*queue)->data + idx) = item; 
    (*queue)->size++;
}

int dequeue(_array_queue_t **queue)
{
    if (is_empty(*queue))
        exit(EXIT_FAILURE);
    int val = *((*queue)->data + (*queue)->first);
    *((*queue)->data + (*queue)->first) = 0;
    (*queue)->first = ((*queue)->first + 1) % (*queue)->capacity;
    (*queue)->size--;
    
    if ((*queue)->size > 0 && (*queue)->capacity / (*queue)->size >= shrinkFactor && ((*queue)->capacity > defaultCapacity))
        _resize(queue,(*queue)->capacity / scaleFactor);
    
        return val;
}
