#include <iostream>
#include <vector>
#include <algorithm> // For max function
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();

        // Initialize count to store the number of chunks
        int count = 0;

        // Variable to track the maximum value seen so far in the array
        int max_seen = 0;

        // Loop through the array to determine chunks
        for (int i = 0; i < n; ++i) {
            // Update the maximum value encountered so far
            max_seen = max(max_seen, arr[i]);

            // If the maximum value seen so far equals the current index,
            // it means all elements up to this point can form a valid chunk
            if (max_seen == i)
                count++;
        }

        // Return the total number of chunks
        return count;
    }
};

int main() {
    // Example input array
    vector<int> arr = {1, 0, 2, 3, 4};

    // Create an object of the Solution class
    Solution solution;

    // Call the function and store the result
    int result = solution.maxChunksToSorted(arr);

    // Print the result
    cout << "Maximum number of chunks: " << result << endl;

    return 0;
}

