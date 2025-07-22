#include <vector>
#include <iostream>

int FindMajor(const std::vector<int>& nums) {
    int candidate = nums[0];
    
    if (nums.size() == 1) {
        return candidate;
    }
    int count = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }
    }

    return candidate;
}

int main()
{
    std::vector<int> nums;
    std::cout << "Enter the number of elements in the array: ";
    int n;
    std::cin >> n;
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        nums.push_back(num);
    }

    int ans;
    ans = FindMajor(nums);
    std::cout << "The majority element is: " << ans << std::endl;

    return 0;
}