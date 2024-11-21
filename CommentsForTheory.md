## For Question 2B
Complexity Analysis
1. Successful Search:
- If the key exists in the tree, the algorithm traverses from the root to the target node.
- The complexity is proportional to the depth of the node, i.e., O(d) where d is the depth.
2. Unsuccessful Search:
- If the key does not exist, the algorithm stops at the node where the search terminates.
- This is either the node with the closest smaller key (predecessor) or the closest larger key (successor).
- The complexity is still O(d) where d is the depth of this last visited node.

**Worst Case:**
In an unbalanced Cartesian tree, the depth of a node can be as large as O(n) (where n is the number of nodes in the tree).
Thus, the worst-case complexity of the search algorithm is O(n).

**Average Case:**
For a balanced Cartesian tree, the depth of any node is O(log n), so the average-case complexity is O(log n).

## For Question 3
### Code Implementation for Insertion in a Cartesian Tree

The process involves:

1.  **BST Insertion**: Insert the new node following BST rules (based on keys).
2.  **Heap Property Restoration**: Perform rotations if the heap property (priorities) is violated.

### Tree Rotations

The diagram in the question shows how to perform a single rotation:

-   If a node `z` violates the heap property with its parent `y` (i.e., `z->priority < y->priority`), we perform a rotation to make `z` the parent of `y`.

### Explanation of the Code

1.  **Binary Search Tree Insertion**:

    -   The new node is inserted following BST rules based on its key.
2.  **Rotations to Fix Heap Property**:

    -   After insertion, if the priority of the new node is less than its parent, a rotation is performed to restore the heap property.
    -   Two types of rotations are implemented:
        -   **Right Rotation**: Used when the new node is in the left subtree and violates the heap property.
        -   **Left Rotation**: Used when the new node is in the right subtree and violates the heap property.
3.  **Recursive Implementation**:

    -   The `insertNode` function is recursive, traversing the tree until the correct position is found, then applying rotations as needed.
4.  **Time Complexity**:

    -   **Insertion**: `O(log n)` for a balanced tree; `O(n)` in the worst case of a skewed tree.
    -   **Rotation**: Each rotation is `O(1)` because it involves pointer manipulations.