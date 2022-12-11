//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        vector<int> rem(k, 0);
        for(int i=0; i<nums.size(); i++) {
            rem[nums[i]%k]++;
        }
        // for(auto i:rem) cout << i << " ";
        for(int i=1; i<=k/2; i++) {
            if(i==k-i and rem[i]%2) return false;
            else if(rem[i]!=rem[k-i]) return false;
        }
        if(rem[0]%2) return false;
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends