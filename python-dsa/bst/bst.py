"""
Implementation of a binary search tree (iterative and recursive solutions)
"""
from collections import deque

class Node(object):
    """Represents node in the tree. We keep count of duplicate nodes"""
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data
        self.duplicate_count = 0
    
    def delete_child(self, child):
        """Delete child node based on data"""
        if self.right:
            if child.data == self.right.data:
                self.right = None
        elif self.left:
            if child.data == self.left.data:
                self.left = None
        else:
            print('Child not found in node')

    def add_child(self, child):
        """Adds child node based on data"""
        if child.data < self.data:
            self.left = child
        elif child.data > self.data:
            self.right = child
        else:
            print('Cannot add child')

class BinarySearchTree(object):
    """BST implementation using Node"""
    def __init__(self):
        self.root = None

    def insert(self, value):
        """Inserts node in tree. If value alredy exists, then increment duplicate"""
        if self.root is None:
            self.root = Node(value)
            return

        walk = self.root
        while True:
            if walk.data == value:
                walk.duplicate_count += 1
                return
            elif value < walk.data:
                if walk.left is None:
                    walk.left = Node(value)
                    return
                walk = walk.left
            else:
                if walk.right is None:
                    walk.right = Node(value)
                    return
                walk = walk.right

    def insert_recursive(self, value):
        """Insert node in the tree"""
        self.root = self._insert_recursive(self.root, value)

    def _insert_recursive(self, root, value):
        if root is None:
            return Node(value)
        elif root.data == value:
            root.duplicate_count += 1
        elif root.data < value:
            root.right = self._insert_recursive(root.right, value)
        elif root.data > value:
            root.left = self._insert_recursive(root.left, value)
        return root

    def print_values_recursive(self):
        """Print values of the tree in order"""
        self._print_values_recursive(self.root)

    def print_values(self):
        """Print values of the tree inorder"""
        curr = self.root
        stack  = []
        while len(stack) > 0 or curr is not None:
            while curr is not None:
                stack.append(curr)
                curr = curr.left
            visit = stack.pop()
            print(visit.data)
            curr = visit.right

    def _print_values_recursive(self, root):
        if root is None:
            return
        self._print_values_recursive(root.left)
        print(root.data)
        self._print_values_recursive(root.right)

    def delete_tree(self):
        """Clear the tree. We will let GC handle it for us"""
        self.root = None

    def get_height(self):
        """Returns height of the BST"""
        curr = self.root
        queue = deque()
        depth = -1
        if curr is None:
            return -1
        queue.append(curr)

        while len(queue) > 0:
            num_nodes_at_level = len(queue)
            depth += 1
            while num_nodes_at_level > 0:
                node = queue.popleft()
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)
                num_nodes_at_level -= 1

        return depth    

    def get_height_recursive(self):
        """Returns height of the internal tree"""
        return self._get_height_recursive(self.root)

    def _get_height_recursive(self, root):
        if root is None:
            return -1
        return max(self._get_height_recursive(root.left), self._get_height_recursive(root.right)) + 1
    
    def get_min(self):
        """Returns minimum value of the tree"""
        curr = self.root
        while curr.left is not None:
            curr = curr.left
        return curr.data

    def get_min_recursive(self):
        """Returns the minimum value stored in the tree"""
        return self._get_min_recursive(self.root)

    def _get_min_recursive(self, root):
        if root is None:
            return float('inf')
        return min(self._get_min_recursive(root.left), self._get_min_recursive(root.right),
                    root.data)

    def _get_min_node(self, root):
        if root is None:
            return root
        walk = root
        while walk.left != None:
            walk = walk.left
        return walk 

    def get_max(self):
        """Returns maximum value of the tree"""
        curr = self.root
        while curr.right is not None:
            curr = curr.right
        return curr.data

    def get_max_recursive(self):
        """Returns the maximum value stored in the tree"""
        return self._get_max_recursive(self.root)

    def _get_max_recursive(self, root):
        if root is None:
            return float('-inf')
        return max(self._get_max_recursive(root.left), self._get_max_recursive(root.right),
                    root.data)

    def is_binary_search_tree(self):
        """Returns whether internal tree meets the binary search tree property"""
        return self._is_binary_search_tree_recursive(self.root, '-inf', 'inf')

    def _is_binary_search_tree_recursive(self, root, min, max):
        if root is None:
            return True

        if (min < root.data < max
            and self._is_binary_search_tree_recursive(root.left, min, root.data)
            and self._is_binary_search_tree_recursive(root.right, root.data, max)):
            return True

        return False

    def delete_value_recursive(self, value):
        """Removes value from the tree"""
        self.root = self._delete_value_recursive(self.root, value)

    def _delete_value_recursive(self, root, value):
        if root is None:
            return None
        if root.data < value:
            root.right = self._delete_value_recursive(root.right, value)
        elif root.data > value:
            root.left = self._delete_value_recursive(root.left, value)
        else:
            if root.duplicate_count > 0:
                root.duplicate_count -= 1
            elif root.left is None and root.right is None:
                return None
            elif root.left and root.right:
                next_node = self._get_min_node(root.right)
                temp = next_node.data
                root.duplicate_count = next_node.duplicate_count
                next_node.duplicate_count = 0
                self._delete_value_recursive(root, next_node.data)
                root.data = temp
            elif root.left:
                root = root.left
            else:
                root = root.right

        return root

    def _get_min_helper(self, root):
        curr = root
        prev = root
        while curr.left != None:
            prev = curr
            curr = curr.left
        return prev, curr

    def delete_value(self, value):
        """Iterative implementation of delete value"""
        curr = self.root
        prev = self.root

        while curr is not None:
            if curr.data == value:
                if curr.duplicate_count > 0:
                    curr.duplicate_count -= 1 
                elif curr.right is None and curr.left is None:
                    prev.delete_child(curr)
                elif curr.right is not None and curr.left is None:
                    prev.add_child(curr.right)
                elif curr.right is None and curr.left is not None:
                    prev.add_child(curr.left)
                elif curr.left and curr.right:
                    parent, minnode = self._get_min_helper(curr.right)

                    curr.data = minnode.data
                    curr.duplicate_count = minnode.duplicate_count
                    if parent != minnode:
                        parent.delete_child(minnode)
                    else:
                        curr.delete_child(minnode)
                return True

            prev = curr
            if value < curr.data:
                curr = curr.left
            else:
                curr = curr.right

        return False

    
    def _find_node(self, root, value):
        if root is None:
            return None
        if value < root.data:
            return self._find_node(root.left, value)
        elif value > root.data:
            return self._find_node(root.right, value)
        else:
            return root

    def get_successor(self, value):
        """Returns next-highest value in the tree after the given value, -1 if none"""
        if self.root is None:
            return -1

        node = self._find_node(self.root, value)
        if node is None:
            return -1

        if node.right:
            return self._get_min_recursive(node.right)
        else:
            ancestor = self.root
            walk = ancestor
            while walk != node:
                if node.data < walk.data:
                    ancestor = walk
                    walk = walk.left
                else:
                    walk = walk.right

            if ancestor.data <= walk.data:
                return -1
            else:
                return ancestor.data

    def get_predecessor(self, value):
        """Returns next-lowest value in the tree before the given value, -1 if none"""
        if self.root is None:
            return -1

        node = self._find_node(self.root, value)
        if node is None:
            return -1

        if node.left:
            return self._get_max_recursive(node.left)
        else:
            ancestor = self.root
            walk = ancestor
            while walk != node:
                if node.data < walk.data:
                    walk = walk.left
                else:
                    ancestor = walk
                    walk = walk.right
            if ancestor.data >= walk.data:
                return -1
            else:
                return ancestor.data