#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<bool>> visited;
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        string build;
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < m ; j++)
                if (back(i, j, board, 0, word))
                    return true;
        return false;

    }

    bool back(int i, int j, vector<vector<char>>& board, int index, string &word) {
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || word[index] != board[i][j])
            return false;
        
        if (index + 1 == word.size()) {
            return true;
        }

        visited[i][j] = true;

        bool found = back(i - 1, j, board, index + 1, word) ||
        back(i + 1, j, board, index + 1, word) ||
        back(i, j - 1, board, index + 1, word) ||
        back(i, j + 1, board, index + 1, word);

        visited[i][j] = false;

        return found;
    }
};