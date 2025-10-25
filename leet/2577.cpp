#include <vector>
#include <stdlib.h>
#include <queue>
#include <limits.h>
using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> times(row, vector<int>(col, INT_MAX));

        if(grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        pq.push({0, 0, 0});
        
        while (!pq.empty()) {

           auto [t, x, y] = pq.top();
           pq.pop();

           if (t > times[x][y]) continue;

           if (x == row - 1 && y == col - 1)
                return times[x][y];

           for (auto dirs : directions) {
                auto [i, j] = dirs;

                int nx = x + i;
                int ny = y + j;

                if (nx < 0 || nx >= row || ny < 0 || ny >= col)
                    continue;
                
                int newtime;
                if (t + 1 >= grid[nx][ny]) {
                    newtime = t + 1;
                } else {
                    newtime = (grid[nx][ny] - t) % 2 == 0 ? grid[nx][ny] + 1 : grid[nx][ny];
                }

                if (times[nx][ny] > newtime) {
                    times[nx][ny] = newtime;
                    pq.push({newtime, nx, ny});
                }
                
           }
        }
        return -1;
    }
};