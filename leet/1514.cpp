#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        vector<double> prob(n, -1);

        for (int i = 0 ; i < edges.size() ; i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> pq;

        prob[start_node] = 1;

        pq.push({1, start_node});

        while (!pq.empty()) {
            auto [p, node] = pq.top();
            pq.pop();

            for (auto [neigh, w] : adj[node]) {
                if (prob[node] * w > prob[neigh]) {
                    prob[neigh] = prob[node] * w;
                    pq.push({prob[neigh], neigh});
                }
            }
        }

        return prob[end_node] == -1 ? 0 : prob[end_node];


    }
};