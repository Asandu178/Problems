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

    int ans = 0;

    int averageOfSubtree(TreeNode* root) {

        helper(root);

        return ans;
    }

    pair<int, int> helper(TreeNode *root) {

        if (root == nullptr)
            return {0, 0};

        auto [ls, lc] = helper(root->left);
        auto [rs, rc] = helper(root->right);

        int cnt = 1 + lc + rc;
        int sum = root->val + ls + rs;

        if (sum / cnt == root->val)
            ans++;

        return {sum, cnt};
    }
};