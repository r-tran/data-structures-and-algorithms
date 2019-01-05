class BinarySearch(object):
    """Contains different methods for binary search"""

    @staticmethod
    def iterative_binary_search(A, key):
        """Classic binary search for sorted Array A"""
        lo, hi = 0, len(A) - 1
        while lo <= hi:
            mid = lo + (hi - lo) / 2
            if A[mid] < key:
                lo = mid + 1
            elif A[mid] > key:
                hi = mid - 1
            else:
                return mid
        return -1

    @staticmethod
    def recursive_binary_search(A, lo, hi, key):
        """Uses recursion for sorted array A"""
        mid = lo + (hi - lo) / 2
        if lo <= hi:
            if A[mid] < key:
                return BinarySearch.recursive_binary_search(A, mid + 1, hi, key)
            elif A[mid] > key:
                return BinarySearch.recursive_binary_search(A, lo, mid - 1, key)
            else:
                return mid
        return -1
