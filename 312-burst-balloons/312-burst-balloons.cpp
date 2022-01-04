class Solution {
public:
    
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if(dp[i][j]!=-1) return dp[i][j];
        if(j-i<=1) return dp[i][j]=0;
        int ans=INT_MIN;
        for(int k=i+1; k<j; k++) {
            ans = max(ans, solve(i, k, nums, dp)+(nums[k]*nums[i]*nums[j])+solve(k, j, nums, dp));
        }
        return dp[i][j]=ans;
    }
    
    int maxCoins(vector<int>& nums) {
        vector<int> new_nums;
        new_nums.push_back(1);
        for(auto i:nums) {
            new_nums.push_back(i);
        }
        new_nums.push_back(1);
        vector<vector<int>> dp(new_nums.size(), vector<int>(new_nums.size(), -1));
        return solve(0, new_nums.size()-1, new_nums, dp);
    }
};