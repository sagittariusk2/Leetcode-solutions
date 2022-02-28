class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if(n==0) return ans;
        int s=nums[0], e=nums[0];
        for(int i=1; i<n; i++) {
            if(nums[i]==nums[i-1]+1) {
                e = nums[i];
            } else {
                if(s==e) ans.push_back(to_string(s));
                else {
                    ans.push_back(to_string(s)+"->"+to_string(e));
                }
                s=e=nums[i];
            }
        }
        if(s==e) ans.push_back(to_string(s));
        else {
            ans.push_back(to_string(s)+"->"+to_string(e));
        }
        return ans;
    }
};