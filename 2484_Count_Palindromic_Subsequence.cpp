class Solution {
public:
    const int MOD = 1e9+7; 
    //size idx = 0, 1, 2, 3, 4
    int f(int i, int size, vector<char>& pattern, string& s, vector<vector<int>>& dp){
        if(size==5) return 1;
        if(i>=s.size()) return 0;
        if(dp[i][size] != -1) return dp[i][size];
        int pick1 = 0;
        int pick2 = 0;
        /*if teh char at index i in s == char at index size in pattern, means this could form the expected palindromic pattern*/
        /*you can put anything as the middle char of palindrome, so when size = 2, we can go to next char with size+1, irrespective of whether char at i in s matched with the char at size in pattern*/
        if(s[i]==pattern[size] || (size==2)) pick1 = f(i+1, size+1, pattern, s, dp);
        
        //lets not pick this char, lessgo to try matching with next char

        pick2 = f(i+1, size, pattern, s, dp);
        return dp[i][size] = pick1%MOD+pick2%MOD;

    }
    int countPalindromes(string& s) {
        int n = s.size();
        //xy_yx, 0<=x<=9, 0<=y<=9
        int count = 0;
        /*now forming different kind of patterns for the first 2 chars,which will also be same as last 2 chars obv*/
        for(int i=0; i<=9; i++){
            for(int j=0; j<=9; j++){
                char x = '0'+i;
                char y = '0'+j;
                vector<vector<int>> dp(n, vector<int>(5, -1));
                vector<char> pattern = {x, y, '0', y, x};
                count  = (count%MOD + f(0, 0, pattern, s, dp)%MOD)%MOD;
            }
        }

        return count;
    }
};
