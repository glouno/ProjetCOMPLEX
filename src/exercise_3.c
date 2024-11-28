
#include <stdio.h>
#include <stdlib.h>
#include "../include/cartesian_tree.h"

int main() {
    // create nodes and empty tree
    Tree* ct = create_empty_tree();

    // Insert nodes (Example from 3.d, sequence 1)
    insert_tree(ct, 'A', 5);
    insert_tree(ct, 'B', 3);
    insert_tree(ct, 'C', 8);
    insert_tree(ct, 'D', 2);
    insert_tree(ct, 'E', 6);
    insert_tree(ct, 'F', 7);
    insert_tree(ct, 'G', 9);
    insert_tree(ct, 'H', 1);
    insert_tree(ct, 'I', 10);
    insert_tree(ct, 'J', 12);

    // Print the resulting tree
    printf("Cartesian Tree after inserting nodes:\n");
    print_tree(ct->root, 0, 'S');

    // Search for a specific node (with depth)
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
