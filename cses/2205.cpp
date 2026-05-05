#include <bits/stdc++.h>

using namespace std;

void backtrack(int n, int idx, vector<vector<char>>& sols, vector<char>& sol) {
    if (n == idx) {
        sols.push_back(sol);
        return;
    }

    for (char i = '0' ; i <= '1' ; i++) {
        sol.push_back(i);
        backtrack(n, idx + 1, sols, sol);
        sol.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> sols;
    vector<char> sol;
    backtrack(n, 0, sols, sol);

    for (int i = 0 ; i < sols.size() ; i++) {
        for (int j = 0 ; j < n ; j++)
            cout << sols[i][j];
        cout << endl;
    }
    return 0;
}