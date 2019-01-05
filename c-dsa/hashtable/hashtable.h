/**
 * Implementation of hashtable using linear probing
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

typedef struct Item
{
    char *key; 
    int value; 
    bool is_sentinel;
} _item_t; 

typedef struct HashTable
{
    _item_t **items;
    int size; 
    int capacity;
} _hashtable_t; 

_hashtable_t *new_hashtable();
void print_table(_hashtable_t *table);
void destroy_hashtable(_hashtable_t *table);
float get_load_factor(_hashtable_t *table);
int hash(char *key, int m);
void add(_hashtable_t **table, char *key, int value);
bool exists(_hashtable_t *table, char *key);
int get(_hashtable_t *table, char *key);
int remove_key(_hashtable_t *table, char *key);

#endif 