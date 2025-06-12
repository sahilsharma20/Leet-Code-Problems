class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxd = 0;

        for(int i = 0; i < n; i++){
            int nextIndex = (i + 1) % n;
            maxd = max(maxd, abs(nums[i] - nums[nextIndex]));
        }
        return maxd;
    }
};
