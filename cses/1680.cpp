#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> neigh(n);
    vector<vector<int>> backedge(n);
    vector<int> indegree(n);
    vector<int> parent(n, -1);
    vector<int> topsort;
    vector<int> dp(n, INT_MIN);
    dp[0] = 1;

    queue<int> q;

    for (int i = 0 ; i < m ; i++) {
        int x, y;
        cin >> x >> y;
        neigh[x - 1].push_back(y - 1);
        backedge[y - 1].push_back(x - 1);
        indegree[y - 1]++;
    }

    for (int i = 0 ; i < n ; i++)
        if (!indegree[i])
            q.push(i);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        topsort.push_back(node);

        for (int next : neigh[node]) {
            indegree[next]--;

            if (indegree[next] == 0)
                q.push(next);
        }

    }

    for (int i = 0 ; i < n ; i++) {
        int u = topsort[i];

        for (int v : backedge[u]) {
            if (dp[v] + 1 > dp[u]) {
                dp[u] = dp[v] + 1;
                parent[u] = v;
            }
        }
    }

    if (dp[n - 1] < 0) {
        cout << "IMPOSSIBLE";
    } else {
        vector<int> route;
        for (int p = n - 1 ; p != -1 ; p = parent[p])
            route.push_back(p);

        cout << dp[n - 1] << endl;

        reverse(route.begin(), route.end());
        for (auto a : route)
            cout << a + 1 << " ";
    }

    return 0;
}