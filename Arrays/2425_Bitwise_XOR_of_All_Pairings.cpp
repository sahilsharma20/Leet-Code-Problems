#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;

        // Find contribution by first array elements
        int m = nums2.size();
        if (m & 1) { // If m is odd
            for (int ele : nums1)
                ans ^= ele;
        }

        // Find contribution by second array elements
        int n = nums1.size();
        if (n & 1) { // If n is odd
            for (int ele : nums2)
                ans ^= ele;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {2, 1, 3};
    vector<int> nums2 = {10, 2, 5, 0};
    cout << "Output (nums1 = [2,1,3], nums2 = [10,2,5,0]): " << sol.xorAllNums(nums1, nums2) << endl;

    // Test Case 2
    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << "Output (nums1 = [1,2], nums2 = [3,4]): " << sol.xorAllNums(nums1, nums2) << endl;

    return 0;
}

