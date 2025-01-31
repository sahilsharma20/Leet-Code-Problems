#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> dir = {-1, 0, 1, 0, -1}; // Directions for 4-way movement

    // Function to check if the given coordinates are valid
    bool isValid(int n, int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < n);
    }

    // Function to mark an island and return its size using DFS
    int markIsland(vector<vector<int>>& grid, int island_number, int n, int x, int y) {
        grid[x][y] = island_number; // Mark the cell with a unique island number
        int count = 1;
        
        for (int i = 0; i < 4; ++i) {
            int newX = x + dir[i];
            int newY = y + dir[i + 1];
            
            if (isValid(n, newX, newY) && grid[newX][newY] == 1) {
                count += markIsland(grid, island_number, n, newX, newY);
            }
        }
        return count;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> island_size; // Map to store island sizes
        int island_number = 2; // Start marking islands from 2 (since 1 is already in the grid)

        // Step 1: Mark islands with unique numbers and store their sizes
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (grid[x][y] == 1) {
                    int size = markIsland(grid, island_number, n, x, y);
                    island_size[island_number] = size;
                    island_number++;
                }
            }
        }

        // Step 2: Check each 0 and see the maximum island size by flipping it to 1
        int max_size = 0;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (grid[x][y] == 0) { // Try converting this 0 to 1
                    set<int> islands; // Store unique neighboring islands
                    for (int i = 0; i < 4; ++i) {
                        int newX = x + dir[i];
                        int newY = y + dir[i + 1];
                        if (isValid(n, newX, newY) && grid[newX][newY] > 1) {
                            islands.insert(grid[newX][newY]);
                        }
                    }
                    
                    // Calculate total possible island size after flipping this 0
                    int curr_island = 1; // This flipped cell itself
                    for (int key : islands) {
                        curr_island += island_size[key];
                    }
                    
                    max_size = max(max_size, curr_island);
                }
            }
        }

        // Step 3: If no 0 was found (grid is already all 1s), return n * n
        return max_size == 0 ? n * n : max_size;
    }
};

// Driver code
int main() {
    Solution sol;
    
    vector<vector<int>> grid1 = {{1, 0}, {0, 1}};
    cout << "Largest Island Size: " << sol.largestIsland(grid1) << endl; // Output: 3

    vector<vector<int>> grid2 = {{1, 1}, {1, 0}};
    cout << "Largest Island Size: " << sol.largestIsland(grid2) << endl; // Output: 4

    vector<vector<int>> grid3 = {{1, 1}, {1, 1}};
    cout << "Largest Island Size: " << sol.largestIsland(grid3) << endl; // Output: 4

    return 0;
}

