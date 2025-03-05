
class Solution {
    #define ll long long
public:
    long long coloredCells(int n) {
        ll count=1;
        ll jump_size=4;
        while(n>1){
            count += jump_size;
            jump_size += 4;
            n--;
        }
        return count;
    }
};
