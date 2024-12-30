#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // MOD is used to prevent overflow by taking results modulo 10^9+7
    int MOD = 1e9+7;

    // Function to count the number of good strings
    int countGoodStrings(int low, int high, int zero, int one) {
        long long int ans = 0; // Stores the final count of good strings
        vector<long long int> dp(high + 1, 0); // DP array to store intermediate results
        dp[0] = 1; // Base case: there's one way to form a string of length 0 (the empty string)

        // Calculate the number of good strings of length 1 to `high`
        for (int len = 1; len <= high; len++) {
            int total = 0;

            // If it's possible to append `zero` 0's to form the current length
            if (len >= zero) {
                total += dp[len - zero];
            }

            // If it's possible to append `one` 1's to form the current length
            if (len >= one) {
                total += dp[len - one];
            }

            dp[len] = total % MOD; // Store the result modulo MOD
        }

        // Sum up the results for lengths between `low` and `high`
        for (int len = low; len <= high; len++) {
            ans += dp[len];
        }

        return ans % MOD; // Return the final result modulo MOD
    }
};

int main() {
    // Create a Solution object
    Solution solution;

    // Test case 1
    int low1 = 3, high1 = 3, zero1 = 1, one1 = 1;
    cout << "Input: low = " << low1 << ", high = " << high1
         << ", zero = " << zero1 << ", one = " << one1 << endl;
    cout << "Output: " << solution.countGoodStrings(low1, high1, zero1, one1) << endl;

    // Test case 2
    int low2 = 2, high2 = 3, zero2 = 1, one2 = 2;
    cout << "Input: low = " << low2 << ", high = " << high2
         << ", zero = " << zero2 << ", one = " << one2 << endl;
    cout << "Output: " << solution.countGoodStrings(low2, high2, zero2, one2) << endl;

    return 0;
}

