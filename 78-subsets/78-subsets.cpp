class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        int m=1<<n;
        vector<int> temp;
        ans.push_back(temp);
        for(int i=1; i<m; i++) {
            int x = log2(i);
            temp = ans[i-(1<<x)];
            temp.push_back(nums[x]);
            ans.push_back(temp);
        }
        return ans;
    }
};