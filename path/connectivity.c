#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Define the adjacency matrix
int graph[MAX_VERTICES][MAX_VERTICES];
int vertices, edges;

// Initialize the visited array
bool visited[MAX_VERTICES];

// Function to perform DFS and check connectivity
void DFS(int vertex) {
    visited[vertex] = true;

    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// Function to check connectivity
bool isGraphConnected() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
    }

    // Find the first unvisited vertex and start DFS from there
    int start_vertex = -1;
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            start_vertex = i;
            break;
        }
    }

    if (start_vertex == -1) {
        // The graph has no vertices, so it's considered connected
        return true;
    }

    DFS(start_vertex);

    // Check if all vertices have been visited
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            return false; // The graph is not connected
        }
    }

    return true; // The graph is connected
}

int main() {
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    // Initialize the adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges (format: source destination):\n");
    for (int i = 0; i < edges; i++) {
        int source, destination;
        scanf("%d %d", &source, &destination);
        graph[source][destination] = 1;
        graph[destination][source] = 1; // For undirected graph
    }

    if (isGraphConnected()) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
