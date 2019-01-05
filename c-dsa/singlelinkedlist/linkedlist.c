#include "linkedlist.h"

void print_list(_single_linklist_t *list)
{
    if (list == NULL || list->head == NULL) exit(EXIT_FAILURE); 
    _node_t *curr = list->head; 
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next; 
    }

    printf("\n");
}

_single_linklist_t *new_list()
{
    _single_linklist_t *list = malloc(sizeof(_single_linklist_t));
    list->size = 0; 
    list->head = NULL;
    return list;
}

static void delete_node(_node_t *node)
{
    node->next = NULL; 
    free(node);
} 

static _node_t *new_node(int data)
{
    _node_t *node = malloc(sizeof(_node_t));
    if (node != NULL)
    {
        node->next = NULL;
        node->data = data;
    }

    return node;
}

int size(_single_linklist_t *list)
{
    return list->size;
}

bool is_empty(_single_linklist_t *list)
{
    return list->size == 0; 
}

int value_at(_single_linklist_t *list, int index)
{
    if (index < 0 || index > list->size - 1)
        return -1;
    
    _node_t *curr = list->head;
    for (int i = 0; i < index; i++)
        curr = curr->next;
    
    return curr->data;
}

int front(_single_linklist_t *list)
{
    if (list->size == 0)
        return -1; 
    return list->head->data; 
}

int back(_single_linklist_t *list)
{
    if (list->size == 0)
        return -1; 
    return value_at(list, list->size - 1);
}

int value_n_from_end(_single_linklist_t *list, int n)
{
    if (n < 0 || n > list->size - 1)
        return -1;
    return value_at(list, list->size - 1 - n);
}

void insert(_single_linklist_t **list, int index, int value)
{
    if (index < 0 || index > (*list)->size)
        exit(EXIT_FAILURE);

    _node_t *node = new_node(value);

    if ((*list)->head == NULL && (*list)->size == 0)
    {
        (*list)->head = node; 
        (*list)->size++;
        return;  
    }

    if (index == 0)
    {
        node->next = (*list)->head; 
        (*list)->head = node; 
        (*list)->size++;
        return; 
    }

    _node_t *curr = (*list)->head;
    for (int i = 0; i < index - 1; i++)
        curr = curr->next; 
    node->next = curr->next;
    curr->next = node; 
    (*list)->size++;
}

void push_front(_single_linklist_t **list, int value)
{
    insert(list, 0, value);
}

void push_back(_single_linklist_t **list, int value)
{
    insert(list, (*list)->size, value);
}

int pop_back(_single_linklist_t **list)
{
    int val = value_at(*list, (*list)->size - 1);
    erase(list, (*list)->size - 1);
    return val; 
}

int pop_front(_single_linklist_t **list)
{
    int val = value_at(*list, 0);
    erase(list, 0);
    return val; 
}

void erase(_single_linklist_t **list, int index)
{
    if (index < 0 || index > (*list)->size - 1 || list == NULL || (*list)->size == 0)
        exit(EXIT_FAILURE);
        
    _node_t *prev = (*list)->head;
    _node_t *curr = (*list)->head; 
    int i = 0; 

    if (index == 0)
    {
        if (curr->next != NULL)
            (*list)->head = curr->next; 
        delete_node(curr);
        (*list)->size--;
        return;
    }  
    
    curr = curr->next; 
    while (i < index - 1)
    {
        prev = curr; 
        curr = curr->next; 
        i++; 
    }
    
    if (curr->next == NULL)
        prev->next = NULL;  
    else 
        prev->next = curr->next;

    delete_node(curr);
    (*list)->size--;
}

void remove_value(_single_linklist_t **list, int value)
{
    if ((*list)->head == NULL || (*list)->size == 0)
        exit(EXIT_FAILURE);
    
    _node_t *curr = (*list)->head;
    _node_t **prev = &(*list)->head;

    while (curr != NULL)
    {
        if (curr->data == value)
        {
            if (curr->next != NULL)
                *prev = curr->next;
            delete_node(curr);
            (*list)->size--;
            return;
        }

        prev = &curr->next;
        curr = curr->next; 
    }
}

void reverse(_single_linklist_t **list)
{
    if ((*list)->head == NULL || list == NULL || *list == NULL || (*list)->size == 0)
        exit(EXIT_FAILURE);
    if ((*list)->size == 1)
        return;
    
    _node_t *prev = (*list)->head; 
    _node_t *curr = prev->next;
    prev->next = NULL;
    
    while (curr->next != NULL)
    {
        _node_t *next = curr->next; 
        curr->next = prev;
        prev = curr; 
        curr = next;
    }

    curr->next = prev;
    (*list)->head = curr;
}