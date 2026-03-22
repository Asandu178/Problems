#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2 ; len <= n ; len++) {
            for (int i = 0 ; len + i <= n ; i++) {
                int j = len + i - 1;
                for (int k = i + 1 ; k < j ; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};