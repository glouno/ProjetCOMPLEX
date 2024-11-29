
#include <stdio.h>
#include <stdlib.h>
#include "../include/cartesian_tree.h"
#include "../include/tree_operations.h"

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
    printf("Initial Cartesian Tree after inserting nodes:\n");
    print_tree(ct->root, 0, 'S');

    // Search for a specific node (with depth)
    char key = 'E';
    int depth;
    Node* found_node = search_tree_with_depth(ct->root, key, &depth);
    if (found_node != NULL) {
        printf("Found node: K: %c, P: %.0f, at depth: %d.\n", found_node->key, found_node->priority, depth);
    } else {
        printf("Key not found in the tree. Closest depth: %d.\n", depth);
    }


    // Delete nodes one by one as per Exercise 4.d
    printf("\nDeleting nodes in sequence:\n");

    char keys_to_delete[] = {'A', 'J', 'H'};
    for (int i = 0; i < 3; i++) {
        printf("\nDeleting node with key '%c'...\n", keys_to_delete[i]);
        delete_tree_node(ct, keys_to_delete[i]);
        printf("Tree after deletion:\n");
        print_tree(ct->root, 0, 'S');
    }

    // Search for a specific node after deletion
    Node* found_node2 = search_tree_with_depth(ct->root, key, &depth);
    if (found_node2 != NULL) {
        printf("Found node: K: %c, P: %.0f, at depth: %d.\n", found_node2->key, found_node2->priority, depth);
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
