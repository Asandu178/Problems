#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());

        if (!words.count(endWord))
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [current, distance] = q.front();
            q.pop();

            if (current == endWord)
                return distance;

            for (int i = 0; i < current.size(); i++) {

                char original = current[i];

                for (char c = 'a'; c <= 'z'; c++) {

                    if (c == original)
                        continue;

                    current[i] = c;

                    if (words.count(current)) {
                        words.erase(current);
                        q.push({current, distance + 1});
                    }
                }

                current[i] = original;
            }
        }

        return 0;
    }
};
