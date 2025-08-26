#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};

    // Step 1: Sort by start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        // Compare last interval in merged with current one
        if (merged.back()[1] >= intervals[i][0]) {
            // Overlap -> merge
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            // No overlap -> add as new interval
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

int main() {
    vector<vector<int>> intervals1 = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result1 = merge(intervals1);

    cout << "Merged intervals: ";
    for (auto &in : result1) {
        cout << "[" << in[0] << "," << in[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> intervals2 = {{1,4},{4,5}};
    vector<vector<int>> result2 = merge(intervals2);

    cout << "Merged intervals: ";
    for (auto &in : result2) {
        cout << "[" << in[0] << "," << in[1] << "] ";
    }
    cout << endl;

    return 0;
}