#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        // Initialize array of size 'length + 1'
        vector<int> arr(length + 1, 0);
        
        // Apply all updates
        for (auto v : updates) {
            arr[v[0]] += v[2];          // Add value at the start index
            if (v[1] + 1 < length) {
                arr[v[1] + 1] -= v[2]; // Subtract value at index just after the end
            }
        }
        
        // Compute the cumulative sum
        for (int i = 1; i < length; ++i) {
            arr[i] += arr[i - 1]; // Cumulative sum of differences
        }
        
        // Remove the extra element we added initially
        arr.pop_back();
        
        return arr;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    vector<vector<int>> updates1 = {{1, 3, 2}, {2, 4, 3}, {0, 2, -2}};
    vector<int> result1 = solution.getModifiedArray(5, updates1);
    for (int val : result1) {
        cout << val << " ";  // Expected output: [-2, 0, 3, 5, 3]
    }
    cout << endl;

    // Test Case 2
    vector<vector<int>> updates2 = {{2, 4, 6}, {5, 6, 8}, {1, 9, -4}};
    vector<int> result2 = solution.getModifiedArray(10, updates2);
    for (int val : result2) {
        cout << val << " ";  // Expected output: [0, 2, 4, 6, 6, 4, 4, 4, 4, 4]
    }
    cout << endl;

    return 0;
}

