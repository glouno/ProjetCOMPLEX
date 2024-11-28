// Code for creating and working with cartesian trees

#include <stdio.h>
#include <stdlib.h>
#include "../include/cartesian_tree.h"

// functions for managing the creation and deletion of nodes
Node* create_node(char key, int priority) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Error in allocating memory for a new node.\n");
        return NULL;
    }

    new_node->key = key;
    new_node->priority = priority;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// functions for managing the creation and deletion of trees
Tree* create_empty_tree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));

    if (tree == NULL) {
        printf("Error in allocating memory for a new tree.\n");
        return NULL;
    }

    return tree;
}

void free_tree(Node* root) {
    if (root == NULL) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void delete_tree(Tree* tree) {
    if (tree != NULL) {
        free_tree(tree->root);
        free(tree);
    }
}

// utility functions
int is_empty(Tree* tree) {
    return (tree->root == NULL);
}

Node* get_left_child(Node* node) {
    if (node != NULL) {
        return node->left;
    }
    return NULL;
}

Node* get_right_child(Node* node) {
    if (node != NULL) {
        return node->right;
    }
    return NULL;
}

void add_left_child(Node* parent, Node* child) {
    if (parent != NULL) {
        parent->left = child;
    }
    else {
        printf("Error: parent node is null.\n");
    }
    return;
}

void add_right_child(Node* parent, Node* child) {
    if (parent != NULL) {
        parent->right = child;
    }
    else {
        printf("Error: parent node is null.\n");
    }
    return;
}


// Special function to print the tree structure
void print_tree(Node* root, int depth, char dir) {
    if (root == NULL) {
        return;
    }

    // print depth number of tabs
    for (int i = 0; i < depth; i++) {
        printf("\t");
    }
    printf("%c, K: %c, P: %.0f\n", dir, root->key, root->priority);
    print_tree(root->left, depth + 1, 'L');
    print_tree(root->right, depth + 1, 'R');
}

// additional utility functions
Node* search_tree(Node* root, char key) {   // EX2 Search tree
    if (root == NULL) {
        return NULL; // Key not found
    }

    if (root->key == key) {
        return root; // Key found
    } else if (key < root->key) {
        return search_tree(root->left, key); // Search in the left subtree
    } else {
        return search_tree(root->right, key); // Search in the right subtree
    }
}

Node* search_tree_withDepth(Node* root, char key, int* depth) {   // EX2 Search tree with depth
    *depth = 0; // Initialize depth at the root
    while (root != NULL) {
        if (key == root->key) {
            return root; // Key found
        }
        (*depth)++; // Increment depth as we move down the tree

        if (key < root->key) {
            root = root->left; // Move to the left subtree
        } else {
            root = root->right; // Move to the right subtree
        }
    }

    return NULL; // Key not found
}
