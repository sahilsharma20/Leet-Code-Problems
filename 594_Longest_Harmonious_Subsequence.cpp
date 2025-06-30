class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //WE JUST HAVE TO RETURN THE LENGTH NOT SEQUENCE, SO WE CAN CHANGE THE ORDER BY SORTING
        int l = 0, r = 1;
        int length = 0;
        while (r < nums.size()) {
            int diff = nums[r] - nums[l];
            if (diff == 1)
                length = max(length, r - l + 1);
            if (diff <= 1)
                r++;
            else
                l++;
        }
        return length;
    }
};
