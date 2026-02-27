#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0 ; i < m ; i++) {
            dfs(board, 0, i, n, m);
            dfs(board, n - 1, i, n, m);
        }

        for (int i = 0 ; i < n ; i++) {
            dfs(board, i, 0, n, m);
            dfs(board, i, m - 1, n, m);
        }

        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < m ; j++)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
    }

    void dfs(vector<vector<char>>& board, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O')
            return;

        board[i][j] = '#';

        dfs(board, i - 1, j, n, m);
        dfs(board, i + 1, j, n, m);
        dfs(board, i, j - 1, n, m);
        dfs(board, i, j + 1, n, m);
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {{'O','X','X','O','X'},{'X','O','O','X','O'},{'X','O','X','O','X'},{'O','X','O','O','O'},{'X','X','O','X','O'}};
    // int n = board.size();
    // int m = board[0].size();
    // vector<vector<bool>> visited(n, vector(m, false));
    // cout << sol.notEnclosed(board, visited, 0, 0, n, m);
    sol.solve(board);
}