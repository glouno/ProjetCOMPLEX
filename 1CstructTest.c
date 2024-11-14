#include <stdio.h>
#include <stdlib.h>

// Définition de la structure de données pour un nœud
typedef struct Node {
    char key;                  // Clé du nœud (par exemple, 'A', 'B', ...)
    int priority;              // Priorité du nœud (par exemple, 1, 2, ...)
    struct Node* left;         // Pointeur vers le fils gauche
    struct Node* right;        // Pointeur vers le fils droit
} Node;

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

// Fonction pour libérer la mémoire d'un nœud
void deleteNode(Node* node) {
    if (node != NULL) {
        free(node);
    }
}
