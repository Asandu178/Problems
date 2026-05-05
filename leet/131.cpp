#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> sol;
        backtrack(0, s, res, sol);
        return res;
    }

    void backtrack(int idx, string s, vector<vector<string>>& parts, vector<string>& sol) {

        if (idx == s.size()) {
            parts.push_back(sol);
            return;
        }

        for (int i = idx ; i < s.size() ; i++) {
            if (isPalindrome(s, idx, i)) {
                sol.push_back(s.substr(idx, i - idx + 1));
                backtrack(i + 1, s, parts, sol);
                sol.pop_back();
            }
        }
    }


    bool isPalindrome(string s, int start, int end) {

        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }

        return true;
    }
};