class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> ans(target+1);
        vector<int> v1;
        ans[0].push_back(v1);
        for(auto i:candidates) {
            for(int j=0; j<=target; j++) {
                if(j-i>=0) {
                    for(auto k:ans[j-i]) {
                        vector<int> x = k;
                        x.push_back(i);
                        ans[j].push_back(x);
                    }
                }
            }
        }
        return ans[target];
    }
};