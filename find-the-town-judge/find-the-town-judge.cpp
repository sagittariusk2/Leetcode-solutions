class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int, int>> v1(n, make_pair(0, 0));
        
        for(auto i:trust) {
            v1[i[0]-1].first++;
            v1[i[1]-1].second++;
        }
        
        for(int i=0; i<n; i++) {
            if(v1[i].first==0 and v1[i].second==n-1) return i+1;
        }
        
        return -1;
    }
};