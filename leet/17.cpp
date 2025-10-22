#include <vector>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    unordered_map<char, string> map = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    vector<string> letterCombinations(string digits) {
        vector<string> output;
        string s;
        backtrack(output, 0, digits, s);
    }

    void backtrack(vector<string>& output, int idx, string &digits, string &s) {
        if (digits.size() == idx) {
            output.push_back(s);
            return;
        }

        string x = map[digits[idx]];

        for (char c : x) {
            s.push_back(c);
            backtrack(output, idx + 1, digits, s);
            s.pop_back();
        }

    }
};