#include <stdio.h>
#include <stdlib.h>

void dfs(int u, int parent, int* disc, int* low,
         int** graph, int* graphColSize,
         int** result, int* returnSize, int* timer) {

    disc[u] = low[u] = (*timer)++;

    for (int i = 0; i < graphColSize[u]; i++) {
        int v = graph[u][i];

        if (v == parent) continue;

        if (disc[v] == -1) {
            dfs(v, u, disc, low, graph, graphColSize, result, returnSize, timer);

            // Update low value
            if (low[v] < low[u]) low[u] = low[v];

            // Bridge condition
            if (low[v] > disc[u]) {
                result[*returnSize][0] = u;
                result[*returnSize][1] = v;
                (*returnSize)++;
            }
        } else {
            if (disc[v] < low[u]) low[u] = disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize,
                         int* connectionsColSize, int* returnSize,
                         int** returnColumnSizes) {

    // Step 1: Count degree
    int* degree = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < connectionsSize; i++) {
        degree[connections[i][0]]++;
        degree[connections[i][1]]++;
    }

    // Step 2: Allocate graph
    int** graph = (int**)malloc(n * sizeof(int*));
    int* graphColSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(degree[i] * sizeof(int));
    }

    // Step 3: Fill graph
    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        graph[u][graphColSize[u]++] = v;
        graph[v][graphColSize[v]++] = u;
    }

    // Step 4: Init arrays
    int* disc = (int*)malloc(n * sizeof(int));
    int* low  = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        disc[i] = -1;
        low[i] = -1;
    }

    // Step 5: Prepare result
    int** result = (int**)malloc(connectionsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(connectionsSize * sizeof(int));

    for (int i = 0; i < connectionsSize; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
        (*returnColumnSizes)[i] = 2;
    }

    *returnSize = 0;

    // Step 6: Run DFS for all components
    int timer = 0;
    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) {
            dfs(i, -1, disc, low, graph, graphColSize, result, returnSize, &timer);
        }
    }

    return result;
}