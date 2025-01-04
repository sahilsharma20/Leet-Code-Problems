#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
    #define pii pair<int, int>
public:
    // Function to count unique palindromic subsequences
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        // STEP-1: Get first and last occurrences of each character
        unordered_map<char, pii> first_last;
        for (int i = 0; i < n; ++i) {
            if (!first_last.count(s[i])) {
                // If the character is seen for the first time, set both first and last to i
                first_last[s[i]].first = first_last[s[i]].second = i;
            } else {
                // Update the last occurrence
                first_last[s[i]].second = i;
            }
        }

        // STEP-2: Count unique characters between first and last occurrences
        int count = 0;
        for (auto [c, se] : first_last) {
            if (se.first == se.second) continue; // Skip characters that appear only once
            // Use a set to find unique characters in the range
            count += unordered_set<char>(s.begin() + se.first + 1, s.begin() + se.second).size();
        }

        return count;
    }
};

int main() {
    Solution solution;

    // Example 1
    string s1 = "aabca";
    cout << "Input: s = \"aabca\"" << endl;
    int result1 = solution.countPalindromicSubsequence(s1);
    cout << "Output: " << result1 << endl;

    // Example 2
    string s2 = "adc";
    cout << "\nInput: s = \"adc\"" << endl;
    int result2 = solution.countPalindromicSubsequence(s2);
    cout << "Output: " << result2 << endl;

    // Example 3
    string s3 = "bbcbaba";
    cout << "\nInput: s = \"bbcbaba\"" << endl;
    int result3 = solution.countPalindromicSubsequence(s3);
    cout << "Output: " << result3 << endl;

    return 0;
}

