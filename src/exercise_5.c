#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/cartesian_tree.h"
#include "../include/tree_operations.h"

// we write our numerical results to a file in order to plot with Python later

// one pair of equal priority nodes affects the height of a tree by at most 1
// so the factor by which priority clashes affect the structure of a tree is directly proportional to their probability of occurrence
// the operations depend on the structure of the tree, but not directly on the priority

int main() {
    // define usable nodes keys
    int keys[15000];
    for (int i = 0; i < 15000; i++) {
        keys[i] = i;
    }

    initialize_random_generator();

    // evaluate balance of Cartesian Trees
    // for number of nodes from 1-100, we construct 3 trees and calculate their height
    // since we are inserting the keys in order, we are studying at the same time the BST worst-case
    FILE *fp = fopen("data/height.csv", "w");
    if (fp == NULL) {
        printf("Error opening height file.\n");
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 3; j++) {
            Tree* ct = create_empty_tree();

            for (int k = 0; k < i; k++) {
                double priority = (double)rand();
                insert_tree(ct, k, priority, NULL);
            }
            int height = height_tree(ct->root);
            fprintf(fp, "%d,%d\n", i+1, height);

            free_tree(ct->root);
            free(ct);
        }
    }

    // evaluate search time
    // construct 3 random trees of height 5000
    // randomly select 1000 nodes and search them
    // we save their depth and search time
    fp = fopen("data/search.csv", "w");
    if (fp == NULL) {
        printf("Error opening search file.\n");
    }

    for (int i = 0; i < 3; i++) {
        Tree* ct = create_empty_tree();
        clock_t start, end;
        double duration;
        int depth;

        for (int k = 0; k < 5000; k++) {
            double priority = (double)rand();
            insert_tree(ct, k, priority, NULL);
        }

        shuffle(keys, 5000);
        for (int k = 0; k < 1000; k++) {
            depth = 0;

            start = clock();
            search_tree_with_depth(ct->root, keys[k], &depth);
            end = clock();
            duration = ((double)(end - start));

            fprintf(fp, "%d,%f\n", depth, duration);
        }
        qsort(keys, 5000, sizeof(int), compare_ints);

        free_tree(ct->root);
        free(ct);
    }

    // conclude that we need to work with much bigger size to see meaningful numbers
    // evaluate search and insert time
    // for 3 random trees of size 10000, record duration of 5000 random new nodes
    FILE* fp_i = fopen("data/insert.csv", "w");
    if (fp_i == NULL) {
        printf("Error opening insert file.\n");
    }
    FILE* fp_d = fopen("data/delete.csv", "w");
    if (fp_d == NULL) {
        printf("Error opening delete file.\n");
    }

    for (int i = 0; i < 3; i++) {
        Tree* ct = create_empty_tree();
        clock_t start, end;
        double duration;

        for (int k = 0; k < 10000; k++) {
            double priority = (double)rand();
            insert_tree(ct, k, priority, NULL);
        }

        shuffle(keys + 10000, 5000);
        for (int k = 0; k < 5000; k++) {
            double priority = (double)rand();
            int depth = 0;
            int key = keys[10000 + k];

            // first insert node
            start = clock();
            insert_tree(ct, key, priority, &depth);
            end = clock();
            duration = ((double)(end - start));

            fprintf(fp_i, "%d,%f\n", depth, duration);

            // then delete it
            start = clock();
            delete_node(ct, key);
            end = clock();
            duration = ((double)(end-start));

            depth = 0;
            search_tree_with_depth(ct->root, key, &depth);
            fprintf(fp_d, "%d,%f\n", depth, duration);
        }
        qsort(keys + 10000, 5000, sizeof(int), compare_ints);

        free_tree(ct->root);
        free(ct);
    }

    return 0;
}