#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
long long MOD = 1e9 + 7;

    int checkRecord(int n) {
        // vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(3, vector<int>(4, 0)));
        int memo[100001][2][3] = {0};
        //return back(n, 0, 0, memo);

        for (int j = 0 ; j < 2 ; j++) {
            for (int k = 0 ; k < 3 ; k++) {
                memo[0][j][k] = 1;
            }
        }
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 0 ; j < 2 ; j++) {
                for (int k = 0 ; k < 3 ; k++) {
                    long long ans = 0;
                    if (j + 1 < 2)
                        ans += memo[i - 1][j + 1][0];
                    if (k + 1 < 3)
                        ans += memo[i - 1][j][k + 1];
                    ans += memo[i - 1][j][0];
                    ans %= MOD;
                    memo[i][j][k] = ans;
                }
            }
        }

        return memo[n][0][0];
    }

    int back(int day, int abs, int late, vector<vector<vector<int>>> &memo) {

        if (abs > 1 || late > 2) {
            return 0;
        }

        if (memo[day][abs][late] != -1) {
            return memo[day][abs][late];
        }

        if (day == 0) {
            memo[day][abs][late] = 1;
            return 1;
        }

        memo[day][abs][late] = (1ULL * back(day - 1, abs, 0, memo) + back(day - 1, abs + 1, 0, memo) + back(day - 1, abs, late + 1, memo)) % MOD;
        return memo[day][abs][late];
    }
};

int main() {
    Solution sol;
    cout << sol.checkRecord(2);
}