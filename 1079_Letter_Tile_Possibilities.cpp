#include <bits/stdc++.h>
using namespace std;

class Solution {
    int buildString(vector<int>& freq) {
        int ways = 0;
        // Try placing each character in the current position
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {  // If character is available
                freq[i]--;
                ways += 1 + buildString(freq);  // Count valid sequences
                freq[i]++;  // Backtrack
            }
        }
        return ways;
    }

public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for (char c : tiles)
            freq[c - 'A']++;  // Count frequency of each character
        return buildString(freq);
    }
};

// Driver code
int main() {
    Solution sol;

    vector<string> testCases = {"AAB", "AAABBC", "V"};
    for (string tiles : testCases) {
        cout << "Tiles: " << tiles << " -> " 
             << sol.numTilePossibilities(tiles) << " possibilities" << endl;
    }

    return 0;
}

