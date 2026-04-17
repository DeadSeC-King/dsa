//Using DFS or BFS, count number of connected components.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void DFS(int graph[MAX][MAX], int visited[MAX], int vertex, int n) {
    visited[vertex] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, visited, i, n);
        }
    }
}

int countConnectedComponents(int graph[MAX][MAX], int n) {
    int visited[MAX] = {0};
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(graph, visited, i, n);
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int graph[MAX][MAX];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int result = countConnectedComponents(graph, n);
    printf("The number of connected components is: %d\n", result);
    return 0;
}

