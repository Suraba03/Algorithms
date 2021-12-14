#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int value;
    struct tree *right;
    struct tree *left;
} tree;

tree *tree_node_create(int crt_value);
tree *search(tree *root, int srch_value);
void print_tree(tree *root, int level);
tree *tree_find_minimum(tree *root);
tree *tree_add_node(tree *root, int add_value);
tree *tree_delete_node(tree *root, int del_value);
void inorder(tree *root);
int checkUtil(tree *root, int level, int *leafLevel);
int check(tree *root);
void delete_tree(tree *curr);

#endif