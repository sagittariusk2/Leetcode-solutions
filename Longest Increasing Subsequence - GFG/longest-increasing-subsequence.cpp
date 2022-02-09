// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
        vector<int> ans;
        for(int i=0; i<n; i++) {
            int j=lower_bound(ans.begin(), ans.end(), a[i])-ans.begin();
            if(j==ans.size()) {
                ans.push_back(a[i]);
            } else {
                ans[j]=a[i];
            }
        }
        return ans.size();
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends