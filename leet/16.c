#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int sumNumbers(struct TreeNode* root) {
    int num = 0;
    int crr = 0;
    rootToLeaf(root, num, crr);
    return crr;
}

void rootToLeaf(struct TreeNode* root, int num, int *crr) {
    if (!root)
        return;

    num = num * 10 + root->val;

    if (!root->left && !root->right) {
        (*crr) += num;
        num /= 10;
    }

    rootToLeaf(root->left, num, crr);
    rootToLeaf(root->right, num, crr);
}