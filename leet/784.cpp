#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> output;
        string crr;
        backtrack(output, 0, s, crr);
        return output;
    }

    void backtrack(vector<string>&output, int idx, string &s, string &crr) {
        if (idx == s.size()) {
            output.push_back(crr);
            return;
        }

            crr.push_back(s[idx]);
            backtrack(output, idx + 1, s, crr);
            crr.pop_back();
            if (isalpha(s[idx])) {
                crr.push_back(s[idx] ^ 32);
                backtrack(output, idx + 1, s, crr);
                crr.pop_back();
            }
    }
};

int main() {
    Solution sol;
    vector<string> rez;
    rez = sol.letterCasePermutation("a1b2");
    for (int i = 0 ; i < rez.size() ; i++)
        cout<< rez[i] << endl;
}