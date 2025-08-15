#include <bits/stdc++.h>
using namespace std;

int longestSubarraySumAtMostK(vector<int>& nums, int K) {
    int n = nums.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    multiset<pair<long long,int>> bst; // {prefixSum, index}
    int ans = 0;

    for (int j = 0; j <= n; j++) {
        // find earliest i such that prefix[j] - prefix[i] <= K
        auto it = bst.lower_bound({prefix[j] - K, INT_MIN});
        if (it != bst.end()) {
            ans = max(ans, j - it->second);
        }
        bst.insert({prefix[j], j});
    }
    return ans;
}

int main() {
    vector<int> nums = {2, -1, 2, 3, -2, 4};
    int K = 5;
    cout << longestSubarraySumAtMostK(nums, K) << endl;
}