#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k) {
    unordered_map<char, int> freq; // to count character frequencies
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.size(); right++) {
        freq[s[right]]++;

        // shrink window if distinct count > k
        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }

        // update max length
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s = "aabacbebebe";
    int k = 3;
    cout << "Longest substring length with at most " << k 
         << " distinct characters: " << longestKSubstr(s, k) << endl;
    return 0;
}