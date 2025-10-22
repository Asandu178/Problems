#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int i : nums)
            maxOr |= i;
        int cnt = 0;
        backtrack(nums, 0, 0, maxOr, cnt);
        return cnt;
    }

    void backtrack(vector<int> &nums, int idx, int currentOR, int maxOR, int &cnt) {
        if (idx == nums.size()) {
            if (currentOR == maxOR)
                cnt++;
            return;
        }
        
        backtrack(nums, idx + 1, currentOR, maxOR, cnt);

        backtrack(nums, idx + 1, currentOR | nums[idx], maxOR, cnt);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5};
    int cnt = sol.countMaxOrSubsets(nums);
    cout << cnt;
}