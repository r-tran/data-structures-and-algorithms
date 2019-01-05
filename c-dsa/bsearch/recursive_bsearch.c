#include "bsearch.h"

int recursive_bsearch(int *arr, int low, int high, int val)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2; 
        if ( *(arr + mid) < val)
            return recursive_bsearch(arr, mid + 1, high, val);
        else if (*(arr + mid) > val)
            return recursive_bsearch(arr, low, mid - 1, val);
        else    
            return mid;
    }
    return -1;
}