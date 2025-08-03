#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Boundary check + visited check
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()
            || grid[i][j] == '0') return;

        // Mark current cell as visited
        grid[i][j] = '0';

        // Explore all 4 directions
        dfs(grid, i + 1, j); // Down
        dfs(grid, i - 1, j); // Up
        dfs(grid, i, j + 1); // Right
        dfs(grid, i, j - 1); // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);  // Start DFS to mark the entire island
                }
            }
        }

        return count;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution s;
    cout << "Number of islands: " << s.numIslands(grid) << endl; // Output: 3
}