#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    // Step 1: Place each number in its correct index if possible
    for (int i = 0; i < n; ++i) {
        // Keep swapping until nums[i] is in the right place or out of range
        while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    // Step 2: Find the first index where nums[i] != i + 1
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    // If all numbers are in the correct position
    return n + 1;
}

int main() {
    vector<int> nums;

    cout << "Enter number of elements: ";
    int n;
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    int result = firstMissingPositive(nums);
    cout << "First missing positive integer: " << result << endl;

    return 0;
}