#include <bits/stdc++.h>
using namespace std;

// Define a class Solution
class Solution {
    #define ll long long // Shortcut for long long
    int mem[1001][1001]; // Memoization array for dynamic programming
    int MOD = 1000000007; // Modulus for large numbers
    int target_size; // Length of the target string
    int word_size; // Length of each word in the words vector
    int n; // Number of words in the words vector
    vector<vector<int>> char_freq; // Frequency of characters at each position in words

    // Recursive function to count ways
    int countWays(vector<string>& words, int idx, string& target, int tpos) {
        // Base case: target is fully matched
        if (tpos == target_size)
            return idx <= word_size;

        // Base case: exhausted words or insufficient remaining size
        if (idx >= word_size || (word_size - idx < target_size - tpos))
            return 0;

        // Return memoized result if it exists
        if (mem[idx][tpos] != -1)
            return mem[idx][tpos];

        // Current target character
        char curr = target[tpos];

        // Option 1: Skip the current position in words
        ll ways_by_not_matching = countWays(words, idx + 1, target, tpos);

        // Option 2: Match the current character
        ll ways_by_matching = countWays(words, idx + 1, target, tpos + 1) % MOD;

        // Calculate total ways considering character frequency at idx
        ll total_ways = (ways_by_not_matching + 
                         (ll)char_freq[idx][curr - 'a'] * ways_by_matching) % MOD;

        // Store result in memoization table and return
        return mem[idx][tpos] = total_ways;
    }

public:
    // Function to calculate the number of ways to form target
    int numWays(vector<string>& words, string target) {
        target_size = target.size();
        word_size = words[0].size();
        n = words.size();

        // Initialize character frequency for each position in words
        char_freq = vector<vector<int>>(word_size, vector<int>(26, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < word_size; ++j) {
                char curr = words[i][j];
                char_freq[j][curr - 'a']++;
            }
        }

        // Initialize memoization table with -1
        memset(mem, -1, sizeof(mem));

        // Start recursive computation
        return countWays(words, 0, target, 0);
    }
};

int main() {
    // Example 1
    vector<string> words1 = {"acca", "bbbb", "caca"};
    string target1 = "aba";
    Solution solution1;
    cout << "Output for Example 1: " << solution1.numWays(words1, target1) << endl;

    // Example 2
    vector<string> words2 = {"abba", "baab"};
    string target2 = "bab";
    Solution solution2;
    cout << "Output for Example 2: " << solution2.numWays(words2, target2) << endl;

    return 0;
}

