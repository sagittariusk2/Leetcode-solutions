class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> v1;
        for(int i=0; i<points.size(); i++) {
            v1.emplace_back(points[i][0]*points[i][0]+points[i][1]*points[i][1], i);
        }
        sort(v1.begin(), v1.end());
        vector<vector<int>> ans;
        for(int i=0; i<k; i++) {
            vector<int> x(2);
            x[0] = points[v1[i].second][0];
            x[1] = points[v1[i].second][1];
            ans.push_back(x);
        }
        return ans;
    }
};