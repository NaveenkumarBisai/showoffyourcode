#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    if (t.empty() || s.empty()) return "";

    unordered_map<char, int> freqT;
    for (char c : t) {
        freqT[c]++;
    }

    unordered_map<char, int> window;
    int have = 0, need = freqT.size();
    int left = 0;
    int minLen = INT_MAX;
    int minStart = 0;

    for (int right = 0; right < s.length(); right++) {
        char c = s[right];
        window[c]++;

        // only count when the frequency of a char in window matches the one in t
        if (freqT.count(c) && window[c] == freqT[c]) {
            have++;
        }

        // Contract window from the left while it's valid
        while (have == need) {
            // Update minimum window
            if ((right - left + 1) < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }

            // Pop from left of window
            char leftChar = s[left];
            window[leftChar]--;
            if (freqT.count(leftChar) && window[leftChar] < freqT[leftChar]) {
                have--;
            }
            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

int main() {
    string s = "ab";
    string t = "A";
    string result = minWindow(s, t);
    cout << "Minimum Window Substring: " << result << endl;
    return 0;
}