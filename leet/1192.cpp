#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int timestamp = 0;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for (auto edge : connections) {
            int x = edge[0];
            int y = edge[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> low(n, -1);
        vector<int> discovery(n, -1);
        vector<vector<int>> sol;

        for (int i = 0 ; i < n ; i++) {
            if (discovery[i] == -1) {
                tarjan(i, -1, low, discovery, adj, sol);
            }
        }

        return sol;
    }

    void tarjan(int node, int parent, vector<int>& low, vector<int>& discovery, vector<vector<int>>& adj, vector<vector<int>>& sol) {
        discovery[node] = ++timestamp;
        low[node] = discovery[node];

        for (int neigh : adj[node]) {
            if (neigh == parent)
                continue;
            
            if (discovery[neigh] == -1) {
                tarjan(neigh, node, low, discovery, adj, sol);
                low[node] = min(low[node], low[neigh]);
                if (low[neigh] > discovery[node])
                    sol.push_back({node, neigh});
            } else
                low[node] = min(low[node], discovery[neigh]);
        }
    }
};