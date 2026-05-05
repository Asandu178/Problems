#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int mod = 1e9 + 7;
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<long long>> dp(grid.size(), vector<long long>(grid[0].size(), 0));
        long long ans = 0;
        for (int i = 0 ; i < grid.size() ; i++) {
            for (int j = 0 ; j < grid[0].size() ; j++) {
                ans = (ans + dfs(i, j, -1, grid, dp)) % mod;
            }
        }

        return ans;
    }

    int dfs(int i, int j, int prev, vector<vector<int>>& grid, vector<vector<long long>>& dp) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || prev >= grid[i][j])
            return 0;

        if (dp[i][j])
            return dp[i][j];
        
        dp[i][j] = (1 + dfs(i + 1, j, grid[i][j], grid, dp) + dfs(i - 1, j, grid[i][j], grid, dp) +
        dfs(i, j - 1, grid[i][j], grid, dp) + dfs(i, j + 1, grid[i][j], grid, dp)) % mod;

        return dp[i][j];
    }
};