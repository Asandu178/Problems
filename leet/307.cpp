#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> arr;
    int n;

    SegmentTree(vector<int>& nums) {
        n = nums.size();
        arr = vector<int>(4 * n);
        build(nums, 1, 0, n - 1);
    }

    void build(vector<int>& nums, int v, int l, int r) {
        if (l == r) {
            arr[v] = nums[l];
        } else {

            int m = (l + r) / 2;

            build(nums, 2 * v, l, m);
            build(nums, 2 * v + 1, m + 1, r);

            arr[v] = arr[2 * v] + arr[2 * v + 1];
        }
    }

    void update(int v, int l, int r, int idx, int val) {

        if (l == r) {
            arr[v] = val;
        } else {
            int m = (l + r) / 2;

            if (idx <= m)
                update(2 * v, l, m, idx, val);
            else
                update(2 * v + 1, m + 1, r, idx, val);

            arr[v] = arr[2 * v] + arr[2 * v + 1];
        }
    }

    int sum(int v, int il, int ir, int l, int r) {

        // total overlap

        if (il >= l && ir <= r)
            return arr[v];

        // no overlap

        if (ir < l || il > r)
            return 0;

        // partial overlap

        int im = (il + ir) / 2;

        int left = sum(2 * v, il, im, l, r);
        int right = sum(2 * v + 1, im + 1, ir, l, r);

        return left + right;
    }

};

class NumArray {
public:

    SegmentTree tree;

    NumArray(vector<int>& nums) : tree(nums) {

    }
    
    void update(int index, int val) {
        tree.update(1, 0, tree.n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return tree.sum(1, 0, tree.n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

