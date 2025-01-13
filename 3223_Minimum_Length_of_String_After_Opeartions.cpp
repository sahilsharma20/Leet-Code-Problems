#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); ++i)
            freq[s[i] - 'a']++;

        int length = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] & 1) // If odd
                length += 1;
            else // If even, take minimum of 2 or the frequency
                length += min(2, freq[i]);
        }
        return length;
    }
};

int main() {
    Solution solution;

    // Example 1
    cout << solution.minimumLength("abaacbcbb") << endl; // Output: 5

    // Example 2
    cout << solution.minimumLength("aa") << endl; // Output: 2

    return 0;
}

