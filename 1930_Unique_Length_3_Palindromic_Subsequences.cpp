class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(first[s[i]-'a']==-1) first[s[i]-'a']=i;
            last[s[i]-'a']=i;
        }
        for(int i=0;i<26;i++)
        {
            if(first[i]==-1) continue;
            int l=first[i];
            int r=last[i];
            if(l+1>=r) continue;
            vector<bool>seen(26,false);
            for(int j=l+1;j<r;j++)
            {
                seen[s[j]-'a']=true;
            }
            for(int k=0;k<26;k++)
            {
                if(seen[k]==true) ans++;
            }
        }
        return ans;
    }
};
