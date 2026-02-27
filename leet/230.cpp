#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int val = root->val;
        helper(root, k, val);
        return val;
    }

    void helper(TreeNode* root, int &k, int &val) {
        if (root == nullptr)
            return;

        helper(root->left, k, val);

        k--;

        if (k == 0)
            val = root->val;

        helper(root->right, k, val);
    }
};