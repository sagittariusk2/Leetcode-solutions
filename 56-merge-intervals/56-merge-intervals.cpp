class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int s = intervals[0].front(), e = intervals[0].back();
        for(int i=1; i<intervals.size(); i++) {
            if(e>=intervals[i].front()) {
                e = max(e, intervals[i].back());
            } else {
                ans.push_back({s, e});
                s = intervals[i].front();
                e = intervals[i].back();
            }
        }
        ans.push_back({s, e});
        
        return ans;
    }
};