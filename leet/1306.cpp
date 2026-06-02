#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        queue<int> q;
        vector<bool> vis(arr.size());
        q.push(start);
        int d[2];

        while (!q.empty()) {
            int idx = q.front();
            q.pop();

            vis[idx] = true;

            if (arr[idx] == 0)
                return true;

            d[0] = idx - arr[idx];
            d[1] = idx + arr[idx];

            for (int x : d) {
                if (x < 0 || x >= arr.size() || vis[x])
                    continue;
                
                q.push(x);
            }
        }

        return false;
    }
};

int main() {
    int n, start;

    cin >> n >> start;

    vector<int> arr(n);

    for (int i = 0 ; i < n ; i++) cin >> arr[i];

    auto sol = Solution();

    cout << sol.canReach(arr, start);
    return 0;
}