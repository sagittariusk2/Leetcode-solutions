class Solution {
public:
    int solve(vector<int> &nums, int n, int x, vector<vector<int>> &dp) {
        // cout << n << " " << x << endl;
        if(x==0) return 1;
        if(n==-1) return 0;
        if(dp[n][x]!=-1) return dp[n][x];
        bitset<16> b1(x), b2(nums[n]);
        bool y=false;
        for(int i=0; i<16; i++) {
            if(b1[i]==0 and b2[i]==1) {
                y=true;
                break;
            }
        }
        
        if(y) return dp[n][x] = solve(nums, n-1, x, dp);
        
        return dp[n][x] = (solve(nums, n-1, x^nums[n], dp) or solve(nums, n-1, x, dp));
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto i:nums) {
            sum += i;
        }
        
        if(sum%k!=0) return false;
        sum /= k;
        int n=1<<nums.size();
        int j=-1, l=-1;
        vector<int> v1(n, 0), ans;
        for(int i=1; i<n; i++) {
            if((i&(i-1))==0) {
                j=i;
                l++;
            }
            
            v1[i]=v1[i-j]+nums[l];
            if(v1[i]==sum) {
                ans.push_back(i);
            }
        }
        
//         for(auto i:ans) {
//             cout << i << " ";
//         }
        
//         cout << endl;
        
        vector<vector<int>> dp(ans.size(), vector<int>(n, -1));
        
        return solve(ans, ans.size()-1, n-1, dp);
    }
};