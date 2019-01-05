#include "linkedlist_tests.h"
#include <stdio.h>

void run_all_tests()
{
    test_size();
    test_isempty();
    test_valueat();
    test_front();
    test_back();
    test_valuenfromend();
    test_insert();
    test_pushfront();
    test_pushback();
    test_erase();
    test_popfront();
    test_popback();
    test_removevalue();
    test_reverse();
    return;
}

void test_size()
{
    _single_linklist_t *list = new_list();
    push_back(&list, 1);
    push_back(&list, 2);
    push_back(&list, 3);

    assert(list->size == 3);
    assert(size(list) == 3);

    pop_back(&list);
    pop_back(&list);
    pop_back(&list);

    assert(list->size == 0);
    assert(size(list) == 0);
}

void test_isempty()
{
    _single_linklist_t *list = new_list();
    assert(is_empty(list) == true);
    push_back(&list, 20);
    assert(is_empty(list) == false);
    pop_back(&list);
    assert(is_empty(list) == true);
}

void test_valueat()
{
    _single_linklist_t *list = new_list();
    push_back(&list, 10);
    push_back(&list, 20);
    push_back(&list, 30);
    push_back(&list, 40);
    push_back(&list, 50);
    assert(value_at(list, 0) == 10);
    assert(value_at(list, 1) == 20);
    assert(value_at(list, 2) == 30);
    assert(value_at(list, 3) == 40);
    assert(value_at(list, 4) == 50);
    assert(value_at(list, 5) == -1);
    assert(value_at(list, -1) == -1);
}

void test_front()
{
    _single_linklist_t *list = new_list();
    assert(front(list) == -1);
    push_back(&list, 10);
    push_back(&list, 20);
    push_back(&list, 30);
    push_back(&list, 40);
    push_back(&list, 50);
    assert(front(list) == 10);
}

void test_back()
{
    _single_linklist_t *list = new_list();
    assert(back(list) == -1);
    push_back(&list, 10);
    push_back(&list, 20);
    push_back(&list, 30);
    push_back(&list, 40);
    push_back(&list, 50);
    assert(back(list) == 50);
}

void test_valuenfromend()
{
    _single_linklist_t *list = new_list();
    push_back(&list, 10);
    push_back(&list, 20);
    push_back(&list, 30);
    push_back(&list, 40);
    push_back(&list, 50);
    assert(value_n_from_end(list, 0) == 50);
    assert(value_n_from_end(list, 1) == 40);
    assert(value_n_from_end(list, 2) == 30);
    assert(value_n_from_end(list, 3) == 20);
    assert(value_n_from_end(list, 4) == 10);
}

void test_insert()
{
    _single_linklist_t *list = new_list();
    assert(list->size == 0);
    insert(&list, 0, 10);
    assert(list->head->data = 10);
    insert(&list, 0, 20);
    assert(list->head->data = 20);
    insert(&list, 0, 30);
    assert(list->head->data = 30);
    assert(list->size == 3);
    
    insert(&list, 1, 100);
    assert(value_at(list, 1) == 100);
    assert(value_at(list, 2) == 20);
    assert(value_at(list, 3) == 10);

    insert(&list,list->size, 1000);
    assert(value_at(list, 4) == 1000);
}

void test_pushfront()
{
    _single_linklist_t *list = new_list();
    int sol[] = {500, 400, 300, 200, 100};
    push_front(&list, 100);
    push_front(&list, 200);
    push_front(&list, 300);
    push_front(&list, 400);
    push_front(&list, 500);
    assert(list->size == 5);

    _node_t *curr = list->head; 
    int i = 0; 
    while (curr != NULL)
    {
        assert(curr->data == sol[i]);
        curr = curr->next; 
        i++;
    }
}

void test_pushback()
{
    _single_linklist_t *list = new_list();
    int sol[] = {100, 200, 300, 400, 500};
    push_back(&list, 100);
    push_back(&list, 200);
    push_back(&list, 300);
    push_back(&list, 400);
    push_back(&list, 500);
    assert(list->size == 5);

    _node_t *curr = list->head; 
    int i = 0; 
    while (curr != NULL)
    {
        assert(curr->data == sol[i]);
        curr = curr->next; 
        i++;
    }
}

void test_erase()
{
    _single_linklist_t *list = new_list();
    for (int i = 0; i < 5; i++)
    {
        push_back(&list, i + 1);
    }

    erase(&list, 0);
    assert(list->size == 4);
    assert(list->head->data == 2);
    
    erase(&list, 2);
    assert(list->size == 3);
    assert(value_at(list, 2) == 5);

    erase(&list, 2);
    assert(list->size == 2);
    assert(value_at(list, 0) == 2);
    assert(value_at(list, 1) == 3);
}

void test_popfront()
{
    _single_linklist_t *list = new_list();

    for (int i = 0; i < 3; i++)
        push_back(&list, i + 1);

    for (int j = 0; j < 3; j++)
    {
        int val = pop_front(&list);
        assert(val == j + 1);
        assert(list->size == 3 - j - 1);
    }

    assert(is_empty(list));
}

void test_popback()
{
    _single_linklist_t *list = new_list();

    for (int i = 0; i < 3; i++)
        push_back(&list, i + 1);

    for (int j = 0; j < 3; j++)
    {
        int val = pop_back(&list);
        assert(val == 3 - j);
        assert(list->size == 3 - j - 1);
    }
    assert(is_empty(list));
}

void test_removevalue()
{
    _single_linklist_t *list = new_list();
    for (int i = 0; i < 5; i++)
        push_back(&list, i + 1);

    remove_value(&list, 5);
    assert(list->size == 4);
    for (int i = 0; i < list->size; i++)
        assert(value_at(list, i) == i + 1);

    remove_value(&list, 1);
    assert(list->size == 3);
    for (int i = 0; i < list->size; i++)
        assert(value_at(list, i) == i + 2);
    
    remove_value(&list, 3);    
    assert(list->size == 2);
    assert(value_at(list, 0) == 2);
    assert(value_at(list, 1) == 4);

    remove_value(&list, 2);
    remove_value(&list, 4);
    assert(is_empty(list));
}

void test_reverse()
{
   _single_linklist_t *list = new_list();
   for (int i = 0; i < 10; i++)
        push_back(&list, i);

    reverse(&list);
    for (int i = 9; i >= 0; i--)
        assert(value_at(list, 9 - i) == i);

    assert(list->head->data == 9);

    _single_linklist_t *list2 = new_list();
    push_back(&list2, 1);
    push_back(&list2, 2);
    reverse(&list2);
    assert(value_at(list2, 0) == 2);
    assert(value_at(list2, 1) == 1);
}
