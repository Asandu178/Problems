#include <bits/stdc++.h>

using namespace std;

class DisjointedSet {
public:
    vector<int> parent;
    vector<int> size;

    DisjointedSet(int n) {
        parent = vector<int>(n + 1);
        size = vector<int>(n + 1, 1);

        for (int i = 1 ; i <= n ; i++) {
            parent[i] = i;
        }
    }

    int setOf(int x) {
        if (x == parent[x])
            return x;

        parent[x] = setOf(parent[x]);
        return parent[x];
    }

    void unionOf(int x, int y) {
        int rx = setOf(x);
        int ry = setOf(y);

        if (size[rx] >= size[ry]) {
            parent[ry] = rx;
            size[rx] += size[ry];
        } else {
            parent[rx] = ry;
            size[ry] += size[rx];
        }
    }
    
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        auto disjointedSet  = DisjointedSet(n);

        vector<pair<int, int>> edges;

        for (int i = 1 ; i <= n ; i++) {
            int m = 2 * i;
            while (m <= n) {
                edges.push_back({i, m});
                edges.push_back({m, i});
                m += i;
            }
        }

        for (auto [x, y] : edges) {
            if (disjointedSet.setOf(x) != disjointedSet.setOf(y) && x > threshold && y > threshold) {
                disjointedSet.unionOf(x, y);
            }
        }

        vector<bool> sol;

        for (auto q : queries)
            sol.push_back(disjointedSet.setOf(q[0]) == disjointedSet.setOf(q[1]));

        return sol;
    }
};