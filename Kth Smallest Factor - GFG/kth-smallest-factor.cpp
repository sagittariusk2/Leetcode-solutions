// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int kThSmallestFactor(int N , int K) {
        // code here
        int m = sqrt(N);
        vector<int> ans;
        for(int i=1; i<=m; i++) {
            if(N%i==0) {
                ans.push_back(i);
                int x = N/i;
                if(x!=i)
                ans.push_back(x);
            }
        }
        sort(ans.begin(), ans.end());
        return (K>ans.size())?-1:ans[K-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;

        Solution ob;
        cout << ob.kThSmallestFactor(N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends