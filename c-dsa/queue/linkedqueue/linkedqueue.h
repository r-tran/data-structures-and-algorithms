#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct Node
{
    struct Node *next;
    int data;
} _node_t;

typedef struct LinkedQueue
{
    _node_t *head; 
    _node_t *tail;
    int size;
} _linked_queue_t; 


_linked_queue_t *new_queue(void);
_node_t *new_node(int element);
void delete_node(_node_t *node);


void print_queue(_linked_queue_t *queue);
bool is_empty(_linked_queue_t *queue);
int get_size(_linked_queue_t *queue);
int get_front(_linked_queue_t *queue);
void enqueue(_linked_queue_t **queue, int element);
int dequeue(_linked_queue_t **queue);
#endif