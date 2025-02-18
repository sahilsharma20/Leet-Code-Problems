#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        stack<int> st;
        string res = "";

        for (int i = 1; i <= n + 1; ++i) {
            st.push(i);
            // If at the end or encounter 'I', pop from stack and add to result
            if (i == n + 1 || pattern[i - 1] == 'I') {
                while (!st.empty()) {
                    res.push_back(char('0' + st.top()));
                    st.pop();
                }
            }
        }
        return res;
    }
};

// Driver Code
int main() {
    Solution sol;
    
    vector<string> testCases = {"IIIDIDDD", "DDD"};
    for (string pattern : testCases) {
        cout << "Pattern: " << pattern << " -> Smallest Number: " 
             << sol.smallestNumber(pattern) << endl;
    }

    return 0;
}

