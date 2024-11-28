#ifndef CARTESIAN_TREE_H
#define CARTESIAN_TREE_H

// node structure
typedef struct Node {
    char key;
    double priority;
    struct Node* left;
    struct Node* right;
} Node;

// tree structure
typedef struct Tree {
    Node* root;
} Tree;

// function prototypes
Node* create_node(char key, int priority);
Tree* create_empty_tree();
void free_tree(Node* root);
void delete_tree(Tree* tree);
int is_empty(Tree* tree);
Node* get_left_child(Node* node);
Node* get_right_child(Node* node);
void add_left_child(Node* parent, Node* child);
void add_right_child(Node* parent, Node* child);
void print_tree(Node* root, int depth, char dir);
Node* search_tree(Node* root, char key);    // EX2 Search tree
Node* search_tree_withDepth(Node* root, char key, int* depth);
// EX3
Node* rotateRight(Node* y);
Node* rotateLeft(Node* x);
Node* insert_node(Node* root, char key, int priority);
void insert_tree(Tree* tree, char key, int priority);
// EX4
Node* delete_node(Node* root, char key);
void delete_tree_node(Tree* tree, char key);
Node* get_lowest_priority_child(Node* node);
Node* rotate_to_leaf(Node* root, Node* target);


#endif