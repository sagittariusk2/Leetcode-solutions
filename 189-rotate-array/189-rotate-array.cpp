class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k %= n;
        for(int i=0; i<n/2; i++) {
            swap(nums[i], nums[n-i-1]);
        }
        for(int i=0, j=k-1; i<j; i++, j--) {
            swap(nums[i], nums[j]);
        }
        for(int i=k, j=n-1; i<j; i++, j--) {
            swap(nums[i], nums[j]);
        }
    }
};