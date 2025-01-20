#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
    #define pii pair<int,int>
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Step 1: Create a lookup table for each value in the matrix
        vector<pii> lookup(m * n + 1); // Stores x, y coordinates for each element in the matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                lookup[mat[i][j]] = make_pair(i, j);
            }
        }

        // Step 2: Track row and column painting progress
        vector<int> row_count(m, 0);
        vector<int> col_count(n, 0);

        for (int i = 0; i < arr.size(); ++i) {
            pii coordinate = lookup[arr[i]];
            int x = coordinate.first;
            int y = coordinate.second;
            
            row_count[x]++;
            col_count[y]++;
            
            // Check if a row or column is completely painted
            if (row_count[x] == n || col_count[y] == m) {
                return i;
            }
        }
        return 0; // Default case (should not occur for valid inputs)
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {1, 3, 4, 2};
    vector<vector<int>> mat1 = {{1, 4}, {2, 3}};
    cout << "Output (Test Case 1): " << sol.firstCompleteIndex(arr1, mat1) << endl;

    // Test Case 2
    vector<int> arr2 = {2, 8, 7, 4, 1, 3, 5, 6, 9};
    vector<vector<int>> mat2 = {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};
    cout << "Output (Test Case 2): " << sol.firstCompleteIndex(arr2, mat2) << endl;

    return 0;
}

