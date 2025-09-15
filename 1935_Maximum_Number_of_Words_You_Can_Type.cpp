class Solution {
public:
    int canBeTypedWords(string& text, string& brokenLetters) {
        const int n=text.size();
        bitset<128> broken=0;
        for(char c: brokenLetters)
            broken[c]=1;
        int cnt=0;
        bool word=1;
        text.push_back(' ');
        for(char c: text){
            if (broken[c]) word=0;
            else if (c==' '){
                cnt+=word;
                word=1;
            }
        }
        return cnt;
    }
};
