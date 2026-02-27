#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> coords;
        int n = land.size();
        int m = land[0].size();
        int maxi, maxj;
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < m ; j++) {
                maxi = 0;
                maxj = 0;
                if (land[i][j]) {
                    dfs(land, i, j, maxi, maxj, n, m);
                    coords.push_back({i, j, maxi, maxj});
                }
            }
        return coords;
    }

    void dfs(vector<vector<int>>& land, int i, int j, int &maxi, int &maxj, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || land[i][j] == 0)
            return;

        land[i][j] = 0;
        maxi = max(i, maxi);
        maxj = max(j, maxj);
        
        dfs(land, i - 1, j, maxi, maxj, n, m);
        dfs(land, i + 1, j, maxi, maxj, n, m);
        dfs(land, i, j - 1, maxi, maxj, n, m);
        dfs(land, i, j + 1, maxi, maxj, n, m);
    }
};