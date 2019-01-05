"""
Nosetests to run linkedlist tests
"""
from linkedlist import LinkedList
from nose.tools import assert_equal, assert_true

class TestLinkedList(object):
    """ Test class for the linkedlist implementation """
    def test_valueat(self):
        llist = LinkedList()
        for i in range(10):
            llist.push_back(i + 1)
            assert_equal(i + 1, llist.value_at(i))

    def test_push_back(self):
        llist = LinkedList()
        for i in range(10):
            llist.push_back(i + 1)
            assert_equal(i + 1, llist.get_back())
        assert_equal(10, len(llist))
        assert_equal(1, llist.get_front())
    
    def test_push_front(self):
        llist = LinkedList()
        for i in range(10):
            llist.push_front(i + 1)
            assert_equal(i + 1, llist.get_front())
        assert_equal(10, len(llist))
        assert_equal(1, llist.get_back())

    def test_pop_front(self):
        llist = LinkedList()
        for i in range(10):
            llist.push_back(i + 1)
        for i in range(10):
            assert_equal(i + 1, llist.pop_front())
            assert_equal(10 - i - 1, len(llist))
        assert_true(llist.is_empty())

    def test_pop_back(self):
        llist = LinkedList()
        for i in range(10):
            llist.push_back(i + 1)
        for i in range(10):
            assert_equal(10 - i, llist.pop_back())
            assert_equal(10 - i - 1, len(llist))
        assert_true(llist.is_empty())

    def test_insert_front(self):
        llist = LinkedList()
        sol = [40, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

        for i in range(10):
            llist.push_back(i + 1)

        llist.insert(0, 40)
        for i in range(11):
            assert_equal(sol[i], llist.value_at(i))
        assert_equal(11, len(llist))

    def test_insert_middle(self):
        llist = LinkedList()
        sol = [1, 2, 3, 4, 5, 40, 6, 7, 8, 9, 10]

        for i in range(10):
            llist.push_back(i + 1)

        llist.insert(5, 40)
        for i in range(11):
            assert_equal(sol[i], llist.value_at(i))
        assert_equal(11, len(llist))

    def test_insert_end(self):
        llist = LinkedList()
        sol = [1, 2, 3, 4, 5, 6, 7, 8, 9, 40, 10]

        for i in range(10):
            llist.push_back(i + 1)

        llist.insert(9, 40)
        for i in range(11):
            assert_equal(sol[i], llist.value_at(i))
        assert_equal(11, len(llist))

    def test_insert_many(self):
        llist = LinkedList()
        sol = [10, 1, 30, 40, 2, 20, 3]
        for i in range(3):
            llist.push_back(i + 1)

        llist.insert(0, 10)
        llist.insert(3, 20)
        llist.insert(2, 30)
        llist.insert(3, 40)

        assert_equal(7, len(llist))
        for i in range(7):
            assert_equal(sol[i], llist.value_at(i))

    def test_erase(self):
        llist = LinkedList()
        sol = [1, 2, 3, 5, 6, 8, 9]
        for i in range(10):
            llist.push_back(i + 1)
        llist.erase(6)
        llist.erase(3)
        llist.erase(len(llist) - 1)
        assert_equal(7, len(llist))

        for i in range(7):
            assert_equal(sol[i], llist.value_at(i))

        for i in range(7):
            llist.erase(0)
            assert_equal(7 - i - 1, len(llist))
        assert_true(llist.is_empty())

    def test_reverse(self):
        llist = LinkedList()
        sol = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
        for i in range(10):
            llist.push_back(i + 1)

        llist.reverse()

        for i in range(10):
            assert_equal(sol[i], llist.value_at(i))
        
        for i in range(10):
            llist.push_back(i + 1)
        sol2 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        for i in range(10, 20):
            assert_equal(sol2[i - 10], llist.value_at(i))

    def test_removevalue(self):
        llist = LinkedList()
        for i in range(10):
            llist.push_back(i + 1)

        llist.remove_value(1)
        assert_equal(9, len(llist))
        sol = [2, 3, 4, 5, 6, 7, 8, 9, 10]
        for i in range(9):
            assert_equal(sol[i], llist.value_at(i))

        llist.remove_value(10)
        assert_equal(8, len(llist))
        sol1 = [2, 3, 4, 5, 6, 7, 8, 9]
        for i in range(8):
            assert_equal(sol1[i], llist.value_at(i))
        
        llist.remove_value(6)
        llist.remove_value(3)
        llist.remove_value(2)
        llist.remove_value(8)
        assert_equal(4, len(llist))
        sol2 = [4, 5, 7, 9]
        for i in range(4):
            assert_equal(sol2[i], llist.value_at(i))
