#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Solution {
public:

    bool canPlaceQueen(int n, int row, int col, vector<string> &board) {
        // first diagonal
        for (int i = row - 1, j = col - 1 ; i >= 0 && j >= 0 ; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        // second diagonal
        for (int i = row - 1, j = col + 1 ; i >= 0 && j < n ; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        // check column
        for (int i = 0 ; i < row ; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<string> board(n, string(n, '.'));
        backtrack(n, 0, output, board);
        return output;
    }

    void backtrack(int n, int row, vector<vector<string>> &output, vector<string>& board) {
        if (n == row) {
            output.push_back(board);
            return;
        }

        for (int col = 0 ; col < n ; col++) {
            if (canPlaceQueen(n, row, col, board)) {
                board[row][col] = 'Q';
                backtrack(n, row + 1, output, board);
                board[row][col] = '.';
            }
        }
    }
};