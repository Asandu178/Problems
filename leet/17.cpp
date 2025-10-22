#include <vector>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> sets;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> set;
        backtrack(0, set, nums);
    }

    void backtrack(int poz, vector<int>& set, vector<int>& nums) {
        if (poz == nums.size()) {
            sets.push_back(set);
            return;
        }

        backtrack(poz + 1, set, nums);

        set.push_back(nums[poz]);
        backtrack(poz + 1, set, nums);
        set.pop_back();
    }
};