#include <iostream>
#include <string>
#include <algorithm> // For std::max

using namespace std;

class Solution {
public:
    // Function to calculate the maximum score of a string after splitting into two non-empty substrings
    int maxScore(string s) {
        int n = s.size(); // Size of the input string

        // Count the total number of '1's in the string
        int one_count = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                one_count++;
            }
        }

        int zero_count = 0; // Count of '0's in the left substring
        int max_score = 0;  // Maximum score achieved

        // Iterate through the string, splitting it into two parts
        for (int i = 0; i < n - 1; ++i) { // Loop ends at n-1 to ensure both substrings are non-empty
            if (s[i] == '1') {
                one_count--; // Decrease the count of '1's in the right substring
            } else {
                zero_count++; // Increase the count of '0's in the left substring
            }

            // Calculate the score and update the maximum score
            max_score = max(max_score, zero_count + one_count);
        }

        return max_score; // Return the maximum score achieved
    }
};

int main() {
    Solution solution; // Create an instance of the Solution class

    // Example 1
    string s1 = "011101";
    cout << "Input: s = \"" << s1 << "\"" << endl;
    cout << "Output: " << solution.maxScore(s1) << endl;
    // Expected output: 5

    // Example 2
    string s2 = "00111";
    cout << "\nInput: s = \"" << s2 << "\"" << endl;
    cout << "Output: " << solution.maxScore(s2) << endl;
    // Expected output: 5

    // Example 3
    string s3 = "1111";
    cout << "\nInput: s = \"" << s3 << "\"" << endl;
    cout << "Output: " << solution.maxScore(s3) << endl;
    // Expected output: 3

    return 0;
}

