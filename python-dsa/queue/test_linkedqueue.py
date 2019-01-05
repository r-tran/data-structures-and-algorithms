"""
Tests the implementation of the linked list queue
"""
from linkedqueue import LinkedQueue, EmptyError
from nose.tools import assert_equal, assert_true, raises

class TestLinkedQueue(object):
    """Test class for the queue implementation"""
    def test_linkedqueue_ctor(self):
        queue = LinkedQueue()
        assert_equal(0, len(queue))

    @raises(EmptyError)
    def test_emptylinkedqueue_front(self):
        queue = LinkedQueue()
        val = queue.front()

    @raises(EmptyError)
    def test_emptylinkedqueue_dequeue(self):
        queue = LinkedQueue()
        val = queue.dequeue()

    def test_linkedqueue_enqueue(self):
        queue = LinkedQueue()
        for i in range(100):
            queue.enqueue(i + 1)
            assert_equal(1, queue.front())
        assert_equal(100, len(queue))

    def test_linkedqueue_dequeue(self):
        queue = LinkedQueue()
        for i in range(100):
            queue.enqueue(i + 1)
        for i in range(100):
            assert_equal(i + 1, queue.dequeue())
            assert_equal(99 - i, len(queue))
        assert_equal(0, len(queue))

    def test_linkedqueue_front(self):
        queue = LinkedQueue()
        for i in range(100):
            queue.enqueue(i + 1)
        for i in range(100):
            assert_equal(i + 1, queue.front())
            queue.dequeue()