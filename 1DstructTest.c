#include <stdio.h>
#include <stdlib.h>

// Structure de données pour un nœud (déjà définie précédemment)
typedef struct Node {
    char key;
    int priority;
    struct Node* left;
    struct Node* right;
} Node;

// Structure de données pour l'arbre cartésien
typedef struct CartesianTree {
    Node* root;  // Pointeur vers le nœud racine
} CartesianTree;

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
