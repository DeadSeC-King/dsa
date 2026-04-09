using System;
using System.Collections.Generic;
using System.Text;

class Solution {
    public string findOrder(string[] words) {
        // Step 1: Initialize graph
        Dictionary<char, HashSet<char>> graph = new Dictionary<char, HashSet<char>>();
        Dictionary<char, int> indegree = new Dictionary<char, int>();

        // Add all unique characters
        foreach (var word in words) {
            foreach (char c in word) {
                if (!graph.ContainsKey(c)) {
                    graph[c] = new HashSet<char>();
                    indegree[c] = 0;
                }
            }
        }

        // Step 2: Build graph
        for (int i = 0; i < words.Length - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            // Edge case: invalid order
            if (w1.Length > w2.Length && w1.StartsWith(w2)) {
                return "";
            }

            int len = Math.Min(w1.Length, w2.Length);
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    if (!graph[w1[j]].Contains(w2[j])) {
                        graph[w1[j]].Add(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }

        // Step 3: Topological Sort (Kahn’s BFS)
        Queue<char> queue = new Queue<char>();
        foreach (var kvp in indegree) {
            if (kvp.Value == 0) {
                queue.Enqueue(kvp.Key);
            }
        }

        StringBuilder result = new StringBuilder();

        while (queue.Count > 0) {
            char curr = queue.Dequeue();
            result.Append(curr);

            foreach (char neighbor in graph[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    queue.Enqueue(neighbor);
                }
            }
        }

        // Step 4: Check for cycle
        if (result.Length != indegree.Count) {
            return "";
        }

        return result.ToString();
    }
}