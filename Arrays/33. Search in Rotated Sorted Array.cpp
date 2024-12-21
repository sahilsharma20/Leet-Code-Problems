#include<iostream>
#include<vector>
using namespace std;

// Solution class implementing binary search on a rotated sorted array
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(); // Get the size of the array
        int start = 0;  // Start pointer
        int end = n-1;  // End pointer

        while(start <= end){
            int middle = (start+end) / 2;  // Calculate the middle index
            
            // Check if the middle element is the target
            if(target==nums[middle]){
                return middle;  // Target found at index 'middle'
            }

            // Check if the left half is sorted
            if(nums[start] <= nums[middle]){
                
                 // If the target lies within the sorted left half
                if(target >= nums[start] && target<nums[middle])
                {
                    end = middle - 1;  // Search in the left half
                }
                else
                {
                    start = middle + 1;  // Search in the right half
                }
            }

            // Otherwise, the right half must be sorted
            else
            {
                // If the target lies within the sorted right half
                if(target > nums[middle] && target<=nums[end]){
                    start = middle + 1;  // Search in the right half
                }
                else{
                    end = middle - 1;  // Search in the left half
                }
            } 
        }
        return -1;   // Target not found   
    }
};

// Main function for testing the Solution class
int main()
{
    // Create an instance of the Solution class
    Solution solution;
    
    // Example 1: Rotated sorted array and target
    vector <int> nums = {4,5,6,7,0,1,2}; // Input array
    int target = 0; // Target value to search for
    
    // Call the search function and store the result
    int result = solution.search(nums,target);
    
    // Output the result of the search
    if (result != -1) {
        cout << "Target found at index: " << result << endl; // Target found
    } else {
        cout << "Target not found in the array." << endl; // Target not found
    }
    
    return 0;
}
