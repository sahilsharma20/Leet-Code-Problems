#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to find the Longest Common Subsequence (LCS)
    string findLCS(string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        // Compute LCS length using bottom-up DP
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Backtrack to construct the LCS string
        string lcs;
        int i = len1, j = len2;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                lcs.push_back(str1[i - 1]);
                --i, --j;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                --i;
            } else {
                --j;
            }
        }
        reverse(lcs.begin(), lcs.end());
        return lcs;
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {
        string ans = "";
        string lcs = findLCS(str1, str2);

        // Merge str1 and str2 while maintaining LCS order
        int p1 = 0, p2 = 0;
        for (char c : lcs) {
            while (str1[p1] != c) ans += str1[p1++]; // Add non-LCS chars from str1
            while (str2[p2] != c) ans += str2[p2++]; // Add non-LCS chars from str2
            
            ans += c; // Add LCS character
            ++p1, ++p2;
        }

        // Add remaining characters from both strings
        ans += str1.substr(p1) + str2.substr(p2);
        return ans;
    }
};

// **Driver Code**
int main() {
    Solution sol;

    vector<pair<string, string>> testCases = {
        {"abac", "cab"},       // Expected Output: "cabac"
        {"aaaaaaaa", "aaaaaaaa"} // Expected Output: "aaaaaaaa"
    };

    for (auto& test : testCases) {
        cout << "Output: " << sol.shortestCommonSupersequence(test.first, test.second) << endl;
    }

    return 0;
}

