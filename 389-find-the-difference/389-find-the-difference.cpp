class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v1(26, 0);
        for(auto i:s) {
            v1[i-'a']++;
        }
        for(auto i:t) {
            v1[i-'a']--;
        }
        for(int i=0; i<26; i++) {
            if(v1[i]) return (char)(i+'a');
        }
        return 'a';
    }
};