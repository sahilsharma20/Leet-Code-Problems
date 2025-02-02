#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int countBreaks = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) { 
                countBreaks++; 
            }
            if (countBreaks > 1) return false;
        }
        return true;
    }
};

// Driver function to test the solution
int main() {
    Solution sol;

    vector<vector<int>> test_cases = {
        {3, 4, 5, 1, 2},  // Rotated sorted array
        {2, 1, 3, 4},     // Not sorted & rotated
        {1, 2, 3}         // Already sorted
    };

    for (auto& nums : test_cases) {
        cout << "Input: ";
        for (int num : nums) cout << num << " ";
        cout << "\nOutput: " << (sol.check(nums) ? "true" : "false") << "\n\n";
    }

    return 0;
}

