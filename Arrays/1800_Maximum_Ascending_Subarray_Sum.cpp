#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];  // Single element case

        int max_sum = nums[0], curr_sum = nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                curr_sum += nums[i];  // Extend the ascending subarray
            } else {
                curr_sum = nums[i];   // Reset sum for new subarray
            }
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};

// Driver function to test the solution
int main() {
    Solution sol;
    
    vector<vector<int>> test_cases = {
        {10, 20, 30, 5, 10, 50},  // Multiple ascending subarrays
        {10, 20, 30, 40, 50},     // Entire array is ascending
        {12, 17, 15, 13, 10, 11, 12} // Multiple ascending sequences
    };

    for (auto& nums : test_cases) {
        cout << "Input: ";
        for (int num : nums) cout << num << " ";
        cout << "\nOutput: " << sol.maxAscendingSum(nums) << "\n\n";
    }

    return 0;
}

