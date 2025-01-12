#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n & 1) return false; // Base case: odd length

        // Check overbalanced ')'
        int opening = 0, closing = 0, wild_card = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0') wild_card++;
            else if (s[i] == '(') opening++;
            else closing++;
            if (wild_card < (closing - opening)) return false;
        }

        // Check overbalanced '('
        opening = closing = wild_card = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '0') wild_card++;
            else if (s[i] == '(') opening++;
            else closing++;
            if (wild_card < (opening - closing)) return false;
        }

        return true;
    }
};

int main() {
    Solution solution;

    // Example 1
    cout << solution.canBeValid("))()))", "010100") << endl; // Output: true

    // Example 2
    cout << solution.canBeValid("()()", "0000") << endl; // Output: true

    // Example 3
    cout << solution.canBeValid(")", "0") << endl; // Output: false

    return 0;
}

