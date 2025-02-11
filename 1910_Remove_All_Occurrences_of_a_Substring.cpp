#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int partLen = part.size();
        string result;
        
        for (char c : s) {
            result.push_back(c);
            // Check if the last 'partLen' characters match 'part'
            if (result.size() >= partLen && result.substr(result.size() - partLen) == part) {
                result.erase(result.size() - partLen, partLen);
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;

    string s1 = "daabcbaabcbc", part1 = "abc";
    string s2 = "axxxxyyyyb", part2 = "xy";

    cout << "Output for \"daabcbaabcbc\", part = \"abc\": " << sol.removeOccurrences(s1, part1) << endl;
    cout << "Output for \"axxxxyyyyb\", part = \"xy\": " << sol.removeOccurrences(s2, part2) << endl;

    return 0;
}

