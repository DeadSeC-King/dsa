using System;

class Solution {
    public int tsp(int[,] cost) {
        int n = cost.GetLength(0);
        int VISITED_ALL = (1 << n) - 1;

        int[,] dp = new int[1 << n, n];

        // Initialize DP with -1
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                dp[i, j] = -1;
            }
        }

        return Solve(1, 0, cost, dp, VISITED_ALL, n);
    }

    private int Solve(int mask, int pos, int[,] cost, int[,] dp, int VISITED_ALL, int n) {
        // All cities visited → return to start
        if (mask == VISITED_ALL) {
            return cost[pos, 0];
        }

        // Already computed
        if (dp[mask, pos] != -1) {
            return dp[mask, pos];
        }

        int ans = int.MaxValue;

        // Try all cities
        for (int city = 0; city < n; city++) {
            // If city not visited
            if ((mask & (1 << city)) == 0) {
                int newAns = cost[pos, city] +
                             Solve(mask | (1 << city), city, cost, dp, VISITED_ALL, n);

                ans = Math.Min(ans, newAns);
            }
        }

        return dp[mask, pos] = ans;
    }
}