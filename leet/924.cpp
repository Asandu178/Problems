#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        queue<int> q;
        vector<bool> visited(n);
        int inf_min = INT_MAX;
        int inf_cnt;
        int idx_min = INT_MAX;

        
        for (int exclude : initial) {

            fill(visited.begin(), visited.end(), false);
            inf_cnt = 0;

            for (int infected : initial)
                if (infected != exclude)
                    q.push(infected);

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                inf_cnt++;

                for (int i = 0 ; i < n ; i++) {
                    if (graph[node][i] && !visited[i]) {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }

            if (inf_min > inf_cnt) {
                inf_min = inf_cnt;
                idx_min = exclude;
            }
            if (inf_min == inf_cnt)
                idx_min = min(idx_min, exclude);
        }
        return idx_min;
    }
};