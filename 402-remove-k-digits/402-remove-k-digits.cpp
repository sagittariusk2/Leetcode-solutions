class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char> st;
        int n=s.size();
        st.push(s[0]);
        for(int i=1; i<n; i++) {
            while(k>0 and !st.empty() and st.top()>s[i]) {
                st.pop();
                k--;
            }
            if(st.empty() and s[i]=='0');
            else st.push(s[i]);
        }
        string ans;
        while(!st.empty()) {
            if(k!=0) k--;
            else ans += st.top();
            st.pop();
        }
        
        if(ans.size()==0) ans = "0";
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};