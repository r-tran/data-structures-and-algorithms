#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>
#include <stdio.h>

static const int minCapacity = 16;
static const int growthFactor = 2;
static const int shrinkFactor = 4;

typedef struct array
{
    int size; 
    int *data;     
    int capacity; 
} _array_t; 

void print_array(_array_t *arr);
_array_t *new_array(int capacity);
int get_size(_array_t *arr);
int get_capacity(_array_t *arr); 
bool is_empty(_array_t *arr);
int at(_array_t *arr, int index);
void push_back(_array_t *arr, int item);
void insert(_array_t *arr, int index, int item);
void prepend(_array_t *arr, int item);
int pop(_array_t *arr);
void delete_index(_array_t *arr, int index);
void remove_element(_array_t *arr, int item);
int find(_array_t *arr, int item); 
#endif