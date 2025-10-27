#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> v;  
        backtrack(0, 0, target, output, v, candidates);
        return output; 
    }

    void backtrack(int start, int sum, int target, vector<vector<int>> &output, vector<int> v, vector<int> candidates) {
        if (sum == target) {
            output.push_back(v);
            return;
        }

        if (sum > target)
            return;
        
        for (int i = start ; i < candidates.size() ; i++) {
            v.push_back(candidates[i]);
            backtrack(i, sum + candidates[i], target, output, v, candidates);
            v.pop_back();
        }
    }
};