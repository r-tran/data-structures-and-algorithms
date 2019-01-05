#ifndef TEST_HASH_TABLE_H
#define TEST_HASH_TABLE_H

#include <stdio.h>
#include <assert.h>
#include "hashtable.h"

void test_table_creation();
void test_table_destruction();
void test_add();
void test_exists();
void test_get();
void test_remove();
void run_all_tests();

#endif