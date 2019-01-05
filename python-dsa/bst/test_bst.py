"""
Module to test the BST implementation 
"""

from bst import BinarySearchTree, Node
from nose.tools import assert_equal, assert_true

class TestBinarySearchTree(object):
    """Test class container for BST implementation"""
    def test_bst_insert_recursive(self):
        bst = BinarySearchTree()
        node_data = [10, 20, 5, 4, 3, 7, 8, 9, 7, 7]
        for value in node_data:
            bst.insert_recursive(value)
        assert_equal(10, bst.root.data)
        assert_equal(20, bst.root.right.data)
        assert_equal(5, bst.root.left.data)
        assert_equal(4, bst.root.left.left.data)
        assert_equal(3, bst.root.left.left.left.data)
        assert_equal(7, bst.root.left.right.data)
        assert_equal(8, bst.root.left.right.right.data)
        assert_equal(9, bst.root.left.right.right.right.data)

        assert_equal(2, bst.root.left.right.duplicate_count)

    def test_bst_getheight_recursive(self):
        bst = BinarySearchTree()
        node_data = [10, 20, 5, 4, 3, 7, 8, 9, 7, 7]
        for value in node_data:
            bst.insert_recursive(value)
        assert_equal(4, bst.get_height_recursive())

    def test_bst_getmin_recursive(self):
        bst = BinarySearchTree()
        node_data = [10, 20, 5, 4, 3, 7, 8, 9, 7, 7]
        for value in node_data:
            bst.insert_recursive(value)
        assert_equal(3, bst.get_min_recursive())

        bst2 = BinarySearchTree()
        bst2.insert_recursive(1000)
        assert_equal(1000, bst2.get_min_recursive())
    
    def test_bst_getmax_recursive(self):
        bst = BinarySearchTree()
        node_data = [10, 20, 5, 4, 3, 7, 8, 9, 7, 7]
        for value in node_data:
            bst.insert_recursive(value)
        assert_equal(20, bst.get_max_recursive())

        bst2 = BinarySearchTree()
        bst2.insert_recursive(1000)
        assert_equal(1000, bst2.get_max_recursive())
    
    def test_bst_isbinarysearchtree_recursive(self):
        bst = BinarySearchTree()
        bst.insert_recursive(14)
        bst.insert_recursive(11)
        bst.insert_recursive(7)
        bst.root.left.right = Node(15)
        assert_equal(False, bst.is_binary_search_tree())

    def test_bst_deletevalue_recursive(self):
        bst = BinarySearchTree()
        bst.insert_recursive(12)
        bst.insert_recursive(5)
        bst.insert_recursive(15)
        bst.insert_recursive(3)
        bst.insert_recursive(7)
        bst.insert_recursive(1)
        bst.insert_recursive(9)
        bst.insert_recursive(8)
        bst.insert_recursive(11)
        bst.insert_recursive(13)
        bst.insert_recursive(14)
        bst.insert_recursive(17)
        bst.insert_recursive(20)
        bst.insert_recursive(18)

        bst.delete_value_recursive(9)
        bst.delete_value_recursive(13)
        bst.delete_value_recursive(20)
        bst.delete_value_recursive(1)

        assert_equal(bst.get_max_recursive(), 18)
        assert_true(bst.get_min_recursive(), 3)

    def test_bst_getsuccessor(self):
        bst = BinarySearchTree()
        bst.insert_recursive(4)
        bst.insert_recursive(8)
        bst.insert_recursive(6)
        bst.insert_recursive(5)
        bst.insert_recursive(7)

        assert_equal(8, bst.get_successor(7))
        assert_equal(5, bst.get_successor(4))
        assert_equal(-1, bst.get_successor(8))
    
    def test_bst_getpredecessor(self):
        bst = BinarySearchTree()
        bst.insert_recursive(4)
        bst.insert_recursive(8)
        bst.insert_recursive(6)
        bst.insert_recursive(5)
        bst.insert_recursive(7)

        assert_equal(4, bst.get_predecessor(5))
        assert_equal(6, bst.get_predecessor(7))
        assert_equal(5, bst.get_predecessor(6))
        assert_equal(-1, bst.get_predecessor(4))

    def test_bst_insert_iterative(self):
        bst = BinarySearchTree()
        node_data = [10, 20, 5, 4, 3, 7, 8, 9, 7, 7]
        for value in node_data:
            bst.insert(value)
        assert_equal(10, bst.root.data)
        assert_equal(20, bst.root.right.data)
        assert_equal(5, bst.root.left.data)
        assert_equal(4, bst.root.left.left.data)
        assert_equal(3, bst.root.left.left.left.data)
        assert_equal(7, bst.root.left.right.data)
        assert_equal(8, bst.root.left.right.right.data)
        assert_equal(9, bst.root.left.right.right.right.data)

        assert_equal(2, bst.root.left.right.duplicate_count)

    def test_bst_getheight_iterative(self):
        bst = BinarySearchTree()
        node_data = [10, 20, 5, 4, 3, 7, 8, 9, 7, 7]
        for value in node_data:
            bst.insert(value)
        assert_equal(4, bst.get_height())

        bst2 = BinarySearchTree()
        bst2.insert(10)
        bst2.insert(4)
        bst2.insert(2)
        bst2.insert(6)
        bst2.insert(8)
        bst2.insert(12)
        bst2.insert(20)
        bst2.insert(24)
        bst2.insert(13)
        bst2.insert(18)
        bst2.insert(19)
        bst2.insert(14)
        bst2.insert(16)
        assert_equal(6, bst2.get_height())

    def test_bst_get_minvalue_iterative(self):
        bst = BinarySearchTree()
        inserts = [20, 10, 14, 15, 9, 4, 19, 26]
        for node in inserts:
            bst.insert(node)
        assert_equal(4, bst.get_min())

    def test_bst_get_maxvalue_iterative(self):
        bst = BinarySearchTree()
        inserts = [24, 40, 42, 31, 8, 17, 84]
        for node in inserts:
            bst.insert(node)
        assert_equal(84, bst.get_max())

    def test_bst_deletevalue_iterative(self):
        bst = BinarySearchTree()
        inserts = [12, 5, 15, 3, 7, 1, 9, 8, 11, 13, 14, 17, 20, 18]
        for node in inserts:
            bst.insert(node)

        bst.delete_value(9)
        bst.delete_value(13)
        bst.delete_value(20)
        bst.delete_value(1)

        assert_equal(bst.get_max(), 18)
        assert_equal(bst.get_min(), 3)

