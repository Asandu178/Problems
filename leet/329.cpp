#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<vector<pair<int, int>>>> neigh(n, vector<vector<pair<int, int>>>(m));
        vector<vector<int>> in_degree(n, vector<int>(m, 0));

        int cnt = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                for (int k = 0 ; k < 4 ; k++) {

                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                        continue;

                    if (matrix[ni][nj] > matrix[i][j]) {
                        neigh[i][j].push_back({ni, nj});
                        in_degree[ni][nj]++;
                    }
                }
            }
        }

        queue<pair<int, int>> q;

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (in_degree[i][j] == 0)
                    q.push({i, j});
            }
        }

        while (!q.empty()) {
            int k = q.size();
            cnt++;

            for (int i = 0 ; i < k ; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [nx, ny] : neigh[x][y]) {
                    in_degree[nx][ny]--;
                    if (in_degree[nx][ny] == 0)
                        q.push({nx, ny});
                }
            }
        }

        return cnt;


    }
};