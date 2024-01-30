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

### Key Terms

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
- `std::queue<Type> queueName` 
- `std::deque<Type> dequeName`

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

AKA: Hash map, dictionary, associative array, map, depending...

- `std::map` and `std::unordered_map`
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
| **Resizing**  | \(O(n)\)     | \(O(n)\)   | This operation is infrequent if resizing is done efficiently.   

### Collision Handling Methods

#### Separate Chaining
- **Concept**: Stores colliding elements in a linked list at the same index.
- **Advantages**: Efficient collision handling, less sensitivity to load factors, good performance even with high load factors.
- **Disadvantages**: Requires extra memory, worst-case time complexity can degrade to \(O(n)\).

#### Linear Probing
- **Concept**: Uses open addressing and probes sequentially for the next available slot after a collision.
- **Advantages**: Simple implementation, all data stored in the hash table itself.
- **Disadvantages**: Prone to clustering, performance degrades when the table is nearly full.|

---

# Graphs

`node` - a node represents a point or a vertex, can hold data and may also have references to other nodes.    
`edge` - connection between two nodes in a graph; in a weighted graph, an edge will also have a weight or cost associated with it, indicating the "cost" of traversing that edge.    
`neighbors` - nodes that are directly connected to it by an edge. If two nodes are connected by an edge, they are said to be adjacent or neighbors; if there's an edge between nodes A and B, then A is a neighbor of B and vice versa.    
`directed graph` - each edge has a starting point and an ending point. Edges are represented by arrows pointing from the starting vertex to the ending vertex; the order of the vertices matters; the edge (A, B) is different from the edge (B, A).

`topological Sorting` - a way to arrange the vertices of a graph in a straight line so that all directed edges go from left to right.    
O(V+E) - v = vertices and e = num of edges    

- `std::unordered_set ` -  no duplicates

- Adjacency matrix
  - Adding a Vertex in a Graph with an Adjacency List is O(1):





---

# Recursion

## Overview
Recursion is a method where the solution to a problem depends on solutions to smaller instances of the same problem.

## Applications
- **Trees**: Inherently recursive, as each tree is made up of smaller trees (subtrees).
- **Graphs**: Recursive algorithms for traversing or searching, like Depth-First Search (DFS).
- **Sorting Algorithms**: Such as Quick Sort and Merge Sort, which divide the array into smaller parts recursively.

## Advantages
- Simplifies code for complex data structures.
- Natural fit for operations on structures like trees and graphs.

## Considerations
- Requires careful handling to avoid infinite recursion.
- May be less efficient in terms of memory due to stack usage.

- STACK OVERFLOW

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
- aka `Level Order Traversal
- starts at the root (or an arbitrary node in a graph) and explores all neighboring nodes at the present depth before moving to the nodes at the next depth level.

---

DFS (Depth-First Search)
- Explores as far as possible along each branch before backtracking; starts at the root (or an arbitrary node) and explores as far as possible along each branch before backtracking.
 * 	In-Order Traversal:
    * Process: Visit the left subtree, the root node, and then the right subtree.
    * Result: Produces a sorted sequence of node values for a binary search tree.
* 		Pre-Order Traversal:
    * Process: Visit the root node first, then the left subtree, and finally the right subtree.
    * Result: Useful for creating a copy of the tree or prefix expression (Polish notation).
* 		Post-Order Traversal:
    * Process: Visit the left subtree, then the right subtree, and finally the root node.
    * Result: Used in deleting the tree or postfix expression (Reverse Polish notation).

---

# Trees

Hierarchical data structures composed of nodes connected by edges.

- **Root**: The top node of a tree.
- **Child**: A node directly connected to another node when moving away from the Root.
- **Parent**: The converse notion of a child.
- **Siblings**: Nodes that share the same parent.
- **Leaf**: A node without children.
- **Subtree**: A tree entirely contained within another tree.

## Properties

- Each node in a tree has one parent node (except the root which has none) and zero or more children nodes.
- Trees are recursive data structures because a tree is composed of smaller trees (subtrees).
- **Full Node**: a full node is one that has the maximum number of children possible. In a binary tree, a full node would have exactly two children. (every node points to 0 or all nodes possible)
- **Complete Tree**: every level, except possibly the last, is completely filled, and all nodes are as far left as possible. (full from left to right with no gaps)
- **Perfect Tree**: all interior nodes have exactly the same number of children, and all leaves are at the same level.

## Common Types

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

B-trees are optimized for systems that read and write large blocks of data. They are widely used in databases and file systems because they provide efficient insertion, deletion, and searching operations, even in large data sets.

---

### Binary Search Tree

- typically O(log n)
- have a `temp` variable traverse the tree
- `while loop` since not sure how long it will run

### Red Black Tree

A type of self-balancing binary search tree; ensures the tree remains balanced after insertions and deletions, leading to more consistent operation times.

- Each node is either red or black.
- The root and leaves (NIL nodes) are black.
- Red nodes can't have red children (No two consecutive red nodes).
- Every path from a node to its descendant NIL nodes contains the same number of black nodes.


1. **Insert the node like a regular BST insertion**.
2. **Color the new node red**.
3. **Fix the tree to maintain Red-Black properties**:
   - If the parent node is black, no further action is required.
   - If the parent node is red, perform rotations and recoloring.

4. **Remove the node using BST deletion rules**.
5. **Fix the tree to maintain Red-Black properties**:
   - If the deleted node's child is red, simply replace the deleted node with its child and recolor it black.
   - If the deleted node's child is black, complex cases involving rotations and recoloring are handled.


- Similar to BST search, O(log n) time complexity.
  
- **Left Rotation**: Pivot on a node to move it down to the left.
- **Right Rotation**: Pivot on a node to move it down to the right.
- Rotations are used to maintain tree balance during insertions and deletions.


- **Time Complexity**: O(log n) for insertions, deletions, and search operations.


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
- **Backtracking** is a recursive, systematic algorithmic technique for solving problems.
- It incrementally builds candidates to the solutions and abandons a candidate ("backtracks") as soon as it determines the candidate cannot possibly be completed to a valid solution.

## Key Principles
1. **Choice**: Choose a candidate or option to add to the current solution.
2. **Constraints**: Check if the current candidate violates any constraints. If it does, abandon it.
3. **Goal**: Check if the current candidate satisfies the goal of the problem.

## Common Use Cases
- **Solving Puzzles**: Such as Sudoku, Crossword puzzles, N-Queens problem.
- **Searching**: Finding all possible configurations, such as permutations of a set.
- **Optimization Problems**: Finding the best solution among all feasible solutions, like in the Traveling Salesman Problem.

## Example: N-Queens Problem
- **Problem**: Place N queens on an N×N chessboard so that no two queens threaten each other.
- **Approach**: Place a queen in a row and recurse to solve for the next row. Backtrack if a conflict is found.

## Advantages
- **Efficiency**: More efficient than naive brute-force approaches, especially when the number of possibilities is large.
- **Flexibility**: Can be applied to many types of problems where exhaustive search is needed.

## Disadvantages
- **Time Consumption**: Can still be slow for problems with large search spaces.
- **Complexity**: Implementing backtracking can be complex, especially for beginners.

## Implementation Tips
- Recursion is often a natural way to implement backtracking.
- Use data structures that facilitate adding and removing elements, like stacks.
- Pruning: Eliminate choices early that clearly lead to a dead end.

---

# Sliding Window
Approach used for solving problems that require checking or computing something among all subarrays of a specific size in an array or list. It's especially efficient for problems involving contiguous sequences with a particular property, such as maximum sum, minimum length, or a certain number of zeroes.

## Key Concepts
- **Two Pointers**: This method often involves two pointers to denote the beginning and end of the window, which can vary in size or move in unison, depending on the problem.
- **Dynamic Window Size**: The window's size can expand or contract based on the problem's requirements.
- **Time Complexity**: Typically offers an efficient solution, usually with a time complexity of O(n), where n is the length of the array or list.

## Applications
- Finding the longest substring without repeating characters.
- Computing the maximum sum subarray of a specified size.
- Identifying the smallest subarray with a given sum.

## Example
Consider an array where you need to find the maximum sum of any contiguous subarray of a fixed size. Using the Sliding Window technique, you can efficiently solve this by sliding the window across the array and recalculating the sum—subtracting the element being left behind and adding the new element entering the window.


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

### Knapsack Problem Unbound

---

# Prim's Algorithm

Greedy algorithm that finds a minimum spanning tree for a weighted undirected graph; it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.

## How it works

1. Start with any `single vertex` and consider it as the spanning tree.
2. Find minimum weight edge that connects a vertex in the tree to a vertex outside the tree.
3. Add this edge to the tree.
4. Repeat step 2 and 3 until all vertices are included in the tree.

## Properties

- **Greedy Algorithm:** It chooses the nearest available vertex not already included in the tree.
- **Complexity:** The time complexity can range from O(V^2) to O(E + log V) depending on the data structures used (V is the number of vertices, E is the number of edges).
- **Suitability:** Prim's algorithm is good for dense graphs where E is close to V^2.

Ensures edges chosen are optimized to produce the minimum spanning tree and it can handle graphs with negative edge weights as well.

---

# Kruskal's Algorithm

Greedy algorithm used to find the minimum spanning tree for a connected weighted graph. The minimum spanning tree is a subset of the graph's edges that connects all vertices together, without any cycles and with the minimum possible total edge weight.

## How it works

1. Sort all the edges from low weight to high.
2. Take the edge with the lowest weight and add it to the spanning tree. If adding the edge creates a cycle, then reject this edge.
3. Keep adding edges until all vertices are bridged.

## Properties

- **Greedy Algorithm:** It selects the smallest available edge to ensure the minimum total weight.
- **Complexity:** When using a disjoint-set data structure, the algorithm has a time complexity of O(E log E) or O(E log V), where E is the number of edges and V is the number of vertices.
- **Suitability:** Kruskal's algorithm is more suitable for sparse graphs where E is much less than V^2.

Can be applied to any connected weighted graph and guarantees to find the minimum spanning tree if the graph is connected and undirected.
---
# Topological Sort
- algorithm applied to **Directed Acyclic Graphs (DAGs)**.
- It linearly orders the vertices of the graph such that for every directed edge from vertex `u` to vertex `v`, `u` comes before `v` in the ordering.

## Key Characteristics
- **DAGs Only**: Topological sorting can only be performed on graphs that have no cycles, i.e., Directed Acyclic Graphs.
- **Uniqueness**: The ordering of the nodes in a topological sort is not necessarily unique. A DAG can have more than one topological ordering.
- **Use Cases**: Commonly used in scenarios like scheduling tasks, organizing dependencies (e.g., dependency resolution in build systems), and course scheduling.

## Algorithm
1. **Count In-Degrees**: For each vertex, count the number of incoming edges.
2. **Initialize Queue**: Add all vertices with in-degree of 0 (i.e., no incoming edges) to a queue.
3. **Process Vertices**: While the queue is not empty:
    - Remove a vertex from the queue (denoting it has no remaining dependencies).
    - Add this vertex to the topological ordering.
    - Decrease the in-degree of all its neighbors. If a neighbor's in-degree becomes 0, add it to the queue.

## Complexity
- **Time Complexity**: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
- **Space Complexity**: O(V) due to storage needed for the in-degree map and the queue.

## Example
- Consider a project consisting of tasks A, B, C, D, E, and F, with dependencies such that A must be completed before B and D, B must be completed before C and E, and D must be completed before E and F. A topological sort of these tasks will provide an order in which to undertake them without violating any dependencies.

## Important Notes
- If the graph contains a cycle, then a topological sort is not possible, as there is no linear ordering that satisfies all dependency requirements.
- There are multiple methods to perform topological sorting, such as Depth-First Search (DFS) based approaches.

---
# Dynamic Programming

Top-Down Approach (Memoization): This approach involves writing the recursive solution first and then storing the results of the subproblems in a table (usually an array or a hash map) to avoid computing the same results multiple times. This is also known as memoization.

Bottom-Up Approach (Tabulation): In this approach, the solution is built starting with the simplest subproblems. By solving larger and larger subproblems using the results of previously solved subproblems, the final solution to the original problem is eventually reached. This approach typically involves filling up a table (array), and it is iterative.

Lookup Tables (Precomputed Answers)
* In this approach, you calculate and store answers for all possible inputs or a significant range of inputs before the actual execution of the main part of the program.
* This is particularly useful when the range of inputs is limited and it's feasible to compute all possible answers ahead of time.
* Example: Precomputing factorial values, Fibonacci numbers, or prime numbers within a certain range.

---------
# Floyd-Warshall
- used for finding the shortest paths between all pairs of vertices in a weighted graph. This graph can be either directed or undirected. One of the main advantages of the Floyd-Warshall algorithm is its ability to handle negative weights, as long as there are no negative weight cycles


-----------------

# C++ STL Algorithmns in Action

- `ios_base::sync_with_stdio(false)` - disables the synchronization between the C++ standard streams (std::cin, std::cout) and the C standard streams (stdin, stdout). Disabling this synchronization can lead to faster I/O operations, as the overhead of maintaining synchronization is removed.

- `cin.tie(NULL)` - breaks the tie between std::cin (standard input stream) and std::cout (standard output stream). By default, std::cout is flushed (i.e., all pending output is written) before each I/O operation on std::cin to ensure that all output is displayed before new input is taken. By setting cin.tie(NULL), this automatic flushing is disabled, which can improve performance when frequent flushing is unnecessary.
 
- `.size()` - used with containers like std::vector, std::list, etc. to get the number of elements.
- `.length()` - used specifically with `std::string` to get the number of characters in the string. Identical in functionality to .size() when used with strings.    
- `.empty()` - returns boolean to check if the container is empty; usually for a stack in coordination with .top() or .pop()    
- `unordered_set` - each element only once; duplicate elements, will be ignored.
- `push_back()`- with sequence containers like `std::vector` to add an element at the end.
- `map` - collection of key-value pairs. Keys are unique, and each key maps to a single value. 
- `unordered_map` - Hash table implementation of a map which allows for fast access and insertion of key-value pairs. Useful for frequency counting and mapping relationships.
- `pair` -  Useful for returning two values from a function or storing two related values together. Accessed via `.first` and `.second`.

- `algorithm functions`
  - Includes `count`, `find()`, `reverse()`, `accumulate()`, `lower_bound()`, `upper_bound()`, and many more for common operations.
      - int count = std::count(container.begin(), container.end(), element_to_count);
      - `max` (from `<algorithm>` header) compares two values and returns the larger one. Syntax: `max(value1, value2)`.
      - `sort` (from `<algorithm>` header) sorts the elements in a given range. Syntax: `sort(startIterator, endIterator)`.

- `bitset`

- `std::stoi` - **Header**: `<string>`
- **Function**: Converts a string to an integer.
- **Usage**: `int num = std::stoi("123");`
- **Exceptions**: Throws `std::invalid_argument` or `std::out_of_range`.

- std::to_string` - **Header**: `<string>`
- **Function**: Converts a numeric value to a string.
- **Usage**: `std::string str = std::to_string(123);`
- **Note**: Works with various numeric types (int, long, long long, float, double).

- `string::npos` - a constant static member value with the greatest possible value for an element of type size_t. This value, when returned by string functions like find(), indicates that a substring or character was not found in the string.

  
--------
# Resources
- [Don’t Just LeetCode; Follow the Coding Patterns Instead](https://levelup.gitconnected.com/dont-just-leetcode-follow-the-coding-patterns-instead-4beb6a197fdb)
- [14 Patterns to Ace Any Coding Interview Question](https://hackernoon.com/14-patterns-to-ace-any-coding-interview-question-c5bb3357f6ed)
- [Leetcode Strategy](https://www.youtube.com/watch?v=ZBmQlFeyEYI)
   Prioritize stacks and queues