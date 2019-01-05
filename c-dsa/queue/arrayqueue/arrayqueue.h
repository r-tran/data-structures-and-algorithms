#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
    int* data; 
    int first;
    int size; 
    int capacity; 
} _array_queue_t; 

_array_queue_t *new_arrayqueue();
void print_queue(_array_queue_t *queue);
bool is_empty(_array_queue_t *queue);
bool is_full(_array_queue_t *queue);
int get_size(_array_queue_t *queue);
int get_front(_array_queue_t *queue);
void enqueue(_array_queue_t **queue, int item);
int dequeue(_array_queue_t **queue);

#endif