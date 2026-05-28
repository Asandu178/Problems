#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> first;
    vector<int> last;

    Solution() : first(26, -1), last(26, -1) {};

    int numberOfSpecialChars(string word) {
        for (int i = 0 ; i < word.size() ; i++) {
            char c = word[i];
            if (isupper(c) && first[c - 'A'] == -1)
                first[c - 'A'] = i;
            else if (islower(c))
                last[c - 'a'] = i;
        }

        int cnt = 0;
        for (int i = 0 ; i < 26 ; i++) {
            if (first[i] == -1 || last[i] == -1)
                continue;
            if (first[i] > last[i])
                cnt++;
        }

        return cnt;
    }
};

int main() {
    string w;
    cin >> w;
    Solution sol;
    cout << sol.numberOfSpecialChars(w);
    return 0;
}