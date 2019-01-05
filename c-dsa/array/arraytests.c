#include "arraytests.h"
#include <stdio.h>

void run_all_tests()
{
    test_size();
    test_capacity();
    test_is_empty();
    test_at_index();
    test_push_back();
    test_insert();
    test_prepend();
    test_pop();
    test_delete_index();
    test_remove_element();
    test_find();
}

void test_size()
{
    _array_t *arr = new_array(16);
    push_back(arr, 10);
    assert(get_size(arr) == 1); 
    push_back(arr, 20);
    assert(get_size(arr) == 2); 
    push_back(arr, 30);
    assert(get_size(arr) == 3); 
    push_back(arr, 40);
    assert(get_size(arr) == 4); 
    push_back(arr, 50);
    assert(get_size(arr) == 5); 
    push_back(arr, 60);
    assert(get_size(arr) == 6); 
    push_back(arr, 70);
    assert(get_size(arr) == 7); 
}

void test_capacity()
{
    // Case: regular capacity
    _array_t *arr = new_array(16);
    int cap = get_capacity(arr);
    assert(cap == 16);

    // Case: default capacity
    _array_t *arr1 = new_array(0);
    assert(get_capacity(arr1) == 16);

    // Case: capacity resized up
    _array_t *arr2 = new_array(30);
    assert(get_capacity(arr2) == 32);
}

void test_is_empty()
{
    _array_t *arr = new_array(16);
    bool flag = is_empty(arr);
    assert(flag);

    for (int i = 0; i < arr->capacity; i++)
    {
        assert( *(arr->data + i) == 0);
    }
}

void test_at_index()
{
    _array_t *arr = new_array(16);
    push_back(arr, 5);
    push_back(arr, 10);
    push_back(arr, 15);
    push_back(arr, 20);
    push_back(arr, 25);

    assert(at(arr,0) == 5);
    assert(at(arr,1) == 10);
    assert(at(arr,2) == 15);
    assert(at(arr,3) == 20);
    assert(at(arr,4) == 25);
}


void test_push_back()
{
    // Case: Push to full capacity
    _array_t *arr = new_array(16);
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12,13,14,15,16,17,18,19,20};
    for (int i = 1; i <= 16; i++)
        push_back(arr, i);
    assert(arr->capacity == 16);
    assert(arr->size == 16);
    for (int i = 0; i < arr->size; i++)
    {
        assert(*(values + i) == *(arr->data + i));
    }

    // Case: Resize to new capacity
    push_back(arr, 17);
    push_back(arr, 18);
    push_back(arr, 19);
    push_back(arr, 20);
    assert(arr->size == 20);
    assert(arr->capacity == 32);
    for (int i = 16; i < arr->size; i++)
    {
        assert(*(values + i) == *(arr->data + i));
    }
}

void test_insert()
{
    //insert at mid
    _array_t *arr = new_array(3);
    int vec[] = {1,4,2,3};

    push_back(arr, 1);
    push_back(arr, 2);
    push_back(arr, 3);
    insert(arr, 1, 4);
    
    for (int i = 0; i < 4; i++)
    {
        assert(*(vec + i) == *(arr->data + i));
    }

    //insert at begin
    _array_t *arr1 = new_array(3);
    int vec1[] = {4,1,2,3};

    push_back(arr1, 1);
    push_back(arr1, 2);
    push_back(arr1, 3);
    insert(arr1, 0, 4);
    
    for (int i = 0; i < 4; i++)
    {
        assert(*(vec1 + i) == *(arr1->data + i));
    }

    //insert at end 
    _array_t *arr2 = new_array(3);
    int vec2[] = {1,2,3,4};

    push_back(arr2, 1);
    push_back(arr2, 2);
    push_back(arr2, 3);
    insert(arr2, 2, 4);
    
    for (int i = 0; i < 4; i++)
    {
        assert(*(vec + i) == *(arr->data + i));
    }
}

void test_prepend()
{
    _array_t *arr = new_array(5);
    int result[] = {10, 1, 2, 3, 4, 5};

    push_back(arr, 1);
    push_back(arr, 2);
    push_back(arr, 3);
    push_back(arr, 4);
    push_back(arr, 5);
    prepend(arr, 10);

    for (int i = 0; i < arr->size; i++)
    {
        assert(*(arr->data + i) == *(result + i));
    }
}

void test_pop()
{
    // Case: Pop all 
    _array_t *arr = new_array(5);
    push_back(arr, 10);
    push_back(arr, 20);
    push_back(arr, 30);
    push_back(arr, 40);
    push_back(arr, 50);

    assert(pop(arr) == 50);
    assert(arr->size == 4);
    assert(pop(arr) == 40);
    assert(arr->size == 3);
    assert(pop(arr) == 30);
    assert(arr->size == 2);
    assert(pop(arr) == 20);
    assert(arr->size == 1);
    assert(pop(arr) == 10);
    assert(arr->size == 0);
    assert(is_empty(arr));

    // Case: pop resize, check for adjusted capacity
    _array_t *arr1 = new_array(16);
    for (int i = 1; i <= 17; i++)
        push_back(arr1, i);
    assert(arr1->capacity == 32);

    for (int i = 0; i < 9; i++)
        pop(arr1);
    assert(arr1->size == 8);
    assert(arr->capacity == 16);
}

void test_delete_index()
{
    // Case: Delete index at end
    _array_t *arr = new_array(5);
    push_back(arr, 1);
    push_back(arr, 2);
    push_back(arr, 3);
    push_back(arr, 4);
    delete_index(arr, 3);
    assert(arr->size == 3);
    int sol[] = {1,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < arr->capacity; i++)
        assert(*(arr->data + i) == *(sol + i));

    //Case: Delete index at front
    _array_t *arr1 = new_array(5);
    push_back(arr1, 1);
    push_back(arr1, 2);
    push_back(arr1, 3);
    push_back(arr1, 4);
    delete_index(arr1, 0);
    assert(arr1->size == 3);
    int sol1[] = {2,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < arr1->capacity; i++)
    {
        assert(*(arr1->data + i) == *(sol1 + i));
    }

    //Case: Delete index at middle
    _array_t *arr2 = new_array(5);
    push_back(arr2, 1);
    push_back(arr2, 2);
    push_back(arr2, 3);
    push_back(arr2, 4);
    delete_index(arr2, 2);
    assert(arr2->size == 3);
    int sol2[] = {1,2,4,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < arr2->capacity; i++)
    {
        assert(*(arr2->data + i) == *(sol2 + i));
    }
    
    //Case: Delete all
    _array_t *arr3 = new_array(5);
    push_back(arr3, 1);
    push_back(arr3, 2);
    push_back(arr3, 3);
    push_back(arr3, 4);
    push_back(arr3, 5);
    delete_index(arr3, 0);
    delete_index(arr3, 0);
    delete_index(arr3, 0);
    delete_index(arr3, 0);
    delete_index(arr3, 0);
    assert(is_empty(arr3));

    // Case: check for resize
    _array_t *arr4 = new_array(16);
    for (int i = 1; i <= 17; i++)
        push_back(arr4, i);
    assert(arr4->capacity == 32);

    for (int i = 0; i < 9; i++)
    {
        delete_index(arr4, 0);
    }

    assert(arr4->size == 8);
    assert(arr4->capacity == 16);
}

void test_remove_element()
{
    // Case: all same element
    _array_t *arr = new_array(5);
    push_back(arr, 1);
    push_back(arr, 1);
    push_back(arr, 1);
    push_back(arr, 1);
    push_back(arr, 1);
    remove_element(arr, 1);
    for (int i = 0; i < arr->capacity; i++)
    {
        assert( *(arr->data + i) == 0);
    }
    assert(is_empty(arr));

    //case remove single element
    _array_t *arr1 = new_array(5);
    push_back(arr1, 1);
    push_back(arr1, 2);
    push_back(arr1, 3);
    push_back(arr1, 4);
    push_back(arr1, 5);
    remove_element(arr1, 4);
    assert(arr1->size == 4);
    int sol1[] = {1,2,3,5};
    for (int i = 0; i < arr1->size; i++)
        assert(*(arr1->data + i) == *(sol1 + i));

    //case remove many elements
    _array_t *arr2 = new_array(5);
    push_back(arr2, 1);
    push_back(arr2, 2);
    push_back(arr2, 3);
    push_back(arr2, 2);
    push_back(arr2, 5);
    remove_element(arr2, 2);
    assert(arr2->size == 3);
    int sol2[] = {1,3,5};
    for (int i = 0; i < arr2->size; i++)
        assert(*(arr2->data + i) == *(sol2 + i));
   
    // case: resize down
    _array_t *arr4 = new_array(16);
    for (int i = 1; i <= 17; i++)
    {
        push_back(arr4, i);
    }
    assert(arr4->capacity == 32);

    for (int i = 1; i <= 9; i++)
        remove_element(arr4, i);

    assert(arr4->size == 8);
    assert(arr4->capacity == 16);
}

void test_find()
{
    _array_t *arr = new_array(5);
    push_back(arr, 1);
    push_back(arr, 2);
    push_back(arr, 3);
    push_back(arr, 4);
    push_back(arr, 5);

    assert(0 == find(arr, 1));
    assert(1 == find(arr, 2));
    assert(2 == find(arr, 3));
    assert(3 == find(arr, 4));
    assert(4 == find(arr, 5));
    assert(-1 == find(arr, 6));
}