#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        back(n, 0, 0, s, ans);
        return ans;
    }

    void back(int n, int open, int closed, string &s, vector<string> &ans) {
        if (2 * n == s.size()) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            s += "(";
            back(n, open + 1, closed, s, ans);
            s.pop_back();
        }

        if (closed < open) {
            s += ")";
            back(n, open, closed + 1, s, ans);
            s.pop_back();
        }
    }

};

int main() {
    int n;
    cin >> n;
    Solution sol;
    vector<string> ans = sol.generateParenthesis(n);

    for (string s : ans)
        cout << s << endl;

    return 0;
}