class Solution {
    
    int solve(int i, unordered_map<int, int> &mpp) {
        if(mpp.find(i)==mpp.end()) {
            return 0;
        } else {
            if(mpp[i]!=-1) return mpp[i];
            else {
                return mpp[i] = 1+solve(i-1, mpp);
            }
        }
    }
    
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto i:nums) {
            mpp.insert(make_pair(i, -1));
        }
        int ans=0;
        for(auto i:nums) {
            int x = solve(i-1, mpp);
            mpp[i] = x+1;
            ans = max(ans, x+1);
        }
        return ans;
    }
};