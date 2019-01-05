from nose.tools import assert_equal
from bsearch import BinarySearch

class TestBinarySearch(object):

    def test_binarysearchiterative_locateskey(self):
        arr = [1, 2, 3, 4, 5, 6]
        index = BinarySearch.iterative_binary_search(arr, 6)
        assert_equal(5, index)

    def test_binarysearchiterative_locateskeyinlargesize(self):
        arr = [i+1 for i in range(200)]
        for i in range(200):
            index = BinarySearch.iterative_binary_search(arr, i + 1)
            assert_equal(i, index)

    def test_binarysearchiterative_cannotlocatekey(self):
        arr = [1, 2, 3, 4, 5, 6]
        index = BinarySearch.iterative_binary_search(arr, 10)
        assert_equal(-1, index)

    def test_binarysearchrecursive_locateskey(self):
        arr = [1, 2, 3, 4, 5, 6]
        index = BinarySearch.recursive_binary_search(arr,0,5, 6)
        assert_equal(5, index)

    def test_binarysearchrecursive_locateskeyinlargesize(self):
        arr = [i+1 for i in range(200)]
        for i in range(200):
            index = BinarySearch.recursive_binary_search(arr, 0, 199, i + 1)
            assert_equal(i, index)

    def test_binarysearchrecursive_cannotlocatekey(self):
        arr = [1, 2, 3, 4, 5, 6]
        index = BinarySearch.recursive_binary_search(arr, 0, 5, 10)
        assert_equal(-1, index)

     