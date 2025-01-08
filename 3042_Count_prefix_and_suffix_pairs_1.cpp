#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    bool isPrefix(const string &s1, const string &s2) {
        int m = s1.size();
        int n = s2.size();
        if (m > n)
            return false;
        for (int i = 0; s1[i] != '\0'; ++i)
            if (s1[i] != s2[i])
                return false;
        return true;
    }

    bool isSuffix(const string &s1, const string &s2) {
        int m = s1.size();
        int n = s2.size();
        if (m > n)
            return false;
        for (int i = m - 1; i >= 0; --i) {
            if (s1[i] != s2[n - (m - i)])
                return false;
        }
        return true;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (isPrefix(words[i], words[j]) && isSuffix(words[i], words[j]))
                    count++;
            }
        }
        return count;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<string> words1 = {"a", "aba", "ababa", "aa"};
    cout << "Output: " << solution.countPrefixSuffixPairs(words1) << endl; // Expected: 4

    // Example 2
    vector<string> words2 = {"pa", "papa", "ma", "mama"};
    cout << "Output: " << solution.countPrefixSuffixPairs(words2) << endl; // Expected: 2

    // Example 3
    vector<string> words3 = {"abab", "ab"};
    cout << "Output: " << solution.countPrefixSuffixPairs(words3) << endl; // Expected: 1

    return 0;
}

