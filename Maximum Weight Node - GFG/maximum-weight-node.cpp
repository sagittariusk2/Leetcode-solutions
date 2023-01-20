//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    int maxWeightCell(int n, vector<int> Edge) {
        vector<int> v1(n, 0);
        for(int i=0; i<n; i++) {
            if(Edge[i]!=-1) {
                v1[Edge[i]]+=i;
            }
        }
        int mx=v1[0], mx_index=0;
        for(int i=1; i<n; i++) {
            if(v1[i]>=mx) {
                mx = v1[i];
                mx_index = i;
            }
        }
        return mx_index;
    }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends