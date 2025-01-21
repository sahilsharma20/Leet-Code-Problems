#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
    #define ll long long
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if (n < 2) return 0;

        ll top_sum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        ll bottom_sum = 0;
        ll min_sum = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            top_sum -= grid[0][i];       // Subtract current top cell from top_sum
            min_sum = min(min_sum, max(top_sum, bottom_sum)); // Update min_sum
            bottom_sum += grid[1][i];   // Add current bottom cell to bottom_sum
        }
        return min_sum;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> grid1 = {{2, 5, 4}, {1, 5, 1}};
    cout << "Output (Test Case 1): " << sol.gridGame(grid1) << endl;

    // Test Case 2
    vector<vector<int>> grid2 = {{3, 3, 1}, {8, 5, 2}};
    cout << "Output (Test Case 2): " << sol.gridGame(grid2) << endl;

    // Test Case 3
    vector<vector<int>> grid3 = {{1, 3, 1, 15}, {1, 3, 3, 1}};
    cout << "Output (Test Case 3): " << sol.gridGame(grid3) << endl;

    return 0;
}

