#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

// Solution class implementing the Target Sum problem using bottom-up DP
class Solution {
public:
    // Function to calculate the number of subsets with a given sum 's'
    int subsetSum(vector<int>& nums, int s) {
        int n = nums.size();
        // DP table to store results of subproblems
        vector<vector<int>> t(n + 1, vector<int>(s + 1, 0));
        
        // Initializing the DP table:
        // If sum is 0, there's always one subset (empty subset)
        for (int row = 0; row < n + 1; row++) 
            t[row][0] = 1;

        // Filling the DP table using bottom-up approach
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < s + 1; j++) {
                if (nums[i - 1] <= j) 
                    t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j]; // Include or exclude the current number
                else
                    t[i][j] = t[i - 1][j]; // Exclude the current number
            }
        }
        
        return t[n][s]; // Return the result for n items and target sum s
    }
    
    // Function to find the number of ways to assign symbols to make the sum equal to the target
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0); // Calculate the total sum of the array
        int zeros = count(nums.begin(), nums.end(), 0); // Count the number of zeros in the array
        
        // Edge cases:
        // If target is greater than the total sum, it's impossible to achieve
        if (target > sum) return 0;
        // If (sum - target) is not divisible by 2, it's impossible to partition
        if ((sum - target) % 2 != 0) return 0;
        
        int s1 = (sum - target) / 2; // Calculate the subset sum
        return pow(2, zeros) * subsetSum(nums, s1); // Account for combinations with zeros
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 1, 1, 1, 1};
    int target1 = 3;
    cout << "Example 1: Number of ways to achieve target = " 
         << solution.findTargetSumWays(nums1, target1) << endl;

    // Example 2
    vector<int> nums2 = {1};
    int target2 = 1;
    cout << "Example 2: Number of ways to achieve target = " 
         << solution.findTargetSumWays(nums2, target2) << endl;

    return 0;
}

