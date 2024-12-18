#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution {
    #define pii pair<int, int> // Pair of <char_index, frequency>
public:
    // Function to construct a repeat-limited string
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0); // Frequency array for 'a' to 'z'

        int n = s.size();
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++; // Count the frequency of each character
        }

        // Max-heap (priority_queue) to store characters sorted by frequency
        priority_queue<pii> maxheap;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                maxheap.push({i, freq[i]}); // Push character index and frequency
            }
        }

        string res; // Resultant string

        // Construct the string
        while (!maxheap.empty()) {
            pii curr = maxheap.top(); // Top element of heap
            maxheap.pop();

            char curr_char = 'a' + curr.first; // Convert index to character
            int count = min(curr.second, repeatLimit); // Number of times to repeat curr_char
            curr.second -= count; // Reduce the frequency
            res.append(count, curr_char); // Append the character to result

            // If the character still has a remaining frequency
            if (curr.second > 0) {
                if (maxheap.empty()) break; // No more characters to insert, avoid consecutive repeats

                // Fetch the next most frequent character
                pii next = maxheap.top();
                maxheap.pop();

                char next_char = 'a' + next.first;
                res.push_back(next_char); // Insert one occurrence of the next character
                next.second--; // Reduce its frequency

                // Push both characters back into the heap if they have remaining frequencies
                if (next.second > 0) {
                    maxheap.push(next);
                }
                maxheap.push(curr);
            }
        }
        return res;
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    string inputString = "cczazzzzz"; // Input string
    int repeatLimit = 2; // Repeat limit

    // Call the function
    string result = solution.repeatLimitedString(inputString, repeatLimit);

    // Output the result
    cout << "Resultant repeat-limited string: " << result << endl;

    return 0;
}

