class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans_index = 0, count=0;
        for(int i=0; i<nums.size(); i++) {
            if(count==0) {
                ans_index = i;
            }
            count += (nums[i]==nums[ans_index])?1:-1;
        }
        return nums[ans_index];
    }
};