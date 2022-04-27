// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    
long long int killinSpree(long long int n)
   {
       long long count = 0,cost = 1;
       
       while(n-cost*cost>=0){
           n = n-cost*cost;
           cost++;
           count++;
       }
       
       return count;
   }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    }
    return 0;
}
  // } Driver Code Ends