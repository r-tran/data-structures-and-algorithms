#include "linkedqueue.h"

bool is_empty(_linked_queue_t *queue)
{
    return queue->size == 0;    
}

int get_size(_linked_queue_t *queue)
{
    return queue->size;
}

int get_front(_linked_queue_t *queue)
{
    if (queue->size == 0)
        exit(EXIT_FAILURE);
    return queue->head->data;
}

void enqueue(_linked_queue_t **queue, int element)
{
    _node_t *node = new_node(element);
    if (is_empty(*queue))
        (*queue)->head = node;
    else    
        (*queue)->tail->next = node;
    (*queue)->tail = node; 
    (*queue)->size++;
}

int dequeue(_linked_queue_t **queue)
{
    if (is_empty(*queue))
        exit(EXIT_FAILURE);

    int val = (*queue)->head->data;

    _node_t *node = (*queue)->head->next;
    delete_node((*queue)->head);
    (*queue)->head = node; 

    if ((*queue)->head == NULL)
        (*queue)->tail = NULL;
    (*queue)->size--;
    return val;
}

void print_queue(_linked_queue_t *queue)
{
    if (is_empty(queue))
        exit(EXIT_FAILURE);
    _node_t *curr = queue->head; 
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

_linked_queue_t *new_queue(void)
{
    _linked_queue_t *q = malloc(sizeof(_linked_queue_t));
    q->size = 0; 
    q->head = NULL;
    q->tail = NULL;
    return q;
}

_node_t *new_node(int element)
{
    _node_t *node = malloc(sizeof(_node_t));
    node->data = element;
    node->next = NULL;
    return node;
}

void delete_node(_node_t *node)
{
    node->next = NULL; 
    node->data = 0;
    free(node);
}
