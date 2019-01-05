"""
Tests the implementation of the array stack
"""
from arraystack import ArrayStack, EmptyError
from nose.tools import assert_equal, assert_true, raises

class TestArrayStack(object):
    """Test class containing methods"""

    def test_arraystack_ctor_initial(self):
        stack = ArrayStack()
        assert_equal(len(stack), 0)

    def test_arraystack_size(self):
        # Arrange, Act, Assert<F12>
        stack = ArrayStack()
        for i in range(10):
            stack.push(10)
            assert_equal(len(stack), i + 1)

    def test_arraystack_push(self):
        stack = ArrayStack()
        for i in range(100):
            stack.push(i + 1)
            assert_equal(stack.top(), i + 1)

    def test_arraystack_pop(self):
        stack = ArrayStack()
        for i in range(100):
            stack.push(i + 1)
        for i in range(100, 0, -1):
            assert_equal(i, stack.pop())

    @raises(EmptyError)
    def test_arraystack_topthrowsempty(self):
        stack = ArrayStack()
        stack.top()

    @raises(EmptyError)
    def test_arraystack_popthrowsempty(self):
        stack = ArrayStack()
        stack.pop()

    @raises(EmptyError)
    def test_arraystack_popallthrowsempty(self):
        stack = ArrayStack()
        for i in range(100):
            stack.push(i + 1)
        for i in range(100):
            stack.pop()
        stack.pop()
