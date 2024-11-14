#include <stdio.h>
#include <stdlib.h>

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



int main() {
    // Création de l'arbre cartésien
    CartesianTree* tree = createCartesianTree();

    // Création des nœuds
    Node* nodeA = createNode('A', 5);
    Node* nodeB = createNode('B', 3);
    Node* nodeC = createNode('C', 8);
    Node* nodeD = createNode('D', 2);
    Node* nodeE = createNode('E', 6);
    Node* nodeF = createNode('F', 7);
    Node* nodeG = createNode('G', 9);
    Node* nodeH = createNode('H', 1);
    Node* nodeI = createNode('I', 10);
    Node* nodeJ = createNode('J', 12);

    // Construction de l'arbre en liant les nœuds manuellement
    tree->root = nodeH;      // H est la racine
    nodeH->left = nodeD;     // D est le fils gauche de H
    nodeD->left = nodeB;     // B est le fils gauche de D
    nodeB->left = nodeA;     // A est le fils gauche de B
    nodeD->right = nodeE;    // E est le fils droit de D
    nodeE->right = nodeF;    // F est le fils droit de E
    nodeH->right = nodeI;    // I est le fils droit de H
    nodeI->left = nodeC;     // C est le fils gauche de I
    nodeI->right = nodeJ;    // J est le fils droit de I
    nodeC->left = nodeG;     // G est le fils gauche de C

    // Libération de la mémoire de l'arbre après usage
    deleteCartesianTree(tree);

    return 0;
}
