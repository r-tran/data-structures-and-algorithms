#ifndef BST_H
#define BST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node
{
    struct Node *left; 
    struct Node *right;
    int data; 
} _node_t; 

_node_t *new_node(int value);
void insert(_node_t **root, int data);
int get_node_count(_node_t *root);
void print_values(_node_t *root);
void delete_tree(_node_t **root);
bool is_in_tree(_node_t *root, int data);
int get_height(_node_t *root);
int get_min(_node_t *root);
int get_max(_node_t *root);
bool is_bst(_node_t *root);
void remove_value(_node_t **root, int value);
int get_successor(_node_t *root, int data);
int get_predecessor(_node_t *root, int data);

#endif