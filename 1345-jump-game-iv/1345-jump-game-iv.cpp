class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, set<int>> mp;
        for(int i=0; i<n; i++) {
            mp[arr[i]].insert(i);
        }
        vector<int> dp(n, INT_MAX);
        int x=1;
        dp[0] = 0;
        set<int> s1;
        s1.insert(0);
        while(!s1.empty()) {
            set<int> s2;
            for(auto i:s1) {
                if(i+1<n and dp[i+1]==INT_MAX) {
                    s2.insert(i+1);
                    dp[i+1]=x;
                }
                if(i-1>=0 and dp[i-1]==INT_MAX) {
                    s2.insert(i-1);
                    dp[i-1]=x;
                }
                for(auto j:mp[arr[i]]) {
                    s2.insert(j);
                    dp[j] = min(x, dp[j]);
                }
                mp.erase(arr[i]);
            }
            x++;
            s1 = s2;
        }
        
        return dp[n-1];
    }
};