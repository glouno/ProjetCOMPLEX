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

// EX3 Insertion & self-balancing
Node* rotateRight(Node* y) {
    printf("Performing right rotation on node with key '%c'\n", y->key);
    Node* x = y->left;
    Node* T = x->right;

    // Perform rotation
    x->right = y;
    y->left = T;

    return x;  // x becomes the new root of the rotated subtree
}

Node* rotateLeft(Node* x) {
    printf("Performing left rotation on node with key '%c'\n", x->key);
    Node* y = x->right;
    Node* T = y->left;

    // Perform rotation
    y->left = x;
    x->right = T;

    return y;  // y becomes the new root of the rotated subtree
}

Node* insert_node(Node* root, char key, int priority) {
    if (root == NULL) {
        // Base case: Create a new node if root is null
        return create_node(key, priority);
    }

    // Perform standard BST insertion
    if (key < root->key) {
        // Insert in the left subtree
        root->left = insert_node(root->left, key, priority);

        // Restore heap property if violated
        if (root->left != NULL && root->left->priority < root->priority) {
            root = rotateRight(root);
        }
    } else if (key > root->key) {
        // Insert in the right subtree
        root->right = insert_node(root->right, key, priority);

        // Restore heap property if violated
        if (root->right != NULL && root->right->priority < root->priority) {
            root = rotateLeft(root);
        }
    } else {
        // Duplicate key case
        printf("Error: Duplicate key '%c' is not allowed in Cartesian Tree.\n", key);
    }

    return root; // Return the updated root
}

void insert_tree(Tree* tree, char key, int priority) {
    if (tree == NULL) {
        printf("Error: Tree is NULL.\n");
        return;
    }
    tree->root = insert_node(tree->root, key, priority);
}
