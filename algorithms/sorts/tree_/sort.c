#include <stdio.h>
#include "sort.h"
#include "tree.h"

void tree_sort(int *m)
{
    tree *root = tree_node_create(m[0]);

    for (int i = 1; i < 12; i++) {
        tree_add_node(root, m[i]);
    }
    int j = 0;

    inorder(root);    
}