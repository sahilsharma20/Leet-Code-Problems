#include <vector>
using namespace std;
class Solution
{
public:
    bool isValidZero(int m, vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> pre(n + 1, 0); // to efficiently perform range updates on an array in constant time
        for (int i = 0; i < m; i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];
            int val = queries[i][2];
            pre[left] += val; // Increment pre[left] by val → pre[left] += val

            if (right + 1 < n)
                pre[right + 1] -= val; // Decrement pre[right+1] by val → pre[right+1] -= val (to stop adding beyond right)
        }
        int pre_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            pre_sum += pre[i]; // calculate prefix sum of designed pre array.
            if (pre_sum < nums[i])
                return false; // if prefix sum till ith index is les than nums[i] return false(invalid).
        }
        return true;
    }
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int low = 0, high = queries.size();
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isValidZero(mid, nums, queries))
            {
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
