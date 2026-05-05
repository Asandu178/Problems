#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    int MOD = 1e9 + 7;
    cin >> n >> m;
    vector<int> v(n);

    for (auto &x : v)
        cin >> x;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));


    if (v[0])
        dp[1][v[0]] = 1;
    else
    for (int i = 1 ; i <= m ; i++)
        dp[1][i] = 1;
    
    for (int i = 2 ; i <= n ; i++) {
        if (v[i - 1]) {
            for (int k : {v[i - 1] - 1, v[i - 1], v[i - 1] + 1})
                if (k >= 1 && k <= m)
                    dp[i][v[i - 1]] += (dp[i - 1][k]) % MOD;
            dp[i][v[i - 1]] %= MOD;
        } else {
            for (int j = 1 ; j <= m ; j++) {
                for (int k : {j - 1, j, j + 1}) {
                    if (k >= 1 && k <= m)
                        dp[i][j] += (dp[i - 1][k] % MOD);
                }
                dp[i][j] %= MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 1 ; i <= m ; i++)
        ans += dp[n][i];

    cout << ans << '\n';
}