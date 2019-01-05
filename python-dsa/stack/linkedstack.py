"""
This module implements a stack ADT using a LinkedList
"""
from arraystack import EmptyError

class LinkedStack(object):
    """Stack ADT implementation using singly-linkedlist with a head pointer"""

    class _Node(object):
        """Internal class to represent the node"""

        __slots__ = ['_next', '_element']

        def __init__(self, nextn, element):
            self._next = nextn
            self._element = element

    def __init__(self):
        self._head = None
        self.__size = 0

    def __len__(self):
        return self.__size

    def pop(self):
        """Removes and returns the top element from the stack"""
        if not self._head:
            raise EmptyError("Stack is empty!")

        val = self._head._element
        self._head = self._head._next
        self.__size -= 1
        return val

    def push(self, element):
        """Adds the element to the top of the stack"""
        node = self._Node(None, element)
        node._next = self._head
        self._head = node
        self.__size += 1


    def top(self):
        """Returns the element on the top of the stack"""
        if not self._head:
            raise EmptyError("Stack is empty!")
        return self._head._element
