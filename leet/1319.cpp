#include <bits/stdc++.h>

using namespace std;

class disjointedSet {

public:

    vector<int> d;
    vector<int> parent;

    disjointedSet(int n) {
        d = vector<int>(n, 1);
        parent = vector<int>(n);

        for (int i = 0 ; i < n ; i++)
            parent[i] = i;
    }

    void unionOf(int x, int y) {
        int rx = parentOf(x);
        int ry = parentOf(y);

        if (d[rx] >= d[ry]) {
            d[rx] += d[ry];
            parent[ry] = rx;
        } else {
            d[ry] += d[rx];
            parent[rx] = ry;
        }
    }

    int parentOf(int x) {
        if (parent[x] == x)
            return x;

        parent[x] = parentOf(parent[x]);
        return parent[x];
    }


};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        int total = connections.size();
        int cnt = 0;

        disjointedSet set(n);

        for (auto edge : connections) {
            int u = edge[0];
            int v = edge[1];

            if(set.parentOf(u) != set.parentOf(v)) {
                set.unionOf(u, v);
                total--;
            }
        }

        for (int i = 0 ; i < n ; i++) {
            if (set.parent[i] == i)
                cnt++;
        }

        if (cnt - 1 <= total)
            return cnt - 1;

        return -1;

    }
};