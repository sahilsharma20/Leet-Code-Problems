class Solution {
public:
    long long distributeCandies(int n, int limit) {
        vector<vector<long long>> dp(2, vector<long long>(n + 1));
        dp[0][0] = 1;
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] + (j <= limit);
        }
        dp[1][0] = 1;
        for(int j = 1; j <= n; j++) {
            dp[1][j] += dp[1][j - 1] + (dp[1 - 1][j] - (j - limit - 1 >= 0 ? dp[1 - 1][j - limit - 1] : 0));
        }
        return dp[1][n] - (n - limit - 1 >= 0 ? dp[1][n - limit - 1] : 0);
    }
};
