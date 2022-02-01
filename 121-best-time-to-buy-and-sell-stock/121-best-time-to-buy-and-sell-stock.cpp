class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT_MIN, x=INT_MAX;
        for(auto i:prices) {
            x = min(x, i);
            ans = max(ans, i-x);
        }
        return ans;
    }
};