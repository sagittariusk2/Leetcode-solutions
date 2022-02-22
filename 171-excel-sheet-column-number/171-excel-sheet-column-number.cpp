class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long x = 1;
        int ans = 0;
        for(int i=columnTitle.size()-1; i>=0; i--) {
            ans += (x*(columnTitle[i]-'A'+1));
            x *= 26;
        }
        return ans;
    }
};