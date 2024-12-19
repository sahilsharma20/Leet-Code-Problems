#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the index to insert the target element
    int searchInsert(vector<int>& nums, int target) {
        // Get the size of the input vector
        int n = nums.size();
        
        // Initialize the start and end pointers for binary search
        int start = 0;
        int end = n - 1;
        
        // Perform binary search to find the correct position
        while (start <= end) {
            // Calculate the middle index
            int mid = (start + end) / 2;
            
            // If the target is found at mid, return the mid index
            if (nums[mid] == target)
                return mid;
            
            // If the target is smaller than the mid value, narrow the search to the left half
            else if (nums[mid] > target)
                end = mid - 1;
            
            // If the target is greater than the mid value, narrow the search to the right half
            else 
                start = mid + 1;
        }
        
        // If the target is not found, return the index where it should be inserted
        return start;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    cout << "Insert position for " << target1 << ": " << solution.searchInsert(nums1, target1) << endl; // Expected output: 2

    // Test case 2
    vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    cout << "Insert position for " << target2 << ": " << solution.searchInsert(nums2, target2) << endl; // Expected output: 1

    // Test case 3
    vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    cout << "Insert position for " << target3 << ": " << solution.searchInsert(nums3, target3) << endl; // Expected output: 4

    // Test case 4
    vector<int> nums4 = {1, 3, 5, 6};
    int target4 = 0;
    cout << "Insert position for " << target4 << ": " << solution.searchInsert(nums4, target4) << endl; // Expected output: 0

    return 0;
}

