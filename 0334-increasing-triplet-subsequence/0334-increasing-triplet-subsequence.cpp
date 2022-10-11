class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long a=LLONG_MAX, b=LLONG_MAX, c=LLONG_MAX;
        for(auto i:nums) {
            if(i<=a) a=i;
            else if(i<=b) b=i;
            else if(i<=c) c=i;
        }
        return c!=LLONG_MAX;
    }
};