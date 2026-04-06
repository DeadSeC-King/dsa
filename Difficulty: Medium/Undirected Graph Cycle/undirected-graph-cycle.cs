using System;
using System.Collections.Generic;

class Solution {
    
    public bool isCycle(int V, int[,] edges) {
        // Step 1: Build adjacency list
        List<int>[] adj = new List<int>[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new List<int>();
        }

        int E = edges.GetLength(0);
        for (int i = 0; i < E; i++) {
            int u = edges[i, 0];
            int v = edges[i, 1];

            adj[u].Add(v);
            adj[v].Add(u); // undirected graph
        }

        // Step 2: Visited array
        bool[] visited = new bool[V];

        // Step 3: Check all components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (DFS(i, -1, visited, adj)) {
                    return true;
                }
            }
        }

        return false;
    }

    private bool DFS(int node, int parent, bool[] visited, List<int>[] adj) {
        visited[node] = true;

        foreach (int neighbor in adj[node]) {
            if (!visited[neighbor]) {
                if (DFS(neighbor, node, visited, adj)) {
                    return true;
                }
            }
            else if (neighbor != parent) {
                // Cycle detected
                return true;
            }
        }

        return false;
    }
}