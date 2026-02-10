#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int adj[MAX][MAX];
bool visited[MAX];
int n; // Number of vertices

// Add edge to undirected graph
void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Breadth First Search
void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    bool qVisited[MAX] = {false};

    queue[rear++] = start;
    qVisited[start] = true;

    printf("BFS Traversal: ");
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && !qVisited[v]) {
                queue[rear++] = v;
                qVisited[v] = true;
            }
        }
    }
    printf("\n");
}

// Depth First Search
void DFS(int u) {
    visited[u] = true;
    printf("%d ", u);

    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            DFS(v);
        }
    }
}

int main() {
    n = 5; // Example with 5 vertices (0 to 4)

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // Example Graph Edges
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);

    printf("Graph initialized with edges: (0,1), (0,2), (1,3), (1,4), (2,4)\n");

    BFS(0);

    for (int i = 0; i < n; i++) visited[i] = false;
    printf("DFS Traversal: ");
    DFS(0);
    printf("\n");

    return 0;
}
