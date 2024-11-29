#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/cartesian_tree.h"
#include "../include/tree_operations.h"

// we will be working with the ASCII range 32-126 for tree keys
// we write our numerical results to a file in order to plot with Python later

// one pair of equal priority nodes affects the height of a tree by at most 1
// so the factor by which priority clashes affect the structure of a tree is directly proportional to their probability of occurrence
// the operations depend on the structure of the tree, but not directly on the priority

int main() {
    // define usable nodes keys
    char keys[30];
    for (int i = 0; i < 30; i++) {
        keys[i] = 32 + i;
    }

    initialize_random_generator();

    // evaluate balance of Cartesian Trees
    // for number of nodes from 1-20, we construct 3 trees and calculate their height
    // since we are inserting the keys in order, we are studying at the same time the BST worst-case
    FILE *fp = fopen("data/height.csv", "w");
    if (fp == NULL) {
        printf("Error opening height file.\n");
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 3; j++) {
            Tree* ct = create_empty_tree();

            for (int k = 0; k < i; k++) {
                double priority = (double)rand();
                insert_tree(ct, keys[k], priority);
            }
            int height = height_tree(ct->root);
            fprintf(fp, "%d,%d\n", i+1, height);

            print_tree(ct->root, 0, 'S');
            free_tree(ct->root);
            free(ct);
        }
    }

    // for each of the 3 size 20 trees, we perform 20 insertions, calculating height at each step
    // we then randomly select 10 nodes
    // we first search for them
    // then we delete them

    return 0;
}