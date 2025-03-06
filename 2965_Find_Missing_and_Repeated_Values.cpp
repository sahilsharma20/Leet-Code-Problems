#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int repeating = -1, missing = -1;
        
        // Flatten the 2D grid into a 1D array
        vector<int> nums(n * n + 1, 0); // Index from 1 to n*n
        
        // Count occurrences
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                nums[grid[i][j]]++;
            }
        }
        
        // Find missing and repeating numbers
        for (int num = 1; num <= n * n; ++num) {
            if (nums[num] == 2) repeating = num;
            if (nums[num] == 0) missing = num;
        }
        
        return {repeating, missing};
    }
};

// **Driver Code**
int main() {
    Solution sol;
    vector<vector<vector<int>>> testCases = {
        {{1,3}, {2,2}},  // Expected Output: [2, 4]
        {{9,1,7}, {8,9,2}, {3,4,6}} // Expected Output: [9, 5]
    };

    for (auto& grid : testCases) {
        vector<int> result = sol.findMissingAndRepeatedValues(grid);
        cout << "Output: [" << result[0] << ", " << result[1] << "]\n";
    }

    return 0;
}

