#include "bsearch.h"

int iterative_bsearch(int *arr, int n, int val)
{
    if (arr == NULL)
        exit(EXIT_FAILURE);

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (*(arr + mid) == val)
            return mid;
        if (*(arr + mid) < val)
            low = mid + 1; 
        else
            high = mid - 1; 
    }

    return -1; 
}