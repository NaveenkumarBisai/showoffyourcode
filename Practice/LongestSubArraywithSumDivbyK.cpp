#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarrayDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> modIndex;
    modIndex[0] = -1;  // Important base case
    int maxLen = 0;
    int sum = 0;

    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        int mod = ((sum % k) + k) % k;  // Handle negative mods safely

        if (modIndex.find(mod) != modIndex.end()) {
            maxLen = max(maxLen, i - modIndex[mod]);
        } else {
            modIndex[mod] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> nums = {2, 7, 6, 1, 4, 5};
    int k = 3;
    cout << "Longest subarray length divisible by " << k << " is: "
         << longestSubarrayDivByK(nums, k) << endl;
    return 0;
}