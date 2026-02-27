#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        long long sum;
        int cnt = 0;

        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < m ; j++)
                if (grid[i][j]) {
                    sum = 0;
                    dfs(grid, i, j, n, m, sum);
                    if (sum % k == 0)
                        cnt++;
                }
        return cnt;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m, long long& sum) {
        if (i < 0 || i >= n || j < 0 || j >= m || !grid[i][j])
            return;

        sum += grid[i][j];
        grid[i][j] = 0;

        dfs(grid, i - 1, j, n, m, sum);
        dfs(grid, i + 1, j, n, m, sum);
        dfs(grid, i, j - 1, n, m, sum);
        dfs(grid, i, j + 1, n, m, sum);
    }
};