#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> output;
        vector<int> v;
        backtrack(1, 0, k, n, v, output);
        return output;
    }

    void backtrack(int start, int sum, int k, int n, vector<int>& v, vector<vector<int>>&output) {
        if (sum == n && k == 0) {
            output.push_back(v);
            return;
        }
        if (sum > n || k < 0)
            return;

        for (int i = start ; i <= 9 ; i++) {
            v.push_back(i);
            backtrack(i + 1, sum + i, k - 1, n, v, output);
            v.pop_back();
        }

    }
};