#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        // **Step 1: Merge adjacent duplicates**
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        
        // **Step 2: Move non-zero elements to the left**
        int nonZeroIdx = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[nonZeroIdx]);
                nonZeroIdx++;
            }
        }
        
        return nums;
    }
};

// **Driver Code**
int main() {
    Solution sol;
    vector<vector<int>> testCases = {
        {1, 2, 2, 1, 1, 0}, // Expected Output: [1,4,2,0,0,0]
        {0, 1}              // Expected Output: [1,0]
    };

    for (auto& test : testCases) {
        vector<int> result = sol.applyOperations(test);
        cout << "Output: ";
        for (int num : result) cout << num << " ";
        cout << endl;
    }

    return 0;
}

