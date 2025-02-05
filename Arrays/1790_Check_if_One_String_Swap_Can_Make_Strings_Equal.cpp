#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;  // Already equal, no swap needed
        if (s1.size() != s2.size()) return false;  // Different sizes, not possible
        
        vector<int> diff;  // Stores indices where characters differ

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) 
                diff.push_back(i);
            if (diff.size() > 2) return false;  // More than two differences, can't fix with one swap
        }

        // There must be exactly **two** differing positions to swap
        return (diff.size() == 2 &&
                s1[diff[0]] == s2[diff[1]] && 
                s1[diff[1]] == s2[diff[0]]);
    }
};

// Driver function to test cases
int main() {
    Solution sol;

    vector<pair<string, string>> test_cases = {
        {"bank", "kanb"},  // True (swap 'b' and 'k')
        {"attack", "defend"}, // False (more than 2 mismatches)
        {"kelb", "kelb"} // True (already equal)
    };

    for (auto& [s1, s2] : test_cases) {
        cout << "Input: \"" << s1 << "\", \"" << s2 << "\"\n";
        cout << "Output: " << (sol.areAlmostEqual(s1, s2) ? "true" : "false") << "\n\n";
    }

    return 0;
}

