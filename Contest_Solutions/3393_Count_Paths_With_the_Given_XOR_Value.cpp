#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        // Define the modulo constant for results to avoid overflow
        const int MOD = 1e9 + 7;

        // Get the dimensions of the grid
        int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns

        // Create a 3D DP array: dp[i][j][xor_value]
        // dp[i][j][xor_value] represents the number of paths to cell (i, j) with a XOR value of `xor_value`
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(1024, 0)));

        // Initialize the starting point at (0, 0) with the XOR value of the first cell
        dp[0][0][grid[0][0]] = 1;

        // Traverse through each cell of the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Iterate through all possible XOR values (0 to 1023)
                for (int xor_value = 0; xor_value < 1024; xor_value++) {
                    // If there are paths leading to this cell with the current XOR value
                    if (dp[i][j][xor_value] > 0) {
                        // Move to the right cell (i, j+1) if within bounds
                        if (j + 1 < n) {
                            int new_xor = xor_value ^ grid[i][j + 1]; // Calculate new XOR value
                            dp[i][j + 1][new_xor] = (dp[i][j + 1][new_xor] + dp[i][j][xor_value]) % MOD;
                        }

                        // Move to the bottom cell (i+1, j) if within bounds
                        if (i + 1 < m) {
                            int new_xor = xor_value ^ grid[i + 1][j]; // Calculate new XOR value
                            dp[i + 1][j][new_xor] = (dp[i + 1][j][new_xor] + dp[i][j][xor_value]) % MOD;
                        }
                    }
                }
            }
        }

        // The result is the number of paths to the bottom-right cell with XOR value equal to `k`
        return dp[m - 1][n - 1][k];
    }
};

// Function to test the examples
void test() {
    Solution solution;

    // Example 1
    vector<vector<int>> grid1 = {{2, 1, 5}, {7, 10, 0}, {12, 6, 4}};
    int k1 = 11;
    cout << "Example 1 Output: " << solution.countPathsWithXorValue(grid1, k1) << endl;

    // Example 2
    vector<vector<int>> grid2 = {{1, 3, 3, 3}, {0, 3, 3, 2}, {3, 0, 1, 1}};
    int k2 = 2;
    cout << "Example 2 Output: " << solution.countPathsWithXorValue(grid2, k2) << endl;

    // Example 3
    vector<vector<int>> grid3 = {{1, 1, 1, 2}, {3, 0, 3, 2}, {3, 0, 2, 2}};
    int k3 = 10;
    cout << "Example 3 Output: " << solution.countPathsWithXorValue(grid3, k3) << endl;
}

// Main function to run the test cases
int main() {
    test();
    return 0;
}

