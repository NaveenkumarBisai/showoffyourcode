#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int farthest = 0;  // farthest index we can reach
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (i > farthest) return false;   // stuck before reaching here
        farthest = max(farthest, i + nums[i]);
        if (farthest >= n - 1) return true; // can reach last index
    }
    return true;
}

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};

    cout << (canJump(nums1) ? "true" : "false") << endl;  // Output: true
    cout << (canJump(nums2) ? "true" : "false") << endl;  // Output: false

    return 0;
}