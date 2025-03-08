#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int white_count = 0, min_operations = INT_MAX;
        
        // Count white blocks in the first `k` window
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') white_count++;
        }
        min_operations = white_count;
        
        // Slide the window across the string
        for (int i = k; i < n; i++) {
            if (blocks[i - k] == 'W') white_count--;  // Remove left element
            if (blocks[i] == 'W') white_count++;      // Add right element
            min_operations = min(min_operations, white_count);
        }
        
        return min_operations;
    }
};

// **Driver Code**
int main() {
    Solution sol;
    vector<pair<string, int>> testCases = {
        {"WBBWWBBWBW", 7},  // Expected Output: 3
        {"WBWBBBW", 2}      // Expected Output: 0
    };

    for (auto& [blocks, k] : testCases) {
        cout << "Output: " << sol.minimumRecolors(blocks, k) << endl;
    }

    return 0;
}

