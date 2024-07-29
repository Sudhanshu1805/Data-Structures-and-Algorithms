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

// Initialize visited array
bool visited[MAX_VERTICES];

// Function to add an edge to the adjacency list
void addEdge(int start, int end) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = end;
    newNode->next = adjacencyList[start];
    adjacencyList[start] = newNode;
}

// Function to perform DFS and find connected components
void findConnectedComponentsDFS(int vertex) {
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node* current = adjacencyList[vertex];
    while (current != NULL) {
        int neighbor = current->vertex;
        if (!visited[neighbor]) {
            findConnectedComponentsDFS(neighbor);
        }
        current = current->next;
    }
}

// Function to find the number of connected components
int findNumberOfComponents(int numVertices) {
    int components = 0;
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            printf("Connected Component %d: ", components + 1);
            findConnectedComponentsDFS(i);
            printf("\n");
            components++;
        }
    }
    return components;
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);

    for (int i = 0; i < numVertices; i++) {
        adjacencyList[i] = NULL;
        visited[i] = false;
    }

    printf("Enter the edges (format: source destination):\n");
    for (int i = 0; i < numEdges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(start, end);
        addEdge(end, start); // For undirected graph
    }

    int components = findNumberOfComponents(numVertices);

    printf("Number of connected components: %d\n", components);

    return 0;
}
