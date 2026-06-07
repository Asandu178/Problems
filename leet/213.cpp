#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n ? nums[0] : 0;
        return max(best_rob(0, n - 2, nums), best_rob(1, n - 1, nums));
    }

    int best_rob(int start, int end, vector<int>& nums) {
        int prev = 0;
        int crr = nums[start];
        for (int i = start + 1 ; i <= end ; i++) {
            int tmp = max(prev + nums[i], crr);
            prev = crr;
            crr = tmp;
        }

        return crr;
    }
};