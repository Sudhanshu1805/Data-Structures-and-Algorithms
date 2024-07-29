#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Define the adjacency matrix
int graph[MAX_VERTICES][MAX_VERTICES];
int vertices, edges;

// Initialize the visited array
bool visited[MAX_VERTICES];

// Define a queue data structure for BFS
int queue[MAX_VERTICES];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue is full.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = vertex;
    }
}

int dequeue() {
    int vertex;
    if (front == -1) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        vertex = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return vertex;
    }
}

// Function to perform BFS and find a path
void BFS(int start, int end) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
    }

    enqueue(start);
    visited[start] = true;

    while (front != -1) {
        int current = dequeue();
        if (current == end) {
            printf("Path found from %d to %d.\n", start, end);
            return;
        }

        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && graph[current][i] == 1) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }

    printf("No path found from %d to %d.\n", start, end);
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

    int start, end;
    printf("Enter the start and end vertices to find a path: ");
    scanf("%d %d", &start, &end);

    BFS(start, end);

    return 0;
}
