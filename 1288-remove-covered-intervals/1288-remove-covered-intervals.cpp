bool comp(vector<int> &a, vector<int> &b) {
    if(a[0]==b[0]) {
        return a[1]>b[1];
    } else {
        return a[0]<b[0];
    }
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int ans=1, n = intervals.size();
        int s=intervals[0][0], e=intervals[0][1];
        for(int i=1; i<n; i++) {
            if(intervals[i][0]>=s and intervals[i][1]<=e) {
                
            } else {
                ans++;
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }
        return ans;
    }
};