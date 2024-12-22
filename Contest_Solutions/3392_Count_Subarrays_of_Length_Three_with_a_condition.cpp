#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0; // Count of valid subarrays
        for (int i = 0; i <= nums.size() - 3; i++) {
            int first = nums[i];
            int middle = nums[i + 1];
            int third = nums[i + 2];
            
            // Check if the arithmetic mean condition is satisfied
            if (first+third==middle/2.0) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    // Example 1
    vector<int> nums1 = {1, 2, 1, 4, 1};
    Solution sol;
    cout << "Example 1 Output: " << sol.countSubarrays(nums1) << endl;

    // Example 2
    vector<int> nums2 = {1, 1, 1};
    cout << "Example 2 Output: " << sol.countSubarrays(nums2) << endl;

    return 0;
}

