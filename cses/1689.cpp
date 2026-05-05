#include <bits/stdc++.h>

using namespace std;

bool backtrack(int i, int j, int cnt, vector<vector<int>>& matrix) {

    if (i < 0 || i >= 8 || j < 0 || j >= 8 || matrix[i][j] != 0) {
        return false;
    }

    matrix[i][j] = cnt;

    if (cnt == 64)
        return true;


    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int z = 0 ; z < 8 ; z++) {
        if (backtrack(i + dx[z], j + dy[z], cnt + 1, matrix))
            return true;
    }

    matrix[i][j] = 0;

    return false;
}

int main() {

    int x, y;
    cin >> y >> x;
    vector<vector<int>> matrix(8, vector<int>(8, 0));

    backtrack(x - 1, y - 1, 1, matrix);

    for (int i = 0 ; i < 8 ; i++) {
        for (int j = 0 ; j < 8 ; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }


}