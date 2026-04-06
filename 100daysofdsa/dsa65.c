// Using DFS and parent tracking, detect if undirected graph has a cycle.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void initGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->vertices[i][j] = 0;
        }
    }
}

void addEdge(Graph* graph, int src, int dest) {
    graph->vertices[src][dest] = 1;
    graph->vertices[dest][src] = 1; // Since the graph is undirected
}

bool dfs(Graph* graph, int vertex, bool visited[], int parent) {
    visited[vertex] = true;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[vertex][i]) { // If there is an edge
            if (!visited[i]) {
                if (dfs(graph, i, visited, vertex)) {
                    return true;
                }
            } else if (i != parent) { // If visited and not parent, cycle detected
                return true;
            }
        }
    }
    return false;
}



bool hasCycle(Graph* graph) {
    bool visited[MAX_VERTICES] = { false };

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    Graph graph;
    initGraph(&graph, 5);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 0); // This creates a cycle
    addEdge(&graph, 3, 4);

    if (hasCycle(&graph)) {
        printf("Graph has a cycle.\n");
    } else {
        printf("Graph does not have a cycle.\n");
    }

    return 0;
}