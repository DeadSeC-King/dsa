using System;
using System.Collections.Generic;

class Solution
{
    static int timer;

    void DFS(int u, int parent, bool[] visited, int[] disc, int[] low,
             List<int>[] adj, bool[] ap)
    {
        visited[u] = true;
        disc[u] = low[u] = ++timer;
        int children = 0;

        foreach (int v in adj[u])
        {
            if (!visited[v])
            {
                children++;
                DFS(v, u, visited, disc, low, adj, ap);

                low[u] = Math.Min(low[u], low[v]);

                if (parent == -1 && children > 1)
                    ap[u] = true;

                if (parent != -1 && low[v] >= disc[u])
                    ap[u] = true;
            }
            else if (v != parent)
            {
                low[u] = Math.Min(low[u], disc[v]);
            }
        }
    }

    public List<int> articulationPoints(int V, List<int>[] adj)
    {
        bool[] visited = new bool[V];
        int[] disc = new int[V];
        int[] low = new int[V];
        bool[] ap = new bool[V];

        timer = 0;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                DFS(i, -1, visited, disc, low, adj, ap);
        }

        List<int> result = new List<int>();

        for (int i = 0; i < V; i++)
        {
            if (ap[i])
                result.Add(i);
        }

        if (result.Count == 0)
            result.Add(-1);

        return result;
    }
}