#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int odd_count = 0, even_count = 1;  // even_count starts with 1 (empty subarray)
        int total = 0, prefix_sum = 0;

        for (int num : arr) {
            prefix_sum += num;
            
            if (prefix_sum % 2 == 1) {  // Odd prefix sum
                total = (total + even_count) % MOD;
                odd_count++;
            } else {  // Even prefix sum
                total = (total + odd_count) % MOD;
                even_count++;
            }
        }
        return total;
    }
};

// **Driver Code**
int main() {
    Solution sol;
    
    vector<vector<int>> testCases = {
        {1, 3, 5},        // Output: 4
        {2, 4, 6},        // Output: 0
        {1, 2, 3, 4, 5, 6, 7}  // Output: 16
    };

    for (auto& test : testCases) {
        cout << "Output: " << sol.numOfSubarrays(test) << endl;
    }

    return 0;
}

