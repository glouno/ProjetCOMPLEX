#include <stdio.h>
#include <stdlib.h>
#include "../include/cartesian_tree.h"
#include "../include/tree_operations.h"

int main() {
    // create tree
    Tree* ct = create_empty_tree();

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

    // Delete nodes one by one as per Exercise 4.d
    printf("\nDeleting nodes in sequence:\n");

    int keys_to_delete[] = {0, 9, 7};
    for (int i = 0; i < 3; i++) {
        printf("\nDeleting node with key '%d'...\n", keys_to_delete[i]);
        delete_node(ct, keys_to_delete[i]);
        printf("Tree after deletion:\n");
        print_tree(ct->root, 0, 'S');
    }

    // free the memory
    free_tree(ct->root);
    free(ct);

    return 0;
}
