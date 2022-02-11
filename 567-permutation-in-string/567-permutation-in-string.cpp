class Solution {
public:
    
    bool equal(int map_s1[], int map_s2[]) {
        for(int i=0; i<26; i++) {
            if(map_s1[i]!=map_s2[i]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int map_s1[26]={0}, map_s2[26]={0};
        int n=s1.length(), m=s2.length();
        
        if(n>m) return false;
        
        for(int i=0; i<n; i++) {
            map_s1[s1[i]-97]++;
        }
        
        for(int i=0; i<n; i++) {
            map_s2[s2[i]-97]++;
        }
        if(equal(map_s1, map_s2)) return true;
        for(int i=n; i<m; i++) {
            map_s2[s2[i]-97]++;
            map_s2[s2[i-n]-97]--;
            if(equal(map_s1, map_s2)) return true;
        }
        return false;
    }
};