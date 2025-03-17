#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        // Count frequency of each element
        for (int num : nums) {
            freq[num]++;
        }
        
        // Check if all elements have even frequency
        for (const auto& pair : freq) {
            if (pair.second % 2 != 0) {
                return false;
            }
        }
        
        return true;
    }
};
