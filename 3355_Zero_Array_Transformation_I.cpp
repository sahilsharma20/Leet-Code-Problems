class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> sweep(n + 1, 0);

        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];
            sweep[l] += 1;
            if (r + 1 <= n) {
                sweep[r + 1] -= 1;
            }
        }

        for (int i = 1; i <= n; ++i) {
            sweep[i] += sweep[i - 1];
        }

        for (int i = 0; i < n; ++i) {
            if (sweep[i] < nums[i]) return false;
        }

        return true;
    }
};
