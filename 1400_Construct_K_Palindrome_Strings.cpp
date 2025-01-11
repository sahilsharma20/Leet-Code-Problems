#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;
        
        // Step 1: Count character frequencies
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        
        // Step 2: Count odd frequency characters
        int odd_freq = 0;
        for (int i = 0; i < 26; ++i)
            if (freq[i] % 2 != 0)
                odd_freq++;
        
        // Step 3: Check if odd_freq <= k
        return odd_freq <= k;
    }
};

int main() {
    Solution solution;

    // Example 1
    cout << solution.canConstruct("annabelle", 2) << endl; // Output: true

    // Example 2
    cout << solution.canConstruct("leetcode", 3) << endl; // Output: false

    // Example 3
    cout << solution.canConstruct("true", 4) << endl; // Output: true

    return 0;
}

