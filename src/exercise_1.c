#include <stdio.h>
#include <stdlib.h>
#include "../include/cartesian_tree.h"

int main() {
    // create nodes and empty tree
    Tree* ct = create_empty_tree();
    Node* A = create_node('A', 5);
    Node* B = create_node('B', 3);
    Node* C = create_node('C', 8);
    Node* D = create_node('D', 2);
    Node* E = create_node('E', 6);
    Node* F = create_node('F', 7);
    Node* G = create_node('G', 9);
    Node* H = create_node('H', 1);
    Node* I = create_node('I', 10);
    Node* J = create_node('J', 12);

    // add nodes to tree
    ct->root = H;
    add_left_child(H, D);
    add_right_child(H, I);

    add_left_child(D, B);
    add_right_child(D, E);
    add_right_child(I, J);

    add_left_child(B, A);
    add_right_child(B, C);
    add_right_child(E, F);

    add_right_child(F, G);

    print_tree(ct->root, 0, 'S');

    // for good practices sake, let's free the memory
    free_tree(ct->root);
    free(ct);

    return 0;
}