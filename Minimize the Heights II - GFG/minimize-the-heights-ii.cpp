// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        // create the array of two elements
        vector<pair<int, int>> towers;
        for(int i=0; i<n; i++) {
            if(arr[i]-k>=0) {
                towers.emplace_back(arr[i]-k, i);
            }
            towers.emplace_back(arr[i]+k, i);
        }
        
        // sort the array
        sort(towers.begin(), towers.end());
        
        // minimum window that will containn my every tower
        vector<int> count(n, 0);
        int occur=0;
        int i=0, j=0;
        int m = towers.size();
        int ans=INT_MAX;
        while(j<m) {
            if(occur==n) {
                count[towers[i].second]--;
                if(count[towers[i].second]==0) occur--;
                i++;
            } else {
                count[towers[j].second]++;
                if(count[towers[j].second]==1) occur++;
                j++;
            }
            if(occur==n) {
                ans = min(ans, towers[j-1].first-towers[i].first);
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends