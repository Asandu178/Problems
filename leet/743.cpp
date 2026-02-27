#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n + 1);
        vector<long long> dist(n + 1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto &t : times)
            adj[t[0]].push_back({t[1], t[2]});

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            auto top = pq.top();

            pq.pop();

            int d = top.first;
            int u = top.second;

            if (d > dist[u])
                continue;

            for (auto &p : adj[u]) {
                int v = p.first;
                int w = p.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;

        for (int i = 1 ; i <= n ; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            if (ans < dist[i])
                ans = dist[i];
        }

        return ans;
    }
};