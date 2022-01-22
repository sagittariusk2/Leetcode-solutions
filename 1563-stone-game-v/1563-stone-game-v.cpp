class Solution {
public:
    
    int solve(int i, int j, vector<int>& stoneValue, vector<vector<int>> &dp) {
        if(dp[i][j]!=-1) return dp[i][j];
        if(j==i) {
            return dp[i][j]=0;
        }
        int ans=INT_MIN;
        for(int k=i; k<j; k++) {
            int x = stoneValue[k]-((i==0)?0:stoneValue[i-1]);
            int y = stoneValue[j]-stoneValue[k];
            // cout << x << " " << y << endl;
            if(x<y) {
                // +y
                ans = max(ans, x+solve(i, k, stoneValue, dp));
            } else if(x>y) {
                // +x
                ans = max(ans, y+solve(k+1, j, stoneValue, dp));
            } else {
                ans = max(ans, max(x+solve(i, k, stoneValue, dp), y+solve(k+1, j, stoneValue, dp)));
            }
        }
        return dp[i][j]=ans;
    }
    
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        for(int i=1; i<n; i++) {
            stoneValue[i] += stoneValue[i-1];
            // cout << stoneValue[i] << " ";
        }
        // cout << endl;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n-1, stoneValue, dp);
    }
};