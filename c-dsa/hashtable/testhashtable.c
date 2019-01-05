#include "testhashtable.h"

void test_table_creation()
{
    _hashtable_t *table = new_hashtable();
    assert(table->size == 0);
    assert(table->capacity == 11);
}

void test_add()
{
    _hashtable_t *table = new_hashtable();
    add(&table, "hello", 1);
    add(&table, "world", 2);
    add(&table, "my name is", 3);
    add(&table, "Ray", 4);
    add(&table, "mond", 5);
    assert(table->size == 5);
    assert(table->capacity == 11);
    print_table(table);

    // Expect resize and rehasing 
    add(&table, "Tran", 6);
    add(&table, "Tran", 10);
    assert(table->size == 6);
    assert(table->capacity == 22);
    print_table(table);
}

void test_exists()
{
    _hashtable_t *table = new_hashtable();
    add(&table, "hello", 1);
    add(&table, "world", 2);
    add(&table, "my name is", 3);
    add(&table, "Ray", 4);
    add(&table, "mond", 5);
    assert(exists(table, "hell") == false);
    assert(exists(table, "hello") == true);
    add(&table, "tran", 5);
    assert(exists(table, "tran") == true);
    assert(exists(table, "key") == false);
}

void test_get()
{
    _hashtable_t *table = new_hashtable();
    add(&table, "hello", 1);
    add(&table, "world", 2);
    add(&table, "my name is", 3);
    add(&table, "Ray", 4);
    add(&table, "mond", 5);
    
    assert(get(table, "hello") == 1);
    assert(get(table, "world") == 2);
    assert(get(table, "my name is") == 3);
    assert(get(table, "Ray") == 4);
    assert(get(table, "mond") == 5);
}

void test_remove()
{

    _hashtable_t *table = new_hashtable();
    add(&table, "hello", 1);
    add(&table, "world", 2);
    add(&table, "my name is", 3);
    add(&table, "Ray", 4);
    add(&table, "mond", 5);

    assert(5 == remove_key(table, "mond"));
    assert(table->size == 4);
    assert(4 == remove_key(table, "Ray"));
    assert(table->size == 3);
    assert(3 == remove_key(table, "my name is"));
    assert(table->size == 2);
    assert(2 == remove_key(table, "world"));
    assert(table->size == 1);
    print_table(table);
    assert(1 == remove_key(table, "hello"));
    assert(table->size == 0);
    assert(1 == remove_key(table, "sup"));
}

void run_all_tests()
{
    test_table_creation();
    test_add();
    test_exists();
    test_get();
    test_remove();
}

int main()
{
    run_all_tests();
    printf("All the tests have passed...\n");
}