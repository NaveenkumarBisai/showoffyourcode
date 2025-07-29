#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1; // base case: sum 0 occurs once

    int currSum = 0, count = 0;

    for (int num : nums) {
        currSum += num;

        // If (currSum - k) exists, we found a subarray
        if (prefixSumCount.find(currSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[currSum - k];
        }

        // Update prefix sum count
        prefixSumCount[currSum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << subarraySum(nums, k) << endl;  // Output: 2
    return 0;
}