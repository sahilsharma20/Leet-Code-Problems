class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        
         sort(nums.begin(), nums.end());
         
        set<int> seen;
        int prev = INT_MIN;
        
        for(int num : nums){
            
            int pos = max(prev + 1, num - k);
            if(pos <= num + k){
                seen.insert(pos);
                prev = pos;
            }
        }
        return seen.size();   
    }
};
