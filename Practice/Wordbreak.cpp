#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Step 1: Build map of length -> words
        unordered_map<int, unordered_set<string>> lengthMap;
        for (auto &word : wordDict) {
            lengthMap[word.size()].insert(word);
        }

        // Memoization map: dp[i] = -1 (not calculated), 0 (false), 1 (true)
        vector<int> dp(s.size(), -1);

        return canBreak(0, s, lengthMap, dp);
    }

private:
    bool canBreak(int start, string &s,
                  unordered_map<int, unordered_set<string>> &lengthMap,
                  vector<int> &dp) {
        // Base case: reached end of string
        if (start == s.size()) return true;

        // Already computed
        if (dp[start] != -1) return dp[start];

        // Try each word length
        for (auto &entry : lengthMap) {
            int len = entry.first;
            if (start + len > s.size()) continue; // out of bounds

            string sub = s.substr(start, len);
            if (entry.second.count(sub)) {
                if (canBreak(start + len, s, lengthMap, dp)) {
                    return dp[start] = 1;
                }
            }
        }

        return dp[start] = 0;
    }
};

int main() {
    Solution sol;
    string s = "applepenapple";
    vector<string> dict = {"apple", "pen"};
    cout << (sol.wordBreak(s, dict) ? "True" : "False") << endl; // Output: True
}