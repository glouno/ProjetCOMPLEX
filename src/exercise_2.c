
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
    printf("Building the tree manually...\n");
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

    // Visualize tree structure
    print_tree(ct->root, 0, 'S');

    // Search for a specific node
    // Node* found_node = search_tree(ct->root, 'E');
    // if (found_node != NULL) {
    //     printf("Found node: K: %c, P: %.0f\n", found_node->key, found_node->priority);
    // } else {
    //     printf("Key not found in the tree.\n");
    // }
    // With depth version
    char key = 'E';
    int depth;
    Node* found_node = search_tree_withDepth(ct->root, key, &depth);
    if (found_node != NULL) {
        printf("Found node: K: %c, P: %.0f, at depth: %d.\n", found_node->key, found_node->priority, depth);
    } else {
        printf("Key not found in the tree. Closest depth: %d.\n", depth);
    }

    // for good practices sake, let's free the memory
    printf("\nDeleting tree...\n");
    free_tree(ct->root);
    free(ct);

    printf("Program finished successfully.\n");
    return 0;
}
