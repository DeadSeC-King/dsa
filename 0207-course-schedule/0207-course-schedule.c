#include <stdbool.h>
#include <stdlib.h>

bool dfs(int node, int** adj, int* adjSize, int* state) {
    if (state[node] == 1) return true;   // cycle found
    if (state[node] == 2) return false;  // already safe

    state[node] = 1; // mark as visiting

    for (int i = 0; i < adjSize[node]; i++) {
        if (dfs(adj[node][i], adj, adjSize, state)) {
            return true;
        }
    }

    state[node] = 2; // mark as safe
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    
    // Step 1: Create adjacency list
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int)); // max possible
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];

        adj[prereq][adjSize[prereq]++] = course;
    }

    // Step 2: State array
    int* state = (int*)calloc(numCourses, sizeof(int));

    // Step 3: DFS for each node
    for (int i = 0; i < numCourses; i++) {
        if (dfs(i, adj, adjSize, state)) {
            return false; // cycle found
        }
    }

    return true; // no cycle
}