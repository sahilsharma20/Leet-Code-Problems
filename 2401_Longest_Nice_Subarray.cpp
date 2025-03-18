#include <vector>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, bitmask = 0, maxLength = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            while ((bitmask & nums[right]) != 0) {
                bitmask ^= nums[left];  // Remove nums[left] from bitmask
                left++;                 // Shrink the window
            }
            bitmask |= nums[right];      // Add nums[right] to bitmask
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
