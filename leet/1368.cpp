#include <vector>
#include <stdlib.h>
#include <queue>
#include <limits.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<pair<int, int>> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> d(n, vector<int>(m, INT_MAX));
        pq.push({0, 0});
        d[0][0] = 0;

        while(!pq.empty()) {
            auto [x, y] = pq.top();

            pq.pop();

            if (x == n - 1 && y == m - 1)
                return d[x][y];

            for (int c = 0 ; c < 4 ; c++) {

                auto [i, j] = directions[c];
                int nx = i + x;
                int ny = j + y;

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                int cost = (c + 1 == grid[x][y] ? 0 : 1);
                if (d[nx][ny] > d[x][y] + cost) {
                    d[nx][ny] = d[x][y] + cost;
                    pq.push({nx, ny});
                }
            }
        }
        return -1;
    }
};