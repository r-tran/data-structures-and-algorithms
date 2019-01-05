"""
This module implements a dynamic array with a minimum capacity of 16.
"""
import ctypes

class Vector(object):
    """ An implementation of a dynamic array. """
    MIN_CAPACITY = 16
    GROWTH_FACTOR = 2
    QUARTER = 4
    SHRINK_FACTOR = 2

    def __init__(self, capacity=MIN_CAPACITY):
        self._capacity = self._get_true_capacity(capacity)
        self._size = 0
        self._data = self._make_array(capacity)

    def __len__(self):
        return self._size

    def __getitem__(self, key):
        if not 0 <= key < self._size:
            raise IndexError('invalid index')
        return self._data[key]

    def __setitem__(self, key, item):
        if not 0 <= key < self._size:
            raise IndexError('invalid index')
        self._data[key] = item

    def get_size(self):
        """Returns the number of elements in the array"""
        return self._size

    def get_capacity(self):
        """Returns the capacity of the array"""
        return self._capacity

    def is_empty(self):
        """Returns whether the array size is zero"""
        return self._size == 0

    def at_index(self, i):
        """Returns the value at the array index i"""
        self.__getitem__(i)

    def push_back(self, item):
        """Inserts an item in the array"""
        if self._size == self._capacity:
            self._resize_to_new_capacity(self._capacity * self.GROWTH_FACTOR)
        self._data[self._size] = item
        self._size += 1

    def insert(self, index, item):
        """Adds the item to the array at index"""
        if not 0 <= index <= self._size:
            raise IndexError('invalid index')
        if self._size == self._capacity:
            self._resize_to_new_capacity(self._capacity * self.GROWTH_FACTOR)
        for i in range(self._size, index, -1):
            self._data[i] = self._data[i - 1]
        self._data[index] = item
        self._size += 1

    def prepend(self, item):
        """Inserts item at the front of the array"""
        self.insert(0, item)

    def pop(self):
        """Returns the rightmost element of the array, removes it from array"""
        val = self._data[self._size - 1]
        self._data[self._size - 1] = None
        self._size -= 1
        if self._capacity / self.QUARTER == self._size and self._capacity > self.MIN_CAPACITY:
            self._resize_to_new_capacity(self._capacity / self.SHRINK_FACTOR)
        return val

    def delete(self, index):
        """Removes the item at the index, shifts elements left"""
        if not 0 <= index < self._size:
            raise IndexError('invalid index')
        for i in range(index, self._size - 1):
            self._data[i] = self._data[i + 1]
        self._data[self._size -1] = None
        self._size -= 1
        if self._capacity / self.QUARTER == self._size and self._capacity > self.MIN_CAPACITY:
            self._resize_to_new_capacity(self._capacity / self.SHRINK_FACTOR)

    def remove(self, item):
        """Removes all occurences of the item from the array"""
        index = 0
        while index < self._size:
            if self._data[index] == item:
                self.delete(index)
                index -= 1
            index += 1

    def find(self, item):
        """Returns the index of the first occurence of item in the array"""
        for i in range(self._size):
            if self._data[i] == item:
                return i
        raise ValueError('item not found')

    def _resize_to_new_capacity(self, newcapacity):
        if self._capacity == newcapacity:
            return
        newarr = self._make_array(newcapacity)
        for i in range(self._size):
            newarr[i] = self._data[i]
        self._capacity = newcapacity
        self._data = newarr

    def _make_array(self, capacity):
        return (capacity * ctypes.py_object)()

    def _get_true_capacity(self, capacity):
        truecapacity = self.MIN_CAPACITY
        while truecapacity < capacity:
            truecapacity *= self.GROWTH_FACTOR
        return truecapacity
