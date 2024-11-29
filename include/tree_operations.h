#ifndef TREE_OPERATIONS_H
#define TREE_OPERATIONS_H

#include "cartesian_tree.h"

// EX2 search functions
Node* search_tree(Node* root, char key);
Node* search_tree_with_depth(Node* root, char key, int* depth);

// EX3 insert function
void rotate_right(Tree* tree, Node* pred, Node* curr);
void rotate_left(Tree* tree, Node* pred, Node* curr);
void insert_tree(Tree* tree, char key, double priority);

// EX4 delete function
void delete_node(Tree* tree, char key);

#endif