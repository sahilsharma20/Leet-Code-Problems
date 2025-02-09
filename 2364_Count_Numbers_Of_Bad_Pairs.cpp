#include <bits/stdc++.h>
using namespace std;

class Solution {
    #define ll long long
public:
    long long countBadPairs(vector<int>& nums) {
        ll n = nums.size();
        
        unordered_map<int, int> freq;
        ll good_pairs = 0;

        for (int i = 0; i < n; ++i) {
            if (freq.count(nums[i] - i)) 
                good_pairs += freq[nums[i] - i];
            freq[nums[i] - i]++;
        }

        ll total_pairs = (n * (n - 1)) / 2;
        return total_pairs - good_pairs;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {4, 1, 3, 3};
    vector<int> nums2 = {1, 2, 3, 4, 5};

    cout << "Output for [4,1,3,3]: " << sol.countBadPairs(nums1) << endl;
    cout << "Output for [1,2,3,4,5]: " << sol.countBadPairs(nums2) << endl;

    return 0;
}

