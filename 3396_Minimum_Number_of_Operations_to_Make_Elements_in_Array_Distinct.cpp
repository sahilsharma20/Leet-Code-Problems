class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        while(true){
            unordered_map<int, int> freq;
            for(int num : nums)
                freq[num]++;

            int duplicates = 0;
            for(auto& pair: freq){
                if(pair.second > 1){
                    duplicates += pair.second - 1;
                }
            }
            
            if(duplicates == 0){
                break;
            }
            
            if(nums.size() >= 3){
                nums.erase(nums.begin(), nums.begin() + 3);
            }
            else{
                nums.clear();
            }
            operations++;
        }
        return operations;
    }
};
