#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Helper function to check if we can split square into parts summing to val
    bool isValid(string& sq, int pos, int sum, int& val) {
        if (pos >= sq.size()) 
            return sum == val;  // If end of string is reached, check sum
        
        for (int i = 0; i + pos < sq.size(); ++i) {
            int curr_val = stoi(sq.substr(pos, i + 1));  // Extract substring as integer
            if (isValid(sq, i + pos + 1, sum + curr_val, val)) 
                return true;
        }
        return false;
    }

public:
    int punishmentNumber(int n) {
        int punishment_number = 0;  // Initialize sum
        
        for (int i = 1; i <= n; ++i) {  
            string sq = to_string(i * i);  // Convert square of i to string
            if (isValid(sq, 0, 0, i)) 
                punishment_number += i * i;  // Add valid numbers to the sum
        }
        
        return punishment_number;
    }
};

// Driver code to test the function
int main() {
    Solution sol;
    cout << "Punishment Number for n=10: " << sol.punishmentNumber(10) << endl;
    cout << "Punishment Number for n=37: " << sol.punishmentNumber(37) << endl;
    return 0;
}

