#include <stdio.h>
#include <stdlib.h>
#include "../include/cartesian_tree.h"
#include "../include/tree_operations.h"

int main() {
    // create nodes and empty tree
    Tree* ct = create_empty_tree();
    Node* A = create_node(0, 5);
    Node* B = create_node(1, 3);
    Node* C = create_node(2, 8);
    Node* D = create_node(3, 2);
    Node* E = create_node(4, 6);
    Node* F = create_node(5, 7);
    Node* G = create_node(6, 9);
    Node* H = create_node(7, 1);
    Node* I = create_node(8, 10);
    Node* J = create_node(9, 12);

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

    // test correctness of search function
    int key = 4;
    int depth = 0;

    Node* found_node = search_tree_with_depth(ct->root, key, &depth);
    if (found_node != NULL) {
        printf("Found node: K: %d, P: %.0f, at depth: %d.\n", found_node->key, found_node->priority, depth);
    } else {
        printf("Key not found in the tree. Closest depth: %d.\n", depth);
    }

    // free memory
    free_tree(ct->root);
    free(ct);

    return 0;
}
