"""
Tests the implementation of the linked stack
"""
from arraystack import EmptyError
from linkedstack import LinkedStack
from nose.tools import assert_equal, assert_true, raises

class TestLinkedStack(object):
    """Test class containing methods"""
    def test_linkedstack_ctor_initial(self):
        stack = LinkedStack()
        assert_equal(0, len(stack))

    @raises(EmptyError)
    def test_linkedstack_top_emptyerror(self):
        stack = LinkedStack()
        stack.top()

    @raises(EmptyError)
    def test_linkedstack_pop_emptyerror(self):
        stack = LinkedStack()
        for i in range(10):
            stack.push(i + 1)
        for i in range(11):
            stack.pop()

    def test_linkedstack_push_addsfront(self):
        stack = LinkedStack()
        for i in range(100):
            stack.push(i + 1)
            assert_equal(i + 1, stack.top())
            assert_equal(i + 1, len(stack))

    def test_linkedstack_pop_returnselement(self):
        stack = LinkedStack()
        for i in range(10):
            stack.push(i + 1)
        for i in range(10):
            val = stack.pop()
            assert_equal(10 - i, val)
            assert_equal(10 - i - 1, len(stack))
