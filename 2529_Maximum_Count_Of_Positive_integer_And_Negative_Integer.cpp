#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // Find the first index of a positive number using binary search
        int posIndex = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
        
        // Find the first index of zero using binary search
        int zeroIndex = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        
        // Number of negative numbers
        int negCount = zeroIndex;
        
        // Number of positive numbers
        int posCount = nums.size() - posIndex;
        
        return max(negCount, posCount);
    }
};
