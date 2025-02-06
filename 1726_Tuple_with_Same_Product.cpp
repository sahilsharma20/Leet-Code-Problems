#include <bits/stdc++.h>
using namespace std;

class Solution {
    int nC2(int n) {
        return (n * (n - 1)) / 2; // Combination formula
    }

public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq; // Stores frequency of each product
        
        // Compute all product pairs
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                freq[nums[i] * nums[j]]++;
            }
        }

        int count = 0;
        // Calculate tuple count
        for (auto [product, frequency] : freq) {
            if (frequency > 1) {
                count += 8 * nC2(frequency);
            }
        }

        return count;
    }
};

// Driver function to test cases
int main() {
    Solution sol;

    vector<vector<int>> test_cases = {
        {2, 3, 4, 6},   // Expected output: 8
        {1, 2, 4, 5, 10} // Expected output: 16
    };

    for (auto& nums : test_cases) {
        cout << "Input: { ";
        for (int num : nums) cout << num << " ";
        cout << "}\n";
        cout << "Output: " << sol.tupleSameProduct(nums) << "\n\n";
    }

    return 0;
}

