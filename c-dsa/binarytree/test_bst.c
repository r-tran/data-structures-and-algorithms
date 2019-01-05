#include "test_bst.h"

void run_all_tests()
{
    test_insert();
    test_get_node_count();
    test_delete_tree();
    test_is_in_tree();
    test_get_height();
    test_get_min();
    test_get_max();
    test_is_bst();
    test_remove_value();
    test_get_predecessor();
    test_get_successor();
}

void test_insert()
{
    _node_t *node = NULL;
    insert(&node, 5);
    insert(&node, 4);
    insert(&node, 100);
    insert(&node, 3);
    insert(&node, 2);
    insert(&node, 1);

    assert(get_node_count(node) == 6);
}

void test_get_node_count()
{
    _node_t *node = NULL;
    for (int i = 0; i < 100; i++)
    {
        insert(&node, i);
        assert(get_node_count(node) == i + 1);
    }
}

void test_delete_tree()
{
    _node_t *node = NULL;
    insert(&node, 3);
    insert(&node, 4);
    insert(&node, 1);

    delete_tree(&node);
    assert(node == NULL);
    assert(get_node_count(node) == 0);
}

void test_is_in_tree()
{
    _node_t *node = NULL; 
    insert(&node, 100);
    insert(&node, 200);
    insert(&node, 300);
    insert(&node, 400);
    insert(&node, 500);
    insert(&node, 600);
    insert(&node, 700);
    assert(is_in_tree(node, 100));
    assert(is_in_tree(node, 200));
    assert(is_in_tree(node, 300));
    assert(is_in_tree(node, 400));
    assert(is_in_tree(node, 500));
    assert(is_in_tree(node, 600));
    assert(is_in_tree(node, 700));
    assert(!is_in_tree(node, 800));
    assert(!is_in_tree(node, 0));
}

void test_get_height()
{
    _node_t *node = NULL; 
    insert(&node, 10);
    insert(&node, 20);
    insert(&node, 30);
    insert(&node, 40);
    insert(&node, 50);
    insert(&node, 9);
    assert(get_height(node) == 4);
}

void test_get_min()
{
    _node_t *node = NULL; 
    insert(&node, 100);
    insert(&node, 50);
    insert(&node, 20);
    insert(&node, 75);
    insert(&node, 150);
    insert(&node, 125);

    assert(get_min(node) == 20);
}

void test_get_max()
{
    _node_t *node = NULL; 
    insert(&node, 100);
    insert(&node, 50);
    insert(&node, 20);
    insert(&node, 75);
    insert(&node, 150);
    insert(&node, 125);

    assert(get_max(node) == 150);
}

void test_is_bst()
{
    _node_t *node = NULL;
    insert(&node, 14);
    insert(&node, 16);
    insert(&node, 10);
    insert(&node, 12);

    assert(is_bst(node));
    node->left->right->right = new_node(15);
    assert(!is_bst(node));
}

void test_remove_value()
{
    // Case 1: No children, Case 2: Single child
    _node_t *node = NULL;
    insert(&node, 10);
    insert(&node, 20);
    insert(&node, 5);
    insert(&node, 4);
    insert(&node, 3);
    insert(&node, 7);
    insert(&node, 8);
    insert(&node, 9);

    assert(is_in_tree(node, 10));
    remove_value(&node, 7);
    assert(!is_in_tree(node, 7));

    // Case 3: Two children
    _node_t *tree = NULL;
    insert(&tree, 12);
    insert(&tree, 5);
    insert(&tree, 15);
    insert(&tree, 3);
    insert(&tree, 1);
    insert(&tree, 7);
    insert(&tree, 9);
    insert(&tree, 8);
    insert(&tree, 11);
    insert(&tree, 13);
    insert(&tree, 17);
    insert(&tree, 14);

    assert(is_in_tree(tree, 9));
    printf("Tree before removal: ");
    print_values(tree);
    printf("\n");
    remove_value(&tree, 9);
    printf("Tree after removal: ");
    print_values(tree);
    printf("\n");

    assert(!is_in_tree(tree, 9));
    assert(is_in_tree(tree, 8));
    assert(is_in_tree(tree, 11));
}

void test_get_predecessor()
{
    _node_t *tree = NULL;
    insert(&tree, 12);
    insert(&tree, 5);
    insert(&tree, 15);
    insert(&tree, 3);
    insert(&tree, 1);
    insert(&tree, 7);
    insert(&tree, 9);
    insert(&tree, 8);
    insert(&tree, 11);
    insert(&tree, 13);
    insert(&tree, 17);
    insert(&tree, 14);

    assert(get_predecessor(tree, 8) == 7);
    assert(get_predecessor(tree, 12) == 11);
}

void test_get_successor()
{
    _node_t *tree = NULL;
    insert(&tree, 12);
    insert(&tree, 5);
    insert(&tree, 15);
    insert(&tree, 3);
    insert(&tree, 1);
    insert(&tree, 7);
    insert(&tree, 9);
    insert(&tree, 8);
    insert(&tree, 11);
    insert(&tree, 13);
    insert(&tree, 17);
    insert(&tree, 14);
    
    assert(get_successor(tree, 11) == 12);
    assert(get_successor(tree, 8) == 9);
    assert(get_successor(tree, 13) == 14);
}

int main()
{
    run_all_tests();
    printf("All the tests have passed....\n");
}