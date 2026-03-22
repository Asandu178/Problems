#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n + 1, 1);
        vector<int> prev(n + 1, -1);

        int maxi = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (nums[i - 1] % nums[j - 1] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }

            if (dp[i] > dp[maxi]) {
                maxi = i;
            }
        }

        vector<int> res;

        int i = maxi;
        while (i != -1) {
            res.push_back(nums[i - 1]);
            i = prev[i];
        }
        return res;
    }
};