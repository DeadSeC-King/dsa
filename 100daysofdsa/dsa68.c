// /Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
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

void topologicalSort(Graph* graph) {
    int inDegree[MAX_VERTICES] = { 0 };
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->vertices[i][j]) {
                inDegree[j]++;
            }
        }
    }

    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    printf("Topological Order: ");
    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->vertices[vertex][i]) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
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