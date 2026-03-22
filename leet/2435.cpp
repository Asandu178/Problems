#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (i == 0 && j == 0)
                    continue;
                for (int r = 0 ; r < k ; r++) {
                    int new_r = (r + grid[i][j]) % k;
                    long long ans = 0;
                    if (i - 1 >= 0)
                        ans += (dp[i - 1][j][r] % MOD);
                    if (j - 1 >= 0)
                        ans += (dp[i][j - 1][r] % MOD);
                    dp[i][j][new_r] = (dp[i][j][new_r] + ans) % MOD;
                }
            }
        }

        return dp[n - 1][m - 1][0];
    }
};