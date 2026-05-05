#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> solutions;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sol;
        sort(candidates.begin(), candidates.end());
        back(candidates, sol, 0, target);
        return solutions;
    }

    void back(vector<int>& candidates, vector<int>& sol, int index, int target) {

        if (target == 0) {
            solutions.push_back(sol);
            return;
        }

        if (target < 0 || index == candidates.size()) {
            return;
        }

        sol.push_back(candidates[index]);
        back(candidates, sol, index + 1, target - candidates[index]);
        sol.pop_back();

        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1])
            index++;
        
        back(candidates, sol, index + 1, target);
    }
};