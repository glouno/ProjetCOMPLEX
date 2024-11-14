# sub-point a
Let's first describe an algorithm for constructing a Cartesian Tree given a list of node keys and their priorities. We will then want to prove that this solution is unique.

ALGORITHM (applied recursively starting from initial list):
1. if our list is empty, we are done
2. else, from the list of nodes, choose the one with the lowest priority; this will be the root of our tree
3. split the list in two based on the keys; the nodes with keys smaller than the root go in list L and thos with larger keys go in list R
4. repeat the algorithm on the lists L and R to build the left and right subtree respectively for the constructed root

Why does this algorithm build a Cartesian Tree (i.e. give a solution)? For each subtree, the root has the lowest priority, so it is lower than any of its children => QUEUE. For each subtree, the root has key larger than nodes in its left subtree, and smaller than nodes in its right subtree => BINARY SEARCH TREE.

Let's write trees using the following notation: {ROOT: , LEFT: , RIGHT: } and omitting LEFT and RIGHT for leaves.

Applying the algorithm above on our example gives:
{ROOT: (H:1), LEFT: {ROOT: (D:2), LEFT: {ROOT: (B:3), LEFT: (A:5), RIGHT: (C:8)}, RIGHT: {ROOT: (E:6), RIGHT: {ROOT: (F:7), RIGHT: (G:9)}}}, RIGHT: {ROOT: (I:10), RIGHT: (J:12)}}

Now, let's prove by induction that given a list of n nodes (represented as key-priority pairs) the associated Cartesian Tree is unique. Firstly let's note that due to our algorithm we now that at least one Cartesian Tree exists (if all keys and priorities are distinct).

For n=0, the tree is indeed unique as the only possibility is an empty tree.

Let's suppose the proposition true for all 0 <= k < n, and let's prove it for n. We have a given list of length n.

Since the root has to have the lowest priority among all nodes of a tree, the root node of any associated Cartesian Tree associated to this list is unique.

Now, the nodes in the left subtree of our root all need to have smaller keys, so the nodes in the left subtree are also unique among all possible Cartesian Trees is also unique! The list of these nodes has smaller length than n, so by the induction hypothesis, the associated Cartesian Tree is unique. We can repeat this argument for the right subtree, so we obtain that the associated tree is unique.

QED

# sub-point b
