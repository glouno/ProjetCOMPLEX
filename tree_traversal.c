#include <stdio.h>
#include "1EmanualTreeTT.h"
#include "tree_traversal.h"

// Function to perform in-order traversal and print nodes
void inOrderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    inOrderTraversal(node->left);  // Visit left child
    printf("Node Key: %c, Priority: %d\n", node->key, node->priority);  // Print current node
    inOrderTraversal(node->right); // Visit right child
}

// Function to perform pre-order traversal and print nodes
void preOrderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("Node Key: %c, Priority: %d\n", node->key, node->priority);  // Print current node
    preOrderTraversal(node->left);  // Visit left child
    preOrderTraversal(node->right); // Visit right child
}
