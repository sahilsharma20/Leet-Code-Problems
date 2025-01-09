#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (auto word : words) {
            bool isPrefix = true;
            for (int i = 0; pref[i]; i++) {
                if (word[i] != pref[i]) {
                    isPrefix = false;
                    break;
                }
            }
            if (isPrefix == true)
                count++;
        }
        return count;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<string> words1 = {"pay", "attention", "practice", "attend"};
    string pref1 = "at";
    cout << "Output: " << solution.prefixCount(words1, pref1) << endl; // Expected: 2

    // Example 2
    vector<string> words2 = {"leetcode", "win", "loops", "success"};
    string pref2 = "code";
    cout << "Output: " << solution.prefixCount(words2, pref2) << endl; // Expected: 0

    return 0;
}

