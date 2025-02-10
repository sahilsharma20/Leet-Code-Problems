#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        string res;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                if (!res.empty())  // Ensure res is not empty before popping
                    res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    string s1 = "abc";
    string s2 = "cb34";

    cout << "Output for \"abc\": " << sol.clearDigits(s1) << endl;
    cout << "Output for \"cb34\": " << sol.clearDigits(s2) << endl;

    return 0;
}

