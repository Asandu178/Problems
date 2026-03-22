#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

        for (int len = k ; len <= n ; len++) {
            for (int i = 0 ; i + len <= n ; i++) {
                int j = len + i - 1;
                for (int z = k ; z + k < j ; z++) {
                    int suma;
                    partial_sum(stones.begin() + z, stones.end() + 2 * z, &suma);
                    dp[i][j] = min(dp[i][j], dp[i][z] + dp[z + k][j] + suma);
                }
            }
        }
        return dp[0][n - 1];
    }
};