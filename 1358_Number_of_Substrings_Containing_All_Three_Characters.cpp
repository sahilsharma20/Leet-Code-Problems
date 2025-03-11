#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int count[3] = {0}; // To track occurrences of 'a', 'b', 'c'
            int left = 0, result = 0;
            
            for (int right = 0; right < s.size(); ++right) {
                count[s[right] - 'a']++;
                
                while (count[0] > 0 && count[1] > 0 && count[2] > 0) { // When all chars exist
                    result += s.size() - right; // All substrings from 'left' to end are valid
                    count[s[left] - 'a']--; // Shrink window
                    left++;
                }
            }
            
            return result;
        }
    };
    