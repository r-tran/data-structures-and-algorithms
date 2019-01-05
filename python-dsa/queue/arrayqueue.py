"""
This module implements the Queue ADT using an underlying array.
To avoid space overhead from a large number of dequeue operations,
the array structure uses a circular structure.
"""
from linkedqueue import EmptyError

class ArrayQueue(object):
    """Implementation of the queue using Python list, with initial size of capacity"""
    defaultCapacity = 16
    shrink = 4
    scaleFactor = 2

    def __init__(self):
        self.__size = 0
        self.__data = [None] * self.defaultCapacity
        self.__first = 0

    def __len__(self):
        return self.__size

    def front(self):
        """Returns the element at the front of the queue"""
        if self.__size == 0:
            raise EmptyError("The queue is empty")
        return self.__data[self.__first]

    def enqueue(self, element):
        """Add the element to the back of the queue"""
        if self.__size == len(self.__data):
            self._resize(self.__size * self.scaleFactor)
        idx = (self.__first + self.__size) % len(self.__data)
        self.__data[idx] = element
        self.__size += 1

    def dequeue(self):
        """Remove and return the element at the front of the queue."""
        if self.__size == 0:
            raise EmptyError("The queue is empty")
        val = self.__data[self.__first]
        self.__data[self.__first] = None
        self.__first = (self.__first + 1) % len(self.__data)
        self.__size -= 1
        if self.__size > 0 and (len(self.__data) // self.__size) >= self.shrink:
            self._resize(len(self.__data) // self.scaleFactor)
        return val

    def _resize(self, newcapacity):
        newarr = [None] * newcapacity
        for i in range(self.__size):
            idx = (self.__first + i) % len(self.__data)
            newarr[i] = self.__data[idx]
        self.__data = newarr
        self.__first = 0

    def print_elements(self):
        """Helper to print all elements of list"""
        for i in range(len(self.__data)):
            print(self.__data[i])