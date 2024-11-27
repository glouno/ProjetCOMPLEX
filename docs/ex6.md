# sub-point a
The depth of a node $x_k$ is equal to its number of proper ancestors. We can thus check for all the other nodes if they are proper ancestors, yielding the following formula for the depth:

$\sum_{i=1}^{n} X_{ik}$

Thus, the expected depth for node $x_k$ is:

$E(\sum_{i=1}^{n} X_{ik}) = \sum_{i=1}^{n} E(X_{ik})$

# sub-point b
For our proof let's suppose that $i \lt k$, since the other case can be treated similarly.

-----
Let's first prove the implication from right to left (i.e. $x_i$ has lowest priority implies $X_{ik} = 1$).
We will argue by induction on the depth at which $x_i$ is inserted, considering we have just inserted it. We omit the proper condition since by definition $i \neq k$.

BASE CASE: $x_i$ is the root of our tree

Then, since $x_k$ has lower priority it will be inserted later in the tree, and so the $x_i$ which is the root is necessarily an ancestor of it.

INDUCTION STEP: Here we have two cases to consider, if $x_i$ is in the left or right subtree of the root.

Let's denote by $x_j$ the root.

CASE 1: $x_i$ is in the left subtree

Then, $i \lt j$. Since we have not yet inserted nodes with keys $i+1, i+2, ..., k$, $j$ cannot be among them, so $j \gt k$. This means that all the nodes in $X(i, k) - \{x_i\}$ will be inserted in the left subtree of $x_j$, in which $x_i$ has depth smaller by 1, so we can continue by induction.

CASE 2: $x_i$ is in the right subtree

Then, $i \gt j$. So we also have that $i+1, i+2, ..., k \gt i \gt j$. This means that all the nodes in $X(i, k) - \{x_i\}$ will also be inserted in the right subtree of $x_j$, in which $x_i$ has depth smaller by 1, so we can continue by induction.

-----
Now let's prove the other implication. We will construct a similar argument to the previous one, arguing based on the position of the node with lowest priority relative to the root.

Let $x_j$ be the node in $X(i, k)$ with lowest priority. Then $x_j$ has the lowest priority in $X(j, k)$, so it is an ancestor of $x_k$ (from the proof above), and furthermore $x_k$ is in its right subtree (since $j \lt k$).

If $j = k$, then $x_i$ has lower priority than $x_k$, so it will be inserted after it. Thus it cannot be an ancestor of $x_k$, which is a contradiction with our hypothesis.

We thus have that $j \lt k$. We suppose that $j \gt i$ and we will prove that this is impossible in order to conclude that $x_i$ has the lowest priority.

Let's look at the position of $x_j$ relative to the root of the tree, $x_l$.

CASE 1: $x_j$ is in the left subtree of the root

Then $l \gt j \gt i$, so $x_i$ is also in the left subtree of the root.

CASE 2: $x_j$ is in the right subtree of the root

Then $j \gt l$, and since the nodes $x_i, x_{i+1}, ..., x_{j-1}$ have not yet been inserted we also have that $l \lt i$. So $x_i$ is also inserted in the right subtree of the root.

-----
Recursively applying the argument above we can reduce to the case where $x_j$ is the root of our tree, i.e. all the other nodes in $X(i, k)$ are inserted in its subtrees. Then, since $i \lt j$, $x_i$ is inserted in its left subtree, and since $k \gt j$, $x_k$ is in its right subtree. So $x_i$ cannot be an ancestor of $x_k$, which is a contradiction.

We conclude that $j = i$, so $x_i$ has the lowest priority in $X(i, k)$, which is what we wanted to prove.

# sub-point c
We write the expected depth as the mean of the expected depths of all $n$ nodes, and using the formula from sub-point a,we can write the expected depth as:

$\frac{1}{n} \sum_{k=1}^{n} \sum_{i=1}^{n} E(X_{ik}) = \frac{1}{n} \sum_{k=1}^{n} \sum_{i=1}^{n} P(X_{ik} = 1) = \frac{1}{n} \sum_{k=1}^{n} \sum_{i=1}^{n} P(x_i \, has \, lowest \, priority \, in \, X(i, k))$

We model the probability of $x_i$ having the lowest priority as uniformly choosing it among the elements of $X(i, k)$, that is $\frac{1}{| k-j |}$.

Computing the sum is the similar to what was done in lecture 6, and we get a result of O(log(n)).