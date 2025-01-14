#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0); // Frequency array for elements in A and B
        vector<int> res(n);        // Result array to store prefix common counts
        int commonCount = 0;       // Counter for common elements

        for (int i = 0; i < n; ++i) {
            // Increment frequency for the current element in A
            freq[A[i]]++;
            if (freq[A[i]] == 2) { 
                // If frequency becomes 2, it means it's common in both arrays
                commonCount++;
            }

            // Increment frequency for the current element in B
            freq[B[i]]++;
            if (freq[B[i]] == 2) {
                // If frequency becomes 2, it means it's common in both arrays
                commonCount++;
            }

            // Update the result array with the current count of common elements
            res[i] = commonCount;
        }
        
        return res;
    }
};

int main() {
    Solution sol;

    // Example Input 1
    vector<int> A1 = {1, 3, 2, 4};
    vector<int> B1 = {3, 1, 2, 4};
    vector<int> result1 = sol.findThePrefixCommonArray(A1, B1);

    // Output Result 1
    cout << "Output for Input 1: ";
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;

    // Example Input 2
    vector<int> A2 = {2, 3, 1};
    vector<int> B2 = {3, 1, 2};
    vector<int> result2 = sol.findThePrefixCommonArray(A2, B2);

    // Output Result 2
    cout << "Output for Input 2: ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

