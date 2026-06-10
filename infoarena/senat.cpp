#include <bits/stdc++.h>

using namespace std;

#define NMAX 203

int cap[NMAX][NMAX], flow[NMAX][NMAX];

vector<vector<int>> adj;

FILE *fin = fopen("senat.in", "r");
FILE *fout = fopen("senat.out", "w");

bool bfs(int src, int trg, vector<int>& parent) {
    queue<int> q;
    parent[src] = src;

    q.push(src);

    while(!q.empty()) {
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

void solve(int src, int trg, int n, int m) {

    vector<int> parent(trg + 1, -1);

    vector<int> sol(m + 1);

    int cost = 0;
    int cnt = n + 1;
    
    while (bfs(src, trg, parent)) {

        for (int i = trg ; i != parent[i] ; i = parent[i]) {
            flow[parent[i]][i]++;
            flow[i][parent[i]]--;
        }

        cost++;

        fill(parent.begin(), parent.end(), -1);
    }

    if (cost < m) {
        fprintf(fout, "0\n");
        return;
    }

    for (int senator = 1 ; senator <= n ; senator++) {
        for (int c = n + 1 ; c <= n + m ; c++) {
            if (flow[senator][c] == 1) {
                sol[c - n] = senator;
            }
        }
    }

    for (int i = 1 ; i <= m ; i++)
        fprintf(fout, "%d\n", sol[i]);
}

int main() {
    int n, m;

    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));

    fscanf(fin, "%d %d\n", &n, &m);


    adj = vector<vector<int>>(n + m + 2);

    int src = 0;
    int trg = n + m + 1;

    char s[10000];

    for (int i = 1 ; i <= m ; i++) {
        fgets(s, 10000, fin);

        char *p = strtok(s, " \n\r");

        while (p) {
            int senator = atoi(p);

            adj[senator].push_back(i + n);
            adj[i + n].push_back(senator);
            cap[senator][i + n] = 1;
            flow[senator][i + n] = 0;
            cap[i + n][senator] = 0;
            flow[i + n][senator] = 0;

            p = strtok(NULL, " \n\r");
        }
    }

    for (int i = 1 ; i <= n ; i++) {
        adj[src].push_back(i);
        adj[i].push_back(src);
        cap[src][i] = 1;
        flow[src][i] = 0;
        cap[i][src] = 0;
        flow[i][src] = 0;
    }

    for (int i = n + 1 ; i <= n + m ; i++) {
        adj[i].push_back(trg);
        adj[trg].push_back(i);
        cap[i][trg] = 1;
        flow[i][trg] = 0;
        cap[trg][i] = 0;
        flow[trg][i] = 0;
    }

    solve(src, trg, n, m);

    return 0;
}