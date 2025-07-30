#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) return 0;

    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; // Sort by end point
    });

    int arrows = 1;
    int end = points[0][1];

    for (const auto& balloon : points) {
        if (balloon[0] > end) {
            arrows++;
            end = balloon[1];
        }
    }

    return arrows;
}

int main() {
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    cout << findMinArrowShots(points) << endl; // Output: 2
    return 0;
}