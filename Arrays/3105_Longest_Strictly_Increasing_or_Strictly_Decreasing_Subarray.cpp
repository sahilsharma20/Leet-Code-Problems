#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;  // A single element is always a valid subarray
        
        int longest = 1;
        int increasing = 1, decreasing = 1;

        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                increasing++;
                decreasing = 1;  // Reset decreasing counter
            } 
            else if (nums[i] < nums[i - 1]) {
                decreasing++;
                increasing = 1;  // Reset increasing counter
            } 
            else {
                increasing = 1;
                decreasing = 1;  // Reset both when elements are equal
            }
            longest = max({longest, increasing, decreasing});
        }
        return longest;
    }
};

// Driver function to test the solution
int main() {
    Solution sol;
    
    vector<vector<int>> test_cases = {
        {1, 4, 3, 3, 2},  // Mixed pattern
        {3, 3, 3, 3},     // All elements are the same
        {3, 2, 1}         // Strictly decreasing
    };

    for (auto& nums : test_cases) {
        cout << "Input: ";
        for (int num : nums) cout << num << " ";
        cout << "\nOutput: " << sol.longestMonotonicSubarray(nums) << "\n\n";
    }

    return 0;
}

