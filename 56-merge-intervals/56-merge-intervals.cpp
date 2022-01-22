class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v2;
        int s = nums[0][0], e=nums[0][1];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i][0]<=e) {
                e = max(e, nums[i][1]);
            } else {
                v2.push_back({s, e});
                s = nums[i][0];
                e = nums[i][1];
            }
        }
        v2.push_back({s, e});
        return v2;
    }
};