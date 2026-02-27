#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int cnt = 0;

        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < m ; j++)
                if(!grid1[i][j])
                    dfs(grid2, i, j, n, m);
        
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < m ; j++)
                if(grid2[i][j]) {
                    cnt++;
                    dfs(grid2, i, j, n, m);
                }
        return cnt;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || !grid[i][j])
            return;

        grid[i][j] = 0;

        dfs(grid, i - 1, j, n, m);
        dfs(grid, i + 1, j, n, m);
        dfs(grid, i, j - 1, n, m);
        dfs(grid, i, j + 1, n, m);
    }
};