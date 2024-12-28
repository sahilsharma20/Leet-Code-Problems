#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
    vector<int> prefix_sum; // To store prefix sums of the array
    int mem[20001][3];      // Memoization table for dynamic programming

    // Helper function to find the maximum sum of three subarrays
    int findMaxSum(vector<int>& nums, int pos, int count, int k) {
        // Base case: if we have selected 3 subarrays
        if (count == 3) return 0;

        // Base case: if the remaining elements are insufficient for a subarray
        if (pos > nums.size() - k) return 0;

        // Return the already computed result
        if (mem[pos][count] != -1) return mem[pos][count];

        // Case 1: Don't start a subarray at the current position
        int dont_start = findMaxSum(nums, pos + 1, count, k);

        // Case 2: Start a subarray at the current position
        int start_here = findMaxSum(nums, pos + k, count + 1, k)
                         + prefix_sum[pos + k] - prefix_sum[pos];

        // Store the result in the memoization table and return the maximum
        return mem[pos][count] = max(dont_start, start_here);
    }

    // Helper function to find the indices of the maximum sum subarrays
    void findMaxSumPath(vector<int>& nums, int pos, int count, int k, vector<int>& path) {
        // Base case: if we have selected 3 subarrays
        if (count == 3) return;

        // Base case: if the remaining elements are insufficient for a subarray
        if (pos > nums.size() - k) return;

        // Case 1: Don't start a subarray at the current position
        int dont_start = findMaxSum(nums, pos + 1, count, k); // Use precomputed result

        // Case 2: Start a subarray at the current position
        int start_here = findMaxSum(nums, pos + k, count + 1, k)
                         + prefix_sum[pos + k] - prefix_sum[pos];

        // Choose the optimal path
        if (start_here >= dont_start) {
            path.push_back(pos); // Add current position to the path
            findMaxSumPath(nums, pos + k, count + 1, k, path); // Move to the next subarray
        } else {
            findMaxSumPath(nums, pos + 1, count, k, path); // Skip the current position
        }
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        memset(mem, -1, sizeof(mem)); // Initialize memoization table with -1

        // Calculate prefix sums
        prefix_sum = vector<int>(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];

        // Find the starting indices of the subarrays contributing to the max sum
        vector<int> path;
        findMaxSumPath(nums, 0, 0, k, path);

        return path; // Return the indices of the three subarrays
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 1, 2, 6, 7, 5, 1};
    int k1 = 2;
    vector<int> result1 = solution.maxSumOfThreeSubarrays(nums1, k1);
    cout << "Indices for Input 1: ";
    for (int idx : result1) cout << idx << " ";
    cout << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 1, 2, 1, 2, 1, 2, 1};
    int k2 = 2;
    vector<int> result2 = solution.maxSumOfThreeSubarrays(nums2, k2);
    cout << "Indices for Input 2: ";
    for (int idx : result2) cout << idx << " ";
    cout << endl;

    return 0;
}

