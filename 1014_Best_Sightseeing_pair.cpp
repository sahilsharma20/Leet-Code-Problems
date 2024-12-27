#include <vector>
#include <algorithm> // For the max function
#include <iostream>  // For printing output
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(); // Get the number of elements in the input array

        // Variable to store the maximum value of values[i] + i encountered so far
        int first = values[0]; 
        
        // Variable to store the maximum score of the sightseeing pair
        int max_pair_sum = 0; 
        
        // Iterate through the array starting from the second element (index 1)
        for (int j = 1; j < n; ++j) {
            // Calculate the current second term as values[j] - j
            int second = values[j] - j; 
            
            // Calculate the sightseeing score for the pair (i, j) and update the maximum
            max_pair_sum = max(max_pair_sum, first + second);
            
            // Update the maximum value of values[i] + i for the next iteration
            first = max(first, values[j] + j);
        }
        
        // Return the maximum sightseeing pair score
        return max_pair_sum;
    }
};

// Main function to test the implementation
int main() {
    Solution solution;
    
    // Test case 1
    vector<int> values1 = {8, 1, 5, 2, 6};
    int result1 = solution.maxScoreSightseeingPair(values1);
    cout << "Result for values1: " << result1 << endl; // Expected output: 11

    // Test case 2
    vector<int> values2 = {1, 2};
    int result2 = solution.maxScoreSightseeingPair(values2);
    cout << "Result for values2: " << result2 << endl; // Expected output: 2

    return 0;
}

