#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row_count(m, 0); // Count servers in each row
        vector<int> col_count(n, 0); // Count servers in each column
        
        int total_servers = 0;

        // Step 1: Count the number of servers in each row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    row_count[i]++;
                    col_count[j]++;
                    total_servers++;
                }
            }
        }

        // Step 2: Deduct isolated servers
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && row_count[i] == 1 && col_count[j] == 1) {
                    total_servers--;
                }
            }
        }

        return total_servers;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> grid1 = {{1, 0}, {0, 1}};
    cout << "Output for grid1: " << sol.countServers(grid1) << endl; // Expected: 0

    // Test Case 2
    vector<vector<int>> grid2 = {{1, 0}, {1, 1}};
    cout << "Output for grid2: " << sol.countServers(grid2) << endl; // Expected: 3

    // Test Case 3
    vector<vector<int>> grid3 = {{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    cout << "Output for grid3: " << sol.countServers(grid3) << endl; // Expected: 4

    return 0;
}

