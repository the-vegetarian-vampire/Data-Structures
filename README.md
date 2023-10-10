# Data-Structures-and-Algorithms

## Common Big-O run times
n = num of operations // time and space complexity based on growth   
- `O(1)` - constant time
- `O(log n)` - log time
- `O(n)` - linear time
- `O(n * log n)` - eg quicksort
- `O(n2)` - eg selection sort
- `O(n!)` - n factorial eg traveling salesperson

------
`base case` - the condition under which the recursion stops, preventing infinite recursion; thus terminating; typically empty or one element  
`pivot` - an element used as a reference point to partition a data set into two separate groups   
`recursion` - keeps track of state

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
- fast search, insert, delete
- modeling relationships
- caching data
