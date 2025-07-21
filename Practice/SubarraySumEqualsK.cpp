#include <iostream>
#include <vector>
#include <unordered_map>

int subarraySumEqualsK(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1; // To handle the case where a subarray starts from index 0
    int currentSum = 0;
    int count = 0;

    for (int num : nums) {
        currentSum += num;

        // Check if there is a prefix sum that equals currentSum - k
        if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[currentSum - k];
        }

        // Record the current prefix sum
        prefixSumCount[currentSum]++;
    }

    return count;
}


int main() {
    std::vector<int> nums;
    int k;
    std::cout << "Enter the number of elements in the array: ";
    int n;
    std::cin >> n;
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        nums.push_back(num);
    }

    std::cout << "Enter the target sum k: ";
    std::cin >> k;

    int result = subarraySumEqualsK(nums, k);
    std::cout << "Number of subarrays that sum to " << k << ": " << result << std::endl;
    return 0;
}