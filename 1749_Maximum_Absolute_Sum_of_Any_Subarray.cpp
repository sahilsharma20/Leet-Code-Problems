#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Kadane's Algorithm to find the maximum subarray sum
    int maxSumSubarrayKadanes(vector<int>& nums) {
        int max_sum = INT_MIN, curr_sum = 0;
        
        for (int num : nums) {
            curr_sum += num;
            max_sum = max(max_sum, curr_sum);
            if (curr_sum < 0) curr_sum = 0; // Reset sum if it goes negative
        }
        
        return max_sum;
    }

public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum = maxSumSubarrayKadanes(nums);
        
        // Flip signs to find the min subarray sum
        for (int& num : nums) num *= -1;
        
        int min_sum = maxSumSubarrayKadanes(nums);
        return max(max_sum, min_sum);
    }
};

// **Driver Code**
int main() {
    Solution sol;
    
    vector<vector<int>> testCases = {
        {1, -3, 2, 3, -4},   // Output: 5
        {2, -5, 1, -4, 3, -2} // Output: 8
    };

    for (auto& test : testCases) {
        cout << "Output: " << sol.maxAbsoluteSum(test) << endl;
    }

    return 0;
}

