// Fundamental operations on trees: search, insert, delete

#include <stdio.h>
#include <stdlib.h>
#include "../include/cartesian_tree.h"
#include "../include/tree_operations.h"

// search functions
Node* search_tree(Node* root, char key) {
    // key not found
    if (root == NULL) {
        return NULL;
    }

    // compare key to current node key
    if (key == root->key) {
        return root;
    }
    else if (key < root->key) {
        return search_tree(root->left, key);
    }
    else {
        return search_tree(root->right, key);
    }
}

Node* search_tree_with_depth(Node* root, char key, int* depth) {
    // key not found
    if (root == NULL) {
        return NULL;
    }

    // compare key to current node key; update depth
    if (key == root->key) {
        return root;
    }
    else if (key < root->key) {
        (*depth)++;
        return search_tree_with_depth(root->left, key, depth);
    }
    else {
        (*depth)++;
        return search_tree_with_depth(root->right, key, depth);
    }
}

// insert function
