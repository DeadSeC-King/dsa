//Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.
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
void addEdge(Graph* graph, int src, int dest, int weight) {
    graph->vertices[src][dest] = weight; // Undirected edge with weight
    graph->vertices[dest][src] = weight; // Undirected edge with weight
}
int minKey(int key[], int mstSet[], int numVertices) {
    int min = __INT_MAX__, minIndex;
    for (int v = 0; v < numVertices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}
int primMST(Graph* graph) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int mstSet[MAX_VERTICES];
    for (int i = 0; i < graph->numVertices; i++) {
        key[i] = __INT_MAX__;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < graph->numVertices - 1; count++) {
        int u = minKey(key, mstSet, graph->numVertices);
        mstSet[u] = 1;

        for (int v = 0; v < graph->numVertices; v++) {
            if (graph->vertices[u][v] && mstSet[v] == 0 && graph->vertices[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->vertices[u][v];
            }
        }
    }

    int totalWeight = 0;
    for (int i = 1; i < graph->numVertices; i++) {
        totalWeight += graph->vertices[parent[i]][i];
    }
    return totalWeight;
}
int main() {
    Graph graph;
    initGraph(&graph, 5);

    addEdge(&graph, 0, 1, 10);
    addEdge(&graph, 0, 2, 20);
    addEdge(&graph, 1, 2, 30);
    addEdge(&graph, 1, 3, 5);
    addEdge(&graph, 2, 3, 15);
    addEdge(&graph, 3, 4, 8);

    int totalWeight = primMST(&graph);
    printf("Total weight of Minimum Spanning Tree: %d\n", totalWeight);
    return 0;
}

