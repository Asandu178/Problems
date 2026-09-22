#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, x, y;
    long long mod = 1e9 + 7;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<vector<int>> backedge(n);
    vector<int> indegree(n, 0);
    queue<int> q;

    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int i = 0 ; i < m ; i++) {
        cin >> x >> y;
        adj[--x].push_back(--y);
        backedge[y].push_back(x);
        indegree[y]++;
    }

    for (int i = 0 ; i < n ; i++)
        if (!indegree[i])
            q.push(i);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int next : adj[node]) {
            indegree[next]--;

            if (!indegree[next])
                q.push(next);
        }

        for (int prev : backedge[node])
            dp[node] = (dp[node] + dp[prev]) % mod;
    }

    cout << dp[n - 1];
    return 0;
}