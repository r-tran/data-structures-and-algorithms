#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    struct Node *next; 
    int data; 
} _node_t;

typedef struct SingleLinkedList
{
    _node_t *head; 
    int size; 
} _single_linklist_t; 

void print_list(_single_linklist_t *list);
_single_linklist_t *new_list();
int size(_single_linklist_t *list);
bool is_empty(_single_linklist_t *list);
int value_at(_single_linklist_t *list, int index);
void push_front(_single_linklist_t **list, int value);
int pop_front(_single_linklist_t **list);
void push_back(_single_linklist_t **list, int value);
int pop_back(_single_linklist_t **list);
int front(_single_linklist_t *list);
int back(_single_linklist_t *list);
void insert(_single_linklist_t **list, int index, int value);
void erase(_single_linklist_t **list,int index);
int value_n_from_end(_single_linklist_t *list,int n);
void reverse(_single_linklist_t **list);
void remove_value(_single_linklist_t **list,int value);
#endif