// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0; i<N; i++) {
            sum += arr[i];
        }
        
        if(sum%2==1) return 0;
        int m=sum/2;
        vector<int> dp(m+1, 0);
        dp[0]=1;
        for(int i=0; i<N; i++) {
            for(int j=m; j>=0; j--) {
                if(j-arr[i]>=0) {
                    dp[j] = max(dp[j], dp[j-arr[i]]);
                }
            }
        }
        if(dp[m]>=1) return 1;
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends