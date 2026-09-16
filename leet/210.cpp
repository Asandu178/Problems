#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
                vector<int> in_degree(numCourses, 0);

        vector<vector<int>> adj(numCourses);

        for (auto req : prerequisites) {

            int a = req[0];
            int b = req[1];
            
            adj[b].push_back(a);
            in_degree[a]++;
        }

        queue<int> q;
        vector<int> ans;

        for (int i = 0 ; i < numCourses ; i++)
            if (!in_degree[i])
                q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int neigh : adj[node]) {

                in_degree[neigh]--;

                if (!in_degree[neigh])
                    q.push(neigh);
            }
        }

        if (ans.size() == numCourses)
            return ans;
        return vector<int>();
    }
};