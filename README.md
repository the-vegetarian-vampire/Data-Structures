# Data-Structures-and-Algorithms

## Common Big-O run times

[Big-O Cheatsheet](https://www.bigocheatsheet.com/)  
n = num of operations // time and space complexity based on growth

- `O(1)` - constant time
- `O(log n)` - log time (divide and conquer)
- `O(n)` - linear time (proportional)
- `O(n * log n)` - eg quicksort
- `O(n2)` - eg selection sort (think of a loop within a loop)
- `O(n!)` - n factorial eg `traveling salesperson`

Simplification: drop non dominants and constants  
Different terms for inputs  
`Theta:` tight bound avg  
`Omega:` lower bound best

---

### Some Terms

`base case` - the condition under which the recursion stops, preventing infinite recursion; thus terminating; typically empty or one element  
`pivot` - an element used as a reference point to partition a data set into two separate groups  
`recursion` - keeps track of state  
`inductive proof` - used to establish the truth of an infinite number of cases; commonly used to analyze recursive algorithms.  
`NP-completeness` - no known fast solution, rather optimal (greedy algo) or `approximation algo` usually suffices

- how fast
- how close to optimal
- sometimes perfect in the enemy of good

`sets` - can't have duplicates - keep track of distinct items without caring about their order or frequency.

- set intersection
- set union
- set difference
- set covering

`dynamic programming` - breaking down a complex problem into simpler subproblems and solving each subproblem only once, storing the results for future reference; works when each sub problem is discrete

`The Fourier transform` - represents data in terms of its frequency components: music, DNA, JPegs...

`Parallel Algorithms`

- MapReduce distributed algorithm
- Apache Hadoop

Simhash "similarity hash" - locality sensative hash, a hash which is similar in output: Google uses a simhash for duplicates in web crawling.

BCrypt hash - designed to be slow and computationally intensive, which makes it resistant to brute-force and rainbow table attacks

---

# Linked lists vs. Arrays

Difference is mostly in read and insertion times

Array

- contiguous Memory
- O(1) reading elements
- O(n) for insertion/deletion
- Memory size needs to be defined in advance

Linked List

- non-contiguous
- O(n) reading elements (iterating over indexes)
- O(1) for insertion/deletion
- head // tail // node = value and next // similar to a set of unordered maps

Singly Linked List

- Solve with two pointers `fast` and `slow` each iterating over the list
- Floyd's cycle-finding algorithm (also known as the "tortoise and the hare" algorithm)

Doubly Linked List

---

#### `std::vector` in C++

- A dynamic array automatically resizing as elements are added or removed.

  - **Access**: \(O(1)\) average time.
  - **Insertion at end (push_back)**: Amortized \(O(1)\).
  - **Insertion not at the end**: \(O(n)\) because of re-indexing
  - **Deletion at end (pop_back)**: \(O(1)\).
  - **Deletion not at end**: \(O(n)\).
  - **Searching (if not sorted)**: \(O(n)\).

- **Memory**:
  - Uses `contiguous` memory, enhancing cache performance.
  - Size can exceed the number of elements due to reserved capacity.
- **Advantages over linked lists**:
  - Cache-friendly due to contiguous memory.
  - Generally more space efficient as there are no node pointers as in linked lists.

---

# Stacks

Last In First Out (LIFO); last element inserted inside the stack is removed first.

### Key Operations:

- **Push**: Adds an element to the top of the stack.
- **Pop**: Removes the element on the top of the stack.
- **Peek/Top**: Retrieves the element on the top of the stack without removing it.
- **isEmpty**: Checks if the stack is empty.

### Complexity:

- **Time Complexity**: O(1) for push, pop, peek, and isEmpty operations under the assumption these operations are implemented with a linked list or dynamic array.
- **Space Complexity**: O(n) for storing n elements in the stack.

### Use Cases:

- Expression evaluation and syntax parsing.
- Backtracking algorithms (like maze solving, backtracking search).
- Maintaining function calls (call stack) during recursive calls.

### Example:

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> stack;
    stack.push(10); // Pushing 10 onto the stack
    stack.push(20); // Pushing 20 onto the stack
    std::cout << stack.top() << std::endl; // Prints 20
    stack.pop(); // Removing the top element (20)
    std::cout << stack.top() << std::endl; // Prints 10
    return 0;
}
```

---

# Queue

First-In-First-Out (FIFO) principle

- **Enqueue (Insertion)**: Adds an element to the back of the queue.

  - Time Complexity: \(O(1)\) - Constant time.

- **Dequeue (Removal)**: Removes an element from the front of the queue.

  - Time Complexity: \(O(1)\) - Constant time.

- **Peek**: Views the front item without removing it.

  - Time Complexity: \(O(1)\) - Constant time.

- **Is Empty**: Checks if the queue is empty.
  - Time Complexity: \(O(1)\) - Constant time.

---

# Hash Table

AKA: Hash map, dictionary, Associative array, map, depending...

- key value pair
- `unordered`
- `load factor` - determines how full the hash table is; When the load factor reaches a certain threshold (a value typically between `0.7` and `1.0`, though this can vary depending on the implementation), the hash table may be resized (usually doubled) to maintain efficient average-case time complexity for operations like insertions, deletions, and retrievals. This resizing process often involves rehashing all the current entries.
- fast search, insert, delete
- modeling relationships
- caching data

| Operation     | Average Case | Worst Case | Notes                                                                                                                                |
| ------------- | ------------ | ---------- | ------------------------------------------------------------------------------------------------------------------------------------ |
| **Insertion** | \(O(1)\)     | \(O(n)\)   | Worst case arises if all keys collide into the same bucket. With an optimal hash function and resizing strategy, this is infrequent. |
| **Deletion**  | \(O(1)\)     | \(O(n)\)   | Similar reasoning as insertion.                                                                                                      |
| **Retrieval** | \(O(1)\)     | \(O(n)\)   | Worst case happens if all keys collide and the key is at the end of a chained list or the element isn't present.                     |
| **Resizing**  | \(O(n)\)     | \(O(n)\)   | This operation is infrequent if resizing is done efficiently.                                                                        |

---

# Graphs

`node` - a node represents a point or a vertex, can hold data and may also have references to other nodes.
`edge` - connection between two nodes in a graph; in a weighted graph, an edge will also have a weight or cost associated with it, indicating the "cost" of traversing that edge.
`neighbors` - nodes that are directly connected to it by an edge. If two nodes are connected by an edge, they are said to be adjacent or neighbors; if there's an edge between nodes A and B, then A is a neighbor of B and vice versa.

`directed graph` - each edge has a starting point and an ending point. Edges are represented by arrows pointing from the starting vertex to the ending vertex; the order of the vertices matters; the edge (A, B) is different from the edge (B, A).

`topological Sorting` - a way to arrange the vertices of a graph in a straight line so that all directed edges go from left to right.

O(V+E) - v = vertices and e = num of edges

---

# Recursion

---

# Sliding Window

---

# Dikstra's Algorithmn

Shortest path from a given source vertex to every other vertex in a `weighted graph`

- no negative weight edges
- either directed or undirected
- no cycles or circular paths (cycle: start at node and end at same node)

  1. Cheapest node
  2. Update the cost of neighbors
  3. Repeat
  4. Calculate

---

# K-Nearest Neighbors (K-NN)

A supervised machine learning algorithm used for classification and regression tasks. It's a simple, non-parametric algorithm that makes predictions based on the similarity of data points in a feature space. K-NN can be used for both classification and regression tasks, but it's most commonly associated with classification.

1. Regression
2. Classification

- Co-sign similarity
- `OCR` optical character recognition
- Naive Bayes Classifier
- Computationally expensive for large datasets because it requires calculating distances for all data points.
- if `n` users look at `sqrt(n)` neighbors: ie Netflix
- feature extraction

---

# Bellman-Ford algorithm

Shortest path from a given source vertex to every other vertex in a weighted graph, including those with `negative weight edges`

---

# BFS (Breadth-First Search) and DFS (Depth-First Search)

BFS is a graph traversal algorithm.

---

# DFS (Depth-First Search)

---

# Trees

Hierarchical data structures composed of nodes connected by edges.

- **Root**: The top node of a tree.
- **Child**: A node directly connected to another node when moving away from the Root.
- **Parent**: The converse notion of a child.
- **Siblings**: Nodes that share the same parent.
- **Leaf**: A node that does not have any children.
- **Subtree**: A tree entirely contained within another tree.

## Properties

- Each node in a tree has one parent node (except the root which has none) and zero or more children nodes.
- Trees are recursive data structures because a tree is composed of smaller trees (subtrees).
- **Full Node**: a full node is one that has the maximum number of children possible. In a binary tree, a full node would have exactly two children. (every node points to 0 or all nodes possible)
- **Complete Tree**: every level, except possibly the last, is completely filled, and all nodes are as far left as possible. (full from left to right with no gaps)
- **Perfect Tree**: all interior nodes have exactly the same number of children, and all leaves are at the same level.

## Common Types of Trees

- **Binary Tree**: A tree where each node has at most two children.
- **Binary Search Tree (BST)**: A binary tree where the left child contains only nodes with values less than the parent node, and the right child only nodes with values greater than the parent node.
- **AVL Tree**: A self-balancing binary search tree.
- **Red-Black Tree**: Another self-balancing binary search tree.
- **Heap**: A specialized tree-based data structure that satisfies the heap property.

## Operations

- **Insertion**: Adding a new node to the tree.
- **Deletion**: Removing a node from the tree.
- **Traversal**: Visiting all the nodes of the tree. There are several traversal methods, including:
  - **In-order**: LNR (Left, Node, Right) for binary trees, which gives sorted order for BSTs.
  - **Pre-order**: NLR (Node, Left, Right).
  - **Post-order**: LRN (Left, Right, Node).
  - **Level-order**: BFS (Breadth-First Search), visiting nodes level by level.
- **Search**: Finding a node within the tree.

## Use Cases

- Representing hierarchical data, such as file systems or organizational structures.
- Making efficient search operations, like in binary search trees.
- Priority Queues implemented as Heaps.

---

### Binary Search Tree

O(log n)

### Red Black Tree

### Heaps

A specialized tree used for priority queue operations.

### Splay Trees

A self-balancing binary search tree.

---

# Bloom Filters

Probablistc data structures - not an exact answer, but probably correct

### HyperLogLog

---

# Backtracking

---

# Sliding Window

---

# Kadane’s Algorithmn

To find the maximum sum of a contiguous subarray.

---

# Parallel Algorithmns

C++17/20

- std::execution par

---

# Knapsack Problem

`Problem:`
You're a thief breaking into a house. You have a knapsack and there are several items in the house you can steal. Each item has a weight and a value (how much it's worth). However, your knapsack can only carry up to a certain weight before it breaks.

`Question:`
What's the most valuable combination of items you can take without exceeding the weight limit of your knapsack?

The knapsack problem is NP-hard for its 0/1 variant, meaning as the number of items grows, the time it takes to find the exact solution can grow very quickly.

```

```
