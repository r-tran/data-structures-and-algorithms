#include "testarrayqueue.h"

void run_all_tests()
{
   test_size(); 
   test_is_empty();
   test_is_full();
   test_front();
   test_is_empty();
   test_enqueue();
   test_dequeue();
}

void test_size()
{
    _array_queue_t *q = new_arrayqueue();
    assert(0 == get_size(q));

    for (int i = 0; i < 100; i++)
    {
        enqueue(&q, i + 1);
        assert(get_size(q) == i + 1);
    }   
}

void test_is_empty()
{
    _array_queue_t *q = new_arrayqueue();
    assert(true == is_empty(q));

    for (int i = 0; i < 100; i++)
    {
        enqueue(&q, i + 1);
        assert(is_empty(q) == false);
    }   
    for (int i = 0; i < 100; i++)
        dequeue(&q);
    assert(is_empty(q) == true);
}

void test_is_full()
{
    _array_queue_t *q = new_arrayqueue();
    assert(false == is_full(q));
    for (int i = 0; i < 128; i++)
        enqueue(&q, i + 1);
    assert(true == is_full(q));
    enqueue(&q, 100);
    assert(false == is_full(q));
}

void test_front()
{
    _array_queue_t *q = new_arrayqueue();
    for (int i = 0; i < 1000; i++)
    {
        enqueue(&q, i + 1);
        assert(get_front(q) == 1);
    }
    for (int i = 0; i < 1000; i++)
    {
        assert(get_front(q) == i + 1);
        dequeue(&q);
    }
}

void test_enqueue()
{
    _array_queue_t *q = new_arrayqueue();
    for (int i = 0; i < 1000; i++)
    {
        enqueue(&q, i + 1);
        assert(get_front(q) == 1);
    }
    assert(get_size(q) == 1000);
    for (int i  = 0; i < 30; i++)
    {
        dequeue(&q);
    }
    for (int i = 0; i < 1000; i++)
    {
        enqueue(&q, i + 1);
        assert(get_front(q) == 31);
    }

    assert(get_size(q) == 1970);
}

void test_dequeue()
{
    _array_queue_t *q = new_arrayqueue();
    for (int i = 0; i < 100; i++)
        enqueue(&q, i + 1);
    for (int i = 0; i < 90; i++)
        assert(dequeue(&q) == i + 1);
    assert(get_front(q) == 91);
    assert(get_size(q) == 10);
    for (int i = 0; i < 100; i++)
        enqueue(&q, i + 101);
    for (int i = 0; i < 110; i++)
    {
        assert(get_front(q) == 91 + i);
        assert(dequeue(&q) == 91 + i);
        assert(get_size(q) == 110 - i - 1);
    }
    assert(is_empty(q));
}

int main()
{
    run_all_tests();
    printf("All tests have passed...\n");
}