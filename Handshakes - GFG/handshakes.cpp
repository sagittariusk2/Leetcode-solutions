// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int count(int N){
        N /= 2;
        vector<int> dp(N+1, 1);
        for(int i=1; i<=N; i++) {
            int x=0;
            for(int j=0; j<i; j++) {
                x += (dp[j]*dp[i-j-1]);
            }
            dp[i]=x;
        }
        return dp[N];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends