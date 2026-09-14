#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;

        back(target, 0, 0, ans, "", num);

        return ans;
    }

    void back(long long target, long long sum, long long last, vector<string>& ans, string s, string num) {

        if (num == "") {
            if (target == sum) {
                ans.push_back(s);
            }
            return;
        }

        for (int i = 0 ; i < num.size() ; i++) {
            string a = num.substr(0, i + 1);

            string rest = "";

            if (i + 1 < num.size())
                rest = num.substr(i + 1);

            if (check(a)) {
                long long val = stoll(a);

                if (s == "") {
                    back(target, val, val, ans, a, rest);
                    continue;
                }

                back(target, sum - val, -val, ans, s + "-" + a, rest);
                back(target, sum + val, val, ans, s + "+" + a, rest);
                back(target, sum - last + last * val, last * val, ans, s + "*" + a, rest);
            }
        }
    }

    bool check(string s) {
        int n = s.length();

        if (n == 1)
            return true;

        if (s[0] == '0')
            return false;

        return true;
    }
};

int main() {
    Solution sol;

    vector<string> ans;
    string s;
    int target;
    cin >> s >> target;
    ans = sol.addOperators(s, target);

    for (auto s : ans)
        cout << s << endl;


}