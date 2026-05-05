#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        back(board);
    }

    bool back(vector<vector<char>>& board) {
        for (int i = 0 ; i < 9 ; i++) {
            for (int j = 0 ; j < 9 ; j++) {
                if (board[i][j] == '.') {
                    for (char z = '1' ; z <= '9' ; z++) {
                        if (isValid(board, i, j, z)) {
                            board[i][j] = z;

                        if (back(board))
                            return true;

                        board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num || board[i][col] == num) return false;
        }
        int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == num) return false;
            }
        }
        return true;
    }
};