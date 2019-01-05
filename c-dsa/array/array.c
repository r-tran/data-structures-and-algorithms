#include "array.h"
#include "stdlib.h"

void print_array(_array_t *arr)
{   printf("arr: ");
    for (int i = 0; i < arr->capacity; i++)
        printf("%d ", *(arr->data + i));
    printf("\n");
}

_array_t *new_array(int capacity)
{
    _array_t *arr = malloc(sizeof(_array_t));

    int trueCapacity = minCapacity;
    while (trueCapacity < capacity)
        trueCapacity *= growthFactor;

    arr->data = malloc(sizeof(int) * trueCapacity);
    arr->size = 0; 
    arr->capacity = trueCapacity;
    return arr;
}

static void resize_up(_array_t *arr)
{
    arr->capacity *= 2; 
    int *newarr = malloc(sizeof(int) * arr->capacity);

    for (int i = 0; i < arr->capacity / 2; i++)
       *(newarr + i) = *(arr->data + i);

    free(arr->data);
    arr->data = newarr;
}

static void resize_down(_array_t *arr)
{
    if (arr->capacity <= minCapacity)
        return;

    arr->capacity = arr->capacity / 2;
    int *newarr = malloc(sizeof(int) * arr->capacity);
    
    for (int i = 0; i < arr->size; i++)
        *(newarr + i)= *(arr->data + i);
    
    free(arr->data);
    arr->data = newarr;
}

int get_size(_array_t *arr)
{
    return arr->size; 
}

int get_capacity(_array_t *arr)
{
    return arr->capacity;
}

bool is_empty(_array_t *arr)
{
    for (int i = 0; i < arr->capacity; i++)
    {
        if (*(arr->data + i) != 0)
            return false;
    }

    if (arr->size != 0)
        return false;
    return true;
}

int at(_array_t *arr, int index)
{
    if (index < 0)
        exit(EXIT_FAILURE);
    
    return *(arr->data + index); 
}

void push_back(_array_t *arr, int item)
{
    if (arr->size == arr->capacity)
        resize_up(arr);

   *(arr->data + arr->size) = item; 
   ++(arr->size);
}

void insert(_array_t *arr, int index, int item)
{
    if (index < 0 || index > arr->size - 1)
        exit(EXIT_FAILURE);

    if (arr->size == arr->capacity)
        resize_up(arr);
    
    for (int i = arr->size - 1; i >= index; i--)
    {
        *(arr->data + i + 1) = *(arr->data + i);
    }
    
    *(arr->data + index) = item; 
    ++arr->size;
}

void prepend(_array_t *arr, int item)
{
    insert(arr, 0, item);    
}

int pop(_array_t *arr)
{
    int val = *(arr->data + arr->size - 1);
    *(arr->data + arr->size - 1) = 0;
    (arr->size)--;

    if ((arr->capacity / shrinkFactor) == arr->size)
        resize_down(arr);
    return val;
}

void delete_index(_array_t *arr, int index)
{
    if (index < 0 || index >= arr->size)
        exit(EXIT_FAILURE);

    for (int i = index; i < arr->size - 1; i++)
        *(arr->data + i) = *(arr->data + i + 1);
    *(arr->data + arr->size - 1) = 0;
    arr->size--;

    if (arr->capacity / shrinkFactor == arr->size)
        resize_down(arr);
}

void remove_element(_array_t *arr, int item)
{
    for (int i = 0; i < arr->size; i++)
    {
        if (*(arr->data + i) == item)
        {
            delete_index(arr, i);
            i--;
        }
    }

    if (arr->capacity / shrinkFactor == arr->size)
        resize_down(arr);
}

int find(_array_t *arr, int item)
{
    for (int i = 0; i < arr->size; i++)
    {
        if ( *(arr->data + i) == item)
            return i;
    }

    return -1;
}