#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

long long MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int odd, even;

        odd = arr[0] % 2;
        even = 1 - odd;
        long long cnt = odd;

        for (int i = 1 ; i < arr.size() ; i++) {
            if (arr[i] % 2 == 0) {
                odd = odd;
                even = even + 1;
            } else {
                int tmp = even + 1;
                even = odd;
                odd = tmp;
            }

            cnt += odd % MOD;
        }

        return cnt % MOD;
    }
};