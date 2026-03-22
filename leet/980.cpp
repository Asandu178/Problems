#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int emptySquares = 0;
    int n, m;
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt;
        int start_i, start_j;

        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < m ; j++) {
                if (grid[i][j] != -1)
                    emptySquares++;
                if (grid[i][j] == 1) {
                    start_i = i;
                    start_j = j;
                }
            }
        
        int paths = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        dfs(start_i, start_j, 0, paths, grid, visited);

        return paths;
    }

    void dfs(int i, int j, int steps, int &paths, vector<vector<int>>& grid, vector<vector<bool>> &visited) {
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] == -1)
            return;

        if (grid[i][j] == 2) {
            if (steps == emptySquares - 1)
                paths++;
            return;
        }

        visited[i][j] = true;

        dfs(i - 1, j, steps + 1, paths, grid, visited);
        dfs(i + 1, j, steps + 1, paths, grid, visited);
        dfs(i, j - 1, steps + 1, paths, grid, visited);
        dfs(i, j + 1, steps + 1, paths, grid, visited);

        visited[i][j] = false;
    }
};