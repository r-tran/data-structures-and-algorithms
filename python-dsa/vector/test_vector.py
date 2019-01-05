"""
Runs the tests for the vector
"""
from nose.tools import assert_equal, assert_true
from nose.tools import raises
from vector import Vector

class TestVector(object):
    """ Test class for the vector """

    def test_vector_constructordefault(self):
        vec = Vector()
        assert_equal(16, vec._capacity)
        assert_equal(0, vec._size)

    def test_vector_constructorcapacity(self):
        vec = Vector(17)
        assert_equal(32, vec._capacity)
        assert_equal(0, vec._size)

        vec1 = Vector(33)
        assert_equal(64, vec1._capacity)
        assert_equal(0, vec1._size)

    def test_vector_len(self):
        vec = Vector()
        for i in range(10):
            vec.push_back(i)
        n_elements = len(vec)

        assert_equal(10, n_elements)

    def test_vector_indexing(self):
        vec = Vector()
        for i in range(1, 11):
            vec.push_back(i)
            assert_equal(vec[i - 1], i)

    @raises(IndexError)
    def test_vector_indexing_throws(self):
        vec = Vector(20)
        for i in range(20):
            vec.push_back("hi")
        element = vec[-1]

    def test_vector_getsize(self):
        vec = Vector(32)
        for i in range(100):
            vec.push_back(i)
        size = vec.get_size()

        assert_equal(100, size)

    def test_vector_getcapacity(self):
        vec = Vector(32)
        for i in range(100):
            vec.push_back(i)
        capacity = vec.get_capacity()

        assert_equal(128, capacity)

    def test_vector_isempty(self):
        vec = Vector(256)
        for i in range(100):
            vec.push_back(i)
        for i in range(100):
            assert_true(not vec.is_empty())
            vec.pop()
        assert_equal(0, vec.get_size())
        assert_true(vec.is_empty)

    @raises(IndexError)
    def test_vector_atindex_throws(self):
        vec = Vector(130)
        for i in range(10):
            vec.push_back(i)
        vec.at_index(10)

    def test_vector_pushback(self):
        vec = Vector(32)
        for i in range(10):
            vec.push_back(i + 10)
            assert_equal(vec._data[i], i + 10)
        assert_equal(10, vec._size)
        assert_equal(32, vec._capacity)

    def test_vector_pushbackresize(self):
        vec = Vector(256)
        for i in range(256):
            vec.push_back("hello")
        assert_equal(256, vec._capacity)
        vec.push_back("boom")
        assert_equal(512, vec._capacity)
        assert_equal(257, vec._size)

    @raises(IndexError)
    def test_vector_insert_throws(self):
        vec = Vector(16)
        for i in range(10):
            vec.push_back(i)
        vec.insert(-1, None)

    def test_vector_insert_empty(self):
        vec = Vector(16)
        vec.push_back(99)
        assert_equal(1, vec._size)
        assert_equal(16, vec._capacity)
        assert_equal(99, vec._data[0])

    def test_vector_insertfront(self):
        vec = Vector()
        for i in range(10):
            vec.push_back(i)
        vec.insert(0, 100)
        assert_equal(100, vec[0])
        assert_equal(11, vec._size)
        for i in range(1, 11):
            assert_equal(i - 1, vec[i])

    def test_vector_insertend(self):
        vec = Vector()
        for i in range(10):
            vec.insert(i, i + 10)
            assert_equal(i + 10, vec[i])

    def test_vector_insertresize(self):
        vec = Vector(32)
        for i in range(32):
            vec.insert(i, 100)
        assert_equal(32, vec._capacity)
        vec.insert(32, 100)
        assert_equal(64, vec._capacity)
        for i in range(64):
            vec.insert(i, 100)
        assert_equal(128, vec._capacity)

    def test_vector_prepend(self):
        vec = Vector(32)
        for i in range(10):
            vec.prepend(i)
        for i in range(10):
            assert_equal(9 - i, vec[i])

    def test_vector_pop(self):
        vec = Vector(16)
        for i in range(16):
            vec.push_back(i)
        for i in range(15, -1, -1):
            val = vec.pop()
            assert_equal(i, val)
            assert_equal(i, vec._size)

    def test_vector_popresize(self):
        vec = Vector(16)
        for i in range(17):
            vec.push_back(i)
        assert_equal(32, vec._capacity)
        for i in range(9):
            vec.pop()
        assert_equal(16, vec._capacity)
        for i in range(8):
            vec.pop()
        assert_true(vec.is_empty())
        assert_equal(16, vec._capacity)

    @raises(IndexError)
    def test_vector_deletethrows(self):
        vec = Vector(16)
        vec.push_back(1)
        vec.delete(1)

    def test_vector_deletefront(self):
        vec = Vector(32)
        for i in range(32):
            vec.push_back(i)
        vec.delete(0)
        for i in range(31):
            assert_equal(i + 1, vec[i])
        assert_equal(31, vec._size)

    def test_vector_deleteend(self):
        vec = Vector(16)
        for i in range(16):
            vec.push_back(i)
        vec.delete(15)
        assert_equal(15, vec._size)
        for i in range(vec._size):
            assert_equal(i, vec[i])

    def test_vector_deleteresize(self):
        vec = Vector(32)
        for i in range(33):
            vec.push_back(i)
        assert_equal(64, vec._capacity)
        for i in range(17):
            vec.delete(0)
        assert_equal(32, vec._capacity)
        for i in range(12):
            vec.delete(0)
        assert_equal(16, vec._capacity)
        while not vec.is_empty():
            vec.delete(0)
        assert_equal(16, vec._capacity)

    def test_vector_removesingleitem(self):
        vec = Vector(16)
        for i in range(16):
            vec.push_back(i)
        vec.remove(3)
        assert_equal(15, vec._size)
        assert_equal(4, vec[3])

    def test_vector_removeduplicateitems(self):
        vec = Vector(16)
        vec.push_back(1)
        vec.push_back(20)
        vec.push_back(2)
        vec.push_back(3)
        vec.push_back(20)
        vec.push_back(4)
        vec.push_back(5)
        vec.push_back(20)
        vec.push_back(20)
        vec.remove(20)
        for i in range(1, 6):
            assert_equal(i, vec[i-1])

    def test_vector_removeallitems(self):
        vec = Vector(16)
        for i in range(16):
            vec.push_back(100)
        vec.remove(100)
        assert_true(vec.is_empty())

    def test_vector_finditem(self):
        vec = Vector(128)
        for i in range(128):
            vec.push_back(i + 1000)
        val = vec.find(1015)
        assert_equal(15, val)
    
    @raises(ValueError)
    def test_vector_finditemdoesnotexist(self):
        vec = Vector(128)
        for i in range(128):
            vec.push_back(i + 1000)
        val = vec.find(1)