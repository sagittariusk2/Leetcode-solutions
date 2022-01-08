// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        bitset<65> b1(N);
        int ans=-1, t=0;
        for(int i=0; i<65; i++) {
            if(b1[i]) {
                t++;
                if(t==1) {
                    ans=i+1;
                } else {
                    ans=-1;
                }
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
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends