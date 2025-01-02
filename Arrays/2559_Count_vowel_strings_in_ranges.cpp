#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    // Helper function to check if a character is a vowel
    bool isVowel(char& c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

public:
    // Function to compute the number of strings starting and ending with vowels for each query
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix_sum(n + 1, 0); // Prefix sum array to store cumulative counts

        // Precompute the prefix sum for strings starting and ending with a vowel
        for (int i = 0; i < n; ++i) {
            char start = words[i][0];      // First character of the word
            char end = words[i].back();   // Last character of the word
            if (isVowel(start) && isVowel(end)) {
                prefix_sum[i + 1] = 1 + prefix_sum[i];
            } else {
                prefix_sum[i + 1] = prefix_sum[i];
            }
        }

        // Compute results for each query
        vector<int> res;
        for (auto query : queries) {
            int count = prefix_sum[query[1] + 1] - prefix_sum[query[0]];
            res.push_back(count);
        }
        return res;
    }
};

int main() {
    Solution solution;

    // Input 1
    vector<string> words1 = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries1 = {{0, 2}, {1, 4}, {1, 1}};
    cout << "Input 1: words = [\"aba\",\"bcb\",\"ece\",\"aa\",\"e\"], queries = [[0,2],[1,4],[1,1]]" << endl;
    vector<int> result1 = solution.vowelStrings(words1, queries1);
    cout << "Output: ";
    for (int res : result1) {
        cout << res << " ";
    }
    cout << endl;

    // Input 2
    vector<string> words2 = {"a", "e", "i"};
    vector<vector<int>> queries2 = {{0, 2}, {0, 1}, {2, 2}};
    cout << "\nInput 2: words = [\"a\",\"e\",\"i\"], queries = [[0,2],[0,1],[2,2]]" << endl;
    vector<int> result2 = solution.vowelStrings(words2, queries2);
    cout << "Output: ";
    for (int res : result2) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}

