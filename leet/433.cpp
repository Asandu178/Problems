#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        if (!st.count(endGene) && startGene != endGene)
            return -1;

        queue<string> q;
        q.push(startGene);

        int steps = 0;
        const string genes = "ACGT";

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string currentGene = q.front();
                q.pop();

                if (currentGene == endGene)
                    return steps;

                for (int i = 0; i < 8; i++) {
                    char old = currentGene[i];
                    for (char c : genes) {
                        if (c == old) continue;
                        currentGene[i] = c;

                        if (st.count(currentGene)) {
                            q.push(currentGene);
                            st.erase(currentGene); // mark visited
                        }
                    }
                    currentGene[i] = old;
                }
            }
            steps++;
        }

        return -1;
    }
};


int main() {
    Solution sol;
    vector<string> bank = {"AACCGATT","AACCGATA","AAACGATA","AAACGGTA"};
    cout << sol.minMutation("AACCGGTT", "AAACGGTA", bank);
}