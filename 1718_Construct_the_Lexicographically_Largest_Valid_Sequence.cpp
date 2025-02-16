#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool findLargestArray(vector<int>& res, vector<bool>& used, int pos, int n) {
        if (pos == 2 * n - 1)  
            return true;  // If all positions are filled, return true

        if (res[pos] != 0)  // Skip already filled positions
            return findLargestArray(res, used, pos + 1, n);
        
        // Try assigning all unused values from largest to smallest
        for (int i = n; i >= 1; --i) {  
            if (used[i]) continue;  // Skip if already used

            used[i] = true;  
            res[pos] = i;
            
            if (i == 1) {  // If `i == 1`, no second occurrence needed
                if (findLargestArray(res, used, pos + 1, n))
                    return true;
            } 
            else if (pos + i < 2 * n - 1 && res[pos + i] == 0) {  
                res[pos + i] = i;  // Place `i` at its second required position
                
                if (findLargestArray(res, used, pos + 1, n))
                    return true;
                
                res[pos + i] = 0;  // Backtrack if solution not found
            }

            used[i] = false;  // Backtrack
            res[pos] = 0;
        }
        return false;
    }

public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2 * n - 1, 0);  // Result array of size (2*n-1)
        vector<bool> used(n + 1, false);  // Track used numbers
        
        findLargestArray(res, used, 0, n);
        return res;
    }
};

// Driver code to test the function
int main() {
    Solution sol;
    int n = 3;
    vector<int> result = sol.constructDistancedSequence(n);

    cout << "Lexicographically largest valid sequence for n = " << n << ": ";
    for (int num : result) 
        cout << num << " ";
    
    cout << endl;
    return 0;
}

