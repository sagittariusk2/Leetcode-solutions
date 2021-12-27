class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> l_sum(n+1, 0), r_sum(n+1, 0);
        
        for(int i=1; i<n; i++) {
            l_sum[i] = l_sum[i-1]+nums[i-1];
        }
        for(int i=n-1; i>=0; i--) {
            r_sum[i] = r_sum[i+1]+nums[i];
        }
        int ans = INT_MAX;
        for(int i=0; i<=n; i++) {
            if(binary_search(l_sum.begin(), l_sum.end(), x-r_sum[n-i])) {
                int y = lower_bound(l_sum.begin(), l_sum.end(), x-r_sum[n-i])-l_sum.begin();
                // cout << i << " " << y << "\n";
                if(y+i<=n)
                    ans = min(ans, i+y);
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};