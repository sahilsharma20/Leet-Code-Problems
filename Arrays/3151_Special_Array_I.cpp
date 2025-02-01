#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 1; i < n; i++) {
            if ((nums[i] & 1) == (nums[i-1] & 1)) // If two adjacent numbers have the same parity
                return false;
        }
        return true;
    }
};

// Driver function to test the solution
int main() {
    Solution sol;
    
    vector<vector<int>> test_cases = {
        {1},        // Single element - Always special
        {2, 1, 4},  // Not special (1 and 4 are both odd)
        {4, 3, 1, 6} // Special (4-even, 3-odd, 1-odd, 6-even)
    };

    for (auto& nums : test_cases) {
        cout << "Input: ";
        for (int num : nums) cout << num << " ";
        cout << "\nOutput: " << (sol.isArraySpecial(nums) ? "true" : "false") << "\n\n";
    }

    return 0;
}

