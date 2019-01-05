#include "bst.h"

void _delete_node(_node_t **node)
{
    free(*node);
    *node = NULL;
}

bool _is_bst_util(_node_t *root, int minVal, int maxVal)
{
    if (root == NULL)
        return true; 
    return root->data > minVal && root->data < maxVal 
        && _is_bst_util(root->left, minVal, root->data)
        && _is_bst_util(root->right, root->data, maxVal);
}

_node_t *new_node(int value)
{
    _node_t *newnode = malloc(sizeof(_node_t));    
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = value;
    return newnode;
}

void insert(_node_t **root, int value)
{
    if (*root == NULL)
    {
        *root = new_node(value);
        return;
    }

    if ((*root)->data < value)
        insert(&((*root)->right), value);
    else 
        insert(&((*root)->left), value);
}

int get_node_count(_node_t *root)
{
    if (root == NULL)
        return 0;
    return get_node_count(root->left) + get_node_count(root->right) + 1;
}

void print_values(_node_t *root)
{
    if (root == NULL)
        return;
    print_values(root->left);
    printf("%d ", root->data);
    print_values(root->right);
}

void delete_tree(_node_t **root)
{
    if (*root == NULL)
        return;
    delete_tree(&((*root)->left));
    delete_tree(&((*root)->right));
    _delete_node(root);
}

bool is_in_tree(_node_t *root, int data)
{
    if (root == NULL)
        return false;
    if (root->data < data)
        return is_in_tree(root->right, data);
    else if (root->data > data)
        return is_in_tree(root->left, data);
    else
        return true;
}

int get_height(_node_t *root)
{
    if (root == NULL)
        return -1;
    int leftHeight = get_height(root->left);
    int rightHeight = get_height(root->right);
    int bestHeight = leftHeight > rightHeight ? leftHeight : rightHeight;
    return bestHeight + 1;
}

int get_min(_node_t *root)
{
    if (root == NULL)
        exit(EXIT_FAILURE);
    _node_t *curr = root;
    while (curr->left != NULL)
        curr = curr->left; 

    return curr->data; 
}

int get_max(_node_t *root)
{
    if (root == NULL)
        exit(EXIT_FAILURE);
    _node_t *curr = root; 
    while (curr->right != NULL)
        curr = curr->right;
    
    return curr->data; 
}

bool is_bst(_node_t *root)
{
    return _is_bst_util(root, -100000000, 10000000);
}

void remove_value(_node_t **root, int value)
{
    if (root == NULL || *root == NULL)
    {
        printf("Could not locate the value to delete\n");
        exit(EXIT_FAILURE);
    }
        
    while (*root != NULL)
    {
        if ((*root)->data < value)
            return remove_value(&(*root)->right, value);
        else if ((*root)->data > value)
            return remove_value(&(*root)->left, value);
        else
        {
            if ((*root)->left == NULL && (*root)->right == NULL)
                _delete_node(root);

            else if ((*root)->left != NULL && (*root)->right != NULL)
            {
               (*root)->data = get_min((*root)->right);
               remove_value(&(*root)->right,(*root)->data);
            }
            else if ((*root)->left != NULL)
            {
                _node_t *tempnode = *root; 
                *root = ((*root)->left); 
                _delete_node(&tempnode);
            }
            else if ((*root)->right != NULL)
            {
                _node_t *tempnode = *root;
                *root = (*root)->right;
                _delete_node(&tempnode);
            }

            return;
        }
    }

}

_node_t *_find_node(_node_t *root, int data)
{
    if (root == NULL)
        return NULL;
    if (root->data < data)
        return _find_node(root->right, data);
    else if (root->data > data)
        return _find_node(root->left, data);
    else
    {
        return root;
    }
}

int get_successor(_node_t *root, int data)
{
    _node_t *curr = _find_node(root, data);
    if (curr == NULL) exit(EXIT_FAILURE);
    if (curr->right != NULL)
    {
        _node_t *walk = curr->right;
        while (walk->left != NULL)
            walk = walk->left;
        return walk->data;
    }
    _node_t *successor = root;
    _node_t *walk = root;
    while (walk != curr)
    {
        if (walk->data < curr->data)
            walk = walk->right;
        else
        {
            successor = walk; 
            walk = walk->left;
        }
    }

    return successor->data;
}

int get_predecessor(_node_t *root, int data)
{
     _node_t *curr = _find_node(root, data);
     if (curr == NULL) exit(EXIT_FAILURE);
     if (curr->left != NULL)
     {
         _node_t *walk = curr->left;
         while (walk->right != NULL)
            walk = walk->right; 
        return walk->data;
     }

     _node_t *predecessor = root;
     _node_t *walk = root;
     while (walk != curr)
     {
         if (walk->data < curr->data)
         {
             predecessor = walk;
             walk = walk->right;
         }
         else
            walk = walk->left; 
     }

     return predecessor->data;
}

