class Solution {
public:
    int countSubstrings(string s) {
        int ans=0, n=s.size();
        // odd
        for(int i=0; i<n; i++) {
            int j=i, k=i;
            while(j>=0 and k<n and s[j]==s[k]) {
                ans++, j--, k++;
            }
        }
        // even
        for(int i=1; i<n; i++) {
            int j=i-1, k=i;
            while(j>=0 and k<n and s[j]==s[k]) {
                ans++, j--, k++;
            }
        }
        return ans;
    }
};