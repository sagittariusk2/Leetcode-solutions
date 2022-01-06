class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v1(1001, 0);
        for(auto i:trips) {
            v1[i[1]]+=i[0];
            v1[i[2]]-=i[0];
        }
        
        if(v1[0]>capacity) return false;
        
        for(int i=1; i<=1000; i++) {
            v1[i] += v1[i-1];
            if(v1[i]>capacity) return false;
        }
        
        return true;
    }
};