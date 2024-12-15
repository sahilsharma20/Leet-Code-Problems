class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0; 
        int n = nums.size();
        for(int i = 0; i<nums.size(); i++){
            if (i<(n-1) && nums[i] == nums[i+1])
                continue;
            else{
                nums[count] = nums[i];
                count++;
            }
        }
    return count;
    }
};
