#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    const int dx[4] = {-1, 0, 0, 1}; // Directions for row movement
    const int dy[4] = {0, -1, 1, 0}; // Directions for column movement

    // Depth First Search (DFS) to explore connected components
    int dfs(int i, int j, int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        // Base case: Out of bounds or already visited or no fish
        if (i < 0 || j < 0 || i >= r || j >= c || vis[i][j] || grid[i][j] == 0)
            return 0;

        vis[i][j] = 1; // Mark the cell as visited
        int totalFish = grid[i][j]; // Start with the current cell's fish count

        // Explore all four directions
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];
            totalFish += dfs(x, y, r, c, vis, grid);
        }

        return totalFish;
    }

    // Function to find the maximum fish in any connected component
    int findMaxFish(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> vis(r, vector<int>(c, 0)); // Visited matrix to track exploration

        int maxFish = 0; // Variable to store the maximum fish count
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (!vis[i][j] && grid[i][j] > 0) {
                    // Perform DFS and calculate the total fish for the connected component
                    int currentFish = dfs(i, j, r, c, vis, grid);
                    maxFish = max(maxFish, currentFish); // Update the maximum fish count
                }
            }
        }

        return maxFish;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> grid1 = {
        {0, 2, 1, 0},
        {4, 0, 0, 3},
        {1, 0, 0, 4},
        {0, 3, 2, 0}
    };
    cout << "Max Fish for Grid 1: " << sol.findMaxFish(grid1) << endl; // Expected: 7

    // Test Case 2
    vector<vector<int>> grid2 = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 1}
    };
    cout << "Max Fish for Grid 2: " << sol.findMaxFish(grid2) << endl; // Expected: 1

    return 0;
}

