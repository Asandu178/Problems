#include <bits/stdc++.h>

using namespace std;

class solution {
public:

int n;

    void solve() {
        ifstream in("input.txt");
        in >> n;
        vector<vector<int>> projects(n + 1, vector(3, 0));

        for (int i = 1 ; i <= n ; i++)
            in >> projects[i][0] >> projects[i][1] >> projects[i][2];
        
        vector<int> dp(n + 1, 0);

        sort(projects.begin() + 1, projects.end(), [](const vector<int>&a, const vector<int>&b) {
            return a[1] < b[1];
        });
    }
};

int main() {
    solution sol;
    sol.solve();

}