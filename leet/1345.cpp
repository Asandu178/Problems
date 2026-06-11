#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if (n == 1)
            return 0;

        if (n == 2)
            return 1;

        if (arr[0] == arr[n - 1])
            return 1;

        vector<bool> vis(n, false);
        unordered_map<int, vector<int>> jumps;

        for (int i = 0 ; i < n ; i++)
            jumps[arr[i]].push_back(i);

        queue<pair<int, int>> q;

        q.push({0, 0});

        vis[0] = true;

        while (!q.empty()) {
            auto [node, d] = q.front();

            if (node == n - 1)
                return d;

            q.pop();

            if (node - 1 >= 0 && !vis[node - 1]) {
                vis[node - 1] = true;
                q.push({node - 1, d + 1});
            }
            if (node + 1 < n && !vis[node + 1]) {
                vis[node + 1] = true;
                q.push({node + 1, d + 1});
            }

            for (auto it : jumps[arr[node]]) {
                if (it != node && !vis[it]) {
                    vis[it] = true;
                    q.push({it, d + 1});
                }
            }

            jumps.erase(arr[node]);
        }

        return 0;
    }
};

int main() {
    auto sol = Solution();

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0 ; i < n ; i++)
        cin >> arr[i];

    cout << sol.minJumps(arr);
    return 0;
}