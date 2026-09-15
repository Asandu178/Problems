#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1 << n;
        vector<int> ans(size);

        for (int i = 0 ; i < size ; i++)
            ans[i] = (i ^ (i >> 1));

        return ans;
    }
};