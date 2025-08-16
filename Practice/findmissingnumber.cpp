#include <iostream>
#include <vector>
using namespace std;

int missingNumberSum(vector<int>& nums) {
    int n = nums.size();
    int expected = n * (n + 1) / 2;
    int actual = 0;
    for (int x : nums) actual += x;
    return expected - actual;
}

int main() {
    vector<int> arr = {3, 0, 1};
    cout << missingNumberSum(arr) << endl; // Output: 2
}