class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        vector<pair<int, int>> nums2;
        for(int i=0; i<nums.size(); i++) {
            nums2.emplace_back(nums[i], i);
        }
        sort(nums2.begin(), nums2.end());
        vector<int> ans(2, -1);
        while(i<j) {
            if(nums2[i].first+nums2[j].first>target) {
                j--;
            } else if(nums2[i].first+nums2[j].first<target) {
                i++;
            } else {
                ans[0]=(nums2[i].second);
                ans[1]=(nums2[j].second);
                break;
            }
        }
        return ans;
    }
};