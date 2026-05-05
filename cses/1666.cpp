#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<vector<int>>& neigh, int colour, vector<int>& colours) {
    
    colours[node] = colour;

    for (int next : neigh[node]) {
        if (colours[next] == -1)
            dfs(next, neigh, colour, colours);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> neigh(n + 1);
    vector<int> colours(n + 1, -1);
    int cnt = 0;

    for (int i = 0 ; i < m ; i++) {
        int x, y;
        cin >> x >> y;
        neigh[x].push_back(y);
        neigh[y].push_back(x);
    }

    for (int i = 1 ; i <= n ; i++) {
        if (colours[i] == -1) {

            cnt++;
            dfs(i, neigh, cnt, colours);
        }
    }

    vector<bool> finished(cnt + 1, false);

    cout << cnt - 1 << endl;
    for (int i = 1 ; i <= n ; i++) {
        if (colours[1] != colours[i] && !finished[colours[i]]) {
            cout << 1 << " " << i << endl;
            finished[colours[i]] = true;
        }
    }
    return 0;
}