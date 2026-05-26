#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> parent(n, -1);
        vector<int> dist(n, INT_MAX);
        vector<bool> used(n, false);

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (i == j)
                    continue;
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, w});
                adj[j].push_back({i, w});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int cost = 0;
        dist[0] = 0;

        // {dist, source}
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [_, node] = pq.top();
            pq.pop();

            if (used[node])
                continue;

            used[node] = true;
            
            if (parent[node] != -1) {
                cost += dist[node];
            }

            for (auto [neigh, w] : adj[node]) {
                if (!used[neigh] && w < dist[neigh]) {
                    dist[neigh] = w;
                    parent[neigh] = node;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        return cost;
        
    }
};