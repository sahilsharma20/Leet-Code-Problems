#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    #define pii pair<int,int>
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Step 1: Store each number along with its original index
        vector<pii> copy;
        for (int i = 0; i < n; ++i)
            copy.push_back(make_pair(nums[i], i));
        
        // Step 2: Sort the array based on the values
        sort(copy.begin(), copy.end());

        // Step 3: Process groups
        int left = 0, right = 1;
        while (right < n) {
            vector<int> pos = {copy[left].second}; // Start a new group
            
            // Find all elements in the group satisfying the `limit` condition
            while (right < n && abs(copy[right].first - copy[right - 1].first) <= limit) {
                pos.push_back(copy[right].second);
                right++;
            }
            
            // Sort the indices of the group in ascending order
            sort(pos.begin(), pos.end());

            // Place the sorted values of the group back into `nums`
            for (int i = 0; i < right - left; ++i)
                nums[pos[i]] = copy[left + i].first;
            
            // Move to the next group
            left = right;
            right++;
        }

        return nums;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 5, 3, 9, 8};
    int limit1 = 2;
    vector<int> res1 = sol.lexicographicallySmallestArray(nums1, limit1);
    cout << "Output for nums1: ";
    for (int num : res1) cout << num << " ";
    cout << endl; // Expected: [1, 3, 5, 9, 8]

    // Test Case 2
    vector<int> nums2 = {1, 7, 6, 18, 2, 1};
    int limit2 = 3;
    vector<int> res2 = sol.lexicographicallySmallestArray(nums2, limit2);
    cout << "Output for nums2: ";
    for (int num : res2) cout << num << " ";
    cout << endl; // Expected: [1, 6, 7, 18, 1, 2]

    // Test Case 3
    vector<int> nums3 = {1, 7, 28, 19, 10};
    int limit3 = 3;
    vector<int> res3 = sol.lexicographicallySmallestArray(nums3, limit3);
    cout << "Output for nums3: ";
    for (int num : res3) cout << num << " ";
    cout << endl; // Expected: [1, 7, 10, 19, 28]

    return 0;
}

