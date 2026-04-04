// Perform DFS starting from a given source vertex using recursion.
#include <stdio.h>
#define MAX 100
int graph[MAX][MAX], visited[MAX], n;
void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}
int main() {
    int edges, u, v, source;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    printf("DFS starting from vertex %d: ", source);
    DFS(source);
    return 0;
}
