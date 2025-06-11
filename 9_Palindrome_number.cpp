#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // Step 1: Handle edge case - negative numbers are never palindromes
        if (x < 0)
            return false;

        // Step 2: Store the original number to compare later
        int temp = x;

        // Step 3: Variable to store the reversed number
        int rev = 0;

        // Step 4: Loop to reverse the digits of x
        while (x > 0)
        {
            int digit = x % 10; // Get the last digit
            // Step 5:
            if (rev > (INT_MAX - digit) / 10)
            {
                // Overflow will occur; hence, we return false.
                return false;
            }

            // Step 6: Safely update the reversed number
            rev = rev * 10 + digit;

            // Step 7: Remove the last digit from x
            x = x / 10;
        }

        // Step 8: After reversing, compare with original number
        return rev == temp;
    }
};

// Example usage of the Solution class
int main()
{
    Solution sol;

    int number = 998765432; // Change this to test other numbers

    // Step 9: Check and print if the number is a palindrome
    if (sol.isPalindrome(number))
    {
        cout << number << " is a palindrome." << endl;
    }
    else
    {
        cout << number << " is not a palindrome." << endl;
    }

    return 0;
}

/**
 * Step 5: Before performing rev = rev * 10 + digit,
 * we must ensure that it won't cause an integer overflow.
 *
 * Why? Because multiplying a large number by 10 may exceed the
 * 32-bit integer limit (INT_MAX = 2147483647).
 *
 * The formula to prevent overflow is:
 * If rev > (INT_MAX - digit) / 10
 * then rev * 10 + digit would overflow.
 */
