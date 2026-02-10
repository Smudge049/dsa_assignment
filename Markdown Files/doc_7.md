# Documentation for Program 7: Dijkstra's Algorithm

## (a) Data Structure Definition
The program uses a **Weighted Graph** represented by an **Adjacency Matrix** (`int graph[V][V]`).
- If `graph[u][v]` is non-zero, it represents the weight of the edge between vertices `u` and `v`.
- An auxiliary array `dist[V]` stores the shortest distance from the source to each vertex.
- A boolean array `sptSet[V]` keeps track of vertices whose shortest distance from the source is finalized.

## (b) Functions Implemented
- `minDistance(int dist[], bool sptSet[])`: Scans the `dist` array to find the vertex with the smallest distance value that hasn't been included in the Shortest Path Tree yet.
- `dijkstra(int graph[V][V], int src)`: The main logic that iteratively selects the minimum distance vertex, adds it to the set, and updates the distances of all its adjacent vertices if a shorter path is found.
- `printSolution(int dist[])`: A utility function to display the final shortest distance for each vertex.

## (c) main() Method Organization
The `main()` function:
1. Initializes a 4-vertex weighted graph with static values matching the example case.
2. Calls the `dijkstra()` function with vertex 0 as the source.
3. Outputs the results to the console.

## (d) Sample Output
```
Dijkstra's Algorithm (Source Node: 0)
Vertex 	 Distance from Source
0 		 0
1 		 4
2 		 7
3 		 12
```
