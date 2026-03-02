#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> paths;
        vector<int> path;
        dfs(paths, path, graph, 0);
        return paths;
    }

    void dfs(vector<vector<int>>& paths, vector<int> &path, vector<vector<int>>& graph, int start) {


        path.push_back(start);


        if (start == graph.size() - 1) {
            paths.push_back(path);
            path.pop_back();
            return;
        }

        for (int node : graph[start])
            dfs(paths, path, graph, node);

        path.pop_back();

    }
};