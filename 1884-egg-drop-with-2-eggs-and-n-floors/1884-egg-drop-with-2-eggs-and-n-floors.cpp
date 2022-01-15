class Solution {
public:
    int solve(int k, int n, vector<vector<int>> &dp) {
        if(dp[k][n]!=-1) return dp[k][n];
        if(k==1 or n==1 or n==0) return dp[k][n]=n;
        int ans = INT_MAX;
        for(int i=1; i<=n; i++) {
            ans = min(ans, 1+max(solve(k, n-i, dp), solve(k-1, i-1, dp)));
        }
        return dp[k][n]=ans;
    }
    
    int twoEggDrop(int n) {
        int k=2;
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        return solve(k, n, dp);
    }
};