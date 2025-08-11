#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool isPossible(vector<int>& nums) {
    if (nums.size() < 6) return false; // as per your rule
    
    map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    while (!freq.empty()) {
        auto it = freq.begin();
        int start = it->first;
        int count = it->second;
        
        // try to form a subsequence starting at `start`
        int length = 0;
        int cur = start;
        
        while (freq[cur] > 0) {
            freq[cur]--;
            if (freq[cur] == 0) {
                freq.erase(cur);
            }
            cur++;
            length++;
        }
        
        if (length < 3) {
            return false;
        }
        
        // Since elements may have freq > 1, 
        // repeat process until map is empty
    }
    
    return true;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 3, 4, 5};
    vector<int> nums2 = {1, 2, 3, 1, 2, 3, 5};
    
    cout << (isPossible(nums1) ? "YES" : "NO") << endl;
    cout << (isPossible(nums2) ? "YES" : "NO") << endl;
    
    return 0;
}