class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stl, str;
        int n = heights.size();
        vector<int> vl(n), vr(n);
        for(int i=0; i<n; i++) {
            while(!stl.empty() and heights[i]<=heights[stl.top()]) {
                stl.pop();
            }
            vl[i] = (stl.empty())? -1 : stl.top();
            stl.push(i);
        }
        
        for(int i=n-1; i>=0; i--) {
            while(!str.empty() and heights[i]<=heights[str.top()]) {
                str.pop();
            }
            vr[i] = (str.empty())? n : str.top();
            str.push(i);
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans = max(ans, (vr[i]-vl[i]-1)*heights[i]);
        }
        return ans;
    }
};