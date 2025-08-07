#include <iostream>
#include <unordered_map>
using namespace std;

int dfs(string& s, int i, unordered_map<int, int>& memo) {
    if (i == s.length()) return 1;
    if (s[i] == '0') return 0;
    if (memo.count(i)) return memo[i];

    // One-digit decode
    int res = dfs(s, i + 1, memo);

    // Two-digit decode
    if (i + 1 < s.length()) {
        int num = stoi(s.substr(i, 2));
        if (num >= 10 && num <= 26)
            res += dfs(s, i + 2, memo);
    }

    return memo[i] = res;
}

int numDecodings(string s) {
    unordered_map<int, int> memo;
    return dfs(s, 0, memo);
}

int main() {
    string s = "226";
    cout << "Number of decodings: " << numDecodings(s) << endl; // Output: 3
    return 0;
}