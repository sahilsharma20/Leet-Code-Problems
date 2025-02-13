#include <bits/stdc++.h>
using namespace std;

class Solution {
    #define ll long long
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> minheap(nums.begin(), nums.end());
        int count = 0;

        while (minheap.size() > 1 && minheap.top() < k) {
            ll min1 = minheap.top(); minheap.pop();
            ll min2 = minheap.top(); minheap.pop();
            
            ll new_val = 2 * min(min1, min2) + max(min1, min2);
            minheap.push(new_val);
            count++;
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2, 11, 10, 1, 3};
    vector<int> nums2 = {1, 1, 2, 4, 9};

    cout << "Output for {2, 11, 10, 1, 3}, k = 10: " << sol.minOperations(nums1, 10) << endl;
    cout << "Output for {1, 1, 2, 4, 9}, k = 20: " << sol.minOperations(nums2, 20) << endl;

    return 0;
}

