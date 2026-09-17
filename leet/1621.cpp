#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int mod = 1e9 + 7;

    int numberOfSets(int n, int k) {
        vector<vector<long long>> dp(n, vector<long long>(k + 1));

        for (int i = 0 ; i < n ; i++)
            dp[i][0] = 1;


        for (int j = 1 ; j <= k ; j++) {
            long long sum = 0;

            for (int i = 1 ; i < n ; i++) {
                sum = (sum + dp[i - 1][j - 1]) % mod;

                dp[i][j] = (dp[i - 1][j] + sum) % mod;
            }
        }

        return dp[n - 1][k];
    }
};