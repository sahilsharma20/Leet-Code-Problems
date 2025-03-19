#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;
        
        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) { // If the current element is 0, flip it with the next two elements
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                operations++;
            }
        }
        
        // Check if all elements are 1
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) return -1;
        }
        
        return operations;
    }
};
