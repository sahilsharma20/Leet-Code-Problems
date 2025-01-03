#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to calculate the number of ways to split the array
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;

        // Calculate the total sum of the array
        for (int ele : nums) {
            sum += ele;
        }

        int count = 0;  // To store the count of valid splits
        long long prefix_sum = 0;  // To store the prefix sum

        // Traverse the array to find valid splits
        for (int i = 0; i < n - 1; ++i) {
            prefix_sum += nums[i];  // Update the prefix sum
            // Check if the prefix sum is greater than or equal to the remaining sum
            if (prefix_sum >= sum - prefix_sum) {
                count++;  // Increment the count of valid splits
            }
        }

        return count;  // Return the count of valid splits
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {10, 4, -8, 7};
    cout << "Input: nums = [10,4,-8,7]" << endl;
    int result1 = solution.waysToSplitArray(nums1);
    cout << "Output: " << result1 << endl;

    // Example 2
    vector<int> nums2 = {2, 3, 1, 0};
    cout << "\nInput: nums = [2,3,1,0]" << endl;
    int result2 = solution.waysToSplitArray(nums2);
    cout << "Output: " << result2 << endl;

    return 0;
}

