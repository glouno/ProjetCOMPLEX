#ifndef CARTESIAN_TREE_H
#define CARTESIAN_TREE_H

// node structure
typedef struct Node {
    char key;
    double priority;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
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

#endif