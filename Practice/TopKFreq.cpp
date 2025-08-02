#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    
    unordered_map<int, int> freq;
    for (int num : nums)
        freq[num]++;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (auto& p : freq) {
        minHeap.push({p.second, p.first});
        if (minHeap.size() > k)
            minHeap.pop();
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}