
#include <stdio.h>
#include <stdlib.h>
#include "../include/cartesian_tree.h"
#include "../include/tree_operations.h"

int main() {
    // create nodes and empty tree
    Tree* ct = create_empty_tree();

    // Insert nodes (Example from 3.d, sequence 1)
    insert_tree(ct, 'A', 5, NULL);
    insert_tree(ct, 'B', 3, NULL);
    insert_tree(ct, 'C', 8, NULL);
    insert_tree(ct, 'D', 2, NULL);
    insert_tree(ct, 'E', 6, NULL);
    insert_tree(ct, 'F', 7, NULL);
    insert_tree(ct, 'G', 9, NULL);
    insert_tree(ct, 'H', 1, NULL);
    insert_tree(ct, 'I', 10, NULL);
    insert_tree(ct, 'J', 12, NULL);

    // Print the resulting tree
    print_tree(ct->root, 0, 'S');

    // free the memory
    free_tree(ct->root);
    free(ct);

    // sequence 2
    ct = create_empty_tree();

    insert_tree(ct, 'H', 1, NULL);
    insert_tree(ct, 'G', 9, NULL);
    insert_tree(ct, 'A', 5, NULL);
    insert_tree(ct, 'B', 3, NULL);
    insert_tree(ct, 'D', 2, NULL);
    insert_tree(ct, 'F', 7, NULL);
    insert_tree(ct, 'C', 8, NULL);
    insert_tree(ct, 'J', 12, NULL);
    insert_tree(ct, 'I', 10, NULL);
    insert_tree(ct, 'E', 6, NULL);

    print_tree(ct->root, 0, 'S');

    free_tree(ct->root);
    free(ct);

    // sequence 3
    ct = create_empty_tree();

    insert_tree(ct, 'E', 6, NULL);
    insert_tree(ct, 'H', 1, NULL);
    insert_tree(ct, 'B', 3, NULL);
    insert_tree(ct, 'D', 2, NULL);
    insert_tree(ct, 'C', 8, NULL);
    insert_tree(ct, 'F', 7, NULL);
    insert_tree(ct, 'G', 9, NULL);
    insert_tree(ct, 'J', 12, NULL);
    insert_tree(ct, 'A', 5, NULL);
    insert_tree(ct, 'I', 10, NULL);

    print_tree(ct->root, 0, 'S');

    free_tree(ct->root);
    free(ct);

    return 0;
}
