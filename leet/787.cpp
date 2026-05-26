#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int size = flights.size();
        vector<int> d(n, INT_MAX);

        d[src] = 0;

        for (int i = 0 ; i <= k ; i++) {

            vector<int> tmp = d;

            for (auto edge : flights) {
                int node = edge[0];
                int neigh = edge[1];
                int w = edge[2];
                if (d[node] != INT_MAX && d[node] + w < tmp[neigh]) {
                    tmp[neigh] = d[node] + w;
                }
            }

            d = tmp;
        }

        return (d[dst] == INT_MAX ? -1 : d[dst]);
    }
};