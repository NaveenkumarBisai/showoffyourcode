#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end()); // Step 1: Sort the array
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate nums[i]
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                // Skip duplicates for left
                while (left < right && nums[left] == nums[left - 1]) left++;
                // Skip duplicates for right
                while (left < right && nums[right] == nums[right + 1]) right--;

            } else if (sum < 0) {
                left++;  // Need bigger sum
            } else {
                right--; // Need smaller sum
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);

    for (auto &triplet : ans) {
        cout << "[ ";
        for (int x : triplet) cout << x << " ";
        cout << "]" << endl;
    }
    return 0;
}