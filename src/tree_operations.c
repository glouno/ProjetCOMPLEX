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
void rotate_right(Tree* tree, Node* pred, Node* curr) {
    Node* B = curr->right;
    curr->right = pred;
    pred->left = B;
    curr->parent = pred->parent;
    pred->parent = curr;

    if (curr->parent == NULL) {
        // curr is now the root of the tree
        tree->root = curr;
    }
    else {
        Node* predpred = curr->parent;
        if (predpred->key > curr->key) {
            predpred->left = curr;
        }
        else {
            predpred->right = curr;
        }
    }
}

void rotate_left(Tree* tree, Node* pred, Node* curr) {
    Node* B = curr->left;
    curr->left = pred;
    pred->right = B;
    curr->parent = pred->parent;
    pred->parent = curr;

    if (curr->parent == NULL) {
        // curr is now the root of the tree
        tree->root = curr;
    }
    else {
        Node* predpred = curr->parent;
        if (predpred->key > curr->key) {
            predpred->left = curr;
        }
        else {
            predpred->right = curr;
        }
    }
}

void insert_tree(Tree* tree, char key, double priority) {
    // first we need to insert as we would in a BST
    Node* pred = NULL;
    Node* curr = tree->root;

    while (curr != NULL) {
        if (key < curr->key) {
            pred = curr;
            curr = curr->left;
        }
        else if (key > curr->key) {
            pred = curr;
            curr = curr->right;
        }
        else {
            printf("Error: tried to insert a key that already exists in the tree.\n");
            return;
        }
    }

    // insert node
    Node* new_node = create_node(key, priority); 
    curr = new_node;
    curr->parent = pred;
    if (pred == NULL) {
        tree->root = curr;
    }
    else if (pred->key > curr->key) {
        pred->left = curr;
    }
    else {
        pred->right = curr;
    }

    // check if we need to rebalance tree
    while ((curr->parent != NULL) && (curr->priority < curr->parent->priority)) {
        if (curr->parent->key > curr->key) {
            rotate_right(tree, curr->parent, curr);
        }
        else {
            rotate_left(tree, curr->parent, curr);
        }
    }
}