#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canRob(vector<int>& nums, int k, int capability) {
        int count = 0, prevRobbed = -2;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= capability && i > prevRobbed + 1) {
                count++;
                prevRobbed = i;
                if (count >= k) return true;
            }
        }
        return false;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canRob(nums, k, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};
