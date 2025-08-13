#include <bits/stdc++.h>
using namespace std;

long long atMostK(const vector<int>& nums, int K) {
    if (K < 0) return 0;
    unordered_map<int,int> freq;
    long long res = 0;
    int left = 0;
    for (int right = 0; right < (int)nums.size(); ++right) {
        if (freq[nums[right]]++ == 0) --K;         // new distinct
        while (K < 0) {                             // too many distinct → shrink
            if (--freq[nums[left]] == 0) ++K;
            ++left;
        }
        res += (right - left + 1);                  // subarrays ending at right
    }
    return res;
}

long long subarraysWithKDistinct(const vector<int>& nums, int K) {
    return atMostK(nums, K) - atMostK(nums, K - 1);
}

int main() {
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
    cout << subarraysWithKDistinct(nums, k) << "\n"; // Output: 7
    return 0;
}