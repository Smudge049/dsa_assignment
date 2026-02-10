# Documentation for Program 5: Graph BFS & DFS

## (a) Data Structure Definition
An **Undirected Graph** is implemented using an **Adjacency Matrix** (`int adj[MAX][MAX]`).
- A 2D array represents connections between vertices.
- `adj[u][v] = 1` indicates an edge exists between vertex `u` and `v`.
- Since it's undirected, both `adj[u][v]` and `adj[v][u]` are set to 1.

## (b) Functions Implemented
- `addEdge(int u, int v)`: Sets the corresponding matrix entries to 1 to represent an edge.
- `BFS(int start)`: Implements Breadth-First Search using a queue-based iterative approach to visit nodes level by level.
- `DFS(int u)`: Implements Depth-First Search using a recursive approach to explore as far as possible along each branch.

## (c) main() Method Organization
The `main()` function:
1. Defines the number of vertices and initializes the adjacency matrix.
2. Sets up a sample graph by calling `addEdge()`.
3. Demonstrates `BFS()` starting from vertex 0.
4. Resets the `visited` array and demonstrates `DFS()` starting from vertex 0.

## (d) Sample Output
```
Graph initialized with edges: (0,1), (0,2), (1,3), (1,4), (2,4)
BFS Traversal: 0 1 2 3 4 
DFS Traversal: 0 1 3 4 2 
```
