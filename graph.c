#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

void displayGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS: ");

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node + 1);

        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int node) {
    printf("%d ", node + 1);
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int edges, u, v;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);

        u--; 
        v--;

        if (u < 0 || v < 0 || u >= n || v >= n) {
            printf("Invalid edge! Try again\n");
            i--;
            continue;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;

        printf("\nMatrix after adding edge %d - %d:\n", u + 1, v + 1);
        displayGraph();
    }

    bfs(0);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS: ");
    dfs(0);

    return 0;
}