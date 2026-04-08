//Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>
#include <stdlib.h>
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

void dfs(Graph* graph, int vertex, bool visited[], int stack[], int* top) {
    visited[vertex] = true;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[vertex][i] && !visited[i]) { // If there is an edge and not visited
            dfs(graph, i, visited, stack, top);
        }
    }
    stack[(*top)++] = vertex; // Push vertex to stack after visiting all neighbors
}

void topologicalSort(Graph* graph) {
    bool visited[MAX_VERTICES] = { false };
    int stack[MAX_VERTICES];
    int top = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited, stack, &top);
        }
    }

    // Print the topological order
    printf("Topological Order: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    Graph graph;
    initGraph(&graph, 6);

    addEdge(&graph, 5, 2);
    addEdge(&graph, 5, 0);
    addEdge(&graph, 4, 0);
    addEdge(&graph, 4, 1);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 1);

    topologicalSort(&graph);

    return 0;
}
    