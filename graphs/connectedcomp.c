#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

// Function prototypes
void dfs(int graph[MAX][MAX], int visited[MAX], int v, int n);
int connectedComponents(int graph[MAX][MAX], int n);

int main() {
    int n, e;  // n = number of vertices, e = number of edges
    int graph[MAX][MAX] = {0};  // Adjacency matrix initialized to 0
    int u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        printf("The edge inserted between %d and %d\n",u,v);
        graph[u][v] = 1;
        graph[v][u] = 1;  // Since the graph is undirected
    }

    int result = connectedComponents(graph, n);
    printf("Number of connected components: %d\n", result);

    return 0;
}

// Function to perform DFS
void dfs(int graph[MAX][MAX], int visited[MAX], int v, int n) {
    visited[v] = 1;  // Mark the current vertex as visited

    for (int u = 0; u < n; u++) {
        if (graph[v][u] == 1 && visited[u] == -1) {  // If connected and not visited
            dfs(graph, visited, u, n);
        }
    }
}

// Function to count the number of connected components
int connectedComponents(int graph[MAX][MAX], int n) {
    int visited[MAX];
    for (int i = 0; i < n; i++) {
        visited[i] = -1;  // Initialize all vertices as not visited
    }

    int count = 0;

    for (int v = 0; v < n; v++) {
        if (visited[v] == -1) {  // If the vertex is not visited
            dfs(graph, visited, v, n);  // Perform DFS
            count++;  // Increment the component count
        }
    }

    return count;
}
