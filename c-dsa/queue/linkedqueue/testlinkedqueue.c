#include "testlinkedqueue.h"
#include <assert.h>

void run_all_tests()
{
   test_size(); 
   test_is_empty();
   test_front();
   test_enqueue();
   test_dequeue();
}

void test_size()
{
   _linked_queue_t *q = new_queue(); 
   for (int i = 0; i < 10; i++)
   {
        enqueue(&q, i + 1);
        assert(i + 1 == get_size(q));
   }
}

void test_is_empty()
{
    _linked_queue_t *q = new_queue();
    assert(is_empty(q) == true);
    for (int i = 0; i < 10; i++)
    {
        enqueue(&q, i + 1);
        assert(is_empty(q) == false);
    }
    for (int i = 0; i < 10; i++)
        dequeue(&q);
    assert(is_empty(q) == true);
}

void test_front()
{
    _linked_queue_t *q = new_queue();
    for (int i = 0; i < 10; i++)
    {
        enqueue(&q, i + 1);
        assert(get_front(q) == 1);
    }
    for (int i = 0; i < 10; i++)
    {
        assert(get_front(q) == i + 1);
        dequeue(&q);
    }
}

void test_enqueue()
{
    _linked_queue_t *q = new_queue();
    for (int i = 0; i < 1000; i++)
    {
        enqueue(&q, i + 1);
    }
    assert(is_empty(q) == false);
    assert(get_front(q) == 1);
    assert(get_size(q) == 1000);
}

void test_dequeue()
{
    _linked_queue_t *q = new_queue();
    for (int i = 0; i < 1000; i++)
        enqueue(&q, i + 1);
    for (int i = 0; i < 1000; i++)
    {
        assert(get_front(q) == i + 1);
        int val = dequeue(&q);
        assert(i + 1 == val);
        assert(1000 - i - 1 == get_size(q));
    }
}