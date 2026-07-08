#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> paths(n);
        vector<bool> visited(n, false);

        int res = INT_MAX;


        for (int i = 0 ; i < roads.size() ; i++) {
            int a = roads[i][0] - 1;
            int b = roads[i][1] - 1;
            int d = roads[i][2];

            paths[a].push_back({b, d});
            paths[b].push_back({a, d});
        }

        solve(0, paths, visited, res);

        return res;
    }

    void solve(int src, vector<vector<pair<int, int>>> &paths, vector<bool>& visited, int &res) {

        visited[src] = true;

        for (auto [neigh, d] : paths[src]) {


            res = min(res, d);


            if (visited[neigh])
                continue;

            solve(neigh, paths, visited, res);
        }

    }
};

int main() {

    Solution sol;

    vector<vector<int>> roads = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};

    cout << sol.minScore(4, roads);
    return 0;
}