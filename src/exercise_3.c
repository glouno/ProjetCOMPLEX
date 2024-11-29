
#include <stdio.h>
#include <stdlib.h>
#include "../include/cartesian_tree.h"
#include "../include/tree_operations.h"

int main() {
    // create nodes and empty tree
    Tree* ct = create_empty_tree();

    // Insert nodes (Example from 3.d, sequence 1)
    insert_tree(ct, 0, 5, NULL);
    insert_tree(ct, 1, 3, NULL);
    insert_tree(ct, 2, 8, NULL);
    insert_tree(ct, 3, 2, NULL);
    insert_tree(ct, 4, 6, NULL);
    insert_tree(ct, 5, 7, NULL);
    insert_tree(ct, 6, 9, NULL);
    insert_tree(ct, 7, 1, NULL);
    insert_tree(ct, 8, 10, NULL);
    insert_tree(ct, 9, 12, NULL);

    // Print the resulting tree
    print_tree(ct->root, 0, 'S');

    // free the memory
    free_tree(ct->root);
    free(ct);

    // sequence 2
    ct = create_empty_tree();

    insert_tree(ct, 7, 1, NULL);
    insert_tree(ct, 6, 9, NULL);
    insert_tree(ct, 0, 5, NULL);
    insert_tree(ct, 1, 3, NULL);
    insert_tree(ct, 3, 2, NULL);
    insert_tree(ct, 5, 7, NULL);
    insert_tree(ct, 2, 8, NULL);
    insert_tree(ct, 9, 12, NULL);
    insert_tree(ct, 8, 10, NULL);
    insert_tree(ct, 4, 6, NULL);

    print_tree(ct->root, 0, 'S');

    free_tree(ct->root);
    free(ct);

    // sequence 3
    ct = create_empty_tree();

    insert_tree(ct, 4, 6, NULL);
    insert_tree(ct, 7, 1, NULL);
    insert_tree(ct, 1, 3, NULL);
    insert_tree(ct, 3, 2, NULL);
    insert_tree(ct, 2, 8, NULL);
    insert_tree(ct, 5, 7, NULL);
    insert_tree(ct, 6, 9, NULL);
    insert_tree(ct, 9, 12, NULL);
    insert_tree(ct, 0, 5, NULL);
    insert_tree(ct, 8, 10, NULL);

    print_tree(ct->root, 0, 'S');

    free_tree(ct->root);
    free(ct);

    return 0;
}
