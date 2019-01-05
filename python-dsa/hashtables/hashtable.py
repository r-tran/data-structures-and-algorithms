"""
Implementation of the hashtable using linear probing
"""
from __future__ import division
import random

class HashTable(object):
    """Uses underlying list to represent a bucket array"""
    #sentinel for removed item in table
    _AVAIL = object()
    MADPRIME = 109345121
    MADSCALE = random.randint(1, MADPRIME - 1) 
    MADSHIFT = random.randrange(MADPRIME)

    def __init__(self):
        self.__size =  0
        self.__capacity = 11
        self.__items = [None] * 11
    
    def __len__(self):
        return self.__size

    def __getitem__(self, key):
        return self.get(key)

    def __contains__(self, key):
        return self.exists(key)

    def __setitem__(self, key, item):
        self.add(key, item)        
    
    def __iter__(self):
        for item in self.__items:
            if not self._item_available(item):
                yield item.key

    def __delitem__(self, key):
        self.remove(key)

    def hash(self, key):
        """Uses MAD compression on hash function"""
        return (((hash(key) * self.MADSCALE) + self.MADSHIFT) % self.MADPRIME) % self.__capacity

    def add(self,key, value):
        """Adds value to table. If key exists, then puts new value. Otherwise creates key"""
        index = self.hash(key)
        while not self._item_available(self.__items[index]):
            if self.__items[index].key == key:
                self.__items[index].value = value
                return
            index = (index + 1) % self.__capacity
        self.__items[index] = self._Item(key, value)
        self.__size += 1 
        if (self.__size / self.__capacity) >= 0.5:
            self._resizeup_table()
    
    def _item_available(self, item):
        if item is None or item is self._AVAIL:
            return True
        return False

    def _resizeup_table(self):
        olditems = self.__items
        self.__items = [None] * self.__capacity * 2
        self.__capacity = self.__capacity * 2
        self.__size = 0
        for item in olditems:
            if not self._item_available(item):
                self.add(item.key, item.value)

    @property
    def capacity(self):
        """Returns the size of the underlying buckets array"""
        return self.__capacity

    def exists(self, key):
        """Returns boolean on whether the passed in key is in the table"""
        index = self.hash(key)
        while not self._item_available(self.__items[index]):
            if self.__items[index].key == key:
                return True
            index = (index + 1) % self.__capacity
        return False

    def get(self, key):
        """Returns the value of the key, if key not found then exception is thrown"""
        index = self.hash(key)
        while not self._item_available(self.__items[index]):
            if self.__items[index].key == key:
                return self.__items[index].value
            index = (index + 1) % self.__capacity
        raise KeyError('The key was not found')        

    def remove(self, key):
        """Removes key value pair from the table. If key cannot be located, throws exception"""
        index = self.hash(key)
        while not self._item_available(self.__items[index]):
            if self.__items[index].key == key:
                self.__items[index] = self._AVAIL
                self.__size -= 1
                return
            index = (index + 1) % self.__capacity
        raise KeyError('The key was not found')


    def print_table(self):
        """Debugger that helps print table"""
        for item in self.__items:
            if not self._item_available(item):
                print('Key: {} .... Value: {}'.format(item.key, item.value))

    class _Item(object):
        """Internal class for item in the table"""
        def __init__(self, key, value):
            self.key = key
            self.value = value
