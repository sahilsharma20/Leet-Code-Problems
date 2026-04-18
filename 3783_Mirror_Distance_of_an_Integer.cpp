class Solution {
public:
    int revnum(int a) {
        if (a / 10 == 0) return a ;
        string s = to_string(a);
        reverse(s.begin(), s.end()) ;
        int i = 0, n = s.size();
        while (s[i] == '0') {
            i++ ;
        }
        s = s.substr(i);
        int ans = stoi(s) ;
        return ans;
    }

    int mirrorDistance(int n) {
        return abs(n - revnum(n)) ;
    }
};
