//Detect cycle in directed graph using DFS and recursion stack.
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
    graph->vertices[src][dest] = 1; // Directed edge from src to dest
}
bool dfs(Graph* graph, int vertex, bool visited[], bool recStack[]) {
    visited[vertex] = true;
    recStack[vertex] = true;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[vertex][i]) { // If there is an edge
            if (!visited[i]) {
                if (dfs(graph, i, visited, recStack)) {
                    return true;
                }
            } else if (recStack[i]) { // If visited and in recursion stack, cycle detected
                return true;
            }
        }
    }
    recStack[vertex] = false; // Remove from recursion stack
    return false;
}
bool hasCycle(Graph* graph) {
    bool visited[MAX_VERTICES] = { false };
    bool recStack[MAX_VERTICES] = { false };

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, visited, recStack)) {
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
