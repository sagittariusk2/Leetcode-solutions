class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber>0) {
            int r = columnNumber%26;
            columnNumber /= 26;
            if(r==0) {
                columnNumber--;
                r = 27;
            } else {
                r++;
            }
            char x = r+'A'-2;
            ans += x;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};