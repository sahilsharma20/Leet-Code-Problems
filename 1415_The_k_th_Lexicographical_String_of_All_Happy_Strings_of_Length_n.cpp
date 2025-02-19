#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        int sz = 3 * (1 << (n - 1)); // Total number of happy strings of length n
        if (k > sz) return ""; // If k is out of bounds, return empty string
        
        auto [q, r] = div(k - 1, 1 << (n - 1)); // Compute quotient and remainder
        string s(n, ' ');
        s[0] = 'a' + q; // First character determined by quotient
        
        bitset<9> bin(r); // Binary representation of remainder
        array<char, 2> xx[3] = { {'b', 'c'}, {'a', 'c'}, {'a', 'b'} };
        
        for (int i = n - 2; i >= 0; i--) {
            char idx = s[n - 2 - i] - 'a'; // Previous character index
            s[n - 1 - i] = (bin[i]) ? xx[idx][1] : xx[idx][0]; // Choose next character
        }
        return s;
    }
};

// Driver Code
int main() {
    Solution sol;
    
    vector<pair<int, int>> testCases = {{1, 3}, {1, 4}, {3, 9}};
    for (auto [n, k] : testCases) {
        cout << "n = " << n << ", k = " << k 
             << " -> Happy String: \"" << sol.getHappyString(n, k) << "\"" << endl;
    }

    return 0;
}

