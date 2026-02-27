#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> money(n, 0);
        money[0] = nums[0];
        money[1] = max(nums[0], nums[1]);
        for (int i = 2 ; i < n ; i++)
            money[i] = max(money[i-1], money[i-2] + nums[i]);
        return money[n - 1];
    }
};