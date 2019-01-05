#include "hashtable.h"

static const int defaultCapacity = 11; 
static const float maxLoad = 0.5;

bool available(_item_t *item)
{
    if (item == NULL || (item->is_sentinel && item->key == NULL))
        return true; 
    
    return false;
}

void print_table(_hashtable_t *table)
{
    printf("*************TABLE***************\n");
    for (int i = 0; i < table->capacity; i++)
    {
        if (table->items[i] != NULL && table->items[i]->key != NULL && table->items[i]->is_sentinel == false)
            printf("Key:%s Value:%d\n", table->items[i]->key, table->items[i]->value);
    }
    printf("**********************************\n");
}

void _resize_table(_hashtable_t **table, int new_capacity)
{
    printf("RESIZING*************************\n");
    _hashtable_t *newtable = new_hashtable();
    newtable->capacity = new_capacity;
    free(newtable->items);
    newtable->items = malloc(sizeof(_item_t) * new_capacity);

    for (int i = 0; i < (*table)->capacity; i++)
    {
        if (!available((*table)->items[i]))
            add(&newtable, (*table)->items[i]->key, (*table)->items[i]->value);
    }

    destroy_hashtable(*table);
    *table = newtable;
}

float get_load_factor(_hashtable_t *table)
{
    return (float) table->size / table->capacity;
}

_hashtable_t *new_hashtable()
{
    _hashtable_t *table = malloc(sizeof(_hashtable_t));
    table->size = 0; 
    table->capacity = defaultCapacity;
    table->items = malloc(sizeof(_item_t) * defaultCapacity);

    for (int i = 0; i < defaultCapacity; i++)
        table->items[i] = NULL;

    return table;
}

void destroy_hashtable(_hashtable_t *table)
{
    free(table->items);
    free(table);
}

_item_t *new_item(char *key, int value)
{
    _item_t *item = malloc(sizeof(_item_t));
    item->key = key; 
    item->value = value; 
    item->is_sentinel = false; 
    return item;
}

int hash(char *key, int m)
{
    int hash = 0; 
    for (int i = 0; i < strlen(key); i++)
        hash = (31 * hash + *(key + i)) % m;
    return hash;
}

void add(_hashtable_t **table, char *key, int value)
{
    int index = hash(key, (*table)->capacity);

    while (!available((*table)->items[index]))
    {
        if (strcmp((*table)->items[index]->key, key) == 0)
        {
            (*table)->items[index]->value = value; 
            return;
        }

        index = (index + 1) % (*table)->capacity;
    }
    if ((*table)->items[index] != NULL && (*table)->items[index]->is_sentinel == true)
    {
        (*table)->items[index]->is_sentinel = false; 
        (*table)->items[index]->key = key; 
        (*table)->items[index]->value = value; 
    }
    else
       (*table)->items[index] = new_item(key, value);
    (*table)->size++; 
    printf("Table size is %d\n", (*table)->size);
    printf("Table capacity is %d\n", (*table)->capacity);
    printf("Table load factor %f\n", get_load_factor(*table));

    if (get_load_factor(*table) >= 0.5) 
        _resize_table(table, (*table)->capacity * 2);
}

bool exists(_hashtable_t *table, char *key)
{
    int index = hash(key, table->capacity);
    while (!available(table->items[index]))
    {
        if (strcmp(table->items[index]->key, key) == 0)
            return true; 
        index = (index + 1) % table->capacity;
    }
    return false;
}

int get(_hashtable_t *table, char *key)
{
    int index = hash(key, table->capacity);
    while (!available(table->items[index]))
    {
        if (strcmp(table->items[index]->key, key) == 0)
            return table->items[index]->value; 

        index = (index + 1) % table->capacity;
    }

    exit(EXIT_FAILURE);
}   

int remove_key(_hashtable_t *table, char *key)
{
    int index = hash(key, table->capacity);
    while (!available(table->items[index]))
    {
        if (strcmp(table->items[index]->key, key) == 0)
        {
            int val = table->items[index]->value;
            table->items[index]->key = NULL;
            table->items[index]->is_sentinel = true; 
            table->items[index]->value = 0; 
            table->size--;
            return val;
        }
        index = (index + 1) % table->capacity;
    }
    return EXIT_FAILURE;
}




