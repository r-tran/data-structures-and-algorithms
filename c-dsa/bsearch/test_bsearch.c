#include "test_bsearch.h"

int main()
{
    run_all_tests();
    printf("All the tests have passed....\n");
    return 0;
}

void test_bsearch_iterative()
{
    int arr[] = {0};
    assert( 0 == iterative_bsearch(arr, 1, 0));
    assert( -1 == iterative_bsearch(arr, 1, 100));

    int arr1[] = {1, 2, 3, 4};
    for (int i = 0; i < 2; i++)
    {
        assert(i == iterative_bsearch(arr1, 4, i + 1));
    }

    int arr2[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        assert(i == iterative_bsearch(arr2, 5, i + 1));
    }

    int arr3[100];
    for (int i = 0; i < 100; i++)
        arr3[i] = i + 1;
    for (int i =0; i < 100; i++)
        assert(i == iterative_bsearch(arr3, 100, i + 1));


    int arr4[100];
    for (int i = 0; i < 100; i++)
        arr4[i] = i + 1;
    for (int i = 0; i < 100; i++)
        assert(-1 == iterative_bsearch(arr4, 100, i + 101));
}

void test_bsearch_recursive()
{

    int arr[] = {0};
    assert( 0 == recursive_bsearch(arr, 0, 0, 0));
    assert( -1 == recursive_bsearch(arr, 0, 0, 100));

    int arr1[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++)
    {
        assert(i == recursive_bsearch(arr1, 0, 3, i + 1));
    }

    int arr2[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        assert(i == recursive_bsearch(arr2, 0, 4, i + 1));
    }

    int arr3[100];
    for (int i = 0; i < 100; i++)
        arr3[i] = i + 1;
    for (int i =0; i < 100; i++)
        assert(i == recursive_bsearch(arr3, 0, 99, i + 1));
    
    int arr4[100];
    for (int i = 0; i < 100; i++)
        arr4[i] = i + 1;
    for (int i = 0; i < 100; i++)
        assert(-1 == recursive_bsearch(arr4, 0, 99, i + 101));
}
void run_all_tests()
{
    test_bsearch_iterative();
    test_bsearch_recursive();
}
