# Data-Structures-and-Algorithms

## Common Big-O run times
n = num of operations // time and space complexity based on growth   
- `O(1)` - constant time
- `O(n)` - linear time
- `O(log n)` - log time
- `O(n * log n)` - eg quicksort
- `O(n2)` - eg selection sort
- `O(n!)` - n factorial eg traveling salesperson

------
`base case` - the condition under which the recursion stops, preventing infinite recursion; thus terminating; typically empty or one element  
`pivot` - an element used as a reference point to partition a data set into two separate groups   
`recursion` - keeps track of state    
`inductive proof` - used to establish the truth of an infinite number of cases; commonly used to analyze recursive algorithms.      

------
# Linked lists vs. Arrays
Difference is mostly in read and insertion times   

Array
- contiguous Memory
- O(1) reading elements
- O(n) for insertion/deletion
- Memory size needs to be defined in advance

Linked List
- non-contiguous
- O(n) reading elements
- O(1) for insertion/deletion

------
# Hash Table
AKA: Hash map, dictionary, Associative array, map, depending...   
- key value pair
- `load factor` - determines how full the hash table is; When the load factor reaches a certain threshold (a value typically between `0.7` and `1.0`, though this can vary depending on the implementation), the hash table may be resized (usually doubled) to maintain efficient average-case time complexity for operations like insertions, deletions, and retrievals. This resizing process often involves rehashing all the current entries.   
- fast search, insert, delete
- modeling relationships
- caching data

| Operation          | Average Case | Worst Case  | Notes |
|--------------------|--------------|-------------|-------|
| **Insertion**      | \(O(1)\)     | \(O(n)\)    | Worst case arises if all keys collide into the same bucket. With an optimal hash function and resizing strategy, this is infrequent. |
| **Deletion**       | \(O(1)\)     | \(O(n)\)    | Similar reasoning as insertion. |
| **Retrieval**      | \(O(1)\)     | \(O(n)\)    | Worst case happens if all keys collide and the key is at the end of a chained list or the element isn't present. |
| **Resizing**       | \(O(n)\)     | \(O(n)\)    | This operation is infrequent if resizing is done efficiently. |

------
# Graphs
`node` - a node represents a point or a vertex, can hold data and may also have references to other nodes.    
`edge` - connection between two nodes in a graph; in a weighted graph, an edge will also have a weight or cost associated with it, indicating the "cost" of traversing that edge.    
`neighbors` - nodes that are directly connected to it by an edge. If two nodes are connected by an edge, they are said to be adjacent or neighbors; if there's an edge between nodes A and B, then A is a neighbor of B and vice versa.    

`directed graph` - each edge has a starting point and an ending point. Edges are represented by arrows pointing from the starting vertex to the ending vertex; the order of the vertices matters; the edge (A, B) is different from the edge (B, A).   

`topological Sorting` - a way to arrange the vertices of a graph in a straight line so that all directed edges go from left to right.

O(V+E) 
 - V = vertices
 - e = num of edges


------
# Dikstra's Algorithmn
Shortest path from a given source vertex to every other vertex in a `weighted graph`   

- no negative weight edges
- either directed or undirected

------
# Bellman-Ford algorithm
Shortest path from a given source vertex to every other vertex in a weighted graph, including those with `negative weight edges`   

------
# BFS (Breadth-First Search) and DFS (Depth-First Search) 

------
# Red Black Tree 

------
# Kadane’s Algorithmn


