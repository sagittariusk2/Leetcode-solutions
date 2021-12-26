class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[256]={0};
        int n=s.length();
        int i=0, j=1;
        if(n==0) return 0;
        map[s[0]]++;
        int ans = 1;
        while(i<n and j<n) {
            if(map[s[j]]<=0) {
                map[s[j++]]++;
            } else {
                map[s[i++]]--;
            }
            ans = max(ans, j-i);
        }
        return ans;
    }
};