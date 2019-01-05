"""
Test linear probing implementation of the hash table.
"""
from nose.tools import assert_equal, assert_true, raises
from hashtable import HashTable

class TestHashTable(object):
    """Test class for the hashtable"""

    def test_hashtable_hashcompression(self):
        table = HashTable()
        keys = ['hello', 'world', 'i', 'like', 'cats', 'puppy']
        results = [table.hash(keyname) for keyname in keys]
        for result in results:
            assert_true(result >= 0 and result < 11)

    def test_hashtable_addnewitem(self):
        table = HashTable()
        
        table['lions'] = 1
        assert_equal(1, table['lions'])
        assert_equal(1, len(table))
        
        table['tigers'] = 2
        assert_equal(2, table['tigers'])
        assert_equal(2, len(table))
        
        table['oh my!'] = 3
        assert_equal(3, table['oh my!'])
        assert_equal(3, len(table))

    def test_hashtable_replaceitem(self):
        table = HashTable()
        table['lions'] = 4
        table['tigers'] = 3
        table['tigers'] = 100
        
        assert_equal(2, len(table))
        assert_equal(100, table['tigers'])
    
    def test_hashtable_resizeup(self):
        table = HashTable()
        table['lions'] = 1
        table['tigers'] = 2
        table['oh'] = 3
        table['my'] = 4
        table['!'] = 5
        assert_equal(11, table.capacity)

        table['hello'] = 6
        assert_equal(22, table.capacity)
        numkeys = [k for k in table]
        assert_equal(6, len(numkeys))
    
    @raises(KeyError)
    def test_hashtable_delete(self):
        table = HashTable()
        table['a'] = 1
        table['b'] = 2
        table['c'] = 3
        table['d'] = 4
        del table['d']
        assert_equal(3, len(table))
        table['d']

