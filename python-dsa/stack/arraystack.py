"""
This module implements a stack ADT using an array
"""

class ArrayStack(object):
    """Stack ADT implementation using list"""
    def __init__(self):
        self._data = []

    def __len__(self):
        return len(self._data)

    def pop(self):
        """Removes and returns the top element from the stack"""
        if not self._data:
            raise EmptyError('The stack is empty')

        val = self._data[-1]
        self._data.pop()
        return val

    def push(self, element):
        """Adds the element to the top of the stack"""
        self._data.append(element)

    def top(self):
        """Returns the element on the top of the stack"""
        if not self._data:
            raise EmptyError('The stack is empty')

        return self._data[-1]

class EmptyError(Exception):
    """Exception class for empty stack"""
    pass
    