#include <bits/stdc++.h>

using namespace std;

#define NMAX 1000


int cap[NMAX][NMAX], flow[NMAX][NMAX];
vector<int> adj[NMAX];
vector<bool> reachableS, reachableT;

bool bfs(int src, int trg, vector<int> &parent) {
    queue<int> q;
    parent[src] = src;

    q.push(src);

    while (!q.empty()) {
        int node = q.front();

        q.pop();

        for (int neigh : adj[node]) {
            if (parent[neigh] == -1 && cap[node][neigh] - flow[node][neigh] > 0) {
                parent[neigh] = node;

                if (neigh == trg)
                    return true;

                q.push(neigh);
            }
        }
    }

    return false;
}

void maximum_flow(int src, int trg, int n) {

    vector<int> parent(n, -1);

    while (bfs(src, trg, parent)) {

        int rc = INT_MAX;

        for (int u = trg ; u != parent[u] ; u = parent[u]) {
            rc = min(rc, cap[parent[u]][u] - flow[parent[u]][u]);
        }

        for (int u = trg ; u != parent[u] ; u = parent[u]) {
            flow[parent[u]][u] += rc;
            flow[u][parent[u]] -= rc;
        }

        fill(parent.begin(), parent.end(), -1);
    }
}

void bfsFromSrc(int src, vector<bool>& vis) {
    queue<int> q;

    vis[src] = true;

    q.push(src);

    while (!q.empty()) {
        int node = q.front();

        q.pop();

        for (int neigh : adj[node]) {
            if (!vis[neigh] && cap[node][neigh] - flow[node][neigh] > 0) {
                vis[neigh] = true;
                q.push(neigh);
            }
        }
    }

}

void bfsFromSink(int trg, vector<bool>& vis) {
    queue<int> q;

    vis[trg] = true;

    q.push(trg);

    while (!q.empty()) {
        int node = q.front();

        q.pop();

        for (int neigh : adj[node]) {
            if (!vis[neigh] && cap[neigh][node] - flow[neigh][node] > 0) {
                vis[neigh] = true;
                q.push(neigh);
            }
        }
    }

}

int main() {

    ifstream fin("critice.in");
    ofstream fout("critice.out");


    int n, m, a, b, c;
    fin >> n >> m;

    reachableS = vector<bool>(n, false);
    reachableT = vector<bool>(n, false);

    vector<pair<int, int>> edges;

    for (int i = 0 ; i < m ; i++) {
        fin >> a >> b >> c;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
        edges.push_back({a - 1, b - 1});
        cap[a - 1][b - 1] = c;
        cap[b - 1][a - 1] = c;
        flow[a - 1][b - 1] = 0;
        flow[b - 1][a - 1] = 0;
    }

    maximum_flow(0, n - 1, n);

    bfsFromSrc(0, reachableS);

    bfsFromSink(n - 1, reachableT);

    vector<int> ans;

    for (int i = 0 ; i < m ; i++) {
        auto [u, v] = edges[i];
        if ((reachableS[u] && reachableT[v] && cap[u][v] == flow[u][v]) || (reachableS[v] && reachableT[u] && cap[v][u] == flow[v][u]))
            ans.push_back(i + 1);
    }

    fout << ans.size() << endl;
    
    for (auto i : ans) fout << i << endl;

    return 0;
}