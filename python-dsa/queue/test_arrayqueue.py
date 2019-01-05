"""
Tests the array implementation for queue
"""
from arrayqueue import ArrayQueue
from linkedqueue import EmptyError
from nose.tools import assert_equal, assert_true, raises

class TestArrayQueue(object):
    """Test class for the queue implementation"""
    def test_ArrayQueue_ctor(self):
        queue = ArrayQueue()
        assert_equal(0, len(queue))

    @raises(EmptyError)
    def test_emptyArrayQueue_front(self):
        queue = ArrayQueue()
        val = queue.front()

    @raises(EmptyError)
    def test_emptyArrayQueue_dequeue(self):
        queue = ArrayQueue()
        val = queue.dequeue()

    def test_ArrayQueue_enqueue(self):
        queue = ArrayQueue()
        for i in range(100):
            queue.enqueue(i + 1)
            assert_equal(1, queue.front())
        assert_equal(100, len(queue))

    def test_ArrayQueue_dequeue(self):
        queue = ArrayQueue()
        for i in range(100):
            queue.enqueue(i + 1)
        for i in range(100):
            assert_equal(i + 1, queue.dequeue())
            assert_equal(99 - i, len(queue))
        assert_equal(0, len(queue))

    def test_ArrayQueue_front(self):
        queue = ArrayQueue()
        for i in range(100):
            queue.enqueue(i + 1)
        for i in range(100):
            assert_equal(i + 1, queue.front())
            queue.dequeue()

    def test_ArrayQueue_multipleoperations(self):
        queue = ArrayQueue()
        for i in range(100):
            queue.enqueue(i + 100)
        for i in range(50):
            queue.dequeue()
        for i in range(100):
            queue.enqueue(i + 200)
        assert_equal(150, queue.front())