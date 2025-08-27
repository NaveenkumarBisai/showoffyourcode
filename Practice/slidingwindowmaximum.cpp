#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;  // stores indices
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Remove indices out of the current window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove smaller elements from the back
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        // Add current element's index
        dq.push_back(i);

        // First window is ready when i >= k - 1
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k);

    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}