#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, sum = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0 ; i < n ; i++) {
        cin >> x;
        sum += x;
        v.push_back(x);
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int l = n - 1 ; l >= 0 ; l--) {
        for (int r = l; r < n ; r++) {
            if (l == r)
                dp[l][r] = v[l];
            else
                dp[l][r] = max(v[l] - dp[l + 1][r], v[r] - dp[l][r - 1]);
        }
    }

    int ans = (sum + dp[0][n - 1]) / 2;

    cout << ans;
}