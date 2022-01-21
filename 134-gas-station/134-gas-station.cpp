class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i=0; i<n; i++) {
            gas[i] -= cost[i];
        }
        for(int i=0; i<n-1; i++) {
            gas.push_back(gas[i]);
        }
        int sum = 0, ans = -1, i=-1, j=0;
        while(j<gas.size()) {
            if(sum<0) {
                i++;
                sum -= gas[i];
            } else {
                if(j-i-1==n) {
                    ans = i+1;
                }
                sum += gas[j++];
            }
        }
        if(sum>=0) {
           if(j-i-1==n) {
                ans = i+1;
            } 
        }
        return ans;
    }
};