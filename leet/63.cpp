#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1)
            return 0;

        vector<vector<int>> dp(n,  vector<int>(m, 0));
        dp[0][0] = 1;

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {

                int sum = 0;

                if (obstacleGrid[i][j] == 1)
                    continue;

                if (i - 1 >= 0)
                    sum += dp[i - 1][j];
                if (j - 1 >= 0)
                    sum += dp[i][j - 1];

                dp[i][j] += sum;
            }
        }

        return dp[n - 1][m - 1];
    }
};