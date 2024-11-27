# sub-point a
The queue structure can be broken when nodes are not inserted in order of increasing priority.

For example, if we have nodes (A:1) and (B:0), inserting them in this order gives a tree that is not a queue.

# sub-point b
Let's denote the denote the depth of the predecessor of our just inserted node by h.

It is clear to see that to have reached this node we have made h comparisons, so we have complexity of O(h). Now, since the rotations take constant time, and we can move up our inserted node at most h times, the rotations have worst-case complexity O(h). Thus, CT-insertion has complexity O(h).

