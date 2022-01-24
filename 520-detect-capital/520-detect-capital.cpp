class Solution {
public:
    bool detectCapitalUse(string word) {
        int x=0, y=0, x1=0, y1=0, n=word.length();
        for(int i=0; i<n; i++) {
            if(i==0) {
                if(word[i]>='A' and word[i]<='Z') x++;
                else y++;
            } else {
                if(word[i]>='A' and word[i]<='Z') x1++;
                else y1++;
            }
        }
        if(x1+x==n or y1+y==n) return true;
        if(x==1 and y1==n-1) return true;
        return false;
    }
};