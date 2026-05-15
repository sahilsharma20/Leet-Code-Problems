class Solution {
public:
    int findMin(vector<int>& nums) {
        int si=0;
        int ei=nums.size()-1;
        int  ans=INT_MAX;
        int n=nums.size();
        while(si<=ei)
        {
                if(nums[si]<nums[ei]){
                return nums[si];
            }
            int mid=si+(ei-si)/2;
            int prev=(mid+n-1)%n;
            int next=(mid+1)%n;

            if(nums[mid]<=nums[prev]  && nums[mid]<=nums[next]){
                return nums[mid];
            }
             if(nums[mid]>=nums[si]){
                si = mid+1;
            }
            else{
                ei = mid-1;
            }
        }
        return -1;
    }
};
