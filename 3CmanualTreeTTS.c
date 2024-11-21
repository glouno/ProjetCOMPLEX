#include <stdio.h>
#include <stdlib.h>

// Traversal Test file !!!
#include "1EmanualTreeTT.h"  // Include the file where Node is defined
#include "tree_traversal.h" // Include the file where inOrderTraversal and preOrderTraversal are defined

// Fonction pour créer un nouveau nœud
Node* createNode(char key, int priority) {
    // Allocation de mémoire pour un nouveau nœud
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        return NULL;
    }
    
    // Initialisation des champs du nœud
    newNode->key = key;
    newNode->priority = priority;
    newNode->left = NULL;      // Pas de fils gauche au début
    newNode->right = NULL;     // Pas de fils droit au début
    
    return newNode;
}

// Is this needed ?
// Fonction pour libérer la mémoire d'un nœud
void deleteNode(Node* node) {
    if (node != NULL) {
        free(node);
    }
}


// Fonction pour créer un arbre cartésien vide
CartesianTree* createCartesianTree() {
    // Allocation de mémoire pour l'arbre
    CartesianTree* tree = (CartesianTree*)malloc(sizeof(CartesianTree));
    if (tree == NULL) {
        printf("Erreur d'allocation de mémoire pour l'arbre\n");
        return NULL;
    }
    // Initialisation de la racine à NULL (arbre vide)
    tree->root = NULL;
    return tree;
}


// Fonction pour vérifier si un arbre cartésien est vide
int isEmpty(CartesianTree* tree) {
    return (tree->root == NULL);
}

// Fonction pour accéder au fils gauche d'un nœud donné
Node* getLeftChild(Node* node) {
    if (node != NULL) {
        return node->left;
    }
    return NULL;
}

// Fonction pour accéder au fils droit d'un nœud donné
Node* getRightChild(Node* node) {
    if (node != NULL) {
        return node->right;
    }
    return NULL;
}

// Fonction pour libérer la mémoire de l'arbre (suppression de tous les nœuds)
void freeTree(Node* node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->left);   // Libère le sous-arbre gauche
    freeTree(node->right);  // Libère le sous-arbre droit
    free(node);             // Libère le nœud actuel
}

void deleteCartesianTree(CartesianTree* tree) {
    if (tree != NULL) {
        freeTree(tree->root);  // Libère tous les nœuds de l'arbre
        free(tree);            // Libère la structure de l'arbre
    }
}

// Function to search for a node with a specific key in the Cartesian tree
Node* searchNode(Node* root, char key) {
    if (root == NULL) {
        // Base case: key not found
        return NULL;
    }

    if (root->key == key) {
        // Key found
        return root;
    } else if (key < root->key) {
        // Search in the left subtree if the key is smaller
        return searchNode(root->left, key);
    } else {
        // Search in the right subtree if the key is larger
        return searchNode(root->right, key);
    }
}

// Function to search for a node and return its depth (or depth of the last visited node if not found)
int searchNodeWithDepth(Node* root, char key, int* depth) {
    *depth = 0;  // Initialize depth to 0 at the root
    Node* current = root;

    while (current != NULL) {
        if (key == current->key) {
            return 1;  // Key found
        }

        (*depth)++;  // Increment depth for each level traversed

        if (key < current->key) {
            current = current->left;  // Move to the left subtree
        } else {
            current = current->right;  // Move to the right subtree
        }
    }

    return 0;  // Key not found
}

// QUESTION 3

// Perform a right rotation at the given node
Node* rotateRight(Node* y) {
    printf("Performing right rotation on node with key '%c'\n", y->key);
    Node* x = y->left;
    Node* T = x->right;

    // Perform rotation
    x->right = y;
    y->left = T;

    return x;  // x becomes the new root of the rotated subtree
}

// Perform a left rotation at the given node
Node* rotateLeft(Node* x) {
    printf("Performing left rotation on node with key '%c'\n", x->key);
    Node* y = x->right;
    Node* T = y->left;

    // Perform rotation
    y->left = x;
    x->right = T;

    return y;  // y becomes the new root of the rotated subtree
}

// Helper function to insert a node into the Cartesian tree and maintain the heap property
Node* insertNode(Node* root, Node* newNode) {
    // Base case: If the tree is empty, the new node becomes the root
    if (root == NULL) {
        printf("Inserting new node with key '%c' and priority %d\n", newNode->key, newNode->priority);
        return newNode;
    }

    // BST Insertion
    if (newNode->key < root->key) {
        printf("Traversing left from node with key '%c'\n", root->key);
        root->left = insertNode(root->left, newNode);

        // Restore heap property: If the new node's priority is less than its parent's
        if (root->left != NULL && root->left->priority < root->priority) {
            printf("Heap property violated at node '%c'. Performing right rotation.\n", root->key);
            root = rotateRight(root);
        }
    } else {
        printf("Traversing right from node with key '%c'\n", root->key);
        root->right = insertNode(root->right, newNode);

        // Restore heap property: If the new node's priority is less than its parent's
        if (root->right != NULL && root->right->priority < root->priority) {
            printf("Heap property violated at node '%c'. Performing left rotation.\n", root->key);
            root = rotateLeft(root);
        }
    }

    return root;
}

// Insert a node into the Cartesian tree
void insertIntoCartesianTree(CartesianTree* tree, char key, int priority) {
    Node* newNode = createNode(key, priority);
    tree->root = insertNode(tree->root, newNode);
}



int main() {
    // Création de l'arbre cartésien
    printf("Creating Cartesian tree...\n");
    CartesianTree* tree = createCartesianTree();

    // Insert nodes as in Question 1.a
    insertIntoCartesianTree(tree, 'A', 5);
    insertIntoCartesianTree(tree, 'B', 3);
    insertIntoCartesianTree(tree, 'C', 8);
    insertIntoCartesianTree(tree, 'D', 2);
    insertIntoCartesianTree(tree, 'E', 6);
    insertIntoCartesianTree(tree, 'F', 7);
    insertIntoCartesianTree(tree, 'G', 9);
    insertIntoCartesianTree(tree, 'H', 1);
    insertIntoCartesianTree(tree, 'I', 10);
    insertIntoCartesianTree(tree, 'J', 12);

    // Print the tree using in-order traversal
    printf("In-Order Traversal:\n");
    inOrderTraversal(tree->root);

    // CAREFUL, the rotation is not fully working as expected

    // Search for a specific key and calculate depth
    char searchKey = 'E';
    int depth;
    printf("Searching for key '%c'...\n", searchKey);
    int found = searchNodeWithDepth(tree->root, searchKey, &depth);

    if (found) {
        printf("Key '%c' found at depth %d.\n", searchKey, depth);
    } else {
        printf("Key '%c' not found. Closest depth: %d.\n", searchKey, depth);
    }

    // Libération de la mémoire de l'arbre après usage
    printf("\nDeleting tree...\n");
    deleteCartesianTree(tree);

    printf("Program finished successfully.\n");
    return 0;
}
