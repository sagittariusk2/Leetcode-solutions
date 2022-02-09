class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mpp;
        for(auto i:nums) {
            mpp[i]++;
        }
        int ans=0;
        if(k==0) {
            for(auto i:mpp) {
                if(i.second>=2) ans++;
            }
            return ans;
        }
        for(auto i:mpp) {
            if(mpp.find(i.first-k)!=mpp.end() and mpp[i.first-k]!=0)
                ans++;
            if(mpp.find(i.first+k)!=mpp.end() and mpp[k+i.first]!=0)
                ans++;
        }
        return ans/2;
    }
};