#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 1, right = *max_element(candies.begin(), candies.end());
        int result = 0;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long count = 0;
            
            for (int c : candies) {
                count += c / mid; // Count how many children can be served with mid-sized candies
            }
            
            if (count >= k) { // If we can serve at least k children, try for a larger size
                result = mid;
                left = mid + 1;
            } else { // Otherwise, try a smaller size
                right = mid - 1;
            }
        }
        
        return result;
    }
};
