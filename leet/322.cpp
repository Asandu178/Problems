#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 0 ; i < dp.size() ; i++) {
            for (int coin : coins) {
                if (coin > i)
                    continue;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        if (dp[amount] == amount + 1)
            return -1;
        return dp[amount];
    }
};