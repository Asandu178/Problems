#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

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
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return 0;

        return helper(root, targetSum) + helper(root->left, targetSum) + helper(root->right, targetSum);
    }

    int helper(TreeNode* root, int targetSum) {

        int cnt = 0;

        if (root == nullptr)
            return 0;
        
        if (root->val == targetSum)
            cnt++;

        cnt += helper(root->left, targetSum - root->val);
        cnt += helper(root->right, targetSum - root->val);

        return cnt;
    }
};