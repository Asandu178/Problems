#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> size;
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        int m = edges.size();
        int min_cost = 0;

        vector<int> critical;
        vector<int> pseudo;
        vector<vector<int>> sol;

        for (int i = 0 ; i < m ; i++) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), [](const vector<int>&a, const vector<int>&b) {
            return a[2] < b[2];
        });

        min_cost = getMst(n, edges, -1, -1);

        for (int i = 0 ; i < m ; i++) {
            if (min_cost < getMst(n, edges, i, -1))
                critical.push_back(edges[i][3]);
            else if (min_cost == getMst(n, edges, -1, i))
                pseudo.push_back(edges[i][3]);
        }

        sol.push_back(critical);
        sol.push_back(pseudo);
        return sol;
    }

    int getMst(int n, vector<vector<int>>& edges, int blocked, int forced) {
        reset(n);
        int cost = 0;
        int cnt = 0;

        if (forced != -1) {
            cost += edges[forced][2];
            cnt++;
            unionOf(edges[forced][0], edges[forced][1]);
        }

        for (int i = 0 ; i < edges.size() ; i++) {
            if (blocked == i)
                continue;
            
            if (setOf(edges[i][0]) != setOf(edges[i][1])) {
                cost += edges[i][2];
                cnt++;
                unionOf(edges[i][0], edges[i][1]);
            }
        }

        if (cnt != n - 1)
            return INT_MAX;
        return cost;
    }

    void reset(int n) {
        parent = vector<int>(n);
        size = vector<int>(n, 1);
        for (int i = 0 ; i < n ; i++)
            parent[i] = i;
    }

    int setOf(int x) {
        if (parent[x] == x)
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