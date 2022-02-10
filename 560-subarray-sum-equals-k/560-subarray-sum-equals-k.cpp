class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mpp;
        mpp[0]=1;
        int sum=0, ans=0;
        for(auto i:nums) {
            sum += i;
            ans += mpp[sum-k];
            mpp[sum]++;
        }
        return ans;
    }
};