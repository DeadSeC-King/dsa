//Perform BFS from a given source using queue.
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int graph[MAX][MAX], visited[MAX], queue[MAX];
void bfs(int start, int n) {
    int front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int n, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int u, v;
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    
    printf("BFS Traversal: ");
    bfs(start, n);
    
    return 0;
}
