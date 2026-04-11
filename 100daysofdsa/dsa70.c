//Compute shortest path from source and detect negative weight cycles using Bellman-Ford.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct {
    int vertex;
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX_VERTICES];
    int num_edges;
} Graph;

void add_edge(Graph* graph, int src, int dest, int weight) {
    graph[src].edges[graph[src].num_edges].vertex = dest;
    graph[src].edges[graph[src].num_edges].weight = weight;
    graph[src].num_edges++;
}

void bellman_ford(Graph* graph, int source, int num_vertices) {
    int dist[MAX_VERTICES];

    for (int i = 0; i < num_vertices; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    for (int i = 1; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            for (int k = 0; k < graph[j].num_edges; k++) {
                Edge edge = graph[j].edges[k];
                if (dist[j] != INT_MAX && dist[j] + edge.weight < dist[edge.vertex]) {
                    dist[edge.vertex] = dist[j] + edge.weight;
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < num_vertices; j++) {
        for (int k = 0; k < graph[j].num_edges; k++) {
            Edge edge = graph[j].edges[k];
            if (dist[j] != INT_MAX && dist[j] + edge.weight < dist[edge.vertex]) {
                printf("Graph contains negative weight cycle\n");
                return;
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    Graph graph[MAX_VERTICES] = {0};
    int num_vertices = 5;

    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 2, 5);
    add_edge(graph, 1, 2, 2);
    add_edge(graph, 1, 3, 1);
    add_edge(graph, 2, 1, 3);
    add_edge(graph, 2, 3, 9);
    add_edge(graph, 2, 4, 2);
    add_edge(graph, 3, 4, 4);
    add_edge(graph, 4, 3, -7); // Negative weight edge

    bellman_ford(graph, 0, num_vertices);

    return 0;
}
