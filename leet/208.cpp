#include <bits/stdc++.h>

using namespace std;

class Trie {
public:
    Trie *children[26];
    bool isLeaf = false;

    Trie() {
        for (int i = 0 ; i < 26 ; i++)
            children[i] = nullptr;
    }
    
    void insert(string word) {
        Trie *path = this;
        for (char c : word) {
            if (path->children[c - 'a'] == nullptr)
                path->children[c - 'a'] = new Trie();
            
            path = path->children[c - 'a']; 
        }

        path->isLeaf = true;
    }
    
    bool search(string word) {
        Trie *path = this;
        for (char c : word) {
            if (path->children[c - 'a'] == nullptr)
                return false;
            path = path->children[c - 'a'];
        }

        return path->isLeaf;
    }
    
    bool startsWith(string prefix) {
        Trie *path = this;
        for (char c : prefix) {
            if (path->children[c - 'a'] == nullptr)
                return false;
            path = path->children[c - 'a'];
        }

        return true;
    }
};