#include <iostream>
using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = __builtin_popcount(num2);
        int res = 0;

        // Cancel set bits from highest to lowest weight
        for (int i = 31; i >= 0 && count; i--) {
            if (num1 & (1 << i)) {
                count--;
                res += (1 << i);
            }
        }

        // Set bits lowest to highest weight
        for (int i = 0; i < 32 && count; i++) {
            if ((num1 & (1 << i)) == 0) {
                count--;
                res += (1 << i);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    int num1 = 3, num2 = 5;
    cout << "Output (num1 = 3, num2 = 5): " << sol.minimizeXor(num1, num2) << endl;

    // Test Case 2
    num1 = 1, num2 = 12;
    cout << "Output (num1 = 1, num2 = 12): " << sol.minimizeXor(num1, num2) << endl;

    return 0;
}

