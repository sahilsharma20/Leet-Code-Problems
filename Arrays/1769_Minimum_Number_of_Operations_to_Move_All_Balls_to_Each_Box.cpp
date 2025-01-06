#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int sum = 0, right_ones = 0;

        // Calculate initial sum and count of "1"s on the right
        for (int i = 0; i < n; ++i) {
            if (boxes[i] == '1') {
                sum += i;
                right_ones++;
            }
        }

        vector<int> res(n);
        int prefix_sum = 0, left_ones = 0;

        // Calculate moves for each position
        for (int i = 0; i < n; ++i) {
            res[i] = sum + prefix_sum;

            // Update counts for the next position
            if (boxes[i] == '1') {
                left_ones++;
                right_ones--;
            }
            prefix_sum += left_ones;
            sum -= right_ones;
        }

        return res;
    }
};

int main() {
    Solution solution;

    // Example 1
    string boxes1 = "110";
    vector<int> result1 = solution.minOperations(boxes1);
    for (int moves : result1) cout << moves << " ";
    cout << endl;  // Expected output: 1 1 3

    // Example 2
    string boxes2 = "001011";
    vector<int> result2 = solution.minOperations(boxes2);
    for (int moves : result2) cout << moves << " ";
    cout << endl;  // Expected output: 11 8 5 4 3 4

    return 0;
}
:w
:wq

