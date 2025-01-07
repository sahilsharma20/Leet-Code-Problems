#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    void precompute_LPS(vector<string>& words, vector<vector<int>>& lps) {
        for (string word : words) {
            int m = word.size();
            vector<int> word_lps(m);

            int i = 1, j = 0;
            while (i < m) {
                if (word[i] == word[j]) {
                    word_lps[i] = j + 1;
                    i++;
                    j++;
                } else if (j > 0) {
                    j = word_lps[j - 1];
                } else {
                    i++;
                }
            }
            lps.push_back(word_lps);
        }
    }

    bool stringMatcher(string& pattern, vector<int>& pattern_lps, string& text) {
        int pattern_size = pattern.size();
        int text_size = text.size();
        int i = 0; // pattern pointer
        int j = 0; // text pointer
        while (j < text_size) {
            if (pattern[i] == text[j]) {
                i++;
                j++;
            }
            if (i == pattern_size)
                return true;

            if (j < text_size && pattern[i] != text[j]) {
                if (i > 0) {
                    i = pattern_lps[i - 1];
                } else {
                    j++;
                }
            }
        }
        return false;
    }

    static bool comparator(string& word1, string& word2) {
        return word1.size() <= word2.size();
    }

public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();

        // Step 1: Sort by word size (Pattern must be of smaller size)
        sort(words.begin(), words.end(), comparator);

        // Step 2: Precompute LPS for all words
        vector<vector<int>> lps;
        precompute_LPS(words, lps);

        // Step 3: Match all O(N^2) combinations of words
        vector<string> res;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stringMatcher(words[i], lps[i], words[j])) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<string> words1 = {"mass", "as", "hero", "superhero"};
    vector<string> result1 = solution.stringMatching(words1);
    for (string word : result1) cout << word << " ";
    cout << endl; // Expected output: "as hero"

    // Example 2
    vector<string> words2 = {"leetcode", "et", "code"};
    vector<string> result2 = solution.stringMatching(words2);
    for (string word : result2) cout << word << " ";
    cout << endl; // Expected output: "et code"

    // Example 3
    vector<string> words3 = {"blue", "green", "bu"};
    vector<string> result3 = solution.stringMatching(words3);
    for (string word : result3) cout << word << " ";
    cout << endl; // Expected output: ""
}

