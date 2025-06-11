#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        string ans = "";

        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());

        // Step 2: Traverse the reversed string and process each word
        for (int i = 0; i < n; i++)
        {
            string word = "";

            // Skip multiple spaces
            while (i < n && s[i] == ' ')
                i++;

            // Build the word until a space is encountered
            while (i < n && s[i] != ' ')
            {
                word += s[i];
                i++;
            }

            // Reverse the current word to restore its original character order
            reverse(word.begin(), word.end());

            // If word is non-empty, append it to the answer string with a space
            if (!word.empty())
            {
                ans += " " + word;
            }
        }

        // Step 3: Return the result by skipping the first space
        // as the result string starts with a space due to our logic above
        return ans.substr(1);
    }
};

// Example usage
int main()
{
    Solution sol;
    string input1 = "the sky is blue";
    string output1 = sol.reverseWords(input1); // Output: "blue is sky the"
    string input2 = "  hello world  ";
    string output2 = sol.reverseWords(input2); // Output: "world hello"
    string input3 = "a good   example";
    string output3 = sol.reverseWords(input3);  // Output: "example good a"
    cout << "Reversed words: \"" << output1 << "\"" << endl;
    cout << "Reversed words: \"" << output2 << "\"" << endl;
    cout << "Reversed words: \"" << output3 << "\"" << endl;

    return 0;
}
