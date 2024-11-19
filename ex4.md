# sub-point a
A method for suppressing a node from a Cartesian Tree is correct if: at the end of the method we are left with a Cartesian Tree, and this Cartesian Tree is one of the trees that can be built from our list of nodes minus the node to be suppressed. Since there is a unique tree corresponding to a given list, it is enough to prove that at the end of the suppression method we are left with a Cartesian Tree.

The main steps in our proof will be the following:
- it is enough to consider only the subtree with root the node we want to suppress. The rest of the tree does not chnage its structure, so if we prove that this subtree is a Cartesian Tree at the end, the whole tree will be.
- we can prove this by induction on the height of this subtree. At each step we consider 3 cases, depending on whether the root has left and right children.

The first claim is true since: the tree minus the subtree we are looking at is not affected, so it keeps its Cartesian Tree structure, rotations preserve the binary tree structure and since we are rotating by the child with the lowest priority, the queue structure is also preserved (omitting the node we are trying to suppress).

Thus, we can only consider the subtree with root the node we are tring to suppress.

The base case of our induction is a tree of height 1. We show the 3 cases in the figure below.

(insert figure here)

Let's call the node are trying to suppress S and the subtree that has S as root TREE(S).

Now, let's look at our induction step. We consider the case where S has both left and right children; the other 2 cases are similar. After a first rotation (in our case to the right), TREE(S) has the same height. We have reduced the number of nodes in one of its children (in the figure below its left child) and kept the other one constant, so since both children have a finite number of nodes we will at some point rotate S in the other direction (in the exampleto the left), after which the height of TREE(S) will decrease by 1. So we can apply our induction hypothesis and we are done.

(insert figure here)

# sub-point b
Similarly to the insertion algorithm, if S is at height $h$, since rotations have a constant cost, the complexity of our algorithm is O(h).