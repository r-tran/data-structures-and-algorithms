
"""
This module implements the Queue ADT using an underlying linkedlist
"""

class LinkedQueue(object):
    """Implementation of the queue using a singly linkedlist with head and tail pointer"""

    class _Node(object):
        """Internal class to represent linkedlist"""
        __slots__ = ['_next', '_element']
        def __init__(self, nextn, element):
            self._next = nextn
            self._element = element

    def __init__(self):
        self.__size = 0
        self.__head = None
        self.__tail = None

    def __len__(self):
        return self.__size

    def front(self):
        """Returns the element at the front of the queue"""
        if self.__size == 0:
            raise EmptyError('Queue is empty!')
        return self.__head._element

    def enqueue(self, element):
        """Add the element to the back of the queue"""
        node = self._Node(None, element)
        if self.__size == 0:
            self.__head = node
            self.__tail = node
            self.__size += 1
            return
        self.__tail._next = node
        self.__tail = node
        self.__size += 1

    def dequeue(self):
        """Remove and return the element at the front of the queue."""
        if self.__size == 0:
            raise EmptyError("The queue is empty!")
        val = self.__head._element
        self.__head = self.__head._next
        if not self.__head:
            self.__tail = None
        self.__size -= 1
        return val

class EmptyError(Exception):
    """Exception class for empty queue ADT"""
    pass
