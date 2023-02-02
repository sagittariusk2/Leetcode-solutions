//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    long long largestSumCycle(int N, vector<int> Edge) {
        long long ans = -1;
        for(int i=0; i<N; i++) {
            vector<int> k;
            int j=i;
            vector<long long> temp;
            while(Edge[j]!=-1) {
                k.push_back(j);
                if(temp.empty()) temp.push_back(j);
                else {
                    long long int x = temp[temp.size()-1]+j;
                    temp.push_back(x);
                }
                int l=Edge[j];
                Edge[j]=-1;
                j=l;
            }
            for(int l=0; l<k.size(); l++) {
                if(k[l]==j) {
                    long long y=(l==0)?0:temp[l-1];
                    ans = max(ans, temp[temp.size()-1]-y);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
signed main(){
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
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends