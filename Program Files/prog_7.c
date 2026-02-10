#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 4 // Number of vertices

// Helper to find the vertex with minimum distance
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the distances
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Core Dijkstra's Algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V]; // Shortest Path Tree set

    // Initialize all distances as infinite and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it's not in sptSet, there's an edge from u to v,
            // and the total weight of path from src to v through u is smaller than current dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main() {
    // Example weighted graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 4, 8, 0},
        {4, 0, 3, 10},
        {8, 3, 0, 5},
        {0, 10, 5, 0}
    };

    printf("Dijkstra's Algorithm (Source Node: 0)\n");
    dijkstra(graph, 0);

    return 0;
}
