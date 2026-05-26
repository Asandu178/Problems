#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int n = targetGrid.size();
        int m = targetGrid[0].size();
        vector<int> in_degree(61, 0);
        vector<vector<int>> adj(61);

        queue<int> q;

        vector<int> xmax(61, -1), xmin(61, n), ymin(61, m), ymax(61, -1);

        for (int i = 0 ; i < n; i++) {
            for (int j = 0 ; j < m ; j++) {
                xmax[targetGrid[i][j]] = max(xmax[targetGrid[i][j]], i);
                xmin[targetGrid[i][j]] = min(xmin[targetGrid[i][j]], i);
                ymax[targetGrid[i][j]] = max(ymax[targetGrid[i][j]], j);
                ymin[targetGrid[i][j]] = min(ymin[targetGrid[i][j]], j);
            }
        }

        for (int col = 1 ; col <= 60 ; col++) {
            for (int i = xmin[col] ; i <= xmax[col] ; i++) {
                for (int j = ymin[col] ; j <= ymax[col] ; j++) {
                    if (targetGrid[i][j] != col) {
                        in_degree[targetGrid[i][j]]++;
                        adj[col].push_back(targetGrid[i][j]);
                    }
                }
            }

        }

        for (int c = 1; c <= 60; c++) {
            if (in_degree[c] == 0)
                q.push(c);
        }


        int visited = 0;

        while (!q.empty()) {
            int c = q.front();
            q.pop();

            visited++;

            for (auto x : adj[c]) {
                in_degree[x]--;
                if (!in_degree[x])
                    q.push(x);
            }
        }

        return visited == 60;
    }
};