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
    unordered_map<int, TreeNode *> tree;

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        int root = 0;

        for (auto v : descriptions) {
            int parent = v[0];
            int child = v[1];
            int isLeft = v[2];

            if (tree.find(parent) == tree.end()) {
                tree.insert({parent, new TreeNode(parent)});
                root ^= parent;
            }

            if (tree.find(child) == tree.end()) {
                tree.insert({child, new TreeNode(child)});
                root ^= child;
            }

            if (isLeft) {
                tree[parent]->left = tree[child];
            } else {
                tree[parent]->right = tree[child];
            }

            root ^= child;
        }
        return tree[root];
    }
};