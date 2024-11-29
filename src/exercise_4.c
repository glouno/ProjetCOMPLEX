
#include <stdio.h>
#include <stdlib.h>
#include "../include/cartesian_tree.h"
#include "../include/tree_operations.h"

int main() {
    // create tree
    Tree* ct = create_empty_tree();

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

    // Delete nodes one by one as per Exercise 4.d
    printf("\nDeleting nodes in sequence:\n");

    char keys_to_delete[] = {'A', 'J', 'H'};
    for (int i = 0; i < 3; i++) {
        printf("\nDeleting node with key '%c'...\n", keys_to_delete[i]);
        delete_node(ct, keys_to_delete[i]);
        printf("Tree after deletion:\n");
        print_tree(ct->root, 0, 'S');
    }

    // free the memory
    free_tree(ct->root);
    free(ct);

    return 0;
}
