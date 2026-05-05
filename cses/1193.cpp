#include <bits/stdc++.h>
 
using namespace std;
 
int main() {

    // TODO add a parent and move matrix because concatenation makes this too slow
 
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    vector<char> sol;
    queue<tuple<int, int, string>> q;
 
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'A')
                q.push({i, j, ""});
        }
    }
 
    while (!q.empty()) {
        auto [x, y, moves] = q.front();
        q.pop();
 
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        char move[] = {'U', 'D', 'L', 'R'};
 
        if (matrix[x][y] == 'B') {
            cout << "YES\n" << moves.length() << endl << moves;
            return 0;
        }
 
        matrix[x][y] = '#';
 
        for (int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || matrix[nx][ny] == '#')
                continue;
 
            q.push({nx, ny, moves + move[i]});
        }
    }
 
    cout << "NO\n";
    return 0;
}