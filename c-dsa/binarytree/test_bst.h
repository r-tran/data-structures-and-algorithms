#ifndef TEST_BST_H
#define TEST_BST_H

#include "bst.h"
#include <stdio.h>
#include <assert.h>

void run_all_tests();

void test_insert();
void test_get_node_count();
void test_delete_tree();
void test_is_in_tree();
void test_get_height();
void test_get_min();
void test_get_max();
void test_is_bst();
void test_remove_value();
void test_get_predecessor();
void test_get_successor();


#endif