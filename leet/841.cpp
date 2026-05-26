#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q;

        q.push(0);

        while (!q.empty()) {
            int room = q.front();
            q.pop();
            visited[room] = true;

            for (auto key : rooms[room]) {
                if (visited[key])
                    continue;
                q.push(key);
            }
        }

        for (auto x : visited)
            if (x == false)
                return x;
        return true;
    }
};