using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DSA.Binary_Search
{
    public class BinarySearch<T> where T: IComparable
    {
        public static int IterativeBinarySearch(T[] arr, T key)
        {
            if (arr.Length == 0) return -1;

            int lo = 0;
            int hi = arr.Length - 1;
            
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (arr[mid].CompareTo(key) > 0)
                    hi = mid - 1;
                else if (arr[mid].CompareTo(key) < 0)
                    lo = mid + 1;
                else
                    return mid;
            }

            return -1;
        }

        public static int RecursiveBinarySearch(T[] arr, int lo, int hi, T key)
        {            
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (arr[mid].CompareTo(key) > 0)
                    return RecursiveBinarySearch(arr, 0, mid - 1, key);
                else if (arr[mid].CompareTo(key) < 0)
                    return RecursiveBinarySearch(arr, mid + 1, hi, key);
                else
                    return mid;
            }

            return -1;
        }
    }
}
