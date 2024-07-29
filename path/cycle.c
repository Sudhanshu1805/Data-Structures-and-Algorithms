#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Define a structure to represent an adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Define the adjacency list
struct Node* adjacencyList[MAX_VERTICES];

// Initialize visited and parent arrays
bool visited[MAX_VERTICES];
int parent[MAX_VERTICES];

// Function to add an edge to the adjacency list
void addEdge(int start, int end) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = end;
    newNode->next = adjacencyList[start];
    adjacencyList[start] = newNode;
}

// Function to perform DFS and detect cycles
bool hasCycleDFS(int vertex, int parent[MAX_VERTICES]) {
    visited[vertex] = true;
    // Assign the parent of the current vertex
    parent[vertex] = parent;

    struct Node* current = adjacencyList[vertex];
    while (current != NULL) {
        int neighbor = current->vertex;
        if (!visited[neighbor]) {
            if (hasCycleDFS(neighbor, parent)) {
                return true;
            }
        } else if (parent[vertex] != neighbor) {
            return true;
        }
        current = current->next;
    }

    return false;
}

// Function to check for cycles in the graph
bool hasCycle(int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
        parent[i] = -1;
    }

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(i, -1)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);

    for (int i = 0; i < numVertices; i++) {
        adjacencyList[i] = NULL;
    }

    printf("Enter the edges (format: source destination):\n");
    for (int i = 0; i < numEdges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(start, end);
        addEdge(end, start); // For undirected graph
    }

    if (hasCycle(numVertices)) {
        printf("The graph contains a cycle.\n");
    } else {
        printf("The graph does not contain a cycle.\n");
    }

    return 0;
}
