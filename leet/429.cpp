#include <bits/stdc++.h>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> levels;
        if (root == nullptr)
            return levels;
        q.push(root);

        while (!q.empty()) {
            int len = q.size();
            vector<int> level;

            for (int i = 0 ; i < len ; i++) {
                Node *node = q.front();
                level.push_back(node->val);
                q.pop();
                for (Node *c : node->children)
                    if (c != nullptr)
                        q.push(c);
            }
            levels.push_back(level);
            
        }
        return levels;
    }
};