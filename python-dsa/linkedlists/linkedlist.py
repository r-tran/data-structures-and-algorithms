"""
This module implements the LinkedList data structure.
"""

class LinkedList(object):
    """ Implementation of a single linkedlist using head and tail pointer """

    class Node(object):
        """ Node for single linkedlist """
        def __init__(self, nextn, data):
            self._data = data
            self._next = nextn

    def __init__(self):
        self.__size = 0
        self.__head = None
        self.__tail = None

    def __len__(self):
        return self.__size

    def is_empty(self):
        """Returns boolean specifying whether the Linklist is empty"""
        return self.__size == 0 and self.__head is None and self.__tail is None

    def value_at(self, index):
        """Returns the value at the index. The index must be within bounds"""
        if index < 0 or index > self.__size - 1:
            raise IndexError("Index out of bounds")
        if self.is_empty():
            raise Empty("The list is empty")

        curr = self.__head
        i = 0
        while curr._next is not None and i < index:
            curr = curr._next
            i += 1
        return curr._data

    def push_front(self, value):
        """Adds newly created node to front of the list"""
        newnode = self.Node(None, value)
        if self.is_empty():
            self.__head = newnode
            self.__tail = newnode
            self.__size += 1
            return
        newnode._next = self.__head
        self.__head = newnode
        self.__size += 1

    def pop_front(self):
        """Removes the node at the head of the list, returns the removed node"""
        if self.is_empty():
            raise Empty("The list is empty")

        val = self.__head._data
        if self.__size == 1 and self.__head == self.__tail:
            self.__size = 0 
            self.__head = None
            self.__tail = None
            return val

        self.__head = self.__head._next
        self.__size -= 1
        return val

    def push_back(self, value):
        """Adds newly created node to back of the list"""
        newnode = self.Node(None, value)
        if self.is_empty():
            self.__head = newnode
            self.__tail = newnode
            self.__size += 1
            return
        self.__tail._next = newnode
        self.__tail = newnode
        self.__size += 1

    def pop_back(self):
        """Removes the node at the back of the list, returns the removed node"""
        if self.is_empty():
            raise Empty("The list is empty")

        val = self.__tail._data

        if self.__size == 1 and self.__head == self.__tail:
            self.__size = 0
            self.__head = None
            self.__tail = None
            return val

        curr = self.__head
        while curr._next != self.__tail:
            curr = curr._next
        self.__tail = curr
        curr._next = None
        self.__size -= 1
        return val

    def get_front(self):
        """Returns the first element of the list"""
        if self.is_empty():
            raise Empty("The list is empty")
        return self.__head._data

    def get_back(self):
        """ Returns the last element of the list"""
        if self.is_empty():
            raise Empty("The list is empty")
        return self.__tail._data

    def insert(self, index, value):
        """Inserts item at specified index. The index must be within bounds"""
        if index < 0 or index > self.__size - 1:
            raise IndexError("Index out of bounds")
        if self.is_empty():
            raise Empty("The list is empty")
        
        if index == 0:
            self.push_front(value)
            return

        node = self.Node(None, value)
        curr = self.__head
        i = 1
        while i < index:
            i += 1
            curr = curr._next

        node._next = curr._next
        curr._next = node
        self.__size += 1
    
    def erase(self, index):
        """Removes the node at the index. The index must be within bounds"""
        if index < 0 or index > self.__size - 1:
            raise IndexError("Index out of bounds")
        if self.is_empty():
            raise Empty("List is empty")
        if index == 0:
            self.pop_front()
            return
        if index == self.__size - 1:
            self.pop_back()
            return
        
        prev = self.__head
        curr = self.__head._next
        i = 1
        while i < index and curr._next is not None:
            curr = curr._next
            prev = prev._next
            i += 1
        prev._next = curr._next
        curr = None
        self.__size -= 1

    def value_n_from_end(self, npos):
        """Returns the nth value from the back  of the list """
        return self.value_at(self.__size - npos - 1)
    
    def reverse(self):
        """Reverses all the elements in the list"""
        if self.is_empty():
            raise Empty("The list is empty")
        if self.__size == 1:
            return

        prev = self.__head
        curr = self.__head._next
        while curr is not None:
            nextptr = curr._next
            curr._next = prev
            prev = curr
            curr = nextptr

        self.__head._next = None
        self.__tail = self.__head
        self.__head = prev

    def remove_value(self, value):
        """Removes the first occurence of value from the list"""
        if self.is_empty():
            raise Empty('The list is empty')

        if self.__size == 1 and self.__head.data != value:
            return

        if self.__head._data == value:
            self.pop_front()
            return

        prev = self.__head
        curr = self.__head._next
        while curr is not None:
            if curr._data == value:
                if curr._next == None:
                    self.pop_back()
                    return
                prev._next = curr._next
                curr = None
                self.__size -= 1
                return
            prev = prev._next
            curr = curr._next

    def print_list(self):
        """Use for debugging purposes"""
        curr = self.__head
        while curr is not None:
            print(curr._data)
            curr = curr._next

class Empty(Exception):
    """Exception for empty ADT"""
    pass
