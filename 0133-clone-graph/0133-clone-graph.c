#include <stdlib.h>

// Hash map size (adjust if needed)
#define MAX 1000

struct Node* visited[MAX];

struct Node* dfs(struct Node* node) {
    if (node == NULL) return NULL;

    // If already cloned
    if (visited[node->val] != NULL)
        return visited[node->val];

    // Create new node
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

    // Mark as visited
    visited[node->val] = clone;

    // Clone neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i]);
    }

    return clone;
}

struct Node *cloneGraph(struct Node *s) {
    if (s == NULL) return NULL;

    // Initialize visited array
    for (int i = 0; i < MAX; i++) {
        visited[i] = NULL;
    }

    return dfs(s);
}