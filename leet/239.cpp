#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        queue<int> q;

        multiset<int, greater<int>> heap;

        vector<int> sol;

        for (int x : nums) {

            if (q.size() < k) {
                q.push(x);
                heap.insert(x);
                continue;
            }

            sol.push_back(*heap.begin());

            int old = q.front();
            q.pop();
            heap.erase(heap.find(old));

            q.push(x);
            heap.insert(x);
        }

        sol.push_back(*heap.begin());
        
        return sol;
    }
};