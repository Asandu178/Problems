#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);
    vector<int> sol;

    for (int i = 0 ; i < m ; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    queue<int> q;

    for (int i = 1 ; i <= n ; i++)
        if (in_degree[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int node = q.front();
        sol.push_back(node);
        q.pop();

        for (int neigh : adj[node]) {
            in_degree[neigh]--;
            if (in_degree[neigh] == 0)
                q.push(neigh);
        }
    }

    bool ok = true;

    for (int v : in_degree) {
        if (v != 0)
            ok = false;
    }

    if (ok) {
        for (int v : sol) {
            cout << v << " ";
        }
    } else {
        cout << "IMPOSSIBLE";
    }

}