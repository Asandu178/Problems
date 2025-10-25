#include <vector>
#include <stdlib.h>
#include <queue>
#include <limits.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
        vector<pair<int, int>> dir = { {0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> times(n, vector<int>(m, INT_MAX));
        times[0][0] = 0;

        pq.push({0, 0, 0, 1});

        while(!pq.empty()) {

            auto [time, i, j, timeForMove] = pq.top();

            pq.pop();

            if (time > times[i][j])
                continue;

            if (i == n - 1 && j == m - 1) {
                return times[i][j];
            }

            for (auto d : dir) {

                auto [d1, d2] = d;

                int ni = i + d1;
                int nj = j + d2;

                if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                    continue;

                int newtime = max(time, moveTime[ni][nj]) + timeForMove;
                int newTimeForMove = (timeForMove == 1 ? 2 : 1);


                if (times[ni][nj] > newtime) {
                    times[ni][nj] = newtime;
                    pq.push({newtime, ni, nj, newTimeForMove});
                }
                
            }
        }
        return -1;
    }
};