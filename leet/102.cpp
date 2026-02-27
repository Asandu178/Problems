#include <bits/stdc++.h>

using namespace std;


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = height(root);
        vector<vector<int>> levels(n);
        helper(root, levels, 0);
        return levels;
    }

    void helper(TreeNode* root, vector<vector<int>> &levels, int level) {
        if (root == nullptr)
            return;
        levels[level].push_back(root->val);

        helper(root->left, levels, level + 1);
        helper(root->right, levels, level + 1);
    }

    int height(TreeNode* root) {
        if (!root)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        return 1 + max(left, right);
    }
};