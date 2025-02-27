#include <stdio.h>

#define MAX 100  // Maximum number of vertices

void computeDegrees(int graph[MAX][MAX], int n) {
    int inDegree[MAX] = {0}, outDegree[MAX] = {0};

    // Compute in-degree and out-degree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                outDegree[i]++;  // Increment out-degree of vertex i
                inDegree[j]++;   // Increment in-degree of vertex j
            }
        }
    }

    // Print results
    printf("Vertex\tIn-Degree\tOut-Degree\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i, inDegree[i], outDegree[i]);
    }
}

int main() {
    int n, graph[MAX][MAX];

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Compute and display degrees
    computeDegrees(graph, n);

    return 0;
}
