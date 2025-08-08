#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < 32; ++i) {
        int sum = 0;
        for (int num : nums) {
            if (num >> i & 1) sum++;
        }
        if (sum % 3) result |= (1 << i);
    }
    return result;
}

int main() {
    vector<int> nums = {2, 2, 3, 2};
    cout << singleNumber(nums) << endl; // Output: 3
}