#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = 0;
    long long curr_sum = 0;
    int min_len = INT_MAX;

    for (j = 0; j < n; j++) {
        curr_sum += nums[j];

        while (curr_sum >= target) {
            min_len = min(min_len, j - i + 1);
            curr_sum -= nums[i];
            i++;
        }
    }

    return (min_len == INT_MAX) ? 0 : min_len;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << minSubArrayLen(target, nums) << endl; // Output: 2
    return 0;
}