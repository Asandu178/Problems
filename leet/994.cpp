#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        int minute = 0;

        queue<pair<int, int>> q;

        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < m ; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                    fresh++;
            }

        while (!q.empty() && fresh) {
            int cnt = q.size();
            minute++;

            for (int k = 0 ; k < cnt ; k++) {
                auto [x, y] = q.front();
                q.pop();

                if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2;
                    fresh--;
                    q.push({x - 1, y});
                }

                if (x + 1 < n && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2;
                    fresh--;
                    q.push({x + 1, y});
                }

                if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 2;
                    fresh--;
                    q.push({x, y - 1});
                }

                if (y + 1 < m && grid[x][y + 1] == 1) {
                    grid[x][y + 1] = 2;
                    fresh--;
                    q.push({x, y + 1});
                }


            }
        }
        return fresh == 0 ? minute : -1;
    }
};