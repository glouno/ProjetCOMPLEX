#ifndef MANUAL_TREE_H
#define MANUAL_TREE_H

// Définition de la structure de données pour un nœud
typedef struct Node {
    char key;                  // Clé du nœud (par exemple, 'A', 'B', ...)
    int priority;              // Priorité du nœud (par exemple, 1, 2, ...)
    struct Node* left;         // Pointeur vers le fils gauche
    struct Node* right;        // Pointeur vers le fils droit
} Node;

// Structure de données pour l'arbre cartésien
typedef struct CartesianTree {
    Node* root;  // Pointeur vers le nœud racine
} CartesianTree;

// Function declarations
Node* createNode(char key, int priority);
void deleteNode(Node* node);
CartesianTree* createCartesianTree();
void deleteCartesianTree(CartesianTree* tree);
int isEmpty(CartesianTree* tree);

#endif // MANUAL_TREE_H
