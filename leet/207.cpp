#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses, 0);

        vector<vector<int>> adj(numCourses);

        for (auto req : prerequisites) {

            int a = req[0];
            int b = req[1];
            
            adj[b].push_back(a);
            in_degree[a]++;
        }

        queue<int> q;

        for (int i = 0 ; i < numCourses ; i++)
            if (!in_degree[i])
                q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neigh : adj[node]) {

                in_degree[neigh]--;

                if (!in_degree[neigh])
                    q.push(neigh);
            }
        }

        for (int x : in_degree)
            if (x)
                return false;
                
        return true;
    }
};