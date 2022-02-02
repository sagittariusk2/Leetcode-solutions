class Solution {
public:
    
    bool check(vector<int> &mpp, vector<int> &curr_mpp) {
        for(int j=0; j<26; j++) {
            if(curr_mpp[j]!=mpp[j]) {
                return false;
            }
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.length()>s.length()) return ans;
        vector<int> mpp(26, 0);
        for(auto i:p) {
            mpp[i-'a']++;
        }
        vector<int> curr_mpp(26, 0);
        for(int i=0; i<p.size(); i++) {
            curr_mpp[s[i]-'a']++;
        }
        if(check(mpp, curr_mpp)) {
            ans.push_back(0);
        }
        for(int i=p.size(); i<s.length(); i++) {
            curr_mpp[s[i]-'a']++;
            curr_mpp[s[i-p.size()]-'a']--;
            if(check(mpp, curr_mpp)) {
                ans.push_back(i-p.size()+1);
            }
        }
        return ans;
    }
};