#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int res = 0;
        for (int ele : derived)
            res ^= ele;
        return res == 0;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> derived = {1, 1, 0};
    cout << "Output (derived = [1,1,0]): " << (sol.doesValidArrayExist(derived) ? "true" : "false") << endl;

    // Test Case 2
    derived = {1, 1};
    cout << "Output (derived = [1,1]): " << (sol.doesValidArrayExist(derived) ? "true" : "false") << endl;

    // Test Case 3
    derived = {1, 0};
    cout << "Output (derived = [1,0]): " << (sol.doesValidArrayExist(derived) ? "true" : "false") << endl;

    return 0;
}

